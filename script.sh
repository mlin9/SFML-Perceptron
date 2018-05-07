g++ -std=c++11 -c *.cpp;
g++ main.o nnetwork.o node.o nnetwork_field.o environment.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system;
