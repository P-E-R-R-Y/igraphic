#pragma once
#include "ISprite.hpp"

class DummySprite : public graphic::ISprite {
public:
    DummySprite() {};
    ~DummySprite() {};

    bool isReady() const override {
        return {};
    }
    Vector4f getBounds() const override {
        return {};
    }
    void setCrop(Vector4f rect) override {
        // no-op
    }
    Vector2f getPosition() const override {
        return {};
    }

    void setPosition(Vector2f position) override {
        // no-op
    }
    float getRotation() const override {
        return {};
    }
    void setRotation(float angle, bool isRad = false) override {
        // no-op
    }
    Vector2f getSize() const override {
        return {};
    }
    void setSize(Vector2f size) override {
        // no-op
    }
};
