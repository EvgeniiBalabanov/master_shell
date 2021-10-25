#pragma once

#include "Script.hpp"
#include "Shell.hpp"

namespace objects {

/*
Instructions for execution.
*/
class Instruction {
private:
  objects::Script script;
  objects::Shell  shell;
  std::string     out;
public:
  Instruction(const objects::Script& script, const objects::Shell& shell);
};

}  // namespace objects
