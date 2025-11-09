/**
 * @file ICamera.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @date 2025-01-29
 * 
 * @addtogroup graphic
 * @{
 */
    

#ifndef ICAMERA_HPP_
    #define ICAMERA_HPP_
    #include "Type.hpp"
    #include "IWindow.hpp"

namespace graphic {

    /**
     * @brief Camera interface
     * @interface ICamera 
     */
    class ICamera {

        public:
            typedef enum{
                PERSPECTIVE,
                ORTHOGRAPHIC
            } Projection;

            typedef enum {
                CUSTOM = 0,              // Custom camera
                FREE,                    // Free camera
                ORBITAL,                 // Orbital camera
                FIRST_PERSON,            // First person camera
                THIRD_PERSON             // Third person camera
            } Mode;

            /**
             * @brief Destroy the ICamera object
             */
            virtual ~ICamera() = default;
            
            /**
             * @brief Get the FOV
             * 
             * @return float
             */
            virtual float getFov() const = 0;
            
            /**
             * @brief Set the FOV
             * 
             * @param fov
             */
            virtual void setFov(float fov) = 0;

            /**
             * @brief Get the mode
             * 
             * @return Mode
             */
            virtual Mode getMode() const = 0;

            /**
             * @brief Set the mode
             * 
             * @param mode
             */
            virtual void setMode(Mode mode) = 0;

            /**
             * @brief Get the position
             * 
             * @return Vector3f
             */
            virtual Vector3f getPosition() const = 0;

            /**
             * @brief Set the position
             * 
             * @param position 
             */
            virtual void setPosition(Vector3f position) = 0;

            /**
             * @brief Get the Projection
             * 
             * @return Vector3f
             */
            virtual Projection getProjection() const = 0;

            /**
             * @brief Set the Projection
             * 
             * @param projection
             */
            virtual void setProjection(Projection projection) = 0;
            
            /**
             * @brief Get the target
             * 
             * @return Vector3f
             */
            virtual Vector3f getTarget() const = 0;

            /**
             * @brief Set the target
             * 
             * @param size
             */
            virtual void setTarget(Vector3f size) = 0;
            
            /**
             * @brief Get the up vector
             * 
             * @return Vector3f
             */
            virtual Vector3f getUp() const = 0;

            /**
             * @brief Set the up vector
             * 
             * @param up
             */
            virtual void setUp(Vector3f up) = 0;

        private:
            //your variables here
    };

} // namespace graphic3

#endif /* !ICAMERA_HPP */