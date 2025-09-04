#pragma once
#include <cmath>
namespace sim {
struct Vec3d { double x{}, y{}, z{}; };
struct Vec3f { float x{}, y{}, z{}; };
inline bool isFinite(double v){ return std::isfinite(v); }
}