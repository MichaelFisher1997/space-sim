#pragma once
#include <string>
#include <vector>

namespace sim {

struct UiEvent {
  enum Type { SelectSystem, FocusBody, ToggleTidalLock } type{SelectSystem};
  std::string stringArg; // system or body name
};

class IUI {
public:
  virtual void init(void* sdlWindow) = 0;
  virtual std::vector<UiEvent> drawFrame(const std::vector<std::string>& systems,
                                         const std::vector<std::string>& bodies) = 0;
  virtual void shutdown() = 0;
  virtual ~IUI() = default;
};

} // namespace sim