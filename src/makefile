UNAME := $(shell uname)
files := entities.cpp levels.cpp inputs.cpp game.cpp rendering.cpp main.cpp
obj_dir := obj
compiled := $(files:%.cpp=$(obj_dir)/%.o)

ifeq ($(UNAME), Linux)

CXX := g++
CXXFLAGS := -w -lSDL2 -lSDL2_image

endif

ifeq ($(UNAME), Windows)

CXX := i686-w64-mingw32-g++
CXXFLAGS := -static-libgcc -static-libstdc++ -mwindows -w -lSDL2 -lSDL2_image

endif


all: ../VerticalPool
	
../VerticalPool: $(compiled)
	$(CXX) $(compiled) $(CXXFLAGS) -o $@

$(obj_dir)/%.o: %.cpp
	$(CXX) -c $< -o $@


clean:
	rm -f $(compiled) ../VerticalPool
