#include "Shell.hpp"
#include <signal.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

namespace objects {

Shell::Shell() {
  pid_shell_ = fork();
  if (!pid_shell_) {
    char* argv[] = {"/bin/bash", "/Users/e.balabanov/Desktop/Projects/master_shell/in", nullptr};
    execve("/bin/bash", argv, nullptr);
  }
};

Shell::~Shell() {
  kill(pid_shell_, 30);
}

}  // namespace objects

void operator<<(objects::Shell& shell, const std::string& in) {
  std::ofstream fifo("/Users/e.balabanov/Desktop/Projects/master_shell/in");
  fifo << in;
}
