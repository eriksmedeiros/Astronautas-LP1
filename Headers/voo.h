#ifndef VOO_H
#define VOO_H

#include "astronauta.h"

class Voo{
private:
    int codigo;
    std::vector<Astronauta> passageiros;
    std::string emPlanejamento;


public:
    //construtor
    Voo();
    Voo(int codigo);

    //métodos para código
    void setCodigo(int novoCodigo);
    int getCodigo();

    //métodos para passageiros
    void setPassageiros(Astronauta& astronauta);
    void rmvPassageiros(Astronauta& astro);
    std::vector<Astronauta> getPassageiros();

    std::string getPlanejamento();
};

#endif