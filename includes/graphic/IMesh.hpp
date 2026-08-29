/**
 * @file IMesh.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2026-08-10
 *
 * @addtogroup igraphic
 * @{
 */

#ifndef IMESH_HPP_
    #define IMESH_HPP_

namespace graphic {

    /**
     * @brief Loaded geometry (vertices/faces), independent of any IModel
     *        instance built from it - deleting every IModel built from a
     *        mesh does not delete the mesh, only deleteMesh() does. Many
     *        IModel instances (e.g. identical enemies) can share one mesh,
     *        each with its own position/rotation/size/animation state.
     * @interface IMesh
     */
    class IMesh {

        public:

            virtual ~IMesh() = default;

            /**
             * @brief notice if the mesh is ready
             *
             * @return bool
             */
            virtual bool isReady() const = 0;
    };

} // namespace graphic

/** @} */

#endif /* !IMESH_HPP_ */
