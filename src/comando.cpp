#include "../include/comando.h"

void Comando::cadAstronauta(){
    
    std::string cpf, nome;
    int idade;

    std::cout << "Digite o CPF do Astronauta: ";
    std::cin >> cpf;

    // verificar se o cpf já existe
    for(auto& a : astronautas){
        if(a.getCpf() == cpf){
            std::cout << "CPF já cadastrado! Tente novamente." << std::endl;
            return;
        }
    }

    std::cin.ignore();

    std::cout << "Digite o nome do Astronauta: ";
    std::getline(std::cin, nome);
    std::cout << "Digite a idade do Astronauta: ";
    std::cin >> idade;

    astronautas.push_back(Astronauta(cpf, nome, idade));
     
    std::cout << "Astronauta cadastrado com sucesso!" << std::endl;
}

void Comando::cadVoo(){
    int codigo;

    std::cout << "Digite o código do Voo: ";
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

    std::cout << "CPF do Astronauta: ";
    std::cin >> cpfAstro;

    Astronauta* newAstro = nullptr;
    for(auto& a : astronautas){
        if(a.getCpf() == cpfAstro){
            if(a.getStatus() == "On"){
                newAstro = &a;
                break;
            } else{
                std::cout << "Astronauta não está disponível!" << std::endl;
                return;
            }
        }
    }

    if(newAstro == nullptr){
        std::cout << "Astronauta não encontrado." << std::endl;
        return;
    }

    std::cout << "Código do Voo: ";
    std::cin >> codigoVoo;

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
                return;
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

    std::cout << "Código do Voo: ";
    std::cin >> codigoVoo;

    std::cout << "CPF do Astronauta: ";
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

    std::cout << "Código do voo: ";
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

        for(auto& astro : astronautas){

            if(astro.getStatus() != "On"){
                std::cout << "Não é possível lançar o voo " << codigoVoo << ". Astronauta " << a.getNome() << " não está disponível.\n";
                return;
            }

            if(a.getCpf() == astro.getCpf()){
                astro.setStatus("off");
            }
        }
    }

    voo->lancamento();
}

void Comando::explodirVoo(){
    int codigoVoo;

    std::cout << "Código do voo: ";
    std::cin >> codigoVoo;

    Voo *voo = nullptr;
    for(auto& v : voos){
        if(v.getCodigo() == codigoVoo){
            if(v.getStatus() == "curso"){
                voo = &v;
                break;
            } else{
                std::cout << "Voo não está em curso!" << std::endl;
                return;
            }
        }
    } 

    if(voo == nullptr){
        std::cout << "Voo não encontrado!" << std::endl;
        return;
    }

    for(auto& a : voo->getPassageiros()){
        for(auto& astro : astronautas){
            if(a.getCpf() == astro.getCpf()){
                astro.setStatus("morto");
            }
        }
    }

    voo->explosao();
}

void Comando::finalizarVoo(){
    int codigoVoo;

    std::cout << "Código do voo: ";
    std::cin >> codigoVoo;

    Voo *voo = nullptr;
    for(auto& v : voos){
        if(v.getCodigo() == codigoVoo){
            if(v.getStatus() == "curso"){
                voo = &v;
                break;
            } else{
                std::cout << "Voo não está em curso!" << std::endl;
                return;
            }
        }
    } 

    if(voo == nullptr){
        std::cout << "Voo não encontrado!" << std::endl;
        return;
    }

    for(auto& a : voo->getPassageiros()){
        for(auto& astro : astronautas){
                if(a.getCpf() == astro.getCpf()){
                    astro.setStatus("On");
                }
            }
    }

    voo->finalizar();
}

void Comando::printVoosPlanejados()
{
    std::cout << "Voos em Planejamento:" << std::endl;
    for(auto&v : voos){
        if(v.getStatus() == "planejamento") {
            std::cout << "Código do voo: " << v.getCodigo() << std::endl;
            std::cout << "Astronautas a bordo:" << std::endl;
            std::cout << " C P F   -   N o m e   -   I d a d e   -   S t a t u s" << std::endl;
            for(auto& a : v.getPassageiros()){
                std::cout << " " << a.getCpf() << "       " << a.getNome() << "       " << a.getIdade() << "       " << a.getStatus() << std::endl;
                std::cout << std::endl;            
            }
        }
    }
}

