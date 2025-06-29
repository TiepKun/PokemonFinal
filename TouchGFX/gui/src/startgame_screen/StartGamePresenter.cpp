#include <gui/startgame_screen/StartGameView.hpp>
#include <gui/startgame_screen/StartGamePresenter.hpp>

StartGamePresenter::StartGamePresenter(StartGameView& v)
    : view(v)
{

}

void StartGamePresenter::activate()
{

}
void StartGamePresenter::updatePointerPosition(int xADC, int yADC)
{
    view.updatePointerPosition(xADC, yADC);
}
void StartGamePresenter::deactivate()
{

}
