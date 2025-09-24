/**
 * @file IEvent.hpp
 * @author @Perry-Chouteau (perry.chouteau@outlook.com)
 * @brief 
 * @date 2025-09-24
 * 
 * @addtogroup graphic
 * @{
 */

#ifndef IEVENT_HPP
#define IEVENT_HPP

namespace graphic {

  /**
   * @brief Event interface
   * @interface IEvent
   */
  class IEvent {
    public:
      virtual ~IEvent() = default;
  };

}

#endif // IEVENT_HPP
