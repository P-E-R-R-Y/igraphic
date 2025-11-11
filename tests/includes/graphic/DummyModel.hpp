#pragma once
#include "IModel.hpp"

class DummyModel : public graphic::IModel {
public:
    DummyModel(std::string model): pos{} {
        
    }

    ~DummyModel() {}

    void setTexture(std::string path) override {

    }

    Vector3f getPosition() const override {
        return pos;
    }
    
    void setPosition(Vector3f position) override {
        pos = position;
    }

    virtual Vector3f getRotation() const override {
        return rota;
    }

    virtual void setRotation(Vector3f rotation) override {
        rota = rotation;
    }

private:
    Vector3f pos;
    Vector3f rota;
};
