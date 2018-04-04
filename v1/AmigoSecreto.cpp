#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#define x 50

string nome [x], aux;
bool tirado [x], tirou[x];
int flag = 1, posicao = 0;

int procura(string n){
    for (int i = 0; i<posicao; i++){
        if ((n == nome[i])&&(!tirou[i]))
            return i;
    }
    cout << "Voce ja tirou\nOutro nome: ";
    return -1;
}

int main (){
    srand(time(NULL));
    FILE *escolh, *tir;
    escolh = fopen("tirado.txt", "rc");
    tir = fopen("tirou.txt", "rc");
    for (int i = 0; i<x; i++){
        int a;
        fscanf(escolh, "%d", &a);
        tirado[i] = a;
    }
    for (int i = 0; i<x; i++){
        int a;
        fscanf(tir, "%d", &a);
        tirou[i] = a;
    }
    int doido;
    char Linha[100];
    FILE *arq;
    arq = fopen("nomes.txt", "rt");
    while (!feof(arq)) {
        fscanf(arq, "%s", Linha);
        nome[posicao] = Linha;
        posicao++;
    }
    cout << "Nomes: \n";
    for (int i = 0; i<posicao; i++){
        cout << nome[i] << endl;
    }
    cout << "\nDigite seu primeiro nome: ";

    do {
        cin >> aux;
    }
    while (procura(aux) == -1);

    tirou[procura(aux)] = true;
    int a;

    do{
        a = rand()%posicao;
    }
    while ((aux == nome[a])||(tirado[a] == true));

    tirado[a] = true;
    cout << "Voce tirou o(a): " << nome[a] << endl;
    system ("pause");
    system ("cls");

    FILE *escolhida;
    escolhida = fopen("tirou.txt", "wc");
    for (int i = 0; i<x; i++){
        fprintf(escolhida, "%d\n", tirou[i]);
    }
    FILE *tirada;
    tirada = fopen("tirado.txt", "wc");
    for (int i = 0; i<x; i++){
        fprintf(tirada, "%d\n", tirado[i]);
    }


}
