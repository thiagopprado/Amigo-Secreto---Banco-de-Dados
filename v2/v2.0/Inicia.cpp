#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
int main (){

    ofstream nomes;
    nomes.open("nomes.txt");
    ofstream tirou;
    tirou.open("tirou.txt");
    ofstream tirado;
    tirado.open("tirado.txt");

    for (int i = 0; i < 50; i++){
        system ("cls");
        cout << "0. Sair\n1. Adicionar Nome\n";

        bool flag;
        cin >> flag;
        if(!flag)
            return 0;

        cout << "Digite o nome: ";
        string nome;
        cin >> nome;
        nomes << nome << endl;
        tirou << false << endl;
        tirado << false << endl;
    }
    nomes.close();
    tirou.close();
    tirado.close();
    return 0;
}
