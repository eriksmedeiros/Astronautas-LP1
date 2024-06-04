#include "comando.h"

int main(){
    Voo voo;
    Comando gerencia;

    std::cout << "------------------ MENU PRINCIPAL ------------------ " << std::endl;
    std::cout << "|                                                    |"
                 "\n| 1 - Cadastrar Astronauta                           |" << std::endl;
    std::cout << "| 2 - Cadastrar Voo                                  |" << std::endl;
    std::cout << "| 3 - Adicionar astronauta em voo                    |" << std::endl;
    std::cout << "| 4 - Remover astronauta de voo                      |" << std::endl;
    std::cout << "| 5 - Listar voos                                    |" << std::endl;
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
            gerencia.cadAstronauta();
            break;
        case 2: 
            gerencia.cadVoo();
            break;
        case 3:
            gerencia.addAstronautaEmVoo();
            break;
        case 4:
            gerencia.rmvAstronautaDeVoo();
            break;
        case 5:
            gerencia.printVoosPlanejados();
            break;
        default:
            std::cout << "Opção inválida! Por favor, escolha uma opção válida." << std::endl;
            break;
        }
    }
     
    return 0;
}