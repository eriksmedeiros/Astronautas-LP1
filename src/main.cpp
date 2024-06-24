#include "../include/comando.h"

int main(){
    Comando* iniciar = new Comando;

    iniciar->escolhaMenu();

    delete iniciar;
     
    return 0;
}