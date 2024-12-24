CXX       = clang++
CXXFLAGS  = -std=c++17 -I/opt/homebrew/include -Wall -Wextra
LDFLAGS   = -L/opt/homebrew/lib -lSDL2 -lSDL2_image

SRC       = $(wildcard src/engine/**/*.cpp src/*.cpp)
OBJ       = $(SRC:.cpp=.o)
TARGET    = PixelEngine

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)