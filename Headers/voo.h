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
    // bool getAstronauta(const Astronaura)
    void setPassageiros(Astronauta& astronauta);
    std::vector<Astronauta> getPassageiros();

    std::string getPlanejamento();
};

#endif