#include "StdAfx.h"
#include "DownloadWindow.h"
#include "HtmlWidgets.h"

DownloadWindow::DownloadWindow(const DownloadDialogPtr& p_Configuration)
: m_recorded_error(0)
, m_recorded_progress(0)
, m_total_progress(0)
, download_started(false)
, download_cancelled(false)
, m_downloaddialog(p_Configuration)
{

}

void DownloadWindow::Create(int x, int y, int width, int height, const wchar_t * caption)
{
    HtmlWindow::Create(L"download.html", x, y, width, height, caption);
}

bool DownloadWindow::Run()
{
    CHECK_BOOL(get(m_downloaddialog) != NULL,
        L"Missing download dialog configuration.");

    if (! m_downloaddialog->IsRequired())
    {
        LOG(L"*** Component '" << m_downloaddialog->component_id << L"': SKIPPING DOWNLOAD/COPY");
        return true;
    }

    Start();

    DoModal(InstallUILevelSetting::Instance->IsAnyUI() 
        ? SW_SHOWNORMAL 
        : SW_HIDE);

    return m_recorded_error == 0;
}

void DownloadWindow::OnShow()
{
    CHECK_BOOL(get(m_downloaddialog) != NULL,
        L"Missing download dialog configuration.");

    sciter::dom::element r = GetRoot();

    // status
    status = r.get_element_by_id("status");

    // error
    error = r.get_element_by_id("error");
    ClearError();

    // progress
    progress = r.get_element_by_id("progress");
    ClearProgress();

    sciter::dom::element dialog_message = r.get_element_by_id("dialog_message");
    if (dialog_message.is_valid()) 
    {
        dialog_message.set_text(m_downloaddialog->help_message.GetValue().c_str());
    }

    button_cancel = r.get_element_by_id("button_cancel");
    if (button_cancel.is_valid()) 
    {
        button_cancel.set_attribute("value", m_downloaddialog->cancel_caption.GetValue().c_str());
    }

    button_start = r.get_element_by_id("button_start");
    if (button_start.is_valid()) 
    {
        button_start.set_attribute("value", m_downloaddialog->start_caption.GetValue().c_str());
        if (m_downloaddialog->auto_start)
        {
            button_start.destroy();
        }
    }
}

void DownloadWindow::Start()
{
    if (InstallUILevelSetting::Instance->IsSilent())
    {
        OnStart();
    }
    else if (m_downloaddialog->auto_start || ! m_downloaddialog->IsDownloadRequired())
    {
        OnStart();
    }
}

void DownloadWindow::OnStart()
{
    download_started = true;
    download_cancelled = false;
    m_downloaddialog->callback = this;
    Html::SetAttribute(&button_start, "disabled", L"disabled");
    ClearError();
    ClearProgress();
    m_downloaddialog->BeginExec();
}

void DownloadWindow::OnCancel()
{
    Html::SetAttribute(&button_cancel, "disabled", L"disabled");
    download_cancelled = true;
    Stop();
}

bool DownloadWindow::on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason)
{
    try
    {
        sciter::dom::element target_element = target;

        if (type == BUTTON_CLICK && button_cancel == target_element)
        {
            OnCancel();
            return TRUE;
        }
        else if (type == BUTTON_CLICK && button_start == target_element)
        {
            OnStart();
            return TRUE;
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

void DownloadWindow::ShowError(const std::wstring& message)
{
    Html::Show(&error);
    Html::SetText(&error, message);
}

void DownloadWindow::ClearError() 
{
    m_recorded_error = 0;
    Html::Hide(&error);
    Html::SetText(&error, L"");
}

void DownloadWindow::SetProgressTotal(int pc)
{
    m_total_progress = pc;
    Html::SetAttribute(&progress, "maxvalue", DVLib::towstring(pc));
}

void DownloadWindow::ClearProgress() 
{
    SetProgress(0);
}

void DownloadWindow::SetStatus(const std::wstring& msg)
{
    Html::SetText(&status, msg);
}

void DownloadWindow::SetProgress(int pc) 
{
    m_recorded_progress = pc;
    Html::Show(&progress);
    Html::SetAttribute(&progress, "value", DVLib::towstring(pc));
}

int DownloadWindow::OnMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_CLOSE:

        if (m_downloaddialog->IsExecuting(1000 * 3)) 
            return -1;

        m_downloaddialog->EndExec();
        break;
    }

    return HtmlWindow::OnMessage(message, wParam, lParam);
}

void DownloadWindow::Connecting(const std::wstring& host)
{
    CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->connecting_message.GetValue().c_str()), host.c_str());
    SetStatus(message);
}

void DownloadWindow::SendingRequest(const std::wstring& host)
{
    CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->sendingrequest_message.GetValue().c_str()), host.c_str());
    SetStatus(message);
}

void DownloadWindow::Status(ULONG progress_current, ULONG progress_max, const std::wstring& description)
{
    SetStatus(description);
    SetProgressTotal(progress_max);
    SetProgress(progress_current);
}

void DownloadWindow::DownloadComplete()
{
    Stop();
}

void DownloadWindow::DownloadError(const std::wstring& error)
{
    SetStatus(L"");
    ShowError(error);
    RecordError();
}

bool DownloadWindow::IsDownloadCancelled() const
{
    return download_cancelled;
}

void DownloadWindow::DownloadingFile(const std::wstring& filename)
{
    CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->downloading_message.GetValue().c_str()), filename.c_str());
    SetStatus(message);
}

void DownloadWindow::CopyingFile(const std::wstring& filename)
{
    CHECK_BOOL(get(m_downloaddialog) != NULL, L"Invalid download dialog");
    std::wstring message = DVLib::FormatMessage(const_cast<wchar_t *>(m_downloaddialog->copying_message.GetValue().c_str()), filename.c_str());
    SetStatus(message);
}

HINSTANCE DownloadWindow::GetInstance() const
{
    return HtmlWindow::s_hinstance;
}

HWND DownloadWindow::GetHwnd() const
{
    return hwnd;
}

void DownloadWindow::Stop()
{
    ::PostMessage(hwnd, WM_CLOSE, 0,0);
}

void DownloadWindow::OnDocumentComplete()
{
    OnShow();
}

void DownloadWindow::RecordError(int error)
{
    if (m_recorded_error == 0) 
    {
        m_recorded_error = error; 
    }
}
