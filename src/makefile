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
HDR = $(H)DisegnabileI.hpp $(H)utils.hpp $(H)Punto.hpp $(H)Direzione.hpp
#insieme di oggetti che vogliono essere lanciati (chiamati da main)
OBJ = Lista.o ListaClasse.o Punto.o utils.o Direzione.o ColoreRGB.o \
	Proiettile.o Fuel.o Navicella.o Bunker.o Pianeta.o SistemaSolare.o\
	visualePianeta.o visualeSistemaSolare.o Gioco.o main.o
# Controlli.o

all: sfml-app
#lancia l'app in automatico
	./$<

#cose utili
Lista.o: $(S)Lista.cpp $(H)Lista.hpp
	$(COMPILE)Lista.cpp

ListaClasse.o: $(S)ListaClasse.cpp $(H)Lista.hpp
	$(COMPILE)ListaClasse.cpp

Punto.o: $(S)Punto.cpp $(H)Punto.hpp
	$(COMPILE)Punto.cpp

utils.o: $(S)utils.cpp $(H)utils.hpp $(H)Punto.hpp
	$(COMPILE)utils.cpp

Direzione.o: $(S)Direzione.cpp $(HDR)
	$(COMPILE)Direzione.cpp

ColoreRGB.o: $(S)ColoreRGB.cpp $(H)ColoreRGB.hpp
	$(COMPILE)ColoreRGB.cpp

#oggetti del gioco
Proiettile.o: $(S)Proiettile.cpp $(H)Proiettile.hpp $(H)Direzione.hpp
	$(COMPILE)Proiettile.cpp

Fuel.o: $(S)Fuel.cpp $(H)Fuel.hpp $(HDR)
	$(COMPILE)Fuel.cpp

Navicella.o: $(S)Navicella.cpp $(H)Navicella.hpp $(HDR) $(H)Fuel.hpp
	$(COMPILE)Navicella.cpp

Bunker.o: $(S)Bunker.cpp $(H)Bunker.hpp $(H)ListaClasse.hpp
	$(COMPILE)Bunker.cpp

Pianeta.o: $(S)Pianeta.cpp $(HDR) $(H)Pianeta.hpp $(H)Fuel.hpp $(H)Bunker.hpp $(H)ListaClasse.hpp $(H)utils.hpp
	$(COMPILE)Pianeta.cpp

SistemaSolare.o: $(S)SistemaSolare.cpp $(H)SistemaSolare.hpp $(H)Pianeta.hpp $(H)ListaClasse.hpp $(H)utils.hpp
	$(COMPILE)SistemaSolare.cpp

#cose per gestire le varie visuali di gioco

visualePianeta.o: $(S)visualePianeta.cpp $(H)visualePianeta.hpp
	$(COMPILE)visualePianeta.cpp

visualeSistemaSolare.o: $(S)visualeSistemaSolare.cpp $(H)visualeSistemaSolare.hpp
	$(COMPILE)visualeSistemaSolare.cpp

Gioco.o: $(S)Gioco.cpp $(H)Gioco.hpp
	$(COMPILE)Gioco.cpp
#main
main.o: $(S)main.cpp $(H)Gioco.hpp $(H)Lista.hpp $(H)Punto.hpp
	$(COMPILE)main.cpp

sfml-app: $(OBJ)
#	linkiamo tutti gli object e la grafica SFML
	$(CC) $(OBJ) -o sfml-app $(LINK_SFML)

clean:
	rm -rf *.o sfml-app
