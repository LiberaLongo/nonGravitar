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
OBJ = Punto.o Lista.o ListaClasse.o definizioni.o Navicella.o Gioco.o


all: sfml-app
#lancia l'app in automatico
	./$<

Lista.o: $(S)Lista.cpp $(H)Lista.hpp
	$(COMPILE) $(S)Lista.cpp

ListaClasse.o: $(S)ListaClasse.cpp $(H)Lista.hpp
	$(COMPILE) $(S)ListaClasse.cpp

definizioni.o: $(S)definizioni.cpp $(S)Lista.cpp
	$(COMPILE) $(S)definizioni.cpp

Punto.o: $(S)Punto.cpp $(H)Punto.hpp
	$(COMPILE) $(S)Punto.cpp

Navicella.o: $(S)Navicella.cpp $(H)Navicella.hpp
	$(COMPILE) $(S)Navicella.cpp

Gioco.o: $(S)Gioco.cpp $(H)Gioco.hpp
	$(COMPILE) $(S)Gioco.cpp

main.o: $(S)main.cpp $(H)Gioco.hpp $(H)Lista.hpp $(H)Punto.hpp
	$(COMPILE) $(S)main.cpp

sfml-app: $(OBJ) main.o
#	linkiamo tutti gli object e la grafica SFML
	g++ $(OBJ) main.o -o sfml-app $(LINK_SFML)

clean:
	rm -rf *.o sfml-app
