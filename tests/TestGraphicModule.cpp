#include <gtest/gtest.h>
#include "IModule.hpp"
#include "IGraphic2Module.hpp"
#include "IGraphic3Module.hpp"
#include "DummyGraphic2Module.hpp"
#include "DummyGraphic3Module.hpp"

#include <vector>
#include "Type.hpp"

TEST(GraphicModuleTest, Graphic2Object) {
    DummyGraphic2Module mod;

    EXPECT_STREQ(mod.name(), "DummyGraphic2");
    EXPECT_STREQ(mod.type(), "graphic2d");

    graphic::ITexture *texture = mod.createTexture("player.png");
    graphic::IFont *font = mod.createFont("arial.ttf");
    ASSERT_NE(texture, nullptr);
    ASSERT_NE(font, nullptr);

    graphic::IPolygon *polygon = mod.createPolygon(std::vector<Vector2f>());
    graphic::ISprite *sprite = mod.createSprite(texture);
    graphic::IText *text = mod.createText("", font);
    graphic::IWindow2 *window = mod.createWindow(1, 1, "window");

    ASSERT_NE(polygon, nullptr);
    ASSERT_NE(sprite, nullptr);
    ASSERT_NE(text, nullptr);
    ASSERT_NE(window, nullptr);

    // deleting the sprite/text never touches the texture/font they came from
    mod.deleteSprite(sprite);
    mod.deleteText(text);

    // texture/font are still alive : build a second sprite/text from them
    graphic::ISprite *sprite2 = mod.createSprite(texture);
    graphic::IText *text2 = mod.createText("again", font);
    ASSERT_NE(sprite2, nullptr);
    ASSERT_NE(text2, nullptr);

    // a 2D window still hands out keyboard/mouse/gamepad - not gated by drawing capability
    graphic::IKeyboard *keyboard = window->createKeyboard();
    graphic::IMouse *mouse = window->createMouse();
    graphic::IGamepad *gamepad = window->createGamepad();

    ASSERT_NE(keyboard, nullptr);
    ASSERT_NE(mouse, nullptr);
    ASSERT_NE(gamepad, nullptr);

    window->deleteKeyboard(keyboard);
    window->deleteMouse(mouse);
    window->deleteGamepad(gamepad);

    mod.deletePolygon(polygon);
    mod.deleteSprite(sprite2);
    mod.deleteText(text2);
    mod.deleteWindow(window);
    mod.deleteTexture(texture);
    mod.deleteFont(font);
}

TEST(GraphicModuleTest, Graphic3ObjectAlsoDoes2D) {
    DummyGraphic3Module mod;

    EXPECT_STREQ(mod.name(), "DummyGraphic3");
    EXPECT_STREQ(mod.type(), "graphic3d");

    graphic::ITexture *texture = mod.createTexture("player.png");
    graphic::IFont *font = mod.createFont("arial.ttf");
    ASSERT_NE(texture, nullptr);
    ASSERT_NE(font, nullptr);

    graphic::ICamera *camera = mod.createCamera({0, 0, 0}, {0, 0, 0}, 0);

    graphic::IMesh *mesh = mod.createMesh("zombie.glb");
    graphic::IAnimationSet *animations = mod.createAnimationSet("zombie.glb");
    ASSERT_NE(mesh, nullptr);
    ASSERT_NE(animations, nullptr);

    graphic::IModel *model = mod.createModel(mesh);
    model->setTexture(texture); // same ITexture, reused on a model too
    model->setAnimations(animations);
    // still available : IGraphic3Module extends IGraphic2Module
    graphic::ISprite *sprite = mod.createSprite(texture);
    graphic::IWindow3 *window = mod.createWindow(1, 1, "window");

    ASSERT_NE(camera, nullptr);
    ASSERT_NE(model, nullptr);
    ASSERT_NE(sprite, nullptr);
    ASSERT_NE(window, nullptr);

    graphic::IText *text = mod.createText("score: 0", font);
    ASSERT_NE(text, nullptr);

    // an IWindow3 IS an IWindow2 : draws sprites too, not just models
    window->beginMode3(camera);
    window->drawModel(model);
    window->drawText3D(text, {0, 1, 0}); // same IText, projected in world space
    window->endMode3();
    window->beginDraw();
    window->drawSprite(sprite);
    window->drawText(text); // and still usable in screen space too
    window->endDraw();

    // deleting the model never touches its mesh/animations - a second
    // zombie can reuse both without reloading from disk
    mod.deleteModel(model);
    graphic::IModel *model2 = mod.createModel(mesh);
    model2->setAnimations(animations);
    ASSERT_NE(model2, nullptr);

    mod.deleteCamera(camera);
    mod.deleteModel(model2);
    mod.deleteMesh(mesh);
    mod.deleteAnimationSet(animations);
    mod.deleteSprite(sprite);
    mod.deleteText(text);
    mod.deleteWindow(window);
    mod.deleteTexture(texture);
    mod.deleteFont(font);
}
