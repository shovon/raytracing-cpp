# Ray Tracing in One Weekend in C++

![Output from ray tracing](/output.png)

This is a ray tracing implementation in C++, pretty much a re-implementation of an [earlier attempt](https://github.com/shovon/raytracing-golang) in Go

All implementation was pretty much the result of me manually typing out everything in the minibook _[Ray Tracing In One Weekend](https://www.amazon.ca/Ray-Tracing-Weekend-Minibooks-Book-ebook/dp/B01B5AODD8)_, but with an _attempt_ at introducing some modern C++ features.

## Running the ray tracer

```
make
./raytracer-cpp > img.ppm
```

The program outputs portable pixmap format to the console/stdout, and so, the `>` symbol writes the output to a file.

Rendering a whole 1024 by 576 image takes around an 4 and half minutes on my 2020 M1 MacBook Pro. If you want something rendered quicker, change the `nx` and `ny` variables in `main()`, in `main.c` to something smaller than 1024 by 576 (perhaps 200 and 100, respectively).
