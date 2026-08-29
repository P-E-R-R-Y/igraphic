/**
 * @file IPolygon.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2025-01-29
 *
 * @addtogroup igraphic
 * @{
 */


#ifndef IPOLYGON_HPP_
    #define IPOLYGON_HPP_
    #include "Type.hpp"
    #include "../window/IWindow.hpp"

    #include <vector>

namespace graphic {

    /**
     * @brief Polygon interface
     * @interface IPolygon
     *
     * The contract speaks in POINTS, never in triangles : createPolygon()
     * takes vertices, getPoints() returns them. Triangulating is a vendor
     * detail - raylib turns it into DrawTriangle calls, sfml into an
     * sf::VertexArray, and both keep the result private. A `Triangle` in
     * this file would have no method to serve.
     *
     * The type doing the actual work is `Triangle<T>` from `system`
     * (Shape.hpp), at global scope.
     */
    class IPolygon {

        public:

            /**
             * @brief Destroy the IPolygon object
             */
            virtual ~IPolygon() = default;

            /**
             * @brief Get the Color object
             *
             * @return Color
             */
            virtual Color getColor() const = 0;

            /**
             * @brief Set the Color object
             *
             * @param position
             */
            virtual void setColor(Color position) = 0;

            /**
             * @brief Get the Position object
             *
             * @return Vector2f
             */
            virtual bool isReady() const = 0;

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
             * @brief Get the Points object
             *
             * @return std::vector<Vector2f>
             */
            virtual std::vector<Vector2f> getPoints() const = 0;
    };

} // namespace graphic

/** @} */

#endif /* !IPOLYGON_HPP_ */