#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <iostream>
#include <string>
#include <vector>

class Astronauta{
    std::string cpf;
    std::string nome;
    int idade;

public:
    Astronauta();
    Astronauta(std::string cpf, std::string nome, int idade);

    ~Astronauta();

    void setCpf(std::string novoCpf);
    std::string getCpf();

    void setNome(std::string novoNome);
    std::string getNome();

    void setIdade(int novaIdade);
    int getIdade();
};
#endif