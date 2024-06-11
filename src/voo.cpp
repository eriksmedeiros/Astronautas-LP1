#include "voo.h"

//implementação do construtor
Voo::Voo() : codigo(0), passageiros() {}

Voo::Voo(int codigo) 
    : codigo(codigo), status("planejamento"){}

//implementação de metodos para o atributo codigo
void Voo::setCodigo(int novoCodigo){
    codigo = novoCodigo;
}

int Voo::getCodigo(){
    return codigo;
}

//implementação de metodos para o atributo passageiros

/*const std::vector<Astronauta> &Voo::getPassageiros() const {
    return passageiros;
}*/

void Voo::setPassageiros(Astronauta& astronauta){  
    passageiros.push_back(astronauta);
}

void Voo::rmvPassageiros(Astronauta& astro) {
    auto it = std::remove_if(passageiros.begin(), passageiros.end(),
                                [&astro](Astronauta& a) { return a.getCpf() == astro.getCpf(); });
    if (it != passageiros.end()) {
        passageiros.erase(it, passageiros.end());
    }
}

std::vector<Astronauta> Voo::getPassageiros(){
    return passageiros;
}

void Voo::printPassageiros(){
    std::vector<Astronauta>::size_type i;
    for(i = 0 ; i < passageiros.size(); i++){
        std::cout << passageiros[i].getCpf() << " " << passageiros[i].getNome() << " " << passageiros[i].getIdade() << std::endl;
    }
    std::cout << std::endl << std::endl;
}

std::string Voo::getStatus(){
    return status;
}

void Voo::setStatus(std::string newStatus){
    status = newStatus;
}

