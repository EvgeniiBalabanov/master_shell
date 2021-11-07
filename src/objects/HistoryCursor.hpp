#pragma once

#include <iostream>
#include <list>
#include <iterator>

#include "Action.hpp"
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
      cursor_++;
    }
  }

  void back(void) {
    if (cursor_ != data_.begin()) {
      cursor_--;
      (*cursor_)->back();
    }
  }

  void add_event(std::shared_ptr<Action> action) {
    if (cursor_ != data_.end()) {
      std::list<std::shared_ptr<Action>>::iterator begin_erase = cursor_;
      std::advance(cursor_, 1);
      data_.erase(begin_erase, data_.end());
    }
    action->next();
    data_.push_back(std::move(action));
  }

  std::ostream& operator<<(std::ostream& stream) const {
    stream << "history_cursor: { data: [ ";
    for (const auto& action : data_) {
      stream << "{ "<< *action << " }, ";
    }
    stream << "], cursor: " << std::distance<std::list<std::shared_ptr<Action>>::const_iterator>(data_.begin(), cursor_) << " } ";
    return stream;
  }

private:
  std::list<std::shared_ptr<Action>> data_;
  std::list<std::shared_ptr<Action>>::iterator cursor_;
};

}  // namespace objects

std::ostream& operator<<(std::ostream& stream, const objects::HistoryCursor& history) {
  return history.operator<<(stream);
}