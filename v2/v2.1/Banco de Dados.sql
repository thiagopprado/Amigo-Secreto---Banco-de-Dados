drop database amigo; /*Deleta o banco*/
create database amigo default character set utf8 default collate utf8_general_ci; /*Cria o banco*/
use amigo; /*Seleciona o Banco*/
create table amigo (nome varchar (30) not null, tirou boolean default false, tirado boolean default false, primary key (nome)); /*Cria uma tabela (struct)*/

insert into amigo (nome, tirou, tirado)
values ('Thiago', false, false),('Victor', false, false),('Sofia', false, false);

update tabela
set tirou = true
where nome = 'Thiago';

Host: sql3.freesqldatabase.com
Database name: sql3210438
Database user: sql3210438
Database password: MqDgPAE5Yk
Port number: 3306









create database nome1 default character set utf8 default collate utf8_general_ci; /*Cria o banco*/
use nome1; /*Seleciona o Banco*/
create table nome2 (nome varchar (30) not null, tirou boolean default false, tirado boolean default false, primary key (nome)); /*Cria uma tabela (struct)*/

insert into nome2 (nome, tirou, tirado)
values ('Thiago', false, false),('Victor', false, false),('Sofia', false, false);

select *from nome2;

update nome2
set tirou = true
where nome = 'Thiago';

drop table nome2;