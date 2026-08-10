#pragma once
#include "ITexture.hpp"

class DummyTexture : public graphic::ITexture {
public:
    DummyTexture() {}
    ~DummyTexture() {}

    bool isReady() const override {
        return true;
    }
    Vector2f getSize() const override {
        return {};
    }
};
