#Compiler
CC=gcc

#Objects
OBJECTS=init.o render.o rect.o main.o input.o checkmatch.o sound.o

#Compiler flags
CFLAGS=-Wall -g `sdl-config --cflags`

#Linker flags
LDFLAGS=`sdl-config --libs` -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer

#main 
main: main.c
	$(CC) $(CFLAGS) -c init.c render.c rect.c main.c input.c checkmatch.c sound.c
	$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o bin/connectit

# clean up
clean:
	rm -rf $(OBJECTS)
	
#EOF
