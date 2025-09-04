#include "engine/renderer/RendererMock.hpp"
#include <cassert>
int main(){
  sim::RendererMock r;
  r.init(nullptr);
  auto mh = r.createSphereMesh(16, 32);
  assert(mh.id == 1u);
  r.shutdown();
  return 0;
}