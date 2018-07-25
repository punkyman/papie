OUTPUT_DIR = ./out

# custom wildcard function for recursive search in a folder
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

OBJ_C = $(call rwildcard, , *.cpp)
OBJ_O = $(patsubst %.cpp,$(OUTPUT_DIR)/%.o, $(OBJ_C))

OBJ_DIRS:=$(dir $(OBJ_O))

# command executed when make runs to create out dir hierarchy
MK_OBJ_DIRS:=$(shell mkdir --parents $(OBJ_DIRS))

TARGET = ./out/papie
CC = gcc

CFLAGS += -g -Wall

LIB = -lstdc++ -lwiringPi

$(TARGET):$(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) -o $@ $(LIB)

$(OUTPUT_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LIB)
	
clean :
	rm -rf $(OUTPUT_DIR)

