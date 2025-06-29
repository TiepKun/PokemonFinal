#include <gui/startgame_screen/StartGameView.hpp>

extern "C" {
#include "main.h"
}

#include <cmath>
#include <algorithm>
int pointerX = 120;
int pointerY = 160;
StartGameView::StartGameView()
{

}

void StartGameView::setupScreen()
{
    StartGameViewBase::setupScreen();

    pointerX = 120;
    pointerY = 100;

    pointerImage.setXY(pointerX, pointerY);
    pointerImage.invalidate();
}
void StartGameView::updatePointerPosition(int xADC, int yADC)
{
    int deltaX = xADC - 128;
    int deltaY = 128 - yADC;

    pointerX += deltaX / 12;
    pointerY += deltaY / 12;

    pointerX = std::max(0, std::min(pointerX, 225));
    pointerY = std::max(0, std::min(pointerY, 300));

    pointerImage.invalidate();
    pointerImage.setXY(pointerX, pointerY);
    pointerImage.invalidate();

    // ⚠️ Giới hạn vùng của buttonWithLabel1 (cố định theo TouchGFX Designer)
    int btnX = 0; // = 0
    int btnY = 160;      // = 160
    int btnW = 240;   // = 240
    int btnH = 50;  // = 50

    bool isPointerInside =
        pointerX >= btnX && pointerX <= (btnX + btnW) &&
        pointerY >= btnY && pointerY <= (btnY + btnH);

    // ✅ Nếu nằm trong vùng nút và người dùng ấn nút
    if (isPointerInside && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
    {
        application().gotoMapScreenNoTransition();
    }
}



void StartGameView::tearDownScreen()
{
    StartGameViewBase::tearDownScreen();
}
