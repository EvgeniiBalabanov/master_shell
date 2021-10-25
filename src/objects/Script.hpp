#pragma once

#include <list>
#include "LineBlock.hpp"

namespace objects {

/*
Script consisting of sequences of LineBlock.
*/
class Script {
private:
  std::list<objects::LineBlock> data_;
};

}  // namespace objects
