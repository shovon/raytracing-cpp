#ifndef METAL_HPP
#define METAL_HPP

#include "ray.hpp"
#include "vec3.hpp"

class metal : public material
{
public:
  metal(const vec3 &a) : albedo{a} {}

  virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered)
  {
    vec3 reflected = reflect(r_in.direction().unit_vector(), rec.normal);
    scattered = ray(rec.p, reflected);
    attenuation = albedo;
    return scattered.direction().dot(rec.normal) > 0;
  }

  vec3 albedo;
}

#endif