#include "StdAfx.h"
#include "InstallerWindow.h"
#include "ConfigFileManager.h"
#include "ExtractCabProcessor.h"
#include "HtmlWidgets.h"
#include "Resource.h"
#include "SetControlValuesTask.h"
#include "DownloadWindow.h"

InstallerWindow::InstallerWindow()
: m_download_started(false)
, m_download_cancelled(false)
, m_running_component(NULL)
{

}

void InstallerWindow::Create(int x, int y, int width, int height, const wchar_t * caption)
{
    HtmlWindow::Create(L"index.html", x, y, width, height, caption);
}

bool InstallerWindow::Run()
{
    DoModal(InstallUILevelSetting::Instance->IsAnyUI() 
        ? SW_SHOWNORMAL 
        : SW_HIDE);

    // return(IDOK == DoModal());
    return true;
}

void InstallerWindow::OnShow()
{
    sciter::dom::element r = GetRoot();
    components = r.get_element_by_id("components");

    // os label
    sciter::dom::element os = r.get_element_by_id("os");
    if (os.is_valid())
    {
        os.set_text((DVLib::GetOperatingSystemVersionString() + L" (" + 
            DVLib::pa2wstring(DVLib::GetProcessorArchitecture()) + L")").c_str());
    }

    // status
    status = r.get_element_by_id("status");

    // error
    error = r.get_element_by_id("error");
    ClearError();

    // progress
    progress = r.get_element_by_id("progress");
    ClearProgress();

    // load components
    LoadComponents();

    InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
    CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

    // labels and info
    sciter::dom::element dialog_message = r.get_element_by_id("dialog_message");
    if (dialog_message.is_valid()) 
    {
        dialog_message.set_text(InstallerSession::Instance->sequence == SequenceInstall 
            ? p_configuration->dialog_message.GetValue().c_str()
            : p_configuration->dialog_message_uninstall.GetValue().c_str());
    }

    button_install = r.get_element_by_id("button_install");
    if (button_install.is_valid()) 
    {
        button_install.set_text(p_configuration->install_caption.GetValue().c_str());
        if (InstallerSession::Instance->sequence != SequenceInstall) button_install.destroy();
    }

    button_uninstall = r.get_element_by_id("button_uninstall");
    if (button_uninstall.is_valid()) 
    {
        button_uninstall.set_text(p_configuration->uninstall_caption.GetValue().c_str());
        if (InstallerSession::Instance->sequence != SequenceUninstall) button_uninstall.destroy();
    }

    button_skip = r.get_element_by_id("button_skip");
    if (button_skip.is_valid()) 
    {
        button_skip.set_text(p_configuration->skip_caption.GetValue().c_str());
        if (! m_additional_config)
        {
            button_skip.destroy();
        }
    }

    button_cancel = r.get_element_by_id("button_cancel");
    if (button_cancel.is_valid()) 
    {
        button_cancel.set_text(p_configuration->cancel_caption.GetValue().c_str());
    }

    AddUserControls();
    AddElevatedControls();

    Start();
}

bool InstallerWindow::RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration)
{
    if (! p_Configuration->IsRequired())
    {
        LOG(L"*** Component '" << p_Configuration->component_id << L"': SKIPPING DOWNLOAD/COPY");
        return true;
    }

    m_downloaddialog = p_Configuration;
    p_Configuration->callback = this;

    html_save_progress progress_saved(& progress, m_recorded_progress, m_total_progress);
    SetProgress(0);
    return 0 == p_Configuration->ExecOnThread();
}

void InstallerWindow::AddComponent(const ComponentPtr& component)
{
    sciter::dom::element opt = sciter::dom::element::create("widget", component->description.c_str());
    opt.set_attribute("type", L"checkbox");
    opt.set_attribute("id", component->id.GetValue().c_str());
    opt.set_attribute("component_ptr", DVLib::towstring(get(component)).c_str());
    if (component->checked) opt.set_attribute("checked", L"true");
    if (component->disabled) opt.set_attribute("disabled", L"true");
    opt.set_attribute("installed", (component->installed ? L"true" : L"false"));
    opt.set_attribute("required", (component->IsRequired() ? L"true" : L"false"));
    Html::Insert(&components, opt, components.children_count());
}

