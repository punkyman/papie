OUTPUT_DIR = ./out

# custom wildcard function for recursive search in a folder
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

OBJ_C = $(call rwildcard, , *.cpp)
OBJ_O = $(patsubst %.cpp,$(OUTPUT_DIR)/%.o, $(OBJ_C))

TARGET = ./out/papie
CC = gcc

CFLAGS += -g -Wall

LIB = -lwiringPi

$(TARGET):$(OBJ_O)
	$(CC) $(CFLAGS) $(OBJ_O) -o $@ $(LIB)

$(OUTPUT_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(LIB)
	
clean :
	rm -f $(OUTPUT_DIR)/*.o
	rm -f $(OUTPUT_DIR)/sdk/*.o
	rm -f $(OUTPUT_DIR)/sdk/driver/*.o

