CXX = g++
CXXFLAGS = -g -Wall
FLAGS = -g -Wall -o
ifeq ($(OS), Windows_NT)
    SHARED-LIB = liblab-07.dll
else
    SHARED-LIB = liblab-07.so
endif
TESTS_PATH = ../tests/
EXECUTABLE = main
BUILD_FOLDER_PATH = ../build/
LIBS_PATH = ./libs



build-lib:
	$(CXX) *.c -I$(LIBS_PATH) -shared -fPIC $(CXXFLAGS) -o $(BUILD_FOLDER_PATH)$(SHARED-LIB)

build-exe:
	$(CXX) *.c -I$(LIBS_PATH) $(CXXFLAGS) -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

run: build-exe
	
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)


move:
	cp $(SHARED-LIB) ../tests
