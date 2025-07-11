/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/map_screen/MapViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

MapViewBase::MapViewBase()
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    landscape.setXY(0, 0);
    landscape.setBitmap(touchgfx::Bitmap(BITMAP_LANDSCAPE_240X320_ID));
    add(landscape);

    npc1.setXY(54, 30);
    npc1.setBitmap(touchgfx::Bitmap(BITMAP_POKEMON_TRAINER_FEMALE_30X30_ID));
    add(npc1);

    npc2.setXY(160, 71);
    npc2.setBitmap(touchgfx::Bitmap(BITMAP_POKEMON_TRAINER_MALE_30X30_ID));
    add(npc2);
}

MapViewBase::~MapViewBase()
{

}

void MapViewBase::setupScreen()
{

}
