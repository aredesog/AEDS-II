#include <iostream>

using namespace std;

int main(){

    int d = 10;
    int* pont = &d;

    printf("%d\n", *pont); 
    /* 
    d é uma variavel com valor atribuido, se no houver a declaração no printf com &d(isso resulta no endereço da variavel apenas)
    agora a declaração do *pont ou o d(resulta no valor da variavel d) 
    */

    int* outroPont = pont; 

    printf("%d\n", *outroPont);
    /*
    A declaração de outro ponteiro que se da o valor de outro ponteiro, ou seja um aponta para o outro, e dessa forma, se faz os pornteiros
    de ponteiros, assim como se é feito nas matrizes.
    */
}