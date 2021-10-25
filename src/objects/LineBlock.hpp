#pragma once

#include <list>
#include "Line.hpp"

namespace objects {

/*
LineBlock consisting of sequences of lines.
*/
class LineBlock {
private:
  std::list<Line> lines_;
  objects::Shell  shell_;
};

}  // namespace objects
