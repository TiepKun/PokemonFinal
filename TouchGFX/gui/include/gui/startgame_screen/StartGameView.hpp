#ifndef STARTGAMEVIEW_HPP
#define STARTGAMEVIEW_HPP

#include <gui_generated/startgame_screen/StartGameViewBase.hpp>
#include <gui/startgame_screen/StartGamePresenter.hpp>

class StartGameView : public StartGameViewBase
{
public:
    StartGameView();
    virtual ~StartGameView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updatePointerPosition(int xADC, int yADC);
protected:
    int pointerX = 120;
    int pointerY = 160;
};

#endif // STARTGAMEVIEW_HPP
