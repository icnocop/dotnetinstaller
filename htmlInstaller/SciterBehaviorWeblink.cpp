#include "StdAfx.h"
#include "SciterBehaviorWeblink.h"

using namespace sciter;

void SciterBehaviorWeblink::attached(HELEMENT)
{
}

void SciterBehaviorWeblink::detached(HELEMENT)
{
}

bool SciterBehaviorWeblink::on_event(HELEMENT he, HELEMENT /* target */, BEHAVIOR_EVENTS type, UINT_PTR /* reason */)
{
    dom::element e = he;

    switch( type )
    {
    case HYPERLINK_CLICK:
        // case HYPERLINK_CLICK | HANDLED:
        DVLib::ShellCmd(e.get_attribute("href"));
        return true;
    }

    return false;
}
