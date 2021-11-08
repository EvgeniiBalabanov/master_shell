#pragma once

#include "BasicAction.hpp"
#include <algorithm>

namespace objects {

/*
Changing the script.
*/
class Group : public BasicAction {
public:
  Group(Script& script, std::list<std::shared_ptr<BasicAction>>&& actions) : BasicAction(script, false), actions_(actions) {};
  void next_implementation(void) const override final {
    for (const auto& action : actions_) {
      action->next();
    }
  }
  void back_implementation(void) const override final {
    for (auto iter = actions_.rbegin(); iter != actions_.rend(); iter++) {
      (*iter)->back();
    }
  }
  Group operator+(const Group& other) const {
    std::list<std::shared_ptr<BasicAction>> new_actions = actions_;
    new_actions.insert(new_actions.end(), other.actions_.begin(), other.actions_.end());
    return Group(
      script_,
      std::move(new_actions)
    );
  }
  Group& operator=(const Group& other) {
    BasicAction::operator=(other);
    actions_ = other.actions_;;
    return *this;
  }
  Group& operator+=(const Group& other) {
    return (*this = *this + other);
  }
  std::ostream& operator<<(std::ostream& stream) const override {
    stream << "group: { actions: [ ";
    for (const auto& action : actions_) {
      stream << "{ " << *action << " }, ";
    }
    stream <<  " ] }";
    return stream;
  }
private:
  std::list<std::shared_ptr<BasicAction>> actions_;
};

} // namespace objects
