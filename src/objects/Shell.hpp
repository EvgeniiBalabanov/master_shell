#pragma once

#include <filesystem>

namespace objects {

/*
Shell for execution.
*/
class Shell {
private:
  std::filesystem::path path_;
};

}  // namespace objects
