#include <gui/map_screen/MapView.hpp>
#include <gui/map_screen/MapPresenter.hpp>

MapPresenter::MapPresenter(MapView& v)
    : view(v)
{

}
void MapPresenter::updatePointerPosition(int xADC, int yADC)
{
    view.updatePointerPosition(xADC, yADC);
}

void MapPresenter::activate()
{

}

void MapPresenter::deactivate()
{

}
