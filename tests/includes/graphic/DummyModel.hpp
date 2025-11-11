#pragma once
#include "IModel.hpp"

class DummyModel : public graphic::IModel {
public:
    DummyModel(std::string model): pos{} {
        
    }

    ~DummyModel() {}

    void setTexture(std::string path) override {

    }

    void setAnimations(std::string path) override {
    }
    int getAnimationsSize() const override {
        return 0;
    }
    void setAnimation(int pos) override {
    }
    int getAnimation() const override {
        return 0;
    }
    void updateAnimation() override {
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

    virtual Vector3f getSize() const override {
        return rota;
    }

    virtual void setSize(Vector3f size) override {
        siz = size;
    }

private:
    Vector3f pos;
    Vector3f rota;
    Vector3f siz;
};
