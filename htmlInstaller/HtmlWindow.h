#pragma once

class HtmlWindow 
	: public sciter::event_handler_raw
	, public sciter::host<HtmlWindow>
{
public:
	static HINSTANCE s_hinstance;
	static HWND s_hwnd;
public:
	HWND hwnd;
	std::wstring m_title;
	sciter::dom::element body;
	sciter::dom::element caption;
	sciter::dom::element button_min;
	sciter::dom::element button_max;
	sciter::dom::element button_icon;
	sciter::dom::element button_close;
	sciter::dom::element corner;
	virtual void Create(const wchar_t * filename, int x, int y, int width, int height, const wchar_t * caption = 0);
	static HtmlWindow * Self(HWND hWnd);
	static ATOM RegisterClass(HINSTANCE hInstance);
    LRESULT on_load_data(LPSCN_LOAD_DATA pnmld);
	HINSTANCE get_resource_instance();
	LRESULT on_document_complete();
	void DoModal(int cmd);
protected:
	HtmlWindow();
	int HitTest(int x, int y);
	HELEMENT GetRoot();
	bool IsWindowMinimized() const;
	bool IsWindowMaximized() const;
	virtual bool subscription(HELEMENT he, UINT& event_groups);
	virtual bool on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason);
	static void Self(HWND hWnd, HtmlWindow * inst);
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual int OnMessage(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void OnShow() = 0;
	virtual void OnDocumentComplete() = 0;
	static bool LoadResourceData(LPCWSTR uri, PBYTE& pb, DWORD& cb);
	void ModalLoop();
private:
	bool m_modal;
	static VOID SC_CALLBACK DebugOutput(LPVOID param, UINT subsystem, UINT severity, LPCWSTR text, UINT text_length);
};
