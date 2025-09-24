#pragma once
#include "IModel.hpp"

class DummyModel : public graphic::IModel {
public:
    DummyModel(): pos(0) {}
    ~DummyModel() {}

    Vector3f getPosition() const override {
        return pos;
    }
    
    void setPosition(Vector3f position) override {
        pos = position;
    }

private:
    Vector3f pos;
};
