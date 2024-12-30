all:
	g++ main.cpp rendering.cpp game.cpp inputs.cpp levels.cpp entities.cpp -g -w -lSDL2 -lSDL2_image -lSDL2_ttf && ./a.out

windows:
	i686-w64-mingw32-g++ -static-libgcc -static-libstdc++ -mwindows main.cpp rendering.cpp game.cpp inputs.cpp levels.cpp entities.cpp -g -w -lSDL2 -lSDL2_image -lSDL2_ttf -o verticalPool.exe

clean:
	rm -f ./a.out