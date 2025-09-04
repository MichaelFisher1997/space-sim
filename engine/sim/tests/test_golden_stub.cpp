#include "engine/sim/SimulationMock.hpp"
#include <cassert>
int main(){
  sim::SimulationMock s;
  s.loadSystem("Solar");
  s.setTime(0.0);
  auto bodies = s.sampleBodies();
  assert(!bodies.empty());
  return 0;
}