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
    std::cout << "Voo " << codigo << " cadastrado com sucesso!" << std::endl;
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
            if(a.getStatus()){
                newAstro = &a;
                break;
            } else{
                std::cout << "Astronauta não está disponível!" << std::endl;
            }
        }
    }

    if(newAstro == nullptr){
        std::cout << "Astronauta não encontrado." << std::endl;
        return;
    }

    Voo* newVoo = nullptr;
    for(auto& v : voos){
        if(v.getCodigo() == codigoVoo){

            if(v.getStatus() == "planejamento"){
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

void Comando::rmvAstronautaDeVoo(){
    int codigoVoo;
    std::string cpfAstro;

    std::cout << "Código do Voo: " << std::endl;
    std::cin >> codigoVoo;

    std::cout << "CPF do Astronauta: " << std::endl;
    std::cin >> cpfAstro;

    Voo* thisVoo = nullptr;
    for(auto& v : voos){
        if(v.getCodigo() == codigoVoo){
            if(v.getStatus() == "planejamento"){
                thisVoo = &v;
                break;
            } else{
                std::cout << "Voo não está em fase de planejamento!" << std::endl;
                return;
            }
        }
    }

     if(thisVoo == nullptr){
        std::cout << "Voo não encontrado!" << std::endl;
        return;
    }

    Astronauta* endAstro = nullptr;
    for(auto& a : thisVoo->getPassageiros()){
        
        if(a.getCpf() == cpfAstro){
            endAstro = &a;
            thisVoo->rmvPassageiros(*endAstro);
            std::cout << "Astronauta removido com sucesso!" << std::endl;
            return;
        }
    }

     if(endAstro == nullptr){
        std::cout << "Astronauta não encontrado." << std::endl;
        return;
    }

}

void Comando::lancarVoo(){
    int codigoVoo;

    std::cout << "Código do voo: " << std::endl;
    std::cin >> codigoVoo;

    Voo *voo = nullptr;
    for(auto& v : voos){
        if(v.getCodigo() == codigoVoo){
            if(v.getStatus() == "planejamento"){
                voo = &v;
                break;
            } else{
                std::cout << "Voo não está em fase de planejamento!" << std::endl;
                return;
            }
        }
    } 

    if(voo == nullptr){
        std::cout << "Voo não encontrado!" << std::endl;
        return;
    }


    if(voo->getPassageiros().empty()){
        std::cout << "Não é possível lançar o voo " << codigoVoo << ". Não há astronautas no voo.\n";
        return;
    }

    for(auto& a : voo->getPassageiros()){
        if(!a.getStatus()){
            std::cout << "Não é possível lançar o voo " << codigoVoo << ". Astronauta " << a.getNome() << " não está disponível.\n";
            return;
        }
    }

    voo->setStatus("Em curso");
    for (auto& a : voo->getPassageiros()){
        a.setStatus();
    }

    std::cout << "Voo " << codigoVoo << " lançado com sucesso!\n";
}


void Comando::printVoosPlanejados()
{
    std::cout << ">>> Voos em Planejamento:" << std::endl;
    for (Voo v : voos)
    {
        if(v.getStatus() == "planejamento")
        {
            std::cout << "> Id: " << v.getCodigo() << ", Passageiros: " << std::endl;
            v.printPassageiros();
            //printMembers(v.getMembers());
        }
    }
}

void Comando::menu(){
    std::cout << "------------------ MENU PRINCIPAL ------------------ " << std::endl;
    std::cout << "|                                                    |"
                 "\n| 1 - Cadastrar Astronauta                           |" << std::endl;
    std::cout << "| 2 - Cadastrar Voo                                  |" << std::endl;
    std::cout << "| 3 - Adicionar astronauta em voo                    |" << std::endl;
    std::cout << "| 4 - Remover astronauta de voo                      |" << std::endl;
    std::cout << "| 5 - Lançar voo                                     |" << std::endl;
    std::cout << "| 6 - Listar voos                                    |" << std::endl;
    std::cout << "| 0 - Sair                                           |" << std::endl;

    
    int escolha = -1;
    while(escolha != 0){

        std::cout << "Escolha: ";
        std::cin >> escolha;

        switch (escolha)
        {
        case 0:
            std::cout << "Saindo do programa..." << std::endl;
            break;
        case 1:
            cadAstronauta();
            break;
        case 2: 
            cadVoo();
            break;
        case 3:
            addAstronautaEmVoo();
            break;
        case 4:
            rmvAstronautaDeVoo();
            break;
        case 5:
            lancarVoo();
            break;
        case 6:
            printVoosPlanejados();
            break;
        default:
            std::cout << "Opção inválida! Por favor, escolha uma opção válida." << std::endl;
            break;
        }
    }
}