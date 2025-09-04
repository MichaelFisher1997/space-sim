#pragma once
#include "contracts/IRenderer.hpp"
#include "engine/core/Logging.hpp"

namespace sim {
class RendererMock final : public IRenderer {
public:
  bool init(void* /*sdlWindow*/) override { SIM_LOG_INFO("RendererMock::init"); return true; }
  MeshHandle createSphereMesh(int rings, int sectors) override {
    SIM_LOG_INFO("RendererMock::createSphereMesh rings=" << rings << " sectors=" << sectors);
    return MeshHandle{1};
  }
  TextureHandle uploadTextureRGBA8(const unsigned char* /*data*/, int /*w*/, int /*h*/) override {
    SIM_LOG_INFO("RendererMock::uploadTextureRGBA8"); return TextureHandle{1};
  }
  void beginFrame(const CameraState&) override { /* no-op */ }
  void drawPlanet(const PlanetRenderData& p, const MeshHandle&) override {
    SIM_LOG_INFO("RendererMock::drawPlanet r=" << p.radiusMeters
      << " pos=(" << p.positionWorld.x << "," << p.positionWorld.y << "," << p.positionWorld.z << ")");
  }
  void endFrame() override { /* no-op */ }
  void shutdown() override { SIM_LOG_INFO("RendererMock::shutdown"); }
};
} // namespace sim