bool InstallerWindow::on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason)
{
    try
    {
        sciter::dom::element target_element = target;
        if (type == BUTTON_CLICK && button_skip == target_element)
        {
            OnOK();
            return TRUE;
        }
        else if (type == BUTTON_CLICK && button_cancel == target_element)
        {
            OnCancel();
            return TRUE;
        }
        else if (type == BUTTON_CLICK && (button_install == target_element || button_uninstall == target_element))
        {
            OnInstall();
            return TRUE;
        }
        else if (type == BUTTON_STATE_CHANGED || type == EDIT_VALUE_CHANGED || type == SELECT_STATE_CHANGED)
        {
            const sciter::string component_ptr = target_element.get_attribute("component_ptr");
            if (!component_ptr.empty())
            {
                Component * p_component = reinterpret_cast<Component *>(DVLib::wstring2long(component_ptr, 16));
                p_component->checked = target_element.get_state(STATE_CHECKED);
            }
        }

        return HtmlWindow::on_event(he, target, type, reason);
    }
    catch(const std::exception& ex)
    {
        TRYLOG(L"Error: " << DVLib::string2wstring(ex.what()));
        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK|MB_ICONSTOP);
        return TRUE;
    }
}

bool InstallerWindow::on_mouse_click(HELEMENT /* he */, HELEMENT /* target */,
                                     POINT /* pt */, UINT /* mouseButtons */, UINT /* keyboardStates */)
{
    return false;
}

bool InstallerWindow::on_mouse_dclick(HELEMENT /* he */, HELEMENT target,
                                      POINT pt, UINT /* mouseButtons */, UINT keyboardStates)
{
    if (keyboardStates != 0)
    {
        sciter::dom::element target_element = target;
        if (target_element.is_valid())
        {
            sciter::dom::element component_element = target_element.find_element(GetHwnd(), pt);
            if (component_element.is_valid())
            {
                if (component_element.get_ctl_type() != CTL_CHECKBOX)
                    component_element = component_element.parent();

                if (component_element.is_valid() && component_element.get_ctl_type() == CTL_CHECKBOX)
                {
                    const sciter::string component_ptr = component_element.get_attribute("component_ptr");
                    if (!component_ptr.empty())
                    {
                        Component * p_component = reinterpret_cast<Component *>(DVLib::wstring2long(component_ptr, 16));

                        if ((keyboardStates & SHIFT_KEY_PRESSED) > 0)
                        {
                            p_component->checked = ! component_element.get_state(STATE_CHECKED);
                            if (p_component->checked)
                            {
                                component_element.set_attribute("checked", L"true");
                                component_element.set_state(STATE_CHECKED, 0);
                            }
                            else
                            {
                                component_element.remove_attribute("checked");
                                component_element.set_state(0, STATE_CHECKED);	
                            }
                        }
                        else if ((keyboardStates & CONTROL_KEY_PRESSED) > 0)
                        {
                            // doesn't have to be thread-safe, running on UI thread

                            if (m_running_component == NULL)
                            {
                                m_running_component = p_component;

                                reset(m_pThread, AfxBeginThread(RunComponentOnThread, this, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED));

                                CHECK_WIN32_BOOL(get(m_pThread) != NULL,
                                    L"AfxBeginThread");

                                m_pThread->m_bAutoDelete = false;
                                m_pThread->ResumeThread();
                            }
                        }

                        return true;
                    }
                }
            }
        }
    }

    return false;
}

UINT InstallerWindow::RunComponentOnThread(LPVOID pParam)
{
    InstallerWindow * p_window = static_cast<InstallerWindow*>(pParam);

    try
    {
        InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(p_window->m_configuration));
        CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");	

        p_window->RunComponent(p_configuration->components.GetComponentPtr(p_window->m_running_component));
    }
    catch(std::exception& ex)
    {
        p_window->m_error = DVLib::string2wstring(ex.what());
        p_window->m_rc = -1;
    }

    p_window->m_running_component = NULL;
    return 0;
}

void InstallerWindow::RunComponent(const ComponentPtr& component)
{
    try
    {
        LOG(L"--- Component '" << component->id << L"' (" << component->GetDisplayName() << L"): EXECUTING");
        if (! OnComponentExecBegin(component))
            return;

        component->Exec();
        component->Wait();

        LOG(L"*** Component '" << component->id << L"' (" << component->GetDisplayName() << L"): SUCCESS");

        if (! OnComponentExecSuccess(component))
            return;
    }
    catch(std::exception& ex)
    {
        LOG(L"*** Component '" << component->id << L"' (" << component->GetDisplayName() << L"): ERROR - " 
            << DVLib::string2wstring(ex.what()));

        DniMessageBox::Show(DVLib::string2wstring(ex.what()).c_str(), MB_OK | MB_ICONSTOP);
    }
}

bool InstallerWindow::on_mouse(HELEMENT he, HELEMENT target, UINT event_type, POINT pt, UINT mouseButtons, UINT keyboardStates)
{
    switch(event_type)
    {
    case MOUSE_CLICK:
        return on_mouse_click(he, target, pt, mouseButtons, keyboardStates);
    case MOUSE_DCLICK:
        return on_mouse_dclick(he, target, pt, mouseButtons, keyboardStates);
    }

    return false;
}

void InstallerWindow::OnOK()
{	
    Stop();
}

void InstallerWindow::OnCancel()
{
    RecordError(-2);

    if (m_download_started)
    {
        m_download_cancelled = true;
    }
    else
    {
        Stop();
    }
}


void InstallerWindow::OnInstall()
{
    BeginExec();
}

void InstallerWindow::ShowError(const std::wstring& message)
{
    Html::Show(&error);
    Html::SetText(&error, message);
}

void InstallerWindow::ClearError()
{ 
    m_download_cancelled = false;
    InstallerUI::ClearError();

    Html::Hide(&error);
    Html::SetText(&error, L"");
}

void InstallerWindow::SetProgressTotal(int pc)
{
    m_total_progress = pc;
    Html::SetAttribute(&progress, "maxvalue", DVLib::towstring(pc));
}

void InstallerWindow::ClearProgress()
{
    m_recorded_progress = 0;
    Html::Hide(&progress);
}

void InstallerWindow::SetStatus(const std::wstring& msg)
{
    Html::SetText(&status, msg);
}

void InstallerWindow::SetProgress(int pc) 
{
    m_recorded_progress = pc;
    Html::Show(&progress);
    Html::SetAttribute(&progress, "value", DVLib::towstring(pc));
}

void InstallerWindow::ResetContent()
{
    Html::Clear(&components);
}

void InstallerWindow::SetControlValues()
{	
    auto_any<HANDLE, close_handle> done;
    reset(done, ::CreateEvent(NULL, FALSE, FALSE, NULL));	
    CHECK_WIN32_BOOL(NULL != get(done),
        L"CreateEvent");

    std::wstring error;

    SetControlValuesTask* task = new SetControlValuesTask(body, get(done), & error);
    task->exec();

    ::WaitForSingleObject(get(done), INFINITE);

    if (!error.empty())
    {
        THROW_EX(error);
    }
}

// IExecuteCallback

void InstallerWindow::OnExecBegin()
{
    SetProgress(m_recorded_progress + 1);

    SetControlValues();

    InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
    CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

    ExtractCab(L"", p_configuration->show_cab_dialog);
}

bool InstallerWindow::OnComponentExecBegin(const ComponentPtr& component)
{
    m_running_component = get(component);
    return InstallerUI::ComponentExecBegin(component);
}

bool InstallerWindow::OnComponentExecWait(const ComponentPtr& component)
{
    LOG(L"--- Component '" << component->id << L" (" << component->GetDisplayName() << L"): FINISHED");
    return true;
}

bool InstallerWindow::OnComponentExecSuccess(const ComponentPtr& component)
{
    m_running_component = NULL;
    SetProgress(m_recorded_progress + 1);
    return InstallerUI::ComponentExecSuccess(component);
}

