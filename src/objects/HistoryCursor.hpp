#pragma once

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include "BasicAction.hpp"
#include "Script.hpp"

namespace objects {

/*
Script Modification History.
*/
class HistoryCursor {
public:
  HistoryCursor(): data_(), cursor_(data_.end()) {}
  void next(void) {
    if (cursor_ != data_.end()) {
      (*cursor_)->next();
      ++cursor_;
    }
  }

  void back(void) {
    if (cursor_ != data_.begin()) {
      --cursor_;
      (*cursor_)->back();
    }
  }

  template<typename TypeBasicAction, typename... Args>
  void add_event(Args&&... args) {
    std::shared_ptr<TypeBasicAction> BasicAction = std::make_shared<TypeBasicAction>(std::forward<Args>(args)...);
    if (cursor_ != data_.end()) {
      data_.erase(++decltype(cursor_)(cursor_), data_.end());
    }
    BasicAction->next();
    data_.push_back(std::move(BasicAction));
  }

  std::ostream& operator<<(std::ostream& stream) const {
    stream << "history_cursor: { data: [ ";
    for (const auto& BasicAction : data_) {
      stream << "{ "<< *BasicAction << " }, ";
    }
    stream << "], cursor: " << std::distance<std::list<std::shared_ptr<BasicAction>>::const_iterator>(data_.begin(), cursor_) << " } ";
    return stream;
  }

private:
  std::list<std::shared_ptr<BasicAction>> data_;
  std::list<std::shared_ptr<BasicAction>>::iterator cursor_;
};

}  // namespace objects

std::ostream& operator<<(std::ostream& stream, const objects::HistoryCursor& history) {
  return history.operator<<(stream);
}