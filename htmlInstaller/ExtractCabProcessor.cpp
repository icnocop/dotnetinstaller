#include "StdAfx.h"
#include "HtmlWidgets.h"
#include "ExtractCabProcessor.h"
#include "Resource.h"

ExtractCabProcessor::ExtractCabProcessor(HMODULE h, const std::wstring& id, sciter::dom::element * status)
: ExtractComponent(h, id)
, m_status(status)
{

}

void ExtractCabProcessor::OnStatus(const std::wstring& msg)
{
    Html::SetText(m_status, msg);
}
