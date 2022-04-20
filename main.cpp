#include <iostream>
#include <cmath>

#include "vec3.hpp"
#include "ray.hpp"

float hit_sphere(const vec3 &center, float radius, const ray &r)
{
  auto oc = r.origin() - center;
  auto a = r.direction().dot(r.direction());
  auto b = 2.0f * oc.dot(r.direction());
  auto c = oc.dot(oc) - radius * radius;
  auto discriminant = b * b - 4 * a * c;
  if (discriminant < 0)
  {
    return -1.0;
  }
  else
  {
    return (-b - sqrt(discriminant)) / (2.0f * a);
  }
}

vec3 color(const ray &r)
{
  auto t = hit_sphere(vec3(0, 0, -1), 0.5, r);
  if (t > 0)
  {
    auto n = (r.point_at_parameter(t) - vec3(0, 0, -1)).unit_vector();
    return 0.5 * vec3(n.x() + 1, n.y() + 1, n.z() + 1);
  }
  auto unit_direction = r.direction().unit_vector();
  t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

int main()
{
  auto nx = 200;
  auto ny = 100;
  std::cout << "P3\n"
            << nx << " " << ny << "\n255" << std::endl;
  vec3 lower_left_corner(-2, -1, -1);
  vec3 horizontal(4, 0, 0);
  vec3 vertical(0, 2, 0);
  vec3 origin(0, 0, 0);
  for (auto j = ny - 1; j >= 0; j--)
  {
    for (int i = 0; i < nx; i++)
    {
      auto u = float(i) / float(nx);
      auto v = float(j) / float(ny);
      ray r(origin, lower_left_corner + u * horizontal + v * vertical);
      vec3 col = color(r);
      auto ir = int(255.99 * col.e0);
      auto ig = int(255.99 * col.e1);
      auto ib = int(255.99 * col.e2);
      std::cout << ir << " " << ig << " " << ib << std::endl;
    }
  }
}