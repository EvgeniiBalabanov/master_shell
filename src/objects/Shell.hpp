#pragma once

#include <filesystem>
#include <unistd.h>
#include <fstream>

namespace objects {

/*
Shell for execution.
 - text
 - zsh // default
 - bash
 - python3
*/
class Shell {
private:
  // std::filesystem::path path_shell_;
  // std::filesystem::path path_fifo_;
  pid_t pid_shell_;

public:
  std::ofstream ofstream_fifo_;
  // int fd_fifo_;
  Shell();
  ~Shell();
};

}  // namespace objects

void operator<<(objects::Shell& shell, const std::string& in);