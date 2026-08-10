/**
 * @file IAnimationSet.hpp
 * @author Perry Chouteau (perry.chouteau@outlook.com)
 * @brief
 * @date 2026-08-10
 *
 * @addtogroup graphic
 * @{
 */

#ifndef IANIMATIONSET_HPP_
    #define IANIMATIONSET_HPP_

namespace graphic {

    /**
     * @brief A file's loaded animation clips, independent of any IModel
     *        bound to it - deleting every bound IModel does not delete the
     *        set, only deleteAnimationSet() does. Many IModel instances can
     *        share one set (same clips), each tracking its own current
     *        clip/frame via IModel::setAnimation()/updateAnimation().
     * @interface IAnimationSet
     */
    class IAnimationSet {

        public:

            virtual ~IAnimationSet() = default;

            /**
             * @brief notice if the animation set is ready
             *
             * @return bool
             */
            virtual bool isReady() const = 0;

            /**
             * @brief Get the number of clips in this set
             *
             * @return int
             */
            virtual int getSize() const = 0;
    };

} // namespace graphic

#endif /* !IANIMATIONSET_HPP_ */
