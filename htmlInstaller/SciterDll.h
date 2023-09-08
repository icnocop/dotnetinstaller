#pragma once

class SciterDll
{
private:
	HMODULE m_h;
	std::wstring m_dir;
	std::wstring m_path;
	void Load();
	void Extract();
	void Unload();
public:
	static shared_any<SciterDll*, close_delete> Instance;
	SciterDll(void);
	~SciterDll(void);
};
