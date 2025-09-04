#pragma once
#include "contracts/ISimulation.hpp"

namespace sim {
class SimulationMock final : public ISimulation {
  std::string current_{"Solar"};
public:
  void loadSystem(const std::string& id) override { current_ = id; }
  void setTime(double) override {}
  std::vector<BodyState> sampleBodies() const override {
    return {
      {"Sun", 6.96e8, {0,0,0}, {0,0,0}, true},
      {"Earth", 6.371e6, {1.496e11,0,0}, {0,29.78e3,0}, false},
      {"Mars", 3.389e6, {2.279e11,0,0}, {0,24.07e3,0}, false},
    };
  }
};
} // namespace sim