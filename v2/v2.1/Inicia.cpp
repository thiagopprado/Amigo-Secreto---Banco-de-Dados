#include <iostream>
#include <cstdlib>
#include <winsock2.h>
#include <mysql/mysql.h>
#include <string.h>

#define endereco "sql3.freesqldatabase.com"
#define banco_de_dados "sql3210438"
#define usuario "xxxx"
#define senha "xxxxxx"
using namespace std;

bool insere (string nome){
    string query = "insert into amigo (nome, tirou, tirado) values ('" + nome + "', false, false);";
    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, endereco, usuario, senha, banco_de_dados, 0, NULL, 0)){
        mysql_query(&conexao, query.c_str());
        cout << "\nInserido com sucesso!\n\n";
        mysql_close(&conexao);
        return true;
    }

    cout << "Falha de conexao\n\n";
    cout << "Erro " << mysql_errno(&conexao) <<":" <<mysql_error(&conexao)<<endl;
    return false;
}

bool apaga(){
    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, endereco, usuario, senha, banco_de_dados, 0, NULL, 0)){
        cout << "Apagando Banco de dados...\n";
        mysql_query(&conexao, "drop table amigo;");
        cout << "\nBanco de dados apagado.\n\n";
        mysql_close(&conexao);
        return true;
    }

    cout << "Falha de conexao\n";
    cout << "Erro " << mysql_errno(&conexao) <<":" <<mysql_error(&conexao)<<endl;
    return false;
}

bool cria(){
    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, endereco, usuario, senha, banco_de_dados, 0, NULL, 0)){
        cout << "Criando Banco de dados...\n";
        mysql_query(&conexao, "create table amigo (nome varchar (30) not null, tirou boolean default false, tirado boolean default false, primary key (nome));");
        cout << "\nBanco de dados Criado.\n\n";
        mysql_close(&conexao);
        return true;
    }
    cout << "Falha de conexao\n";
    cout << "Erro " << mysql_errno(&conexao) <<":" <<mysql_error(&conexao)<<endl;
    return false;
}
using namespace std;
int main (){

    /*ofstream nomes;
    nomes.open("nomes.txt");
    ofstream tirou;
    tirou.open("tirou.txt");
    ofstream tirado;
    tirado.open("tirado.txt");
    */
    if (!apaga()){
        system ("pause");
        return 0;
    }
    system ("pause");
    system ("cls");
    if (!cria()){
        system ("pause");
        system ("cls");
    }
    for (int i = 0; i < 50; i++){
        system ("pause");
        system ("cls");
        cout << "0. Sair\n1. Adicionar Nome\n";

        bool flag;
        cin >> flag;
        if(!flag)
            return 0;

        cout << "Digite o nome: ";
        string nome;
        cin >> nome;
        if(!insere(nome))
            return 1;
        /*nomes << nome << endl;
        tirou << false << endl;
        tirado << false << endl;
        */
    }
    /*
    nomes.close();
    tirou.close();
    tirado.close();
    */
    return 0;
}
