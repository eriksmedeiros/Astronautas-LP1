#include "comando.h"

void Comando::cadAstronauta(){
    
    std::string cpf, nome;
    int idade;

    std::cout << "Digite o CPF do Astronauta (000.000.000-00): ";
    std::cin >> cpf;

    // verificar se o cpf já existe
    for(auto& a : astronautas){
        if(a.getCpf() == cpf){
            std::cout << "CPF já cadastrado! Tente novamente." << std::endl;
            return;
        }
    }

    std::cout << "Digite o nome do Astronauta: ";
    std::cin >> nome;
    std::cout << "Digite a idade do Astronauta: ";
    std::cin >> idade;

    astronautas.push_back(Astronauta(cpf, nome, idade));
     
    std::cout << "Astronauta cadastrado com sucesso!" << std::endl;
}

void Comando::cadVoo(){
    int codigo;

    std::cout << "Digite o código do Voo: " << std::endl;
    std::cin >> codigo;

    for(auto& v : voos){
        if(v.getCodigo() == codigo){
            std::cout << "Voo já cadastrado! Tente novamente." << std::endl;
            return;
        }
    }

    voos.push_back(Voo(codigo));
    std::cout << "Voo" << codigo << "cadastrado com sucesso!" << std::endl;
}

void Comando::addAstronautaEmVoo(){
    int codigoVoo;
    std::string cpfAstro;

    std::cout << "Código do Voo: " << std::endl;
    std::cin >> codigoVoo;

    std::cout << "CPF do Astronauta: " << std::endl;
    std::cin >> cpfAstro;

    Astronauta* newAstro = nullptr;
    for(auto& a : astronautas){
        if(a.getCpf() == cpfAstro){
            newAstro = &a;
            break;
        }
    }

    if(newAstro == nullptr){
        std::cout << "Astronaura não encontrado." << std::endl;
        return;
    }

    Voo* newVoo = nullptr;
    for(auto& v : voos){
        if(v.getCodigo() == codigoVoo){

            if(v.getPlanejamento() == "planejamento"){
                newVoo = &v;
                v.setPassageiros(*newAstro);
                std::cout << "Astronauta adicionado com sucesso!" << std::endl;
                return;
            } else{
                std::cout << "Voo não está em fase de planejamento!" << std::endl;
            }
        }
    }

    if(newVoo == nullptr){
        std::cout << "Voo não encontrado!" << std::endl;
    }

}

void Comando::printVoosPlanejados()
{
    std::cout << ">>> Voos em Planejamento:" << std::endl;
    for (Voo v : voos)
    {
        if(v.getPlanejamento() == "planejamento")
        {
            std::cout << "> Id: " << v.getCodigo() << ", Passageiros: " << std::endl;
            v.getPassageiros();
            //printMembers(v.getMembers());
        }
    }
}