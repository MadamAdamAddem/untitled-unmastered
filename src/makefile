ifeq ($(OS),Windows_NT)
	UNAME := Windows
else
	UNAME := $(shell uname)
endif

files := entities.cpp levels.cpp inputs.cpp game.cpp rendering.cpp main.cpp
obj_dir := obj
compiled := $(files:%.cpp=$(obj_dir)/%.o)

ifeq ($(UNAME), Linux)

CXX := g++
CXXFLAGS := -w -O2 -lSDL2 -lSDL2_image

endif

ifeq ($(UNAME), Windows)

CXX := g++
CXXFLAGS := -static-libgcc -static-libstdc++ -mwindows -w -O2 -lSDL2 -lSDL2_image

endif


all: ../VerticalPool
	
../VerticalPool: $(compiled)
	$(CXX) $(compiled) $(CXXFLAGS) -o $@

$(obj_dir)/%.o: %.cpp | $(obj_dir)
	$(CXX) -c $< -o $@

$(obj_dir):
	mkdir $(obj_dir)

touch:
	touch *.cpp




ifeq ($(UNAME), Linux)

clean:
	rm -f $(compiled) ../VerticalPool
	rm -rf $(obj_dir)

endif
ifeq ($(UNAME), Windows)

clean:
	rmdir /s /q $(obj_dir)

endif
