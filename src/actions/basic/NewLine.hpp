#pragma once

#include "BasicAction.hpp"

namespace objects {

/*
Changing the script.
*/
class NewLine : public BasicAction {
public:
  NewLine(Script& script, bool reverse) : BasicAction(script, reverse) {};
  void next_implementation(void) const override final {
    auto iter = script_.data_.begin();
    std::advance(iter, ++script_.position_.yy_);
    if (iter == script_.data_.end()) {
      script_.data_.push_back(Line());
    } else {
      script_.data_.insert(iter, Line());
    }
    script_.position_.xx_ = 0;
  }
  void back_implementation(void) const override final {
    if (script_.position_.yy_) {
      auto iter = script_.data_.begin();
      std::advance(iter, --script_.position_.yy_);
      script_.position_.xx_ = iter->length();
      script_.data_.erase(++iter);
    }
  }
  std::ostream& operator<<(std::ostream& stream) const override {
    stream << "new_line: { reverse: " << reverse_ << " }";
    return stream;
  }
};

} // namespace objects
