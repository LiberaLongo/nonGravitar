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

#insieme di oggetti che vogliono essere lanciati (chiamati da main)
OBJ = Punto.o Lista.o definizioni.o


all: sfml-app
#lancia l'app in automatico
	./$<

Lista.o: $(S)Lista.cpp $(H)Lista.hpp
	$(COMPILE) $(S)Lista.cpp

definizioni.o: $(S)definizioni.cpp $(S)Lista.cpp
	$(COMPILE) $(S)definizioni.cpp

Punto.o: $(S)Punto.cpp $(H)Punto.hpp
	$(COMPILE) $(S)Punto.cpp

main.o: $(S)main.cpp $(H)Lista.hpp
	$(COMPILE) $(S)main.cpp

sfml-app: $(OBJ) main.o
#	g++ ... -o sfml-app $(LINK_SFML)
	g++ $(OBJ) main.o -o sfml-app

clean:
	rm -rf *.o sfml-app