bool InstallerWindow::OnComponentExecError(const ComponentPtr& component, std::exception& ex)
{
    m_running_component = NULL;
    SetProgress(m_recorded_progress + 1);
    return InstallerUI::ComponentExecError(component, ex);
}

void InstallerWindow::ExtractCab(const std::wstring& id, bool /* display_progress */)
{
    ExtractCabProcessorPtr p_extractcab(new ExtractCabProcessor(s_hinstance, id, & status));
    int cab_count = p_extractcab->GetCabCount();
    if (cab_count == 0)
    {
        LOG(L"Extracting embedded files for component '" << (id.empty() ? L"*" : id) << L"': NO FILES EMBEDDED");
        return;
    }

    LOG(L"Extracting embedded files for component '" << (id.empty() ? L"*" : id) << L"': " << cab_count << L" CAB(s)");

    InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
    p_extractcab->cab_path = p_configuration->cab_path;
    p_extractcab->cab_cancelled_message = p_configuration->cab_cancelled_message;
    p_extractcab->BeginExec();
    p_extractcab->EndExec();
}

int InstallerWindow::OnMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_CLOSE:

        if (IsExecuting(INFINITE))
            return -1;

        EndExec();
        InstallerUI::Terminate();
        break;
    }

    return HtmlWindow::OnMessage(message, wParam, lParam);
}

int InstallerWindow::ExecOnThread()
{
    try
    {
        auto_any<sciter::dom::element *, html_disabled> btn_install(& button_install);
        Html::Disable(&button_install);
        auto_any<sciter::dom::element*, html_disabled> btn_skip(&button_skip);
        Html::Disable(&button_skip);

        ClearError();
        ClearProgress();

        InstallConfiguration * p_configuration = reinterpret_cast<InstallConfiguration *>(get(m_configuration));
        CHECK_BOOL(p_configuration != NULL, L"Invalid configuration");

        if (RestartElevated())
        {
            OnCancel();
            return 0;
        }

        Components components = p_configuration->GetSupportedComponents(
            InstallerSession::Instance->lcidtype, InstallerSession::Instance->sequence);

        SetProgressTotal(components.size() * 2);

        int rc = components.Exec(this);
        InstallerUI::AfterInstall(rc);
        return 0;
    }
    catch(std::exception& ex)
    {
        LOG(L"*** Failed to install one or more components: " << DVLib::string2wstring(ex.what()));
        ShowError(DVLib::string2wstring(ex.what()));
        RecordError();
    }
    catch(...)
    {
        LOG(L"*** Failed to install one or more components");
        ShowError(TEXT("Failed to install one or more components"));
        RecordError();
    }

    return 0;
}

void InstallerWindow::Connecting(const std::wstring& host)
{
    CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->connecting_message.GetValue().c_str()), host.c_str());
    SetStatus(message);
}

void InstallerWindow::SendingRequest(const std::wstring& host)
{
    CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->sendingrequest_message.GetValue().c_str()), host.c_str());
    SetStatus(message);
}

void InstallerWindow::Status(ULONG progress_current, ULONG progress_max, const std::wstring& description)
{
    SetStatus(description);
    SetProgressTotal(progress_max);
    SetProgress(progress_current);
}

void InstallerWindow::DownloadComplete()
{
    m_download_started = false;
}

void InstallerWindow::DownloadError(const std::wstring& error)
{
    SetStatus(L"");
    ShowError(error);
    RecordError();
    m_download_started = false;
    m_download_cancelled = false;
}

bool InstallerWindow::IsDownloadCancelled() const
{
    return m_download_cancelled;
}

void InstallerWindow::DownloadingFile(const std::wstring& filename)
{
    m_download_started = true;
    CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->downloading_message.GetValue().c_str()), filename.c_str());
    SetStatus(message);
}

void InstallerWindow::CopyingFile(const std::wstring& filename)
{
    m_download_started = true;
    CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->copying_message.GetValue().c_str()), filename.c_str());
    SetStatus(message);
}

