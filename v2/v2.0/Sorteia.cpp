#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main (){
    ifstream inNomes, inTirou, inTirado;

    inNomes.open("nomes.txt");
    inTirou.open("tirou.txt");
    inTirado.open("tirado.txt");

    if(inNomes.fail()){
        cout << "Deu merda";
        return 0;
    }

    int count = 0;
    string nomes[50];
    bool tirado[50], tirou[50];

    //Lê
    while (!inNomes.eof()){
        getline(inNomes, nomes[count]);
        inTirou >> tirou[count];
        inTirado >> tirado[count];
        cout << nomes[count] << endl;
        count ++;
    }
    count --;


    //Sorteia
    int sorteado;
    cout << "Digite seu nome: ";
    string pessoa;
    cin >> pessoa;
    int i;
    for (i = 0; i<count; i++){
        if (nomes[i] == pessoa)
            break;
    }
    if (tirou[i] || i == count){
        cout << "\nVoce ja tirou ou nao tem seu nome ai!"<<endl;
        inNomes.close();
        inTirou.close();
        inTirado.close();
        return 0;
    }
    tirou[i] = true;
    system ("cls");
    srand(time(NULL));

    //Ve se só faltam 2
    int c = 0;
    for (int j = 0; j<count; j++){
        if (!tirado[j])
            c++;
    }

    if (c == 2){
        int p[2];
        int a = 0;
        for (int j = 0; j<count; j++){
            if (!tirado[j]){
                p[a] = j;
                a++;
            }
        }

        if (i == p[0]){
            sorteado = p[1];
        }
        else{
            if (i == p[1]){
                sorteado = p[0];
            }
            else{
                if (!tirou [p[0]]&&!tirado[p[0]])
                    sorteado = p[0];
                    else{
                        sorteado = p[1];
                    }
            }
        }
    }
    else{
        do{
            sorteado = rand()%count;
        }
        while(i==sorteado || tirado[sorteado]);
    }
    cout << "Voce tirou o(a): " << nomes[sorteado] << endl;
    tirado[sorteado] = true;

    //Regrava
    ofstream outTirou, outTirado;

    outTirou.open("tirou.txt");
    outTirado.open("tirado.txt");

    for (int j = 0; j< count; j++){
        outTirou << tirou[j] << endl;
        outTirado << tirado[j] << endl;
    }

    inNomes.close();
    inTirou.close();
    inTirado.close();

    outTirou.close();
    outTirado.close();
    system ("pause");
    return 0;

}
