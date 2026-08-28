/**
 * @file IGraphic2Module.hpp
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

#ifndef IGRAPHIC2_MODULE_HPP
#define IGRAPHIC2_MODULE_HPP

#include "window/IWindow2.hpp"

#include "event/IGamepad.hpp"
#include "event/IKeyboard.hpp"
#include "event/IMouse.hpp"

#include "graphic/IFont.hpp"
#include "graphic/IPolygon.hpp"
#include "graphic/ISprite.hpp"
#include "graphic/IText.hpp"
#include "graphic/ITexture.hpp"

#include "IModule.hpp"


/**
 * @brief A vendor's 2D factory : window, input, loaded resources and the
 *        objects that reference them. A vendor that cannot do 3D
 *        implements this one and nothing else.
 */
class IGraphic2Module : public IModule {

public:
    /// Symbol the loader looks up : present = this vendor can draw 2D
    static constexpr const char *entry = "getGraphic2Module";

    /// Ce que type() doit rendre. Ecrit ici et pas chez chaque vendor : une
    /// seule source, donc pas de faute de frappe qui viderait une ligne.
    static constexpr const char *contract = "graphic2";

    /**
     * @brief Les contrats qui me satisfont, du plus general au plus precis.
     *
     * Un IGraphic3Module EST un IGraphic2Module : qui demande de la 2D se
     * contente d'un vendor 3D. La relation vit ICI, une fois, chez celui
     * qui la definit - pas dans chaque module, qui devrait alors se
     * reediter le jour ou une sur-interface apparait, et pas recopiee dans
     * chaque hote.
     *
     * Chaine litterale plutot qu'un include : IGraphic3Module.hpp inclut
     * deja ce fichier, le citer ferait un cycle.
     */
    static constexpr const char *accepts[] = {"graphic2", "graphic3", nullptr};

    virtual ~IGraphic2Module() = default;

    // window - nullptr quand le vendor ne peut pas en ouvrir une de plus
    virtual graphic::IWindow2 *createWindow(int32_t screenWidth, int32_t screenHeight, std::string title) = 0;
    virtual void deleteWindow(graphic::IWindow2 *) = 0;

    /**
     * @brief La fenetre ouverte de ce vendor, nullptr s'il n'y en a pas.
     *
     * Elle appartient au MODULE, pas a qui l'a demandee. Celui qui a appele
     * createWindow la detruira ; les autres ne font que l'emprunter.
     *
     * C'est ainsi qu'un jeu heberge dessine dans la fenetre de la borne au
     * lieu d'en ouvrir une seconde - ce que raylib ne saurait pas faire, et
     * qui sous sfml donnerait deux fenetres dont une seule a le clavier.
     *
     * Un vendor qui en gere plusieurs rend la premiere ; createWindow reste
     * la pour qui en veut vraiment une a lui.
     *
     * @return graphic::IWindow2*
     */
    virtual graphic::IWindow2 *window() = 0;

    // keyboard - the window is handed over at construction, the way an
    // ITexture is to an ISprite : the link can never be missing, and no
    // method has to reconcile it later.
    virtual graphic::IKeyboard *createKeyboard(graphic::IWindow *window) = 0;
    virtual void deleteKeyboard(graphic::IKeyboard *keyboard) = 0;
    // mouse
    virtual graphic::IMouse *createMouse(graphic::IWindow *window) = 0;
    virtual void deleteMouse(graphic::IMouse *mouse) = 0;
    // gamepad - nullptr when this vendor has no such device
    virtual graphic::IGamepad *createGamepad(graphic::IWindow *window) = 0;
    virtual void deleteGamepad(graphic::IGamepad *gamepad) = 0;

    // texture
    virtual graphic::ITexture *createTexture(std::string path) = 0;
    virtual void deleteTexture(graphic::ITexture *texture) = 0;
    // font
    virtual graphic::IFont *createFont(std::string path) = 0;
    virtual void deleteFont(graphic::IFont *font) = 0;

    // polygon
    virtual graphic::IPolygon *createPolygon(std::vector<Vector2f> points) = 0;
    virtual void deletePolygon(graphic::IPolygon *polygon) = 0;
    // sprite
    virtual graphic::ISprite *createSprite(graphic::ITexture *texture) = 0;
    virtual void deleteSprite(graphic::ISprite *sprite) = 0;
    // text
    virtual graphic::IText *createText(std::string text, graphic::IFont *font) = 0;
    virtual void deleteText(graphic::IText *text) = 0;
};

/** @} */

#endif /* !IGRAPHIC2_MODULE_HPP */
