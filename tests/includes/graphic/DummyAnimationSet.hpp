#pragma once
#include "IAnimationSet.hpp"

class DummyAnimationSet : public graphic::IAnimationSet {
public:
    DummyAnimationSet() {}
    ~DummyAnimationSet() {}

    bool isReady() const override { return true; }
    int getSize() const override { return 0; }
};
