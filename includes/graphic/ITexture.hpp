/**
 * @file ITexture.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2026-08-10
 *
 * @addtogroup igraphic
 * @{
 */

#ifndef ITEXTURE_HPP_
    #define ITEXTURE_HPP_
    #include "Type.hpp"

namespace graphic {

    /**
     * @brief Loaded pixel data, independent of any ISprite that references
     *        it. Deleting every ISprite built from a texture does not
     *        delete the texture - only deleteTexture() does.
     * @interface ITexture
     */
    class ITexture {

        public:

            virtual ~ITexture() = default;

            /**
             * @brief notice if the texture is ready
             *
             * @return bool
             */
            virtual bool isReady() const = 0;

            /**
             * @brief Get the Size object
             *
             * @return Vector2f
             */
            virtual Vector2f getSize() const = 0;
    };

} // namespace graphic

/** @} */

#endif /* !ITEXTURE_HPP_ */
