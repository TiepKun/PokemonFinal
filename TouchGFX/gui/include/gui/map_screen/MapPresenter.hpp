#ifndef MAPPRESENTER_HPP
#define MAPPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MapView;

class MapPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MapPresenter(MapView& v);

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
    virtual void updatePointerPosition(int xADC, int yADC);
    virtual ~MapPresenter() {}

private:
    MapPresenter();

    MapView& view;
};

#endif // MAPPRESENTER_HPP
