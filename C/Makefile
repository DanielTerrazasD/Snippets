# Compiler and Linker
CC = gcc
CFLAGS = -g

# Paths to include in the compilation
PATHS = Code/
PATHS += Code/Event_Generator
PATHS += Code/Event_Mediator
PATHS += Code/Event_Queue
PATHS += Code/Modules
PATHS += Code/Modules/Channels
PATHS += Code/Modules/Processors
PATHS += Code/Modules/Queue
PATHS += Code/System_Files

# Source, Dependency and Object file extensions
SOURCE_EXT = c
DEPS_EXT = h
OBJ_EXT = o

# Name of the target file
TARGET = program

# -----------------------------------------------------------------------------
# Rules and variables for rules start below this line.
# TODO:
#   1: Generate folder structure for output:
#       ./Output, ./Output/Object, ./Output/Bin
#   2: Store object files and bin file in its corresponding folder.

INCLUDE_PATHS = $(addprefix -I, $(PATHS))
DEPS = $(shell find . -type f -name '*.$(DEPS_EXT)')
SOURCE = $(shell find . -type f -name '*.$(SOURCE_EXT)')
OBJ = $(SOURCE:%.$(SOURCE_EXT)=%.$(OBJ_EXT))

# Linking object files to generate target:
# Generate $(TARGET): that depend on $(OBJ) files
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

# Compiling source files:
# Generate $(OBJ): with every $(OBJ_EXT): for every $(SOURCE_EXT) and $(DEPS)
$(OBJ): %.$(OBJ_EXT): %.$(SOURCE_EXT) $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@ $(INCLUDE_PATHS)


.PHONY: clean clean_all
# clean: remove all object files.
clean:
	rm $(OBJ)

# clean_all: remove all generated files.
clean_all:
	rm $(OBJ) $(TARGET)

# Rules and variables for rules end at this line.
# -----------------------------------------------------------------------------