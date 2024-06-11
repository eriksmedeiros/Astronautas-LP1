#include "astronauta.h"

Astronauta::Astronauta() : cpf(""), nome(""), idade(0) {}

Astronauta::Astronauta(std::string cpf, std::string nome, int idade){
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->status = true;
}

Astronauta::~Astronauta(){}

void Astronauta::setCpf(std::string novoCpf){
    cpf = novoCpf;
}

std::string Astronauta::getCpf(){
    return cpf;
}

void Astronauta::setNome(std::string novoNome){
    nome = novoNome;
}

std::string Astronauta::getNome(){
    return nome;
}

void Astronauta::setIdade(int novaIdade){
    idade = novaIdade;
}

int Astronauta::getIdade(){
    return idade;
}

int Astronauta::getStatus(){
    return status;
}

void Astronauta::setStatus(){
    status = false;
}