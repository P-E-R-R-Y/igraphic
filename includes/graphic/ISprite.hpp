/**
 * @file ISprite.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef ISPRITE_HPP_
    #define ISPRITE_HPP_
    #include "Type.hpp"
    #include "../window/IWindow.hpp"

namespace graphic {

    /**
     * @brief Sprite interface
     * @interface ISprite
     */
    class ISprite {

        public:

            /**
             * @brief Destroy the ISprite object
             */
            virtual ~ISprite() = default;
            
            /**
             * @brief notice if the sprite is ready
             * 
             * @return bool
             */
            virtual bool isReady() const = 0;
            
            /**
             * @brief give the bounds of the sprite
             * 
             * @return Vector4f
             */
            virtual Vector4f getBounds() const = 0;
            
            /**
             * @brief Crop the sprite with a rectangle
             * 
             * @param rect
             */
            virtual void setCrop(Vector4f rect) = 0;
            
            /**
             * @brief Get the Position object
             * 
             * @return Vector2f
             */
            virtual Vector2f getPosition() const = 0;

            /**
             * @brief Set the Position object
             * 
             * @param position
             */
            virtual void setPosition(Vector2f position) = 0;
            
            /**
             * @brief Get the Rotation object
             * 
             * @return float
             */
            virtual float getRotation() const = 0;
            
            /**
             * @brief Set the Rotation object
             * 
             * @param angle
             * @param isRad
             */
            virtual void setRotation(float angle, bool isRad = false) = 0;
            
            /**
             * @brief Get the Sprite size
             * 
             * @return Vector4f
             */
            virtual Vector2f getSize() const = 0;

            /**
             * @brief Set the Sprite size
             * 
             * @param size
             */
            virtual void setSize(Vector2f size) = 0;

    };

} // namespace graphic3

#endif /* !ISPRITE_HPP_ */