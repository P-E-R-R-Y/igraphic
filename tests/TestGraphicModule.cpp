#include <gtest/gtest.h>
#include "IModule.hpp"
#include "IGraphicModule.hpp"
#include "DummyGraphicModule.hpp"

#include <vector>
#include "Type.hpp"

TEST(GraphicModuleTest, RegisterAndRetrieve) {
    ModuleRegistry registry;

    // Create and register
    auto* module = new DummyGraphicModule();
    registry.add(module);

    // Retrieve by name
    std::vector<IModule*> graphicModules = registry.get("graphic");
    ASSERT_EQ(graphicModules.size(), 1);
    
    IModule* retrievedBase = graphicModules[0];
    ASSERT_NE(retrievedBase, nullptr);
    
    auto* retrieved = dynamic_cast<IGraphicModule*>(retrievedBase);
    ASSERT_NE(retrieved, nullptr);
    EXPECT_EQ(retrieved->getName(), "DummyGraphic");
    EXPECT_EQ(retrieved->getType(), "graphic");

    delete module; // cleanup manually, or use smart pointer in real app
}

TEST(GraphicModuleTest, GraphicObject) {
    ModuleRegistry registry;

    // Create and register
    auto* mod = new DummyGraphicModule();
    
    ASSERT_NE(mod, nullptr);
    EXPECT_EQ(mod->getName(), "DummyGraphic");
    EXPECT_EQ(mod->getType(), "graphic");

    // Use a method
    //audio
    graphic::IMusic* music = mod->createMusic("");
    graphic::ISound* sound = mod->createSound("");
    //event
    graphic::IEvent* event = mod->createEvent();
    graphic::IKeyboard* keyboard = mod->createKeyboard(event);
    graphic::IMouse* mouse = mod->createMouse(event);

    graphic::IModel *model = mod->createModel("");
    graphic::IPolygon *polygon = mod->createPolygon(std::vector<Vector2f>());
    graphic::ISprite* sprite = mod->createSprite("");
    graphic::IText *text = mod->createText("", "");

    graphic::ICamera *camera = mod->createCamera({0, 0, 0}, {0, 0, 0}, 0);
    graphic::IWindow *window = mod->createWindow(1, 1, "window");
    ASSERT_NE(music, nullptr);
    ASSERT_NE(sound, nullptr);

    ASSERT_NE(event, nullptr);
    ASSERT_NE(keyboard, nullptr);
    ASSERT_NE(mouse, nullptr);

    ASSERT_NE(model, nullptr);
    ASSERT_NE(polygon, nullptr);
    ASSERT_NE(sprite, nullptr);
    ASSERT_NE(text, nullptr);

    ASSERT_NE(camera, nullptr);
    ASSERT_NE(window, nullptr);

    mod->deleteMusic(music);
    mod->deleteSound(sound);

    mod->deleteKeyboard(keyboard);
    mod->deleteMouse(mouse);
    mod->deleteEvent(event);

    mod->deleteModel(model);
    mod->deletePolygon(polygon);
    mod->deleteSprite(sprite);
    mod->deleteText(text);

    mod->deleteCamera(camera);
    mod->deleteWindow(window);

    delete mod; // cleanup manually, or use smart pointer in real app
}
