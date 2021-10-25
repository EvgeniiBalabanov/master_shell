#pragma once

#include <list>
#include <optional>
#include <string>

#include "LineBlock.hpp"

namespace objects {

/*
Script consisting of sequences of LineBlock.
*/
class Script {
private:
  // uuid
  std::optional<std::string>    name_;
  std::list<objects::LineBlock> data_;
};

}  // namespace objects
