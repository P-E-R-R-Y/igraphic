#include "IMouse.hpp"

class DummyMouse : public graphic::IMouse {
public:
    DummyMouse(graphic::IEvent *event) {};

    ~DummyMouse() {};

    bool isButtonPressed(Buttons key) const override {return true;}

    bool isButtonDown(Buttons key) const override {return true;}

    bool isButtonReleased(Buttons key) const override {return true;}

    bool isButtonUp(Buttons key) const override {return true;}
            
    Vector2f getPosition() const override {return {0,0};}
            
    void setPosition(Vector2f position) override {}
            
    float GetMouseWheelMove() const override {return 0;}

};