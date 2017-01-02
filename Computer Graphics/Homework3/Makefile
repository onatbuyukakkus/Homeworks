SRC = Camera.cpp Color.cpp Image.cpp main.cpp Model.cpp Scene.cpp Triangle.cpp Vector3.cpp Vertex.cpp 

CPPFLAGS = -std=c++11 -O3

OBJ = $(SRC:.cpp=.o)

.cpp.o:
		g++ -c $< $(CPPFLAGS)

all: test



test: $(OBJ) 
		g++ $(OBJ) -o rasterizer $(CPPFLAGS)

clean:
		rm -f *.o rasterizer *.ppm
