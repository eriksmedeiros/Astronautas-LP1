#ifndef SISTEMA_ESPACIAL_H
#define SISTEMA_ESPACIAL_H

#include "voo.h"

class Comando{
private:
    std::vector<Astronauta> astronautas;
    std::vector<Voo> voos;

public:
    std::vector<Voo> getVoosCadastrados();


    void cadAstronauta();

    void cadVoo();

    void addAstronautaEmVoo();

    void rmvAstronautaDeVoo();

    void lancarVoo();

    void printVoosPlanejados();

    void printVoosEmCurso();

    void printVoosFinalizados();

    void explodirVoo();

    void finalizarVoo();

    void filtrarMortos(Astronauta astro);

    void printAstroMortos();
    
    void menu();

    void escolhaMenu();

    void limparTela();
};

#endif