HINSTANCE InstallerWindow::GetInstance() const
{
    return HtmlWindow::s_hinstance;
}

HWND InstallerWindow::GetHwnd() const
{
    return HtmlWindow::s_hwnd;
}

void InstallerWindow::StartInstall()
{
    OnInstall();
}

void InstallerWindow::Stop()
{
    ::PostMessage(hwnd, WM_CLOSE, 0,0);
}

std::wstring InstallerWindow::GetPositionStyle(const WidgetPosition& position)
{
    std::wstringstream style;

    if (position.IsSet())
    {
        style << L"position: fixed;";
        style << L"left: " << position.Left() << L"px;";
        style << L"top: " << position.Top() << L"px;";
        style << L"width: " << position.Width() << L"px;";
        style << L"height: " << position.Height() << L"px;";
    }

    return style.str();
}

std::wstring InstallerWindow::GetControlStyle(const ControlText& control)
{
    std::wstringstream style;

    if (! control.font_name.empty())
    {
        style << L"font: " << control.font_name << L";";
    }

    if (control.font_size > 0)
    {
        style << L"font-size: " << control.font_size << L" px;";
    }

    return style.str();
}

void InstallerWindow::AddControl(const ControlLabel& control)
{
    sciter::dom::element elt = sciter::dom::element::create("span", control.text.GetValue().c_str());
    elt.set_attribute("control_ptr", DVLib::towstring(& const_cast<ControlLabel&>(control)).c_str());
    if (!control.IsEnabled()) elt.set_attribute("disabled", L"true");
    if (control.has_value_disabled) elt.set_attribute("has_value_disabled", L"true");
    elt.set_attribute("style", (GetControlStyle(control) + GetPositionStyle(control.position)).c_str());
    Html::Insert(&components, elt, components.children_count());
}

void InstallerWindow::AddControl(const ControlCheckBox& control)
{
    sciter::dom::element elt = sciter::dom::element::create("widget", control.text.GetValue().c_str());
    elt.set_attribute("type", L"checkbox");
    elt.set_attribute("id", control.id.GetValue().c_str());
    if (control.checked) elt.set_attribute("checked", L"true");
    if (!control.IsEnabled()) elt.set_attribute("disabled", L"true");
    if (control.has_value_disabled) elt.set_attribute("has_value_disabled", L"true");
    elt.set_attribute("control_ptr", DVLib::towstring(& const_cast<ControlCheckBox&>(control)).c_str());
    elt.set_attribute("style", (GetControlStyle(control) + GetPositionStyle(control.position)).c_str());
    Html::Insert(&components, elt, components.children_count());
}

void InstallerWindow::AddControl(const ControlEdit& control)
{
    sciter::dom::element elt = sciter::dom::element::create("widget", control.text.GetValue().c_str());
    elt.set_attribute("type", L"text");
    elt.set_attribute("id", control.id.GetValue().c_str());
    if (!control.IsEnabled()) elt.set_attribute("disabled", L"true");
    if (control.has_value_disabled) elt.set_attribute("has_value_disabled", L"true");
    elt.set_attribute("control_ptr", DVLib::towstring(& const_cast<ControlEdit&>(control)).c_str());
    elt.set_attribute("style", (GetControlStyle(control) + GetPositionStyle(control.position)).c_str());
    Html::Insert(&components, elt, components.children_count());
}

void InstallerWindow::AddControl(const ControlBrowse& control)
{
    sciter::dom::element elt = sciter::dom::element::create("widget");
    if (control.folders_only) elt.set_attribute("type", L"folder-path");
    else elt.set_attribute("type", L"file-path");
    elt.set_attribute("id", control.id.GetValue().c_str());
    if (!control.filter.empty()) elt.set_attribute("filter", control.filter.GetValue().c_str());
    if (!control.IsEnabled()) elt.set_attribute("disabled", L"true");
    if (control.has_value_disabled) elt.set_attribute("has_value_disabled", L"true");
    elt.set_attribute("novalue", control.text.GetValue().c_str());
    // TODO: control.allow_edit, control.must_exist, control.hide_readonly
    elt.set_attribute("control_ptr", DVLib::towstring(& const_cast<ControlBrowse&>(control)).c_str());
    elt.set_attribute("style", (GetControlStyle(control) + GetPositionStyle(control.position)).c_str());
    Html::Insert(&components, elt, components.children_count());
}

