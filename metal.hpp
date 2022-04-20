#ifndef METAL_HPP
#define METAL_HPP

#include "ray.hpp"
#include "vec3.hpp"

class metal : public material
{
public:
  metal(const vec3 &a, float f) : albedo{a}
  {
    if (f < 1)
    {
      fuzz = f;
    }
    else
    {
      fuzz = 1;
    }
  }

  virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const
  {
    vec3 reflected = reflect(r_in.direction().unit_vector(), rec.normal);
    scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere());
    attenuation = albedo;
    return scattered.direction().dot(rec.normal) > 0;
  }

  vec3 albedo;
  float fuzz;
};

#endif