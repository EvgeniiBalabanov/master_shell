#pragma once

#include <list>
#include <optional>
#include <string>
#include <iostream>

#include "Line.hpp"
#include "HistoryCursor.hpp"
#include "Position.hpp"

namespace objects {

/*
Script consisting of sequences of Line.
*/
struct Script {
  // uuid
  std::optional<std::string>    name_;
  std::list<Line>      data_;
  Position             position_;
  HistoryCursor        history_;
  Script() : data_({Line()}), position_{0, 0}, history_() {};
  Line& get_current_line(void) {
    auto iter = data_.begin();
    std::advance(iter, position_.yy_);
    return *iter;
  }
  std::ostream& operator<<(std::ostream& stream) const {
    stream << "script : { data : [";
    for (const auto& line : data_) {
      stream << "\"" << line << "\"" << ", ";
    }
    stream << "], " << position_ << ", " << history_ << "}";
    return stream;
  }
};

}  // namespace objects

std::ostream& operator<<(std::ostream& stream, const objects::Script& script) {
  return script.operator<<(stream);
}