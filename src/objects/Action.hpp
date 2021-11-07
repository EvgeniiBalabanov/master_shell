#pragma once

#include <iostream>

#include "Script.hpp"

namespace objects {

struct Script;

/*
Changing the script.
*/
class Action {
public:
  Action(Script& script, bool reverse = false) : script_(script), reverse_(reverse) {};
  Action(Action&& other) : script_(other.script_), reverse_(other.reverse_) {};
  Action& operator=(const Action& other) {
    reverse_ = other.reverse_;
    return *this;
  }
  virtual ~Action() = default;
  void next(void) const {
    if (reverse_ == false) {
      next_implementation();
    } else {
      back_implementation();
    }
  };
  void back(void) const {
    if (reverse_ == false) {
      back_implementation();
    } else {
      next_implementation();
    }
  };
  virtual void next_implementation(void) const = 0;
  virtual void back_implementation(void) const = 0;
  virtual std::ostream& operator<<(std::ostream& stream) const = 0;

protected:
  Script& script_;
  bool reverse_;
};

} // namespace objects

std::ostream& operator<<(std::ostream& stream, const objects::Action& action) {
  return action.operator<<(stream);
};