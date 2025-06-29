#ifndef FIGHTPRESENTER_HPP
#define FIGHTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class FightView;

class FightPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    FightPresenter(FightView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~FightPresenter() {}

private:
    FightPresenter();

    FightView& view;
};

#endif // FIGHTPRESENTER_HPP
