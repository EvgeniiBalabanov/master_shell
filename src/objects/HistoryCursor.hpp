#pragma once

#include <iostream>
#include <list>
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
      (*cursor_)->back();
      cursor_--;
    }
  }

  void add_event(std::shared_ptr<Action> action) {
    if (cursor_ != data_.end()) {
      std::list<std::shared_ptr<Action>>::iterator begin_erase = cursor_;
      std::advance(cursor_, 1);
      data_.erase(begin_erase, data_.end());
    }
    data_.push_back(std::move(action));
    next();
  }

  std::ostream& operator<<(std::ostream& stream) const {
    stream << "history_cursor: { data_: { ";
    for (const auto& action : data_) {
      stream << *action << ", ";
    }
    stream << "}, cursor_: NaN } ";
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