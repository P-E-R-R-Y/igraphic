/**
 * @file IGraphic3Module.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @version 0.1
 * @date 2026-08-10
 *
 * @copyright Copyright (c) 2026
 *
 * @addtogroup igraphic
 * @{
 */

#ifndef IGRAPHIC3_MODULE_HPP
#define IGRAPHIC3_MODULE_HPP

#include "IGraphic2Module.hpp"

#include "window/ICamera.hpp"
#include "window/IWindow3.hpp"

#include "graphic/IAnimationSet.hpp"
#include "graphic/IMesh.hpp"
#include "graphic/IModel.hpp"


/**
 * @brief A vendor's 3D factory. Extends IGraphic2Module : implementing it
 *        means implementing all of the 2D too, and the window it returns
 *        is an IWindow3, hence usable as an IWindow2.
 *
 * A vendor without 3D DOES NOT EXPORT this symbol, rather than returning
 * empty objects : the missing symbol is the only way the loader learns the
 * capability is absent.
 */
class IGraphic3Module : public IGraphic2Module {

public:
    /// Symbol the loader looks up : present = this vendor can draw 3D
    static constexpr const char *entry = "getGraphic3Module";

    /// Le contrat le PLUS PRECIS que ce module remplit. Un IGraphic3Module
    /// EST un IGraphic2Module, mais type() n'en rend qu'un seul : c'est a
    /// l'appelant de savoir que chercher de la 2D veut dire regarder les
    /// deux lignes. La table, elle, ignore la chaine d'heritage.
    static constexpr const char *contract = "graphic3";

    /** @brief Rien d'autre ne fait de la 3D : je ne m'accepte que moi. */
    static constexpr const char *accepts[] = {"graphic3", nullptr};

    virtual ~IGraphic3Module() = default;

    // window
    virtual graphic::IWindow3 *createWindow(int32_t screenWidth, int32_t screenHeight, std::string title) = 0;

    // camera
    virtual graphic::ICamera *createCamera(Vector3f position, Vector3f target, float fov) = 0;
    virtual void deleteCamera(graphic::ICamera *) = 0;
    // mesh
    virtual graphic::IMesh *createMesh(std::string path) = 0;
    virtual void deleteMesh(graphic::IMesh *mesh) = 0;
    // animation set
    virtual graphic::IAnimationSet *createAnimationSet(std::string path) = 0;
    virtual void deleteAnimationSet(graphic::IAnimationSet *animations) = 0;
    // model
    virtual graphic::IModel *createModel(graphic::IMesh *mesh) = 0;
    virtual void deleteModel(graphic::IModel *model) = 0;
};

/** @} */

#endif /* !IGRAPHIC3_MODULE_HPP */
