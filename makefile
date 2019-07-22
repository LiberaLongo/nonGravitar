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
LINK = g++
CFLAGS = -c -std=c++11
COMPILE = $(CC) $(CFLAGS)

#indieme di header molto usati
HDR = $(H)DisegnabileI.hpp $(H)utils.hpp $(H)Punto.hpp $(H)Direzione.hpp
#insieme di oggetti che vogliono essere lanciati (chiamati da main)
OBJ = ListaParent.o Lista.o Punto.o utils.o ColoreRGB.o Direzione.o Poligono.o\
	Proiettile.o Entity.o Fuel.o Navicella.o Bunker.o Pianeta.o SistemaSolare.o\
	visualeMenu.o visualeSistemaSolare.o visualePianeta.o Gioco.o main.o
# Controlli.o

all: app
#lancia l'app in automatico
	./$<

#cose utili (in ./utils)
ListaParent.o: $(U)ListaParent.cpp $(H)ListaParent.hpp
	$(COMPILE) $(U)ListaParent.cpp -o ListaParent.o

Lista.o: $(U)Lista.cpp $(H)Lista.hpp
	$(COMPILE) $(U)Lista.cpp -o Lista.o

Punto.o: $(U)Punto.cpp $(H)Punto.hpp
	$(COMPILE) $(U)Punto.cpp -o Punto.o

utils.o: $(U)utils.cpp $(H)utils.hpp $(H)Punto.hpp
	$(COMPILE) $(U)utils.cpp -o utils.o

ColoreRGB.o: $(U)ColoreRGB.cpp $(H)ColoreRGB.hpp
	$(COMPILE) $(U)ColoreRGB.cpp -o ColoreRGB.o

Direzione.o: $(U)Direzione.cpp $(HDR)
	$(COMPILE) $(U)Direzione.cpp -o Direzione.o

Poligono.o: $(U)Poligono.cpp $(H)Poligono.hpp $(HDR) $(H)ColoreRGB.hpp $(U)ListaParent.cpp
	$(COMPILE) $(U)Poligono.cpp -o Poligono.o

#oggetti del gioco (in ./src)

Proiettile.o: $(S)Proiettile.cpp $(H)Proiettile.hpp $(H)Direzione.hpp
	$(COMPILE) $(S)Proiettile.cpp -o Proiettile.o

Entity.o: $(S)Entity.cpp $(H)Entity.hpp $(HDR) $(H)Lista.hpp $(H)Proiettile.hpp $(U)ListaParent.cpp
	$(COMPILE) $(S)Entity.cpp -o Entity.o

Fuel.o: $(S)Fuel.cpp $(H)Fuel.hpp $(HDR) $(H)ColoreRGB.hpp
	$(COMPILE) $(S)Fuel.cpp -o Fuel.o

Navicella.o: $(S)Navicella.cpp $(H)Navicella.hpp $(HDR) $(H)Entity.hpp $(H)Fuel.hpp $(H)Proiettile.hpp
	$(COMPILE) $(S)Navicella.cpp -o Navicella.o

Bunker.o: $(S)Bunker.cpp $(H)Bunker.hpp $(H)Entity.hpp $(H)Lista.hpp $(H)Proiettile.hpp
	$(COMPILE) $(S)Bunker.cpp -o Bunker.o

Pianeta.o: $(S)Pianeta.cpp $(HDR) $(H)Pianeta.hpp $(H)Fuel.hpp $(H)Bunker.hpp $(H)Poligono.hpp $(H)Lista.hpp $(H)utils.hpp $(U)ListaParent.cpp
	$(COMPILE) $(S)Pianeta.cpp -o Pianeta.o

SistemaSolare.o: $(S)SistemaSolare.cpp $(H)SistemaSolare.hpp $(H)Pianeta.hpp $(H)Lista.hpp $(H)utils.hpp $(H)Navicella.hpp $(U)ListaParent.cpp
	$(COMPILE) $(S)SistemaSolare.cpp -o SistemaSolare.o

#cose per gestire le varie visuali di gioco (in ./main)

visualeMenu.o: $(M)visualeMenu.cpp $(H)visualeMenu.hpp $(H)cScreen.hpp $(H)SistemaSolare.hpp
	$(COMPILE) $(M)visualeMenu.cpp -o visualeMenu.o

visualeSistemaSolare.o: $(M)visualeSistemaSolare.cpp $(H)visualeSistemaSolare.hpp $(H)cScreen.hpp $(H)Navicella.hpp $(H)SistemaSolare.hpp
	$(COMPILE) $(M)visualeSistemaSolare.cpp -o visualeSistemaSolare.o

visualePianeta.o: $(M)visualePianeta.cpp $(H)visualePianeta.hpp $(H)cScreen.hpp $(H)SistemaSolare.hpp
	$(COMPILE) $(M)visualePianeta.cpp -o visualePianeta.o

Gioco.o: $(M)Gioco.cpp $(H)Gioco.hpp $(H)visualeSistemaSolare.hpp $(H)visualePianeta.hpp
	$(COMPILE) $(M)Gioco.cpp -o Gioco.o

main.o: $(M)main.cpp $(H)Gioco.hpp $(H)Lista.hpp $(H)Punto.hpp
	$(COMPILE) $(M)main.cpp -o main.o

#link all into an executable
app: $(OBJ)
#	linkiamo tutti gli object e la grafica SFML
	$(LINK) $(OBJ) -o app $(LINK_SFML)

#clean target
.PHONY: clean

clean:
	rm -rf *.o app
