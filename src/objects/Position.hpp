#pragma once

#include <cstddef>
#include <iostream>

namespace objects {

/*
*/
struct Position {
  std::size_t yy_;
  std::size_t xx_;
};

}  // namespace objects

std::ostream& operator<<(std::ostream& stream, const objects::Position& position) {
  stream << "position: { yy : " << position.yy_ << ", xx : " << position.xx_ << "}";
  return stream;
}