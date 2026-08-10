#pragma once
#include "IMesh.hpp"

class DummyMesh : public graphic::IMesh {
public:
    DummyMesh() {}
    ~DummyMesh() {}

    bool isReady() const override { return true; }
};
