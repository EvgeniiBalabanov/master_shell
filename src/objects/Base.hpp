#pragma once

#include <list>
#include "Shell.hpp"
#include "Script.hpp"
#include "Mode.hpp"

namespace objects {

/*
*/
class Base {
private:
  std::list<objects::Shell>   shells_;
  std::list<objects::Script>  scripts_;
  std::list<object::Mode>     modes_;
};

}  // namespace objects
