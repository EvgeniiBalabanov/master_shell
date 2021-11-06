#pragma once

#include "Action.hpp"

namespace objects {

/*
Changing the script.
*/
class Insert : public Action {
public:
  Insert(Script& script, bool reverse, const std::string& str) : Action(script, reverse), str_(str) {};
  void next_implementation(void) const override final {
    script_.get_line(script_.position_.yy_).insert(script_.position_.xx_, str_);
    script_.position_.xx_ += str_.length();
  }
  void back_implementation(void) const override final {
    script_.get_line(script_.position_.yy_).erase(script_.position_.xx_ - str_.length(), str_.length());
    script_.position_.xx_ -= str_.length();
  }
  Insert operator+(const Insert& other) const {
    if (other.reverse_ == reverse_ == false) {
      return Insert(
        script_,
        false,
        str_ + other.str_
      );
    } else if (other.reverse_ == reverse_ == true) {
      return Insert(
        script_,
        true,
        other.str_ + str_
      );
    } else { // has not other variant
      throw std::runtime_error("reverse is different");
    }
  }
  Insert& operator=(const Insert& other) {
    script_ = other.script_;
    reverse_ = other.reverse_;
    str_ = other.str_;
    return *this;
  }
  Insert& operator+=(const Insert& other) {
    return (*this = *this + other);
  }
  std::ostream& operator<<(std::ostream& stream) const override {
    stream << "insert: { reverse: " << reverse_ << ", string: " << str_ << "}";
    return stream;
  }
private:
  std::string str_;
};

} // namespace objects
