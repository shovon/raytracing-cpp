CC := clang++
OBJ := obj
SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))
OUTNAME := $(notdir $(CURDIR))

all: $(OBJECTS)
	$(CC) -std=c++20 -O3 $^ -o $(OUTNAME)

%.o: %.cpp
	$(CC) -std=c++20 -O3 -I. -c $< -o $@

clean:
	rm *.o $(OUTNAME)