void InstallerWindow::AddControl(const ControlLicense& control)
{
    // checkbox
    {
        CRect checkbox_rect = control.position.ToRect();
        checkbox_rect.right = checkbox_rect.left + 20;
        WidgetPosition control_position = control.position;
        control_position.FromRect(checkbox_rect);
        sciter::dom::element elt = sciter::dom::element::create("widget");
        elt.set_attribute("type", L"checkbox");
        elt.set_attribute("id", control.resource_id.GetValue().c_str());
        if (control.accepted) elt.set_attribute("checked", L"true");
        if (!control.IsEnabled()) elt.set_attribute("disabled", L"true");
        if (control.has_value_disabled) elt.set_attribute("has_value_disabled", L"true");
        elt.set_attribute("license", L"true");
        elt.set_attribute("control_ptr", DVLib::towstring(& const_cast<ControlLicense&>(control)).c_str());
        elt.set_attribute("style", GetPositionStyle(control_position).c_str());
        Html::Insert(&components, elt, components.children_count());
    }
    // hyperlink
    {
        WidgetPosition control_position = control.position;
        CRect link_rect = control_position.ToRect();
        link_rect.left += 20;
        control_position.FromRect(link_rect);
        sciter::dom::element elt = sciter::dom::element::create("a", control.text.GetValue().c_str());
        elt.set_attribute("href", control.license_file.GetValue().c_str());
        elt.set_attribute("target", L"_blank");
        if (!control.IsEnabled()) elt.set_attribute("disabled", L"true");
        elt.set_attribute("control_ptr", DVLib::towstring(& const_cast<ControlLicense&>(control)).c_str());
        elt.set_attribute("style", (GetControlStyle(control) + GetPositionStyle(control_position)).c_str());
        Html::Insert(&components, elt, components.children_count());
    }
}

void InstallerWindow::AddControl(const ControlHyperlink& control)
{
    sciter::dom::element elt = sciter::dom::element::create("a", control.text.GetValue().c_str());
    elt.set_attribute("href", control.uri.GetValue().c_str());
    elt.set_attribute("target", L"_blank");
    if (!control.IsEnabled()) elt.set_attribute("disabled", L"true");
    if (control.has_value_disabled) elt.set_attribute("has_value_disabled", L"true");
    elt.set_attribute("control_ptr", DVLib::towstring(& const_cast<ControlHyperlink&>(control)).c_str());
    elt.set_attribute("style", (GetControlStyle(control) + GetPositionStyle(control.position)).c_str());
    Html::Insert(&components, elt, components.children_count());
}

void InstallerWindow::AddControl(const ControlImage& control)
{
    sciter::dom::element elt = sciter::dom::element::create("img");
    elt.set_attribute("src", control.resource_id.GetValue().c_str());
    CHECK_BOOL(DVLib::ResourceExists(s_hinstance, control.resource_id.GetValue(), L"CUSTOM"),
        L"Resource " << control.resource_id.GetValue() << " doesn't exist");
    if (!control.IsEnabled()) elt.set_attribute("disabled", L"true");
    if (control.has_value_disabled) elt.set_attribute("has_value_disabled", L"true");
    elt.set_attribute("control_ptr", DVLib::towstring(& const_cast<ControlImage&>(control)).c_str());
    elt.set_attribute("style", GetPositionStyle(control.position).c_str());
    Html::Insert(&components, elt, components.children_count());
}

void InstallerWindow::OnDocumentComplete()
{
    if (get(m_configuration) != NULL)
    {
        OnShow();
    }
}

void InstallerWindow::SetElevationRequired(bool required)
{
    auto_any<sciter::dom::element *, html_disabled> btn_install(& button_install);
    Html::SetAttribute(&button_install, "elevate", required ? L"true" : L"false");
}
