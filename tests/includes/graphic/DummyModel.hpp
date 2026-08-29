#pragma once
#include "IModel.hpp"
#include "IMesh.hpp"

class DummyModel : public graphic::IModel {
public:
    DummyModel(graphic::IMesh *mesh): pos{} {

    }

    ~DummyModel() {}

    void setTexture(graphic::ITexture *texture) override {

    }

    void setAnimations(graphic::IAnimationSet *animations) override {
    }
    int getAnimationsSize() const override {
        return 0;
    }
    void setAnimation(int pos) override {
    }
    int getAnimation() const override {
        return 0;
    }
    bool updateAnimation() override {
        return false;
    }
    void setFrameRange(int first, int last) override {
    }
    int getFirstFrame() const override {
        return 0;
    }
    int getLastFrame() const override {
        return 0;
    }
    void setFrame(int frame) override {
    }
    int getFrame() const override {
        return 0;
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
