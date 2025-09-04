#pragma once
#include <string>
#include <vector>

namespace sim {

struct double3 { double x{}, y{}, z{}; };

struct BodyState {
  std::string name;
  double radius_m{};
  double3 positionWorld_m{};
  double3 velocityWorld_mps{};
  bool isStar{false};
};

class ISimulation {
public:
  virtual void loadSystem(const std::string& systemId) = 0; // "Solar", "TRAPPIST-1", etc.
  virtual void setTime(double t_seconds_since_epoch) = 0;
  virtual std::vector<BodyState> sampleBodies() const = 0;
  virtual ~ISimulation() = default;
};

} // namespace sim