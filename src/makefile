#system, window, graphics, network and audio
SYSTEM := -lsfml-system
WINDOW := -lsfml-window
GRAFICS := -lsfml-graphics
NETWORK := -lsfml-network
AUDIO := -lsfml-audio

#link all
LINK_SFML = $(SYSTEM) $(WINDOW) $(GRAFICS) $(NETWORK) $(AUDIO)

#cartelle progetto
S = ./
H = ../header/

#comando per compilare
CC = g++
CFLAGS = -c -std=c++11
COMPILE = $(CC) $(CFLAGS) $(S)

#indieme di header molto usati
HDR = $(H)DisegnabileI.hpp $(H)utils.hpp $(H)Punto.hpp
#insieme di oggetti che vogliono essere lanciati (chiamati da main)
OBJ = Lista.o ListaClasse.o Punto.o utils.o Direzione.o Fuel.o Navicella.o Gioco.o main.o
# Controlli.o

all: sfml-app
#lancia l'app in automatico
	./$<
Lista.o: $(S)Lista.cpp $(H)Lista.hpp
	$(COMPILE)Lista.cpp

ListaClasse.o: $(S)ListaClasse.cpp $(H)Lista.hpp
	$(COMPILE)ListaClasse.cpp

Punto.o: $(S)Punto.cpp $(H)Punto.hpp
	$(COMPILE)Punto.cpp

utils.o: $(S)utils.cpp $(H)utils.hpp $(H)Punto.hpp
	$(COMPILE)utils.cpp

Direzione.o: $(S)Direzione.cpp $(H)Direzione.hpp $(HDR)
	$(COMPILE)Direzione.cpp

Fuel.o: $(S)Fuel.cpp $(H)Fuel.hpp $(HDR)
	$(COMPILE)Fuel.cpp

#include "../header/Gioco.hpp"
Navicella.o: $(S)Navicella.cpp $(H)Navicella.hpp $(HDR) $(H)Direzione.hpp $(H)Fuel.hpp
	$(COMPILE)Navicella.cpp

#pianeta

#Controlli.o: $(S)Controlli.cpp $(H)Controlli.hpp
#	$(COMPILE)Controlli.cpp

Gioco.o: $(S)Gioco.cpp $(H)Gioco.hpp
	$(COMPILE)Gioco.cpp

main.o: $(S)main.cpp $(H)Gioco.hpp $(H)Lista.hpp $(H)Punto.hpp
	$(COMPILE)main.cpp

sfml-app: $(OBJ)
#	linkiamo tutti gli object e la grafica SFML
	$(CC) $(OBJ) -o sfml-app $(LINK_SFML)

clean:
	rm -rf *.o sfml-app
