#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
extern "C" {
#include "main.h"
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 10);
    int xADC = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);

    HAL_ADC_Start(&hadc2);
    HAL_ADC_PollForConversion(&hadc2, 10);
    int yADC = HAL_ADC_GetValue(&hadc2);
    HAL_ADC_Stop(&hadc2);

    if (modelListener)
    {
        modelListener->updatePointerPosition(xADC, yADC);  // ← truyền nguyên giá trị ADC
    }

}
