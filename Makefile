CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC = src/Lik.cpp src/main.cpp
OBJ = $(SRC:src/%.cpp=build/%.o)
TARGET = borba

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

build/%.o: src/%.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build $(TARGET)
