#pragma once

#include "Action.hpp"

namespace objects {

/*
Changing the script.
*/
class Move : public Action {
public:
  Move(Script& script, bool reverse, long yy, long xx) : Action(script, reverse), yy_(yy), xx_(xx) {};
  void next_implementation(void) const override final {
    script_.position_.yy_ += yy_;
    script_.position_.xx_ += xx_;
  }
  void back_implementation(void) const override final {
    script_.position_.yy_ -= yy_;
    script_.position_.xx_ -= xx_;
  }
  Move operator+(const Move& other) const {
    return Move(
      script_,
      reverse_,
      yy_ + (other.reverse_ == reverse_ ? other.yy_ : -other.yy_),
      xx_ + (other.reverse_ == reverse_ ? other.xx_ : -other.xx_));
  }
  Move& operator=(const Move& other) {
    Action::operator=(other);
    yy_ = other.yy_;
    xx_ = other.xx_;
    return *this;
  }
  Move& operator+=(const Move& other) {
    return (*this = *this + other);
  }
  std::ostream& operator<<(std::ostream& stream) const override {
    stream << "move: { reverse: " << reverse_
      << ", yy: " << yy_
      << ", xx: " << xx_
      << "}";
    return stream;
  }
private:
  long yy_;
  long xx_;
};

} // namespace objects
