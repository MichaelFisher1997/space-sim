#pragma once
#include <cstdint>

namespace sim {

struct float3 { float x{}, y{}, z{}; };

struct TextureHandle { uint32_t id{0}; };
struct MeshHandle    { uint32_t id{0}; };

struct PlanetRenderData {
  float radiusMeters{};
  float3 positionWorld{};   // meters
  float3 albedoTint{1.f,1.f,1.f};
  TextureHandle albedo{};   // optional
};

struct CameraState {
  float3 eye{}, lookAt{}, up{0.f,1.f,0.f};
  float  vfovDegrees{60.f}, nearPlane{0.1f}, farPlane{1e9f};
};

class IRenderer {
public:
  virtual bool init(void* sdlWindow) = 0;
  virtual MeshHandle createSphereMesh(int rings, int sectors) = 0;
  virtual TextureHandle uploadTextureRGBA8(const unsigned char* data, int w, int h) = 0;
  virtual void beginFrame(const CameraState&) = 0;
  virtual void drawPlanet(const PlanetRenderData&, const MeshHandle&) = 0;
  virtual void endFrame() = 0;
  virtual void shutdown() = 0;
  virtual ~IRenderer() = default;
};

} // namespace sim