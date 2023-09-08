#pragma once

struct SciterBehaviorWeblink: public sciter::event_handler
{
    virtual void attached (HELEMENT he);
    virtual void detached (HELEMENT he);
    virtual bool on_event (HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason);
};

struct SciterBehaviorWeblinkFactory : public sciter::behavior_factory
{
    SciterBehaviorWeblinkFactory()
        : behavior_factory("weblink")
    {
    }

    // the only behavior_factory method:
    virtual sciter::event_handler* create(HELEMENT he)
    {
        return new SciterBehaviorWeblink();
    }

};

// instantiating and attaching it to the global list of supported behaviors
SciterBehaviorWeblinkFactory SciterBehaviorWeblinkFactoryInstance;