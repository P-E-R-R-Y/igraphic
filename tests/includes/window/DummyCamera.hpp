#pragma once
#include "ICamera.hpp"

class DummyCamera : public graphic::ICamera {
public:
    DummyCamera() {}
    ~DummyCamera() {}

    float getFov() const override {
        return {};
    }
    void setFov(float fov) override {
        // no-op
    }
    Mode getMode() const override {
        return {};
    }
    void setMode(Mode mode) override {
        // no-op
    }
    Vector3f getPosition() const override {
        return {};
    }
    void setPosition(Vector3f position) override {
        // no-op
    }
    Projection getProjection() const override {
        return {};
    }
    void setProjection(Projection projection) override {
        // no-op
    }
    Vector3f getTarget() const override {
        return {};
    }
    void setTarget(Vector3f size) override {
        // no-op
    }
    Vector3f getUp() const override {
        return {};
    }
    void setUp(Vector3f up) override {
        // no-op
    }
};
