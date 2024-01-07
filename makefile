PROG=main

CC=g++
CCFLAGS=-std=c++17 -Wall
SRC_DIR=src
INCLUDE_DIR=include
BUILD_DIR=build
BIN_DIR=bin
SRC= $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJ= $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))
LIBS=-lSDL2_image -lSDL2_ttf -lSDL2 
INCLUDE=-I./${INCLUDE_DIR}
OUT=${BIN_DIR}/${PROG}.out

all: ${OUT}

${BUILD_DIR}/%.o: ${SRC_DIR}/%.cpp
	mkdir -p ${BUILD_DIR} ${BIN_DIR}
	$(CC) $(CCFLAGS) $< -c -o $@ ${INCLUDE}


${OUT}: ${SRC_OBJ}
	$(CC) $(CCFLAGS) $^ -o $@ $(LIBS)

run: ${OUT}
	./${OUT}

clean:
	-rm -r ${BIN_DIR} ${BUILD_DIR}