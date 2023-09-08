#pragma once

#include "HtmlWindow.h"

// HTML DOM helper methods
struct Html
{
	static void Hide(const sciter::dom::element* element)
	{
		performActionIfValid(element, [](const sciter::dom::element* element)
		{
			element->set_style_attribute("display", L"none");
		});
	}

	static void Show(const sciter::dom::element* element)
	{
		performActionIfValid(element, [](const sciter::dom::element* element)
		{
			element->set_style_attribute("display", NULL);
		});
	}

	static void SetText(sciter::dom::element* element, const WCHAR* t)
	{
		performActionIfValid(element, t, [](sciter::dom::element* element, const WCHAR* t)
		{
			element->set_text(t);
		});
	}

	static void SetText(sciter::dom::element* element, const std::wstring& t)
	{
		SetText(element, t.c_str());
	}

	static void SetText(sciter::dom::element* element, const std::wstring* t)
	{
		SetText(element, t->c_str());
	}

	static void SetAttribute(sciter::dom::element* element, const char* name, const WCHAR* value)
	{
		performActionIfValid(element, name, value, [](sciter::dom::element* element, const char* name, const WCHAR* value)
		{
			element->set_attribute(name, value);
		});
	}

	static void SetAttribute(sciter::dom::element* element, const char* name, const std::wstring value)
	{
		SetAttribute(element, name, value.c_str());
	}

	static void Insert(sciter::dom::element* element, const sciter::dom::element& e, unsigned int index)
	{
		performActionIfValid(element, e, index, [](sciter::dom::element* element, const sciter::dom::element& e, unsigned int index)
		{
			element->insert(e, index);
		});
	}

	static void Clear(sciter::dom::element* element)
	{
		performActionIfValid(element, [](sciter::dom::element* element)
		{
			element->clear();
		});
	}

	static void Disable(sciter::dom::element* element)
	{
		performActionIfValid(element, [](sciter::dom::element* element)
		{
			element->set_attribute("disabled", L"disabled");
		});
	}

	static void Enable(sciter::dom::element* element)
	{
		performActionIfValid(element, [](sciter::dom::element* element)
		{
			element->remove_attribute("disabled");
		});
	}

private:
	static void performActionIfValid(const sciter::dom::element* element, std::function<void(const sciter::dom::element* element)> action)
	{
		if (element != nullptr && element->is_valid())
		{
			action(element);
		}
	}

	static void performActionIfValid(sciter::dom::element* element, std::function<void(sciter::dom::element* element)> action)
	{
		if (element != nullptr && element->is_valid())
		{
			action(element);
		}
	}

	static void performActionIfValid(const sciter::dom::element* element, const WCHAR* t, std::function<void(const sciter::dom::element* element, const WCHAR* t)> action)
	{
		if (element != nullptr && element->is_valid())
		{
			action(element, t);
		}
	}

	static void performActionIfValid(sciter::dom::element* element, const WCHAR* t, std::function<void(sciter::dom::element* element, const WCHAR* t)> action)
	{
		if (element != nullptr && element->is_valid())
		{
			action(element, t);
		}
	}

	static void performActionIfValid(sciter::dom::element* element, const char* name, const WCHAR* value, std::function<void(sciter::dom::element* element, const char* name, const WCHAR* value)> action)
	{
		if (element != nullptr && element->is_valid())
		{
			action(element, name, value);
		}
	}

	static void performActionIfValid(sciter::dom::element* element, const sciter::dom::element& e, unsigned int index, std::function<void(sciter::dom::element* element, const sciter::dom::element& e, unsigned int index)> action)
	{
		if (element != nullptr && element->is_valid())
		{
			action(element, e, index);
		}
	}
};

// auto pointers

struct html_disabled
{
    static void close(sciter::dom::element * p)
    {
		Html::Enable(p);
    }
};

struct html_save_progress
{
	int m_value;
	int m_maxvalue;
	sciter::dom::element * m_p;

	html_save_progress(sciter::dom::element * p, int value, int maxvalue)
		: m_p(p)
		, m_value(value)
		, m_maxvalue(maxvalue)
	{

	}

    virtual ~html_save_progress()
    {	
		Html::SetAttribute(m_p, "maxvalue", DVLib::towstring(m_maxvalue));
		Html::SetAttribute(m_p, "value", DVLib::towstring(m_value));
    }
};
