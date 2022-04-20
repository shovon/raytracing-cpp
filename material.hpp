#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "ray.hpp"
#include "hitable.hpp"

class material
{
public:
  virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const = 0;
};

inline vec3 reflect(const vec3 &v, const vec3 &n)
{
  return v - 2 * v.dot(n) * n;
}

#endif