void Comando::printVoosEmCurso(){
    std::cout << "Voos em Curso:" << std::endl;
    for(auto&v : voos){
        if(v.getStatus() == "curso") {
            std::cout << "Código do voo: " << v.getCodigo() << std::endl;
            std::cout << "Astronautas a bordo:" << std::endl;
            std::cout << " C P F   -   N o m e   -   I d a d e   -   S t a t u s" << std::endl;
            for(auto& a : v.getPassageiros()){
                std::cout << " " << a.getCpf() << "       " << a.getNome() << "       " << a.getIdade() << "       " << a.getStatus() << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

void Comando::printVoosFinalizados(){
    std::cout << "Voos finalizados:" << std::endl;
    for(auto&v : voos){
        if(v.getStatus() == "finalizado"){
            std::cout << "Código do voo: " << v.getCodigo() << std::endl;
            std::cout << "Status: " << v.getStatus() << std::endl;
            std::cout << "Astronautas a bordo:" << std::endl;
            std::cout << " C P F   -   N o m e   -   I d a d e   -   S t a t u s" << std::endl;
            for(auto& a : v.getPassageiros()){
                std::cout << " " << a.getCpf() << "       " << a.getNome() << "       " << a.getIdade() << "       " << a.getStatus() << std::endl;
                std::cout << std::endl;

            }
        } else if(v.getStatus() == "explodiu"){
            std::cout << "Código do voo: " << v.getCodigo() << std::endl;
            std::cout << "Status: " << v.getStatus() << std::endl;
            std::cout << "Astronautas a bordo:" << std::endl;
            std::cout << " C P F   -   N o m e   -   I d a d e   -   S t a t u s" << std::endl;
            for(auto& a : v.getPassageiros()){
                std::cout << " " << a.getCpf() << "       " << a.getNome() << "       " << a.getIdade() << "       " << a.getStatus() << std::endl;
                std::cout << std::endl;
            }
        }
    }
}

void Comando::filtrarMortos(Astronauta astro){
    bool found = false;
    for(auto& v : voos){    
        for(auto& a : v.getPassageiros()){
            if(astro.getCpf() == a.getCpf()){
                if(!found){
                    std::cout << "Voos que participou: " << std::endl;
                    found = true; 
                }
                std::cout << " " << v.getCodigo() << std::endl;
            }
        }
    }
    if(!found){
        std::cout << " Nenhum voo encontrado." << std::endl;       
    }
}

void Comando::printAstroMortos(){
    std::cout << "Astronautas Mortos:" << std::endl;
    std::cout << " C P F   -   N o m e   -   I d a d e   -   S t a t u s" << std::endl;

    for(auto& a : astronautas){
        if(a.getStatus() == "morto"){
            std::cout << " " << a.getCpf() << "       " << a.getNome() << "       " << a.getIdade() << "       " << a.getStatus() << std::endl;
            std::cout << std::endl;
            filtrarMortos(a);
            std::cout << std::endl;
        }
    }
}

void Comando::limparTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Comando::menu(){
    std::cout << " ----------------- MENU PRINCIPAL -------------------" << std::endl;
    std::cout << "| 1 - Cadastrar Astronauta                           |" << std::endl;
    std::cout << "| 2 - Cadastrar Voo                                  |" << std::endl;
    std::cout << "| 3 - Adicionar astronauta em voo                    |" << std::endl;
    std::cout << "| 4 - Remover astronauta de voo                      |" << std::endl;
    std::cout << "| 5 - Lançar voo                                     |" << std::endl;
    std::cout << "| 6 - Explodir voo                                   |" << std::endl;
    std::cout << "| 7 - Finalizar voo                                  |" << std::endl;
    std::cout << "| 8 - Listar voos planejados                         |" << std::endl;
    std::cout << "| 9 - Listar voos em curso                           |" << std::endl;
    std::cout << "| 10 - Listar voos finalizados                       |" << std::endl;
    std::cout << "| 11 - Listar astronautas mortos                     |" << std::endl;
    std::cout << "| 0 - Sair                                           |" << std::endl;
    std::cout << " --------------------------------------------------- " << std::endl;
}

void Comando::escolhaMenu(){
    int escolha = -1;
    while(escolha != 0){

        menu();

        std::cout << "Escolha: ";
        std::cin >> escolha;
        limparTela();

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
            explodirVoo();
            break;
        case 7:
            finalizarVoo();
            break;
        case 8:
            printVoosPlanejados();
            break;
        case 9:
            printVoosEmCurso();
            break;
        case 10:
            printVoosFinalizados();
            break;
        case 11:
            printAstroMortos();
            break;
        default:
            std::cout << "Opção inválida! Por favor, escolha uma opção válida." << std::endl;
            break;
        }
    }
}