CC = gcc
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = game
COMPILER_FLAGS = -std=c11 -Wall -O0 -g -pedantic `pkg-config --cflags sdl2 SDL2_ttf SDL2_image`
LIBS=`pkg-config --libs sdl2 SDL2_ttf SDL2_image`

main:
	$(CC) $(COMPILER_FLAGS) $(SRC_FILES) -o $(OBJ_NAME) $(LIBS)