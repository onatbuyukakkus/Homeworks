SRC = Camera.cpp Color.cpp Image.cpp main.cpp Material.cpp Mesh.cpp PointLight.cpp Scene.cpp Triangle.cpp Vector3.cpp Vertex.cpp 

CPPFLAGS = -std=c++11 -O3 -lGLEW -lGL -lglut -lGLU

OBJ = $(SRC:.cpp=.o)

.cpp.o:
		g++ -c $< $(CPPFLAGS)

all: test



test: $(OBJ) 
		g++ $(OBJ) -o hw4 $(CPPFLAGS)

clean:
		rm -f *.o hw4 *.ppm