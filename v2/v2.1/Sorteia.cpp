#include <iostream>
#include <cstdlib>
#include <winsock2.h>
#include <mysql/mysql.h>
#include <string>
#include <ctime>
#define endereco "sql3.freesqldatabase.com"
#define banco_de_dados "sql3210438"
#define usuario "sql3210438"
#define senha "MqDgPAE5Yk"

#define HOST "sql3.freesqldatabase.com"
#define DB "sql3210438"
#define USER "xxxx"
#define PASS "xxxxxx"

using namespace std;

int main (){


    MYSQL conexao;
    string nomes[50];
    bool tirou[50], tirado[50];
    int maximo = 0;
    for (int w = 0; w<50; w++){
        nomes[w] = "";
        tirou[w] = tirado[w] = 0;
    }
	//MYSQL conexao;
    MYSQL_RES *resp;
    MYSQL_ROW linhas;
    char query[]="SELECT * FROM amigo;";
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao,HOST,USER,PASS,DB,0,NULL,0))
    {
        cout <<"Conectado com Sucesso!\n";
        if (mysql_query(&conexao,query)){
            cout << "Erro: "<< mysql_error(&conexao)<<endl;
            system ("pause");
            return 0;
        }
        else
        {
            resp = mysql_store_result(&conexao);//recebe a consulta
            if (resp){ //se houver consulta
                while ((linhas=mysql_fetch_row(resp)) != NULL){
                    string x1, x2;
                    nomes[maximo] = linhas[0];
                    x1 = linhas[1];
                    tirou[maximo] = x1.c_str()[0]-48;
                    x2 = linhas[2];
                    tirado[maximo] = x2.c_str()[0]-48;
                    maximo ++;
                }
            }
            else{
                system ("pause");
                return 0;
            }
            mysql_free_result(resp);//limpa a variável do resultado: resp
            }
            mysql_close(&conexao);
    }
    else
    {
        cout <<"Conexao Falhou\n";
        if (mysql_errno(&conexao))
            cout <<"Erro" << mysql_errno(&conexao) << " : " <<  mysql_error(&conexao) <<"\n";
        system ("pause");
        return 0;
    }
    cout << "\nParticipantes:\n\n";
    for (int w = 0; w<maximo; w++){
        cout << nomes[w] << endl;
    }

    mysql_close(&conexao);
    int sorteado;
    cout << "\nDigite seu nome do jeito que ele aparece na lista (sem acentos): ";
    string pessoa;
    cin >> pessoa;
    int i;
    for (i = 0; i<maximo; i++){
        if (nomes[i] == pessoa)
            break;
    }
    if (tirou[i] || i == maximo){
        cout << "\nVoce ja tirou ou nao tem seu nome ai!\n"<<endl;
        system ("pause");
        return 0;
    }
    tirou[i] = true;
    system ("cls");
    srand(time(NULL));

    //Ve se só faltam 2
    int c = 0;
    for (int j = 0; j<maximo; j++){
        if (!tirado[j])
            c++;
    }

    if (c == 2){
        int p[2];
        int a = 0;
        for (int j = 0; j<maximo; j++){
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
            sorteado = rand()%maximo;
        }
        while(i==sorteado || tirado[sorteado]);
    }
    cout << "Voce, "<< nomes[i] << ", tirou o(a): " << nomes[sorteado] << endl;
    tirado[sorteado] = true;

    string queryTirou = "update amigo set tirou = true where nome = '" + nomes[i] + "';";
    string queryTirado = "update amigo set tirado = true where nome = '" + nomes[sorteado] + "';";

    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, endereco, usuario, senha, banco_de_dados, 0, NULL, 0)){
        cout << "Atualizando Banco de dados...\n";
        mysql_query(&conexao, queryTirou.c_str());
        mysql_query(&conexao, queryTirado.c_str());
        cout << "\nBanco de dados Atualizado.\n\n";
        mysql_close(&conexao);

    }
    else{
        cout << "Conexao Falhou.";
        system ("pause");
        return 0;
    }
    /*
    for (int w = 0; w<maximo; w++){
        cout << nomes[w] <<"\t"<< tirou[w] <<"\t"<< tirado[w]<<endl;
    }
    */
    system ("pause");
	return 0;
}
