#system, window, graphics, network and audio
SYSTEM := -lsfml-system
WINDOW := -lsfml-window
GRAFICS := -lsfml-graphics
NETWORK := -lsfml-network
AUDIO := -lsfml-audio

#link all
LINK_SFML = $(SYSTEM) $(WINDOW) $(GRAFICS) $(NETWORK) $(AUDIO)

#cartelle progetto
H = ./header/
M = ./main/
S = ./src/
U = ./utils/

#comando per compilare
CC = g++
CFLAGS = -c -std=c++11
COMPILE = $(CC) $(CFLAGS)

#indieme di header molto usati
HDR = $(H)DisegnabileI.hpp $(H)utils.hpp $(H)Punto.hpp $(H)Direzione.hpp
#insieme di oggetti che vogliono essere lanciati (chiamati da main)
OBJ = ListaParent.o Lista.o Punto.o utils.o ColoreRGB.o \
	Direzione.o Proiettile.o Entity.o Fuel.o Navicella.o Bunker.o Pianeta.o SistemaSolare.o\
	visualePianeta.o visualeSistemaSolare.o Gioco.o main.o
# Controlli.o

all: sfml-app
#lancia l'app in automatico
	./$<

#cose utili (in ./utils)
ListaParent.o: $(U)ListaParent.cpp $(H)ListaParent.hpp
	$(COMPILE) $(U)ListaParent.cpp

Lista.o: $(U)Lista.cpp $(H)Lista.hpp
	$(COMPILE) $(U)Lista.cpp

Punto.o: $(U)Punto.cpp $(H)Punto.hpp
	$(COMPILE) $(U)Punto.cpp

utils.o: $(U)utils.cpp $(H)utils.hpp $(H)Punto.hpp
	$(COMPILE) $(U)utils.cpp

ColoreRGB.o: $(U)ColoreRGB.cpp $(H)ColoreRGB.hpp
	$(COMPILE) $(U)ColoreRGB.cpp

#oggetti del gioco (in ./src)
Direzione.o: $(S)Direzione.cpp $(HDR)
	$(COMPILE) $(S)Direzione.cpp

Proiettile.o: $(S)Proiettile.cpp $(H)Proiettile.hpp $(H)Direzione.hpp
	$(COMPILE) $(S)Proiettile.cpp

Entity.o: $(S)Entity.cpp $(H)Entity.hpp $(HDR) $(H)Lista.hpp $(H)Proiettile.hpp
	$(COMPILE) $(S)Entity.cpp

Fuel.o: $(S)Fuel.cpp $(H)Fuel.hpp $(HDR) $(H)ColoreRGB.hpp
	$(COMPILE) $(S)Fuel.cpp

Navicella.o: $(S)Navicella.cpp $(H)Navicella.hpp $(HDR) $(H)Entity.hpp $(H)Fuel.hpp $(H)Proiettile.hpp
	$(COMPILE) $(S)Navicella.cpp

Bunker.o: $(S)Bunker.cpp $(H)Bunker.hpp $(H)Entity.hpp $(H)Lista.hpp $(H)Proiettile.hpp
	$(COMPILE) $(S)Bunker.cpp

Pianeta.o: $(S)Pianeta.cpp $(HDR) $(H)Pianeta.hpp $(H)Fuel.hpp $(H)Bunker.hpp $(H)Lista.hpp $(H)utils.hpp
	$(COMPILE) $(S)Pianeta.cpp

SistemaSolare.o: $(S)SistemaSolare.cpp $(H)SistemaSolare.hpp $(H)Pianeta.hpp $(H)Lista.hpp $(H)utils.hpp $(H)Navicella.hpp
	$(COMPILE) $(S)SistemaSolare.cpp

#cose per gestire le varie visuali di gioco (in ./main)

visualePianeta.o: $(M)visualePianeta.cpp $(H)visualePianeta.hpp $(H)cScreen.hpp $(H)utils.hpp $(H)SistemaSolare.hpp
	$(COMPILE) $(M)visualePianeta.cpp

visualeSistemaSolare.o: $(M)visualeSistemaSolare.cpp $(H)visualeSistemaSolare.hpp $(H)cScreen.hpp $(H)Navicella.hpp $(H)SistemaSolare.hpp
	$(COMPILE) $(M)visualeSistemaSolare.cpp

Gioco.o: $(M)Gioco.cpp $(H)Gioco.hpp $(H)visualeSistemaSolare.hpp $(H)visualePianeta.hpp
	$(COMPILE) $(M)Gioco.cpp

main.o: $(M)main.cpp $(H)Gioco.hpp $(H)Lista.hpp $(H)Punto.hpp
	$(COMPILE) $(M)main.cpp

sfml-app: $(OBJ)
#	linkiamo tutti gli object e la grafica SFML
	$(CC) $(OBJ) -o sfml-app $(LINK_SFML)

clean:
	rm -rf *.o sfml-app
