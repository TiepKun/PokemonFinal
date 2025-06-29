#include <gui/common/FrontendApplication.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

void FrontendApplication::handleTickEvent()
{
    FrontendApplicationBase::handleTickEvent(); // giữ các xử lý mặc định
    model.tick();  // GỌI HÀM tick() MỖI FRAME
}
