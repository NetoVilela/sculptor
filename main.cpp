#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Sculptor.h"
#include "Interpretador.h"


using namespace std;

int main()
{

    Sculptor *sculptor;
    Interpretador parser;
    vector<FiguraGeometrica*> figuras;

    figuras = parser.parse("sculptor.txt");

    sculptor = new Sculptor(parser.getDx(), parser.getDy(), parser.getDz());

    for(size_t i = 0; i < figuras.size(); i++){
        figuras[i] -> draw(*sculptor);
    }

    sculptor -> writeOFF((char*)"sculptor.off");

    for(size_t i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }

    delete sculptor;
    return 0;

}
