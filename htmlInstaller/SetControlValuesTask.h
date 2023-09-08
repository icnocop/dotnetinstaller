#pragma once

class SetControlValuesTask
{
private:
	sciter::dom::element m_root;
	HANDLE m_event;
	std::wstring * m_perror;
public:
	SetControlValuesTask(const sciter::dom::element& root, HANDLE evt, std::wstring * perror);
	void exec(sciter::dom::element elt);
	void exec();	
};
