/**
 * @file IPolygon.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */


#ifndef IPOLYGON_HPP_
    #define IPOLYGON_HPP_
    #include "type.hpp"
    #include "../window/IWindow.hpp"

    #include <vector>

namespace graphic {
    
    /**
     * @brief Triangle structure
     */
    typedef struct triangle_s {
        Vector2f A;
        Vector2f B;
        Vector2f C;
    } triangle_t;

    /**
     * @brief Polygon interface
     * @interface IPolygon 
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

#endif /* !IPOLYGON_HPP_ */