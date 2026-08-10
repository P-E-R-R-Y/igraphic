/**
 * @file IGraphic3Module.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @version 0.1
 * @date 2026-08-10
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef IGRAPHIC3_MODULE_HPP
#define IGRAPHIC3_MODULE_HPP

#include "IGraphic2Module.hpp"

#include "window/ICamera.hpp"
#include "window/IWindow3.hpp"

#include "graphic/IModel.hpp"

class IGraphic3Module : public IGraphic2Module {

public:
    static constexpr const char *entry = "getGraphic3Module";

    virtual ~IGraphic3Module() = default;

    // window
    virtual graphic::IWindow3 *createWindow(int32_t screenWidth, int32_t screenHeight, std::string title) = 0;

    // camera
    virtual graphic::ICamera *createCamera(Vector3f position, Vector3f target, float fov) = 0;
    virtual void deleteCamera(graphic::ICamera *) = 0;
    // model
    virtual graphic::IModel *createModel(std::string path) = 0;
    virtual void deleteModel(graphic::IModel *model) = 0;
};

#endif /* !IGRAPHIC3_MODULE_HPP */
