#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "./utils.hpp"
#include "./DisegnabileI.hpp"
#include "./Punto.hpp"
#include "./ColoreRGB.hpp"

extern float WIDTH, HEIGHT;

class Button : public DisegnabileI
{
private:
    bool checked = false; //se true "colora inversamente" testo e sfondo
    int charSize = 20;
    Punto position; //default (0,0)
    float width = WIDTH/2;
    float height = HEIGHT/8;
    ColoreRGB coloreTesto = ColoreRGB(LUMUS_MAXIMA, 0, 0); //rosso
    ColoreRGB coloreSfondo = ColoreRGB(LUMUS_MAXIMA, LUMUS_MAXIMA, LUMUS_MAXIMA); //bianco
    string testo = "";
    string fontName = "verdanab.ttf";
    sf::Font font;
    sf::Text buttonText;

private:
    void settaFontTesto(void);

public:
    //costruttore
    //costruttore vuoto
    Button(void);
    //altri costruttori
    Button(float x, float y, string testo);
    //non usato, ma simile
    Button(Punto centro, string testo);

    //distruttore
    virtual ~Button(void) {};

    //setters
    void setChecked(bool checked);
    void setCharacterSize(int charSize);
    //... position
    void setX(float x);
    void setY(float y);
    void setPosition(float x, float y);
    void setPosition(Punto position);
    //... dimension
    void setWidth(float width);
    void setHeight(float height);
    void setDimensions(float width, float height);
    //... colore
    void setColoreTesto(ColoreRGB coloreTesto);
    void setColoreSfondo(ColoreRGB coloreSfondo);
    void setColore(ColoreRGB coloreTesto, ColoreRGB coloreSfondo);
    //... altri
    void setString(string testo);
    void setFont(sf::Font font);
    void setFontByName(string fontName);
    void setText(sf::Text text);

    //getters
    bool getChecked(void);
    int getCharacterSize(void);
    //... position
    float getX(void);
    float getY(void);
    //... dimension
    float getWidth(void);
    float getHeight(void);
    //... colore
    ColoreRGB getColoreTesto(void);
    ColoreRGB getColoreSfondo(void);
    //... altri
    string getString(void);
    sf::Font getFont(void);
    sf::Text getText(void);
    
    //stampa
    void print(void);

    //disegna
    void draw(sf::RenderWindow &window);

    //controlla se dentro
    bool checkMouse(Punto mouse);
};

#endif //BUTTON_HPP
