#include <iostream>

#include "vec3.hpp"
#include "ray.hpp"

vec3 color(const ray &r)
{
  auto unit_direction = r.direction().unit_vector();
  auto t = 0.5 * (unit_direction.y() + 1.0);
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