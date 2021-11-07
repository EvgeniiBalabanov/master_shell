#pragma once

#include "BasicAction.hpp"
#include <algorithm>

namespace objects {

/*
Changing the script.
*/
class Group : public BasicAction {
public:
  Group(Script& script, std::list<std::shared_ptr<BasicAction>>&& BasicActions) : BasicAction(script, false), BasicActions_(BasicActions) {};
  void next_implementation(void) const override final {
    for (const auto& BasicAction : BasicActions_) {
      BasicAction->next();
    }
  }
  void back_implementation(void) const override final {
    for (auto iter = BasicActions_.rbegin(); iter != BasicActions_.rend(); iter++) {
      (*iter)->back();
    }
  }
  Group operator+(const Group& other) const {
    std::list<std::shared_ptr<BasicAction>> new_BasicActions = BasicActions_;
    new_BasicActions.insert(new_BasicActions.end(), other.BasicActions_.begin(), other.BasicActions_.end());
    return Group(
      script_,
      std::move(new_BasicActions)
    );
  }
  Group& operator=(const Group& other) {
    BasicAction::operator=(other);
    BasicActions_ = other.BasicActions_;;
    return *this;
  }
  Group& operator+=(const Group& other) {
    return (*this = *this + other);
  }
  std::ostream& operator<<(std::ostream& stream) const override {
    stream << "group: { BasicActions: [ ";
    for (const auto& BasicAction : BasicActions_) {
      stream << "{ " << *BasicAction << " }, ";
    }
    stream <<  " ] }";
    return stream;
  }
private:
  std::list<std::shared_ptr<BasicAction>> BasicActions_;
};

} // namespace objects
