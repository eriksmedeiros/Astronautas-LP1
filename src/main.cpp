#include "comando.h"

int main(){
    Comando* iniciar = new Comando;

    iniciar->menu();

    delete iniciar;
     
    return 0;
}