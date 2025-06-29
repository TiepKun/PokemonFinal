#ifndef MAPVIEW_HPP
#define MAPVIEW_HPP

#include <gui_generated/map_screen/MapViewBase.hpp>
#include <gui/map_screen/MapPresenter.hpp>

class MapView : public MapViewBase
{
public:
    MapView();
    virtual ~MapView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    //virtual void handleTickEvent() override;
    void updatePointerPosition(int xADC, int yADC);

protected:
    int npc1X = 54;
    int npc1Y = 30;
};

#endif // MAPVIEW_HPP
