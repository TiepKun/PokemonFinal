#ifndef STARTGAMEPRESENTER_HPP
#define STARTGAMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class StartGameView;

class StartGamePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    StartGamePresenter(StartGameView& v);

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
    void updatePointerPosition(int xADC, int yADC);
    virtual ~StartGamePresenter() {}

private:
    StartGamePresenter();
    StartGameView& view;
};

#endif // STARTGAMEPRESENTER_HPP
