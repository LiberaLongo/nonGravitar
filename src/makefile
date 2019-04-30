#system, window, graphics, network and audio
SYSTEM := -lsfml-system
WINDOW := -lsfml-window
GRAFICS := -lsfml-graphics
NETWORK := -lsfml-network
AUDIO := -lsfml-audio

#link all
LINK_SFML =  $(SYSTEM) $(WINDOW) $(GRAFICS) $(NETWORK) $(AUDIO)

#cartelle progetto
S = ./src/
H = ../header/
U = ../utils/

all: sfml-app
#lancia l'app in automatico
	./$<

List.o: $(U)Lista.cpp $(U)Lista.hpp
	g++ -c Lista.cpp

main.o: $(S)main.cpp $(U)Lista.hpp
	g++ -c main.cpp

#sfml-app: main.o
#	g++ main.o -o sfml-app $(LINK_SFML)

clean:
	rm -rf *.o sfml-app
