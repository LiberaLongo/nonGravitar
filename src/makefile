#system, window, graphics, network and audio
SYSTEM := -lsfml-system
WINDOW := -lsfml-window
GRAFICS := -lsfml-graphics
NETWORK := -lsfml-network
AUDIO := -lsfml-audio

#link all
LINK_SFML =  $(SYSTEM) $(WINDOW) $(GRAFICS) $(NETWORK) $(AUDIO)

#cartelle progetto
S = ./
H = ../header/

#comando per compilare
COMPILE = g++ -c

all: sfml-app
#lancia l'app in automatico
	./$<

Lista.o: $(S)Lista.cpp $(H)Lista.hpp
	$(COMPILE) $(S)Lista.cpp

main.o: $(S)main.cpp $(H)Lista.hpp
	$(COMPILE) $(S)main.cpp

sfml-app: Lista.o main.o
#	g++ main.o -o sfml-app $(LINK_SFML)
	g++ main.o -o sfml-app

clean:
	rm -rf *.o sfml-app
