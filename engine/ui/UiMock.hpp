#pragma once
#include "contracts/IUI.hpp"

namespace sim {
class UiMock final : public IUI {
public:
  void init(void* /*sdlWindow*/) override {}
  std::vector<UiEvent> drawFrame(const std::vector<std::string>& systems,
                                 const std::vector<std::string>& bodies) override {
    // Always request Solar and focus Earth for now.
    std::vector<UiEvent> out;
    if (!systems.empty()) out.push_back(UiEvent{UiEvent::SelectSystem, systems[0]});
    if (bodies.size() > 1) out.push_back(UiEvent{UiEvent::FocusBody, bodies[1]});
    return out;
  }
  void shutdown() override {}
};
} // namespace sim