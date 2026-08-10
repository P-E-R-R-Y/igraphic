#pragma once
#include "IFont.hpp"

class DummyFont : public graphic::IFont {
public:
    DummyFont() {}
    ~DummyFont() {}

    bool isReady() const override {
        return true;
    }
};
