#include <iostream>
#include <time.h>
#include <fstream>


using namespace std;


int main () {
    srand(time(NULL));
    ofstream arquivo_saida ("output.txt");

    while (true) {
        arquivo_saida << rand() % 100 << " ";
    }


    arquivo_saida.close();
    return 0;
}