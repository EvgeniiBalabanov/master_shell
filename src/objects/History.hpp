#pragma once

#include <list>
#include "Action.hpp"

namespace objects {

/*
Script Modification History.
*/
class History {
private:
  std::list<objects::Action> data_;
};

}  // namespace objects
