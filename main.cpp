#include <iostream>
#include <cmath>
#include <vector>

#include "vec3.hpp"
#include "ray.hpp"
#include "hitable.hpp"
#include "hitable_list.hpp"
#include "sphere.hpp"
#include "camera.hpp"

vec3 color(const ray &r, hitable *world)
{
  hit_record rec;
  // std::cerr << rec.normal << " " << rec.p << " " << rec.t << std::endl;
  if (world->hit(r, 0.0, MAXFLOAT, rec))
  {
    return 0.5 * vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
  }

  auto unit_direction = r.direction().unit_vector();
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * vec3(1, 1, 1) + t * vec3(0.5, 0.7, 1.0);
}

int main()
{
  auto nx = 200;
  auto ny = 100;
  auto ns = 100;

  std::cout << "P3\n"
            << nx << " " << ny << "\n255" << std::endl;
  std::vector<hitable *> list;
  list.emplace_back(new sphere(vec3(0, 0, -1), 0.5));
  list.emplace_back(new sphere(vec3(0, -100.5, -1), 100));
  hitable *world = new hitable_list(list, 2);
  camera cam;
  for (auto j = ny - 1; j >= 0; j--)
  {
    for (int i = 0; i < nx; i++)
    {
      vec3 col(0, 0, 0);
      for (int s = 0; s < ns; s++)
      {
        auto u = float(i + drand48()) / float(nx);
        auto v = float(j + drand48()) / float(ny);
        auto r = cam.get_ray(u, v);
        col += color(r, world);
      }
      col /= float(ns);

      auto ir = int(255.99 * col.e0);
      auto ig = int(255.99 * col.e1);
      auto ib = int(255.99 * col.e2);
      std::cout << ir << " " << ig << " " << ib << std::endl;
    }
  }
}