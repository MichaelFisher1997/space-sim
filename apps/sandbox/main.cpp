#include "engine/renderer/RendererMock.hpp"
#include "engine/sim/SimulationMock.hpp"
#include "engine/ui/UiMock.hpp"
#include "contracts/IRenderer.hpp"
#include "contracts/ISimulation.hpp"
#include "contracts/IUI.hpp"
#include "engine/core/Logging.hpp"
#include <vector>
#include <string>

int main() {
  SIM_LOG_INFO("Sandbox starting (mocks)");
  sim::RendererMock renderer;
  sim::SimulationMock sim;
  sim::UiMock ui;

  renderer.init(nullptr);
  sim.loadSystem("Solar");
  sim.setTime(0.0);
  ui.init(nullptr);

  auto bodies = sim.sampleBodies();
  std::vector<std::string> systems = {"Solar","TRAPPIST-1"};
  std::vector<std::string> bodyNames;
  for (auto& b : bodies) bodyNames.push_back(b.name);

  auto events = ui.drawFrame(systems, bodyNames);
  for (auto& e : events) {
    if (e.type == sim::UiEvent::SelectSystem) SIM_LOG_INFO("UI SelectSystem: " << e.stringArg);
    if (e.type == sim::UiEvent::FocusBody)   SIM_LOG_INFO("UI FocusBody: " << e.stringArg);
  }

  sim::CameraState cam{};
  renderer.beginFrame(cam);
  auto sphere = renderer.createSphereMesh(16, 32);
  for (auto& b : bodies) {
    sim::PlanetRenderData rd{};
    rd.radiusMeters  = static_cast<float>(b.radius_m);
    rd.positionWorld = {static_cast<float>(b.positionWorld_m.x),
                        static_cast<float>(b.positionWorld_m.y),
                        static_cast<float>(b.positionWorld_m.z)};
    renderer.drawPlanet(rd, sphere);
  }
  renderer.endFrame();

  ui.shutdown();
  renderer.shutdown();
  SIM_LOG_INFO("Sandbox exit");
  return 0;
}