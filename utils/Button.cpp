#include "../header/Button.hpp"

//PRIVATA
void Button::settaFontTesto(void)
{
    //carico il font
    if (!this->font.loadFromFile(this->fontName))
    {
        std::cerr << "Error loading " << this->fontName << std::endl;
        return;
    }
    //setto il buttonText
    this->buttonText.setFont(this->font);
    this->buttonText.setCharacterSize(this->charSize);
    this->buttonText.setString(this->testo);
    this->buttonText.setPosition({this->getX()+this->dist, this->getY()});
}

//PUBBLICHE

//costruttore
//costruttore vuoto
Button::Button(void)
{
    //mantenendo tutto di default...
    this->settaFontTesto();
}
//altri costruttori
Button::Button(float x, float y, string testo)
{
    this->position.setCoord(x, y);
    this->testo = testo;
    //e il resto di default
    this->settaFontTesto();
}
Button::Button(float x, float y, string testo, float size)
{
    this->position.setCoord(x, y);
    this->testo = testo;
    this->width = size;
    this->height = size;
    //e il resto di default
    this->settaFontTesto();
}

Button::Button(float x, float y, string testo, float width, float height)
{
    this->position.setCoord(x, y);
    this->testo = testo;
    this->width = width;
    this->height = height;
    //e il resto di default
    this->settaFontTesto();
}

//setters
void Button::setChecked(bool checked)
{
    this->checked = checked;
}
void Button::setCharacterSize(int charSize)
{
    this->charSize = charSize;
    this->buttonText.setCharacterSize(this->charSize);
}
//... position
void Button::setX(float x)
{
    this->position.setX(x);
    this->buttonText.setPosition({this->getX(), this->getY()});
}
void Button::setY(float y)
{
    this->position.setY(y);
    this->buttonText.setPosition({this->getX(), this->getY()});
}
void Button::setPosition(float x, float y)
{
    this->position.setCoord(x, y);
    this->buttonText.setPosition({this->getX(), this->getY()});
}
void Button::setPosition(Punto position)
{
    this->position = position;
    this->buttonText.setPosition({this->getX(), this->getY()});
}
//... dimension
void Button::setWidth(float width)
{
    this->width = width;
}
void Button::setHeight(float height)
{
    this->height = height;
}
void Button::setDimensions(float width, float height)
{
    this->width = width;
    this->height = height;
}
//... colore
void Button::setColoreTesto(ColoreRGB coloreTesto)
{
    this->coloreTesto = coloreTesto;
}
void Button::setColoreSfondo(ColoreRGB coloreSfondo)
{
    this->coloreSfondo = coloreSfondo;
}
void Button::setColore(ColoreRGB coloreTesto, ColoreRGB coloreSfondo)
{
    this->setColoreTesto(coloreTesto);
    this->setColoreSfondo(coloreSfondo);
}
//... altri
void Button::setString(string testo)
{
    this->testo = testo;
    this->buttonText.setString(this->testo);
}
void Button::setFont(sf::Font)
{
    this->font = font;
    this->buttonText.setFont(this->font);
}
void Button::setFontByName(string fontName)
{
    this->fontName = fontName;
    //carico il font
    if (!this->font.loadFromFile(this->fontName))
    {
        std::cerr << "Error loading " << this->fontName << std::endl;
        return;
    }
    this->buttonText.setFont(this->font);
}
void Button::setText(sf::Text text)
{
    this->buttonText = text;
}

//getters
bool Button::getChecked(void)
{
    return this->checked;
}
int Button::getCharacterSize(void)
{
    return this->charSize;
}
//... position
float Button::getX(void)
{
    return this->position.getX();
}
float Button::getY(void)
{
    return this->position.getY();
}
//... dimension
float Button::getWidth(void)
{
    return this->width;
}
float Button::getHeight(void)
{
    return this->height;
}
ColoreRGB Button::getColoreTesto(void)
{
    return this->coloreTesto;
}
ColoreRGB Button::getColoreSfondo(void)
{
    return this->coloreSfondo;
}
string Button::getString(void)
{
    return this->testo;
}
sf::Font Button::getFont(void)
{
    return this->font;
}
sf::Text Button::getText(void)
{
    return this->buttonText;
}

//stampa
void Button::print(void)
{
    cout << "Bottone: {\n";
    cout << "testo = " << this->testo << endl;
    this->position.print();
    cout << ", widht = " << this->width;
    cout << ", height = " << this->height << endl;
    cout << "coloreTesto = ";
    this->coloreTesto.print();
    cout << "coloreSfondo = ";
    this->coloreSfondo.print();
    cout << "}\n";
}

//disegna
void Button::draw(sf::RenderWindow &window)
{
    //rettangolo
    sf::RectangleShape rettangolo(sf::Vector2f(this->width, this->height));
    rettangolo.setPosition({this->getX(), this->getY()});
    //setta un bordo di 10 all'interno del cerchio
    rettangolo.setOutlineThickness(-this->outlinesize);
    //colore del bordo giallo
    rettangolo.setOutlineColor(sf::Color::Black);
    if (!this->checked)
    {
        //se il rettangolo NON è checked è tutto normale...
        //... il rettangolo del colore di sfondo
        rettangolo.setFillColor(this->coloreSfondo.getColorLib());
        //... e il testo del colore del testo
#ifndef NON_FUNZIONA_FILL_COLOR
        this->buttonText.setFillColor(this->coloreTesto.getColorLib());
#endif
#ifdef NON_FUNZIONA_FILL_COLOR
        this->buttonText.setColor(this->coloreTesto.getColorLib());
#endif
    }
    else
    {
        //se il rettangolo è checked inverto i colori
        //il rettangolo del colore del testo ...
        rettangolo.setFillColor(this->coloreTesto.getColorLib());
        //... e il testo del colore dello sfondo
#ifndef NON_FUNZIONA_FILL_COLOR
        this->buttonText.setFillColor(this->coloreSfondo.getColorLib());
#endif
#ifdef NON_FUNZIONA_FILL_COLOR
        this->buttonText.setColor(this->coloreSfondo.getColorLib());
#endif
    }
    //e disegno
    window.draw(rettangolo);
    window.draw(this->buttonText);
}

//controlla se dentro
bool Button::checkMouse(Punto mouse) {
    return mouse.isNear(this->getX()+this->width/2, this->getY()+this->height/2, this->width/2, this->height/2);
}