#include <iostream>
#include <cmath>
#include <vector>

#include "vec3.hpp"
#include "ray.hpp"
#include "hitable.hpp"
#include "hitable_list.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "material.hpp"
#include "lambertian.hpp"
#include "metal.hpp"
#include "dialectric.hpp"

vec3 color(const ray &r, hitable *world, int depth)
{
  hit_record rec;
  if (world->hit(r, 0.001, MAXFLOAT, rec))
  {
    ray scattered;
    vec3 attenuation;
    if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered))
    {
      return attenuation * color(scattered, world, depth + 1);
    }
    else
    {
      return vec3(0, 0, 0);
    }
  }

  auto unit_direction = r.direction().unit_vector();
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * vec3(1, 1, 1) + t * vec3(0.5, 0.7, 1.0);
}

hitable *random_scene()
{
  int n = 500;
  std::vector<hitable *> list;

  list.emplace_back(new sphere(vec3(0, -1000, 0), 1000, new lambertian(vec3(0.5, 0.5, 0.5))));

  for (int a = -11; a < 11; a++)
  {
    for (int b = -11; b < 11; b++)
    {
      float choose_mat = drand48();
      vec3 center(a + 0.9 * drand48(), 0.2, b + 0.9 * drand48());
      if ((center - vec3(4, 0.2, 0)).length() > 0.9)
      {
        if (choose_mat < 0.8)
        {
          list.emplace_back(new sphere(center, 0.2, new lambertian(vec3(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()))));
        }
        else if (choose_mat < 0.95)
        {
          list.emplace_back(new sphere(center, 0.2, new metal(vec3(0.5 * (1 + drand48()), 0.5 * (1 + drand48()), 0.5 * (1 + drand48())), 0.5 * drand48())));
        }
        else
        {
          list.emplace_back(new sphere(center, 0.2, new dialectric(1.5)));
        }
      }
    }
  }

  list.emplace_back(new sphere(vec3(0, 1, 0), 1.0, new dialectric(1.5)));
  list.emplace_back(new sphere(vec3(-4, 1, 0), 1.0, new lambertian(vec3(0.4, 0.2, 0.1))));
  list.emplace_back(new sphere(vec3(4, 1, 0), 1.0, new metal(vec3(0.7, 0.6, 0.5), 0.0)));

  return new hitable_list(list);
}

int main()
{
  auto nx = 1024;
  auto ny = 576;
  auto ns = 100;

  std::cout << "P3\n"
            << nx << " " << ny << "\n255" << std::endl;
  // std::vector<hitable *> list;
  // list.emplace_back(new sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.8, 0.3, 0.3))));
  // list.emplace_back(new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0))));
  // list.emplace_back(new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), 1.0)));
  // list.emplace_back(new sphere(vec3(-1, 0, -1), 0.5, new dialectric(1.5)));
  // list.emplace_back(new sphere(vec3(-1, 0, -1), -0.45, new dialectric(1.5)));
  // hitable *world = new hitable_list(list, 2);

  vec3 lookfrom(12, 2, 4);
  vec3 lookat(0, 1, 0);
  float dist_to_focus = (lookfrom - lookat).length();
  float aperture = 0.2;
  hitable *world = random_scene();

  camera cam(lookfrom, lookat, vec3(0, 1, 0), 20, float(nx) / float(ny), aperture, dist_to_focus);
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
        col += color(r, world, 0);
      }
      col /= float(ns);
      col = vec3(sqrt(col.e0), sqrt(col.e1), sqrt(col.e2));

      auto ir = int(255.99 * col.e0);
      auto ig = int(255.99 * col.e1);
      auto ib = int(255.99 * col.e2);

      std::cout << ir << " " << ig << " " << ib << std::endl;
    }
  }
}