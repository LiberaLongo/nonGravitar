#include "../header/ColoreRGB.hpp"

//costruttore vuoto
ColoreRGB::ColoreRGB(void)
{
    //tutto di default
}
//costruttore completo
ColoreRGB::ColoreRGB(int red, int green, int blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

//setters
void ColoreRGB::setRed(int red)
{
    this->red = red;
}
void ColoreRGB::setGreen(int green)
{
    this->green = green;
}
void ColoreRGB::setBlue(int blue)
{
    this->blue = blue;
}
void ColoreRGB::setRGB(int red, int green, int blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

//getters
int ColoreRGB::getRed(void)
{
    return this->red;
}
int ColoreRGB::getGreen(void)
{
    return this->green;
}
int ColoreRGB::getBlue(void)
{
    return this->blue;
}

//stampa
void ColoreRGB::print(void)
{
    cout << "( " << this->red << ", " << this->green << ", " << this->blue << " )";
}

sf::Color ColoreRGB::getColorLib(void)
{
    return sf::Color(this->getRed(), this->getGreen(), this->getBlue());
}
