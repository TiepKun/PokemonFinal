#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <cstdint>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}
    virtual void updatePointerPosition(int x, int y) {}
    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
