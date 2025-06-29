#include <gui/map_screen/MapView.hpp>
#include "main.h"
#include <cmath>
#include <algorithm>

// Tọa độ ban đầu của npc1 (nữ)
int npc1X = 54;
int npc1Y = 30;

MapView::MapView()
{
}

void MapView::setupScreen()
{
    MapViewBase::setupScreen();

    // Khởi tạo vị trí npc1
    npc1X = 54;
    npc1Y = 60;

    npc1.setXY(npc1X, npc1Y);
    npc1.invalidate();
}

void MapView::tearDownScreen()
{
    MapViewBase::tearDownScreen();
}

void MapView::updatePointerPosition(int xADC, int yADC)
{
    int deltaX = xADC - 128;
    int deltaY = 128 - yADC;

    npc1X += deltaX / 12;
    npc1Y += deltaY / 12;

    npc1X = std::max(0, std::min(npc1X, 225));
    npc1Y = std::max(0, std::min(npc1Y, 300));

    npc1.invalidate();
    npc1.setXY(npc1X, npc1Y);
    npc1.invalidate();

    // === Thông số cố định của npc2 ===
    const int npc2X = 160;
    const int npc2Y = 71;
    const int npcW = 30;
    const int npcH = 30;

    // === Kiểm tra va chạm giữa npc1 và npc2 ===
    bool isColliding =
        npc1X + npcW > npc2X &&
        npc1X < npc2X + npcW &&
        npc1Y + npcH > npc2Y &&
        npc1Y < npc2Y + npcH;

    if (isColliding)
    {
        application().gotoFightScreenNoTransition();
    }
}




//#include <gui/map_screen/MapView.hpp>
//#include "cmsis_os.h"
//#include <cstdio>
//#include "main.h"
//#include <cmath>
//#include <algorithm>
//
//
////static constexpr int16_t STEP = 5;
////extern osMessageQueueId_t Queue1Handle;
//MapView::MapView()
//{
//
//}
//
//void MapView::setupScreen()
//{
//    MapViewBase::setupScreen();
//
////    uint8_t dummy;
////        while (osMessageQueueGet(Queue1Handle, &dummy, NULL, 0) == osOK) {}
//}
//
//void MapView::tearDownScreen()
//{
//    MapViewBase::tearDownScreen();
//}
////void MapView::handleTickEvent()
////{
////
////    MapViewBase::handleTickEvent();
////
////    uint8_t move_cmd;
////
////    if (osMessageQueueGet(Queue1Handle, &move_cmd, NULL, 0) == osOK)
////    {
////        int x = npc2.getX();
////        int y = npc2.getY();
////
////        switch (move_cmd)
////        {
//////            case 1: // select: teleport npc2 to npc1
//////                x = npc1.getX();
//////                y = npc1.getY();
//////                break;
////            case 2: // right
////                if(x <= 162) x += STEP;
////                break;
////            case 3: // up
////                if(y > 0) y -= STEP;
////                break;
////            case 4: // down
////                if(y <= 72) y += STEP;
////                break;
////            case 5: // left
////                if(x > 0) x -= STEP;
////                break;
////            default:
////                // no action
////                break;
////        }
////
////        npc2.setXY(x,y);
////        npc2.invalidate();
////
////    }
////
////    if(npc1.getRect().intersect(npc2.getRect())){
////    	application().gotoFightScreenNoTransition();
////    	return;
////    }
////}
//
//void StartGameView::updatenpc1Position(int xADC, int yADC)
//{
//    int deltaX = xADC - 128;
//    int deltaY = 128 - yADC;
//
//    npc1X += deltaX / 12;
//    npc1Y += deltaY / 12;
//
//    npc1X = std::max(0, std::min(npc1X, 225));
//    npc1Y = std::max(0, std::min(npc1Y, 300));
//
//    npc1Image.invalidate();
//    npc1Image.setXY(npc1X, npc1Y);
//    npc1Image.invalidate();
//
//    // ⚠️ Giới hạn vùng của buttonWithLabel1 (cố định theo TouchGFX Designer)
//    int btnX = 0; // = 0
//    int btnY = 160;      // = 160
//    int btnW = 240;   // = 240
//    int btnH = 50;  // = 50
//
//    bool isnpc1Inside =
//        npc1X >= btnX && npc1X <= (btnX + btnW) &&
//        npc1Y >= btnY && npc1Y <= (btnY + btnH);
//
//    // ✅ Nếu nằm trong vùng nút và người dùng ấn nút
//    if (isnpc1Inside && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET)
//    {
//        application().gotoMapScreenNoTransition();
//    }
//}
//
//
//
