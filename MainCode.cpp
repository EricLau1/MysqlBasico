#include <iostream>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define T 40

// M E N S A G E M //
/*
 * Desculpe os erros de portugu�s meu interesse era s� estudar os comandos do MySQL
*/
void mensagem();

//Fun��o para direcionar onde o ponteiro sera iniciado
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*-------------------------------------*/
void linha() {
	for (int i = 0; i < 90; i++) {
		cout << "-";
	}
}
/*-------------------------------------*/

//Fun��es para cor de texto
void amarelo();
void branco();

//Comandos para relacionar tabelas
void interactiveTables();
void addForeignKeyReferences();
void selectFromJoin();
void selectFromAs();
void selectFromLeftRightOuterJoin();
void relationshipMultTables();
void selectMultTables();

//Comandos de vizualiza��o
void visualComands();
void selectFrom();
void selectFromOrderBy();
void selectFromWhere();
void selectFromWhereLike();
void selectDistinct();
void selectCount();
void selectFromGroupBy();
void selectFromGroupByHaving();

//Comandos de Inser��o
void insertComands();
void insertInto();
void alterTableAddColumn();
void alterTableDropColumn();
void alterTableModifyColumn();
void alterTableChangeColumn();
void alterTableRenameTo();
void alterTableAddPrimaryKey();
void updateSetWhere();
void updateSetWhereLimit();
void deleteFromWhere();
void truncateTable();

//Comandos de cria��o
void createComands();
void createDatabase();
void showDatabases();
void useNameBanco();
void dropDatabase();
void tiposPrimitivos();
void createTable();
void showTables();
void describeNameTable();
void dropTable();
void padraoUTF8();
void chavePrimaria();
void createTableIfNotExists();

// Menu Principal
void menuMySql() {
	int opcao;
	bool ativo = true;
	while (ativo) {
		gotoxy(T-10, 1);
		cout << "MAXIMIZE A JANELA PARA MELHOR VIZUALIZA��O DOS TEXTOS";
		gotoxy(T, 5);
		cout << "COMANDOS MYSQL";
		gotoxy(T, 10);
		cout << "1- COMANDOS DE CRIA��O";
		gotoxy(T, 12);
		cout << "2- INSERINDO DADOS";
		gotoxy(T, 14);
		cout << "3- COMANDOS VISUAIS";
		gotoxy(T, 16);
		cout << "4- INTERA��O ENTRE TABELAS";

		gotoxy(T-10, 25);
		cout << "digite 0 para sair ou voltar de um menu";
		gotoxy(T, 20);
		cout << "Escolha uma op��o: ";
		cin >> opcao;
		
		system("cls");
		switch (opcao) {
		case(1): {
			createComands();
			break;
		}
		case(2): {
			insertComands();
			break;
		}
		case(3): {
			visualComands();
			break;
		}
		case(4): {
			interactiveTables();
			break;
		}
		default: {
			char r;
			gotoxy(T, 10);
			cout << "SAIR? (S / N) ";
			cin >> r;
			if (r == 's' || r == 'S') {
				system("cls");
				gotoxy(T, 10);
				cout << "@Author: ericlau.gitrrbb@gmail.com";
				getch();
				//Sleep(3000);
				ativo = false;
			}
			break;
		}//fim default

		}//fim switch
		system("cls");
	}//fim while

}


int main() {
	setlocale(LC_ALL, "");
	mensagem();
	menuMySql();

}

//Relacionamento entre Tabelas

void interactiveTables() {
	int opcao;
	bool ativo = true;
	while (ativo) {
		gotoxy(T, 1);
		cout << "RELACIONAMENTO ENTRE TABELAS";
		gotoxy(T, 5);
		cout << "1- CHAVE ESTRANGEIRA";
		gotoxy(T, 6);
		cout << "2- SELECT FROM INNER JOIN";
		gotoxy(T, 7);
		cout << "3- SELECT FROM AS";
		gotoxy(T, 8);
		cout << "4- SELECT FROM LEFT/RIGHT OUTER JOIN";
		gotoxy(T, 9);
		cout << "5- RELATIONSHIP MULT TABLES";
		gotoxy(T, 10);
		cout << "6- SELECT MULT TABLES";
		
		gotoxy(T, 20);
		cout << "Escolha uma op��o:";
		cin >> opcao;
		system("cls"); //limpa tela
		switch (opcao) {
		case(1): {
			addForeignKeyReferences();
			break;
		}
		case(2): {
			selectFromJoin();
			break;
		}
		case(3): {
			selectFromAs();
			break;
		}
		case(4): {
			selectFromLeftRightOuterJoin();
			break;
		}
		case(5): {
			relationshipMultTables();
			break;
		}
		case(6): {
			selectMultTables();
			break;
		}
		default: {
			ativo = false;
			break;
		}
		}//fim switch
		system("cls");
	}//fim while

}

void selectMultTables() {
	cout << "SELECT MULT TABLES";
	gotoxy(T, 5);
	cout << "Primeiro deve-se inserir as chaves estrangeiras na tabela. Segue o exemplo";
	amarelo();
	gotoxy(T, 7);
	cout << "insert into `tabela_meio` (default, 'primaria1' 'primaria2', '2017-01-05');";
	gotoxy(T, 9);
	branco();
	cout << "O comando acima leva em considera��o o exemplo anterior na op��o 5-";
	gotoxy(T, 11);
	cout << "Lembrando que as chaves primarias se tornam chaves estrangeiras ali dentro.";
	gotoxy(T, 13);
	cout << "Exemplo de como unir e relacionar as tr�s tabelas:";
	amarelo();
	gotoxy(T, 15);
	cout << "mysql> select t1.atributo, tmeio.atributo, t2.atributo";
	gotoxy(T, 17);
	cout << "from tabela1 as t1 inner join tabela_meio as tmeio";
	gotoxy(T, 19);
	cout << "on t1.primaria = tmeio.estrangeira1";
	gotoxy(T, 21);
	cout << "inner join tabela2 as t2";
	gotoxy(T, 23);
	cout << "on tmeio.estrangeira2 = t2.primaria;";
	branco();
	getch();
}

void relationshipMultTables() {
	cout << "RELA��O ENTRE VARIAS TABELAS";
	gotoxy(T, 5);
	cout << "O relacionamento entra varias tabelas ocorre quando um relacionamento entre tabelas tem";
	gotoxy(T, 7);
	cout << "cardinalidade N pra N. O que acontece � que o losango que representa a rela��o entre duas";
	gotoxy(T, 9);
	cout << "tabelas, se torna uma entidade que recebera duas chaves estrangeiras, al�m de ter sua pr�pria";
	gotoxy(T, 11);
	cout << "chave prim�ria. As chaves estrangeiras ser�o as chaves prim�rias das tabelas relacionadas";
	gotoxy(T, 13);
	cout << "Exemplo de como criar uma tabela com duas chaves estrangeiras:";
	gotoxy(T, 15);
	amarelo();
	cout << "mysql> create table `tabela_meio` ( idm int not null auto_increment,";
	gotoxy(T, 17);
	cout << "`idtabela1` int, `idtabela2` int, data date,";
	gotoxy(T, 19);
	cout << "primariy key (idm),";
	gotoxy(T, 21);
	cout << "foreign key(idtabela1) references `tabela1`(`primaria`),";
	gotoxy(T, 23);
	cout << "foreign key(idtabela2) references `tabela2`(`primaria`) ) default charset=utf8;";
	branco();
	gotoxy(T, 25);
	cout << "Lembrando que as chaves estrangeiras tem que ser do mesmo TIPO que as prim�rias.";
	getch();
}

void selectFromLeftRightOuterJoin() {
	cout << "SELECT FROM LEFT/RIGHT OUTER JOIN";
	gotoxy(T, 5);
	cout << "LEFT ou RIGHT OUTER para dar prioridade a tabela da esquerda ou da direita";
	gotoxy(T, 7);
	cout << "Segue um exeplo:";
	amarelo();
	gotoxy(T, 9);
	cout << "mysql> select t1.atributo, t2.atributo from tabela1 as t1 ";
	gotoxy(T, 11);
	cout << "left outer join tabela2 as t2 on t1.estrangeira = t2.primaria; ";
	gotoxy(T, 13);
	branco();
	cout << "No comando acima ele ir� mostrar todos os dados do atributo da tabela da esquerda";
	gotoxy(T, 15);
	cout << "por�m a coluna da tabela da direita s� mostrar� os dados que tem rela��o com a esquerda";
	gotoxy(T, 17);
	cout << "Caso fosse definido RIGHT OUTER JOIN ele daria preferencia a tabela da direita";
	getch();
}


void selectFromAs() {
	cout << "SELECT FROM AS";
	gotoxy(T, 5);
	cout << "AS � usado para dar um `apelido` para uma tabela, e � bastante util para encurtar comandos";
	gotoxy(T, 7);
	cout << "muito grandes. Vejo o exemplo: ";
	gotoxy(T, 9);
	amarelo();
	cout << "mysql> select t1.atributo, t2.atrbuto from tabela as t1 inner join tabela2 as t2 on t1.atributo = t2.atributo;";
	branco();
	gotoxy(T, 11);
	cout << "O apelido n�o pode estar entre aspas simples ou duplas afinal ele � o nome da tabela e nao um valor qualquer.";
	getch();
}

void selectFromJoin() {
	cout << "SELECT FROM JOIN AND INNER JOIN ON";
	gotoxy(T, 5);
	cout << "O JOIN fara uma jun��o entre tabelas, ou seja, duas tabelas ser�o mostradas ao mesmo tempo";
	gotoxy(T, 7);
	cout << "Segue o exmeplo:";
	gotoxy(T, 9);
	amarelo();
	cout << "mysql> select tabela1.atributo, tabela2.atributo from `tabela1` join `tabela2`;";
	branco();
	gotoxy(T, 11);
	cout << "O comando acima mostra os atributos selecionados das duas tabelas. O problema �";
	gotoxy(T, 13);
	cout << "que como n�o existe nada especificando a rela��o entra as duas os dados ficar�o";
	gotoxy(T, 15);
	cout << "desajustados. Para melhorar isso � preciso seguir algum passos. Segue o exemplo:";
	amarelo();
	gotoxy(T, 17);
	cout << "mysql> select tabela1.atributo, tabela2.atributo from `tabela1` inner join `tabela2`";
	gotoxy(T, 19);
	cout << "on tabela.chaveestrangeira = tabela2.chaveprimaria;";
	branco();
	gotoxy(T, 21);
	cout << "Agora mostrar� apenas os atributos das duas tabelas que est�o relacionados pela chave.";
	gotoxy(T, 23);
	cout << "ON determina que as tabelas est�o interligadas pela chave estrangeira e prim�ria.";
	gotoxy(T, 25);
	cout << "estrangeira. Lembrando que essas chaves s�o os atributos que correspondem a cada tabela";
	getch();
}

void addForeignKeyReferences() {
	cout << "CHAVE ESTRANGEIRA";
	gotoxy(T, 5);
	cout << "Para que exista uma chave estrangeira � preciso que haja algum relacionamento entre duas tabelas";
	gotoxy(T, 7);
	cout << "A chave estrangeira de uma tabela � a chave prim�ria da outra";
	gotoxy(T, 9);
	cout << "Para que uma tabela tenha uma chave estrangeira  � preciso que ela tenha um atributo do mesmo tipo";
	gotoxy(T, 11);
	cout << "que a chave primaria da outra tabela. O mesmo ficar� encarregado de guardar as chaves prim�rias,";
	gotoxy(T, 13);
	cout << "por isso � chamado de chave estrangeira, pois � uma chave que vem de outro lugar";
	gotoxy(T, 15);
	cout << "Segue um exemplo de como adicionar uma chave estrangeira:";
	gotoxy(T, 17);
	amarelo();
	cout << "mysql> alter table `tabela1` add foreign key(`atributo`) references `tabela2`(`chaveprimaria`)";
	branco();
	gotoxy(T, 19);
	cout << "REFERENCES refencia de qual tabela � a chave estrangeira";
	gotoxy(T, 21);
	cout << "Quando existem linhas de tabelas relacionadas com chave estrangeira, geralmente os comandos delete";
	gotoxy(T, 23);
	cout << "n�o funcionam";
	getch();
}


//Comandos de Visualiza��o de dados ----------------------------------------------------------------------------------------------------------

void visualComands() {
	int opcao;
	bool ativo = true;
	while (ativo) {
		gotoxy(T, 1);
		cout << "COMANDOS PARA VISUALIZA��O DE DADOS";
		gotoxy(T, 5);
		cout << "1- SELECT FROM";
		gotoxy(T, 6);
		cout << "2- SELECT FROM ORDER BY";
		gotoxy(T, 7);
		cout << "3- SELECT FROM WHERE";
		gotoxy(T, 8);
		cout << "4- SELECT FROM WHERE LIKE";
		gotoxy(T, 9);
		cout << "5- SELECT DISTINCT";
		gotoxy(T, 10);
		cout << "6- SELECT COUNT MAX MIN SUM AVG";
		gotoxy(T, 11);
		cout << "7- SELECT FROM GROUP BY";
		gotoxy(T, 12);
		cout << "8- SELECT FROM GROUP BY HAVING";

		gotoxy(T, 20);
		cout << "Escolha uma op��o: ";
		cin >> opcao;
		system("cls");
		switch (opcao) {
		case(1): {
			selectFrom();
			break;
		}
		case(2): {
			selectFromOrderBy();
			break;
		}
		case(3): {
			selectFromWhere();
			break;
		}
		case(4): {
			selectFromWhereLike();
			break;
		}
		case(5): {
			selectDistinct();
			break;
		}
		case(6): {
			selectCount();
			break;
		}
		case(7): {
			selectFromGroupBy();
			break;
		}
		case(8): {
			selectFromGroupByHaving();
			break;
		}
		default: {
			ativo = false;
			break;
		}
				 
		}//fim switch
		system("cls");
	}//fim while
}

void selectFromGroupByHaving() {
	cout << "SELECT FROM GROUP BY HAVING";
	gotoxy(T, 5);
	cout << "O HAVING � como se fosse um WHERE s� que usado ap�s um GROUP BY";
	gotoxy(T, 7);
	cout << "significa que ele s� funcionar� para o atributo que foi agrupado";
	gotoxy(T, 9);
	cout << "Ao usar o HAVING o select s� ir� mostrar o groupo que seguir uma ";
	gotoxy(T, 11);
	cout << "condi��o que ser� definida. Veja o exemplo:";
	amarelo();
	gotoxy(T, 13);
	cout << "mysql> select `atributo`, count(*) from `tabela` group `atributo` having count(*) > '3';";
	branco();
	gotoxy(T, 15);
	cout << "O comando acima s� mostrar� grupos maiores que tr�s, ou seja, no m�nimo quatro elementos";
	gotoxy(T, 17);
	cout << "precisam ter os valores do atributo selecionado semelhantes";
	gotoxy(T, 19);
	cout << "Segue mais um exemplo:";
	amarelo();
	gotoxy(T, 21);
	cout << "mysql> select `atributo` from `tabela` where `atributo` = 'valor' group by `atributo`";
	gotoxy(T, 23);
	cout << "having `atributo` > (select avg(`atributo`) from `tabela`);";
	branco();
	gotoxy(T, 25);
	cout << "O comando acima seleciona um atributo especifico onde possua um valor determinado no WHERE,";
	gotoxy(T, 27);
	cout << "agrupa os elementos que possuem este valor, ou seja os elementos que tem os valores iguais.";
	gotoxy(T, 29);
	cout << "E o HAVING ir� mostrar somente os atributos agrupados que possuem um valor maior";
	gotoxy(T, 31);
	cout << "que a m�dia de todos os valores daquele atributo dentro da tabela";
	getch();
}


void selectFromGroupBy() {
	cout << "SELECT FROM GROUP BY";
	gotoxy(T, 5);
	cout << "GROUP BY basicamente agrupa todos os elementos iguais. Veja o exemplo:";
	amarelo();
	gotoxy(T, 7);
	cout << "mysql> select `atributo`, count(*) from `tabela` group by `atributo`;";
	branco();
	gotoxy(T, 9);
	cout << "O COUNT(*) serve para mostrar quantos elementos possuem aquele valor";
	getch();
}

void selectCount() {
	cout << "SELECT COUNT MAX MIN SUM AVG";
	gotoxy(T, 5);
	cout << "COUNT conta quantas linhas tem uma tabela. Segue o exemplo:";
	amarelo();
	gotoxy(T, 7);
	cout << "mysql> select count(*) from `nomedatabela`;";
	gotoxy(T, 9);
	branco();
	cout << "Os pr�ximos comandos s�o para determinados tipos de c�lculos:";
	gotoxy(T, 11);
	amarelo();
	cout << "mysql> select max(`atributo`) from `tabela`;";
	gotoxy(T, 13);
	branco();
	cout << "MAX mostra o maior valor existente em uma das linhas do atributo escolhido";
	amarelo();
	gotoxy(T, 15);
	cout << "mysql> select min(`atributo`) from `tabela`;";
	branco();
	gotoxy(T, 17);
	cout << "MIN mostra o menor valor existente em um das linhas do atributo escolhido";
	gotoxy(T, 19);
	amarelo();
	cout << "mysql> select sum(`atributo`) from `tabela`;";
	branco();
	gotoxy(T, 21);
	cout << "SUM soma todos os valores dos campos do atributo escolhido";
	amarelo();
	gotoxy(T, 23);
	cout << "mysql> select avg(`atributo`) from `tabela`;";
	branco();
	gotoxy(T, 25);
	cout << "AVG faz a media aritim�tica, somando todos os valores do atributo escolhido";
	gotoxy(T, 27);
	cout << "e dividindo pela quantidade de linhas";
	gotoxy(T, 29);
	cout << "� poss�vel usar o WHERE em todos os comandos acima caso queira procurar valores espec�ficos";
	getch();
}

void selectDistinct() {
	cout << "SELECT DISTINCT";
	gotoxy(T, 5);
	cout << "DISTINCT ir� mostrar todas as linhas de um atributo, exceto as que";
	gotoxy(T, 7);
	cout << "tenham algum valor repetido. Segue o exemplo:";
	gotoxy(T, 9);
	amarelo();
	cout << "mysql> select distinct `atributo` from `nomedatabela`;";
	branco();
	getch();
}

void selectFromWhereLike() {
	cout << "SELECT FROM WHERE LIKE";
	gotoxy(T, 5);
	cout << "LIKE � usado quando se quer mostrar palavras que comecem ou terminem com";
	gotoxy(T, 7);
	cout << "determinadas letras. Ap�s digitar o LIKE coloca-se a letra da palavra entre";
	gotoxy(T, 9);
	cout << "aspas simples(''), junto com um s�mbolo de porcentagem antes ou ap�s a letra";
	gotoxy(T, 11);
	cout << "O simbolo de \"%\" significa: \"nenhum ou mais caracteres\". ";
	gotoxy(T, 13);
	cout << "Ou seja, quando se coloca uma letra e o \"%\" na frente, significa que ser�o";
	gotoxy(T, 15);
	cout << "mostradas, palavras que comecem com aquela letra seguidas por nenhum ou mais";
	gotoxy(T, 17);
	cout << "caracteres. Veja o exemplo";
	gotoxy(T, 19);
	amarelo();
	cout << "mysql> select * from `tabela` where `atributo` like `A%`;";
	branco();
	gotoxy(T, 21);
	cout << "� poss�vel colocar quantas '%' quiser para especifcar uma ou mais palavras numa frase";
	gotoxy(T, 23);
	cout << "Caso a palavra tenha caracter como ESPA�O use o underline para representa-lo";
	gotoxy(T, 25);
	cout << "Exemplo:";
	gotoxy(T, 27);
	amarelo();
	cout << "mysql> select * from `tabela` where `atributo` like '%o_%a';";
	branco();
	gotoxy(T, 29);
	cout << "No exemplo acima vai ser mostrada uma palavra que termine com a letra 'o' e tenha um caractere";
	gotoxy(T, 31);
	cout << "seperando a proxima palavra que terminar� com 'a'. Bem util para usar em nomes com sobrenomes";
	gotoxy(T, 33);
	cout << "Este comando � case-sensitive, ele diferencia mai�sculas de min�sculas!";
	getch();
}

void selectFromWhere() {
	cout << "SELECT FROM WHERE BETWEEN AND IN";
	gotoxy(T, 5);
	cout << "WHERE tamb�m pode ser usando junto com o SELECT para visualizar registros espec�ficos";
	gotoxy(T, 7);
	cout << "Ap�s digitar o comando SELECT especificando quais os atributos da tabela ser�o mostrados,";
	gotoxy(T, 9);
	cout << "digite \"where\" depois do nome da tabela e coloque as condi��es para que as linhas";
	gotoxy(T, 11);
	cout << " sejam mostradas. Segue o exemplo:";
	gotoxy(T, 13);
	amarelo();
	cout << "mysql> select * from `tabela` where `atributo1` > 'valor' and `atributo2` = 'valor';";
	branco();
	gotoxy(T, 15);
	cout << "AND � mesmo que: &&  assim como OR � o mesmo que ||";
	gotoxy(T, 17);
	cout << "O comando BETWEEN seleciona linhas que est�o entre determinados valores inclusive os extremos";
	gotoxy(T, 19);
	cout << "j� o comando IN s� mostra as linhas que correspondem as condi��es definidas. Segue os exemplos:";
	gotoxy(T, 21);
	amarelo();
	cout << "mysql> select `atributo` from `tabela` where `atributo` between 'valor' and 'valor';";
	gotoxy(T, 23);
	cout << "mysql> select `atributo` from `tabela` where `atributo` in ('valor1', 'valor2');";
	branco();
	gotoxy(T, 25);
	cout << "IN aceita um ou mais valores. O ORDER BY pode ser usado ap�s as condi��es";
	getch();
}

void selectFromOrderBy() {
	cout << "SELECT FROM ORDER BY";
	gotoxy(T, 5);
	cout << "ORDER BY � usado para ordenar uma coluna com palavras ou numeros";
	gotoxy(T, 7);
	cout << "Ap�s colocar quais as colunas ser�o mostradas, digite ORDER BY ";
	gotoxy(T, 9);
	cout << "e em seguida um  o atributo que vai ser ordenado. Segue o Exemplo:";
	gotoxy(T, 11);
	amarelo();
	cout << "mysql> select `atributo1`, `atributo2` from `nomedatabela` order by `atributo1`;";
	branco();
	gotoxy(T, 13);
	cout << "Tamb�m � poss�vel especificar se a coluna ser� ordena de baixo para cima";
	gotoxy(T, 15);
	cout << "ou de cima para baixo, usando os parametros ASC ou DESC. Segue os exemplos:";
	amarelo();
	gotoxy(T, 17);
	cout << "mysql> select `atributo` from `nomedatabela` order by `atributo` asc;";
	gotoxy(T, 19);
	cout << "mysql> select `atributo` from `nomedatabela` order by `atributo` desc;";
	gotoxy(T, 21);
	branco();
	cout << "ASC vai ordenar do menor para o maior ou no caso de palavras come�ar� de A a Z";
	gotoxy(T, 23);
	cout << "DESC ordena ao contr�rio do ASC";
	getch();
}

void selectFrom() {
	cout << "SELECT FROM";
	gotoxy(T, 5);
	cout << "SELECT FROM � usado para mostrar todos os dados registrados em uma tabela";
	gotoxy(T, 7);
	cout << "Ap�s digitar \"select\", � preciso definir quais colunas ser�o mostradas";
	gotoxy(T, 9);
	cout << "o simbolo asterisco(*) � usado para mostrar todas as colunas";
	gotoxy(T, 11);
	cout << "Caso queira colunas especificas � preciso definir quais os atributo ap�s o";
	gotoxy(T, 13);
	cout << "select. Depois digite FROM e em seguida o nome da tabela. Veja os exemplos:";
	gotoxy(T, 15);
	cout << "Exemplo com * :";
	amarelo();
	gotoxy(T, 17);
	cout << "mysql> select * from `nomedatabela`;";
	branco();
	gotoxy(T, 19);
	cout << "Exemplo com colunas espec�ficas:";
	amarelo();
	gotoxy(T, 21);
	cout << "mysql> select `atributo1`, `atributo2` from `nomedatabela`;";
	branco();
	getch();
}





//Comandos de Inser��o de dados --------------------------------------------------------------------------------------------------------------------

void insertComands() {
	int opcao;
	bool ativo = true;
	while (ativo) {
		gotoxy(T, 1);
		cout << "COMANDOS PARA INSERIR OU REMOVER DADOS NA TABELA";
		gotoxy(T, 5);
		cout << "1- INSERT INTO";
		gotoxy(T, 6);
		cout << "2- ALTER TABLE ADD COLUMN";
		gotoxy(T, 7);
		cout << "3- ALTER TABLE DROP COLUMN";
		gotoxy(T, 8);
		cout << "4- ALTER TABLE MODIFY COLUMN";
		gotoxy(T, 9);
		cout << "5- ALTER TABLE CHANGE COLUMN";
		gotoxy(T, 10);
		cout << "6- ALTER TABLE RENAME TO";
		gotoxy(T, 11);
		cout << "7- ALTER TABLE ADD PRIMARY KEY";
		gotoxy(T, 12);
		cout << "8- UPDATE SET WHERE";
		gotoxy(T, 13);
		cout << "9- UPDATE SET WHERE LIMIT";
		gotoxy(T-1, 14);
		cout << "10- DELETE FROM WHERE";
		gotoxy(T - 1, 15);
		cout << "11- TRUNCATE TABLE";

		gotoxy(T, 20);
		cout << "Escolha uma op��o: ";
		cin >> opcao;
		system("cls");
		switch (opcao) {

		case(1): {
			insertInto();
			break;
		}
		case(2): {
			alterTableAddColumn();
			break;
		}
		case(3): {
			alterTableDropColumn();
			break;
		}
		case(4): {
			alterTableModifyColumn();
			break;
		}
		case(5): {
			alterTableChangeColumn();
			break;
		}
		case(6): {
			alterTableRenameTo();
			break;
		}
		case(7): {
			alterTableAddPrimaryKey();
			break;
		}
		case(8): {
			updateSetWhere();
			break;
		}
		case(9): {
			updateSetWhereLimit();
			break;
		}
		case(10): {
			deleteFromWhere();
			break;
		}
		case(11): {
			truncateTable();
			break;
		}
		default: {
			ativo = false;
		}
		
		}//fim switch
		system("cls");
	}
}

void truncateTable() {
	cout << "TRUNCATE TABLE";
	gotoxy(T, 5);
	cout << "TRUNCATE TABLE � o comando que apaga todas as linhas ou dados registrados na tabela";
	gotoxy(T, 7);
	cout << "Basicamente ele esvazia uma tabela inteira. Segue um exemplo:";
	gotoxy(T, 9);
	amarelo();
	cout << "mysql> truncate table `nomedatabela`;";
	branco();
	getch();
}

void deleteFromWhere() {
	cout << "DELETE FROM WHERE";
	gotoxy(T, 5);
	cout << "DELETE FROM WHERE � comando usado para remover uma linha/registro da tabela";
	gotoxy(T, 7);
	cout << "a partir de alguma condi��o colocada no WHERE. Veja um exemplo:";
	gotoxy(T, 9);
	amarelo();
	cout << "mysql> delete from `nomedatabela` where `atributo` = 'valor';";
	branco();
	gotoxy(T, 11);
	cout << "Tamb�m � possivel colcar o comando LIMIT. Segue outro exemplo:";
	amarelo();
	gotoxy(T, 13);
	cout << "mysql> delete from `tabela` where `atributo1` >= 'valor' || `atributo2` != 'valor' limit 5;";
	branco();
	getch();
}

void updateSetWhereLimit() {
	cout << "UPDATE SET WHERE LIMIT";
	gotoxy(T, 5);
	cout << "LIMIT indica a quantidade de linhas da tabela que receber� os updates";
	gotoxy(T, 7);
	cout << "Ou seja, n�o importam quais sejam as condi��es colocadas no WHERE";
	gotoxy(T, 9);
	cout << "O LIMIT far� o update percorrendo a tabela come�ando da primeira posi��o at� a ultima.";
	gotoxy(T, 11);
	cout << "Segue o exemplo:";
	gotoxy(T, 13);
	amarelo();
	cout << "mysql> update `tabela` set `atributo` = 'update' where `atributo1` != 'valor' && `atributo2` = 'valor' limit 1;";
	branco();
	gotoxy(T, 15);
	cout << "No comando acima n�o importa quantas linhas cumprem as condi��es colocadas";
	gotoxy(T, 17);
	cout << "Se a primeira linha cumprir as condi��es, somente ela receber� o update por causa do LIMIT 1";
	gotoxy(T, 19);
	cout << "Caso coloque LIMIT 3 ou LIMIT 10, ele percorrer� as tr�s primeiras ou as dez primeiras";
	gotoxy(T, 21);
	cout << "linhas que cumprem as condi��es WHERE e far� os updates";
	getch();
}

void updateSetWhere() {
	cout << "UPDATE SET WHERE";
	gotoxy(T, 5);
	cout << "UPDATE SET WHERE vair modificar os dados preenchidos nas linhas das tabelas";
	gotoxy(T, 7);
	cout << "Ap�s digitar \"update\", digite o comando SET que vair indicar qual atributo recebera o UPDATE";
	gotoxy(T, 9);
	cout << "Digite o nome do atributo colocando o sinal de igual(=) que significa que ele ir� receber um valor";
	gotoxy(T, 11);
	cout << "Em seguida digite entre aspas simples('') o novo valor ";
	gotoxy(T, 13);
	cout << "WHERE serve para especificar quais as linhas ou apenas uma linha que recebera o UPDATE";
	gotoxy(T, 15);
	cout << "Segue o exemplo";
	gotoxy(T, 17);
	amarelo();
	cout << "mysql> update `nomedatabela` set `atributo` = 'update' where `algumAtributo` = 'valor';";
	branco();
	gotoxy(T, 19);
	cout << "Tamb�m � poss�vel dar UPDATE em varios campos de um s� vez. Veja o exemplo: ";
	amarelo();
	gotoxy(T, 21);
	cout << "mysql> update `nomedatabela` set `atributo1` = 'update', `atributo2` = 'update' where `algumAtributo` <> 'valor';";
	branco();
	gotoxy(T, 23);
	cout << "O comando WHERE usa os operadores l�gicos: &&  || < > >= <=";
	gotoxy(T, 25);
	cout << "O operador maior e menor juntos signifcam o mesmo que: != (diferente de)";
	getch();
}

void alterTableAddPrimaryKey() {
	cout << "ALTER TABLE ADD PRIMARY KEY";
	gotoxy(T, 5);
	cout << "ADD PRIMARY KEY define um atributo que ja esteja na tabela como chave prim�ria";
	gotoxy(T, 7);
	cout << "Veja o Exemplo:";
	amarelo();
	gotoxy(T, 9);
	cout << "mysql> alter table `nomedatabela` add primary key(`atributo`);";
	branco();
	getch();
}



void alterTableRenameTo() {
	cout << "ALTER TABLE RENAME TO";
	gotoxy(T, 5);
	cout << "RENAME TO � usado para modificar o nome da tabela";
	gotoxy(T, 7);
	cout << "Ap�s o comando \"rename to\" digite o novo nome da tabela";
	gotoxy(T, 9);
	cout << "Finalize com ponto e virgula(;). Segue o exemplo:";
	gotoxy(T, 11);
	amarelo();
	cout << "mysql> alter table `nomedatabela` rename to `novoNome`;";
	branco();
	getch();
}

void alterTableChangeColumn() {
	cout << "ALTER TABLE CHANGE COLUMN";
	gotoxy(T, 5);
	cout << "CHANGE COLUMN segue quase as mesmas especifica��es do MODIFY COLUMN";
	gotoxy(T, 7);
	cout << "A principal diferen�a � que com o \"change column\" � poss�vel alterar";
	gotoxy(T, 9);
	cout << "O nome do atributo. Veja o exemplo:";
	amarelo();
	gotoxy(T, 11);
	cout << "mysql> alter table `nomedatabela` change column `atributo` `novoAtributo` int(3) not null default '0';";
	branco();
	gotoxy(T, 13);
	cout << "Novamente ele ir� mudar caso o tipo definido e os parametros n�o entrem em conflitos com a defini��o anterior";
	gotoxy(T, 15);
	cout << "Tipos primitivos n�o podem ser mudados, somente os tipos da mesma classe";
	gotoxy(T, 17);
	cout << "As mudan�as n�o podem entrar em conflito com algum dado ja adiciona naquela coluna";
	getch();
}

void alterTableModifyColumn() {
	cout << "ALTER TABLE MODIFY COLUMN";
	gotoxy(T, 5);
	cout << "MODIFY COLUMN serve para modificar um atributo e seus parametros";
	gotoxy(T, 7);
	cout << "Ap�s digitar \"alter table `nomedatabela` modify column\"";
	gotoxy(T, 9);
	cout << "digite o nome do atributo que deseja modificar e seus novos parametros";
	gotoxy(T, 11);
	cout << "finalize com ponto e v�rgula(;). Segue o exemplo:";
	gotoxy(T, 13);
	amarelo();
	cout << "mysql> alter table `nomedatabela` modify column `atributo` varchar(20);";
	branco();
	gotoxy(T, 15);
	cout << "Uma coisa importante caso queira, por exemplo modificar o comando acima";
	gotoxy(T, 17);
	cout << "No comando acima o atributo foi modificado por�m n�o especificado o parametro NOT NULL";
	gotoxy(T, 19);
	cout << "O MySQL o deixara por padr�o a aceitar valores nulos";
	gotoxy(T, 21);
	cout << "Caso queira modifcar o comando novamente colocando o NOT NULL, ele ir� dar ERRO!";
	gotoxy(T, 23);
	cout << "Para corrigir isto modifique o atributo primeiramente colocando um default vazio ('')";
	gotoxy(T, 25);
	cout << "Segue o exemplo:";
	amarelo();
	gotoxy(T, 27);
	cout << "mysql> alter table `nomedatabela` modify column `atributo` varchar(20) default ' ';";
	branco();
	gotoxy(T, 29);
	cout << "Agora � poss�vel modifica-lo e definir os parametros com not null";
	gotoxy(T, 31);
	amarelo();
	cout << "mysql> alter table `nomedatabela` modify column `atributo` varchar(30) not null default '';";
	branco();
	gotoxy(T, 33);
	cout << "� poss�vel que o comando de erro se algum parametros entrar em conflito com os dados dentro do atributo modificado";
	gotoxy(T, 35);
	cout << "Por exemplo, caso o atributo recebia palavras com 20 letras, ele nao ir� modificar o tamanho do array";
	gotoxy(T, 37);
	cout << "caso exista um dado que ocupe a quantidade de espa�os definida antes";
	gotoxy(T, 39);
	cout << "Um atributo definido como varchar pode ser modificado por outro tipo literal,";
	gotoxy(T, 41);
	cout << "mas dar� erro caso tente modificar o tipo primitivo";
	getch();
}

void alterTableDropColumn() {
	cout << "ALTER TABLE DROP COLUMN";
	gotoxy(T, 5);
	cout << "DROP COLUMN remove um atributo/campo da tabela";
	gotoxy(T, 7);
	cout << "Ap�s digitar o comando \"alter table `nomedatabela` drop column\" ";
	gotoxy(T, 9);
	cout << "Digite o nome do atributo que deseja remover e finalize com ponto e virgua(;)";
	gotoxy(T, 11);
	cout << "Segue o exemplo:";
	gotoxy(T, 13);
	amarelo();
	cout << "mysql> alter table `pessoa` drop column `atributo`;";
	branco();
	getch();
}

void alterTableAddColumn() {
	cout << "ALTER TABLE ADD COLUMN";
	gotoxy(T, 5);
	cout << "ALTER TABLE significa que a estrutura da tabela ser� alterada";
	gotoxy(T, 7);
	cout << "Ap�s digitar \"alter table\", digite o nome da tabela ";
	gotoxy(T, 9);
	cout << "em seguida digte o comando \"add column\" que significa que";
	gotoxy(T, 11);
	cout << "uma nova coluna sera colocada na tabela. Digite o nome do novo";
	gotoxy(T, 13);
	cout << "atributo, seu tipo e seu parametros, ele ser� um novo campo a ser";
	gotoxy(T, 15);
	cout << "preenchido pelo usu�rio. Finalize com ponto e v�rgula";
	gotoxy(T, 17);
	cout << "Segue o exemplo:";
	gotoxy(T, 19);
	amarelo();
	cout << "mysql> alter table `pessoa` add column `atributo` varchar(20);";
	gotoxy(T, 21);
	branco();
	cout << "Ao digitar este comando a coluna ser� inserida automaticamente no final da tabela por padr�o";
	gotoxy(T, 23);
	cout << "� poss�vel especificar em que posi��o deseja colocar o atributo na tabela  com os paramtros: FIRST e AFTER";
	gotoxy(T, 25);
	cout << "Exemplo com FIRST:";
	gotoxy(T, 27);
	amarelo();
	cout << "mysql> alter table `pessoa` add column `atributo` varchar(20) first;";
	branco();
	gotoxy(T, 29);
	cout << "FIRST significa que o atributo ficara na primeira posi��o da tabela";
	gotoxy(T, 31);
	cout << "Exemplo com AFTER:";
	gotoxy(T, 33);
	amarelo();
	cout << "mysql> alter table `pessoa` add column `novo-atributo` after `atributo`";
	branco();
	gotoxy(T, 35);
	cout << "AFTER significa que o novo atributo ficar� ap�s um atributo ja existente na tabela";
	getch();
}


void insertInto() {
	cout << "INSERT INTO";
	gotoxy(T, 5);
	cout << "O comando \"insert into\" � usado para inserir dados nos campos da tabela";
	gotoxy(T, 7);
	cout << "Ap�s o comando, digite o nome da tabela, abra parenteses e digite os atributos separando-os por vigula,";
	gotoxy(T, 9);
	cout << "em seguida, feche o paretenses e digite a palavra VALUES para come�ar a inserir os dados. ";
	gotoxy(T, 11);
	cout << "Abra parenteses novamente e comece a inserir os dados entre aspas simples('') dentro dele";
	gotoxy(T, 13);
	cout << "separando cada dado ao seu respectivo atributo com virgula. Termine fechando parenteses";
	gotoxy(T, 15);
	cout << "e finalize com ponto v�rgula(;)";
	gotoxy(T, 17);
	cout << "Segue o exemplo:";
	gotoxy(T, 19);
	amarelo();
	cout << "mysql> insert into pessoa (id, nome, nascimento, sexo, altura) values";
	gotoxy(T, 21);
	cout << "(default, 'Nome', '2001-05-10', 'M', '1.58');";
	branco();
	gotoxy(T, 23);
	cout << "DEFAULT quer dizer que esse campo vai ser preenchido por um valor padr�o que foi";
	gotoxy(T, 25);
	cout << "definido na cria��o da tabela";
	gotoxy(T, 27);
	cout << "� possivel inserir varias linhas na tabela de uma s� vez. Segue o exemplo:";
	gotoxy(T, 29);
	amarelo();
	cout << "mysql> insert into pessoa (id, nome, nascimento, sexo, altura) values";
	gotoxy(T, 31);
	cout << "(default, 'Nome1', '2000-06-11', 'F', '1.59'),";
	gotoxy(T, 33);
	cout << "(default, 'Nome2', '1996-12-24', 'M', '1.64');";
	gotoxy(T, 35);
	branco();
	cout << "Coloque os valores decimais separados por ponto (.)";
	gotoxy(T, 37);
	cout << "Os parenteses com dados s�o separados por virgula.";
	gotoxy(T, 39);
	cout << "O ponto e v�rgula(;) ser� colocado no ultimo.";
	getch();
}






//Comandos de Cria��o

void createComands() {
	int opcao;
	bool ativo = true;
	while (ativo) {
		gotoxy(T, 1);
		cout << "COMANDOS INICIAIS E ESTRUTURA��O DO BANCO EM MYSQL";
	
		gotoxy(T, 5);
		cout << "1- CREATE DATABASE";
		gotoxy(T, 6);
		cout << "2- SHOW DATABASES";
		gotoxy(T, 7);
		cout << "3- USE";
		gotoxy(T, 8);
		cout << "4- DROP DATABASE";
		gotoxy(T, 9);
		cout << "5- TIPOS PRIMITIVOS";
		gotoxy(T, 10);
		cout << "6- CREATE TABLE";
		gotoxy(T, 11);
		cout << "7- SHOW TABLES";
		gotoxy(T, 12);
		cout << "8- DESCRIBE";
		gotoxy(T, 13);
		cout << "9- DROP TABLE";
		gotoxy(T-1, 14);
		cout << "10- PADR�O UTF8";
		gotoxy(T-1, 15);
		cout << "11- CHAVE PRIM�RIA + APRIMORAMENTOS";
		gotoxy(T-1, 16);
		cout << "12- CREATE TABLE IF NOT EXISTS";
		
		gotoxy(T, 20);
		cout << "Escolha uma op��o: ";
		cin >> opcao;
		system("cls");
		switch (opcao) {
		case(1): {
			createDatabase();
			break;
		   }
		case(2): {
			showDatabases();
			break;
		}
		case(3): {
			useNameBanco();
			break;
		}
		case(4): {
			dropDatabase();
			break;
		}
		case(5): {
			tiposPrimitivos();
			break;
		}
		case(6): {
			createTable();
			break;
		}
		case(7): {
			showTables();
			break;
		}
		case(8): {
			describeNameTable();
			break;
		}
		case(9): {
			dropTable();
			break;
		}
		case(10): {
			padraoUTF8();
			break;
		}
		case(11): {
			chavePrimaria();
			break;
		}
		case(12): {
			createTableIfNotExists();
			break;
		}
		default: {
			ativo = false;
			break;
		}
	     
		}//fim switch
		system("cls");
	}//fim while
}

//DESCRI��O DOS COMANDOS DE CRIA��O -------------------------------------------------------------------------------------------------------------

void createTableIfNotExists() {
	cout << "CREATE TABLE IF NOT EXISTS";
	gotoxy(T, 5);
	cout << "CREATE TABLE IF NOT EXISTS � sempre usado quando for criar uma nova tabela";
	gotoxy(T, 7);
	cout << "caso ja exista uma tabela com o mesmo nome a nova tabela n�o ir� sobrescreve-la";
	gotoxy(T, 9);
	cout << "e o sistema n�o ir� retornar uma mensagem de erro. Segue um exemplo:";
	gotoxy(T, 11);
	amarelo();
	cout << "mysql> create table if not exists `nomedatabela`(nome varchar(30) unique,";
	gotoxy(T, 13);
	cout << "idade int(3) unsigned ) default charset=utf8;";
	branco();
	gotoxy(T, 15);
	cout << "Se existir uma tabela com o mesmo nome a nova n�o ser� criada.";
	gotoxy(T, 17);
	cout << "UNIQUE quer dizer que esse campo n�o vai aceitar nomes repetidos";
	gotoxy(T, 19);
	cout << "UNSIGNED siginifica que esse campo n�o aceita valores negativos ou abaixo de zero";
	gotoxy(T, 21);
	cout << "tambem � possivel usar um comando semelhante para excluir a tabela. Veja o exemplo: ";
	amarelo();
	gotoxy(T, 23);
	cout << "mysql> drop table if exists `nomedatabela`;";
	branco();
	getch();
}


void createDatabase() {
	cout << "CREATE DATABASE";
	gotoxy(T, 5);
	cout << "CREATE DATABASE � o comando usado para criar um Banco de Dados.";
	gotoxy(T, 7);
	cout << "Ap�s digitar o comando \"create database\" � necess�rio dar um";
	gotoxy(T, 9);
	cout<< "nome ao banco e finalizar com ponto e virgula(;)";
	gotoxy(T, 11);
	cout << "Segue um exemplo:";
	gotoxy(T, 13);
	amarelo();
	cout << "mysql> create database `nomedobanco`;";
	branco();
	getch();
}

void showDatabases() {
	cout << "SHOW DATABASES";
    gotoxy(T, 5);
	cout << "SHOW DATABASES � o comando usado para mostrar os Banco de dados Dispon�veis no servidor.";
	gotoxy(T, 7);
	cout << "Ap�s digitar o comando � necessario finalizar com ponto e v�rgula(;)";
	gotoxy(T, 9);
	cout << "Segue o exemplo:";
	gotoxy(T, 11);
	amarelo();
	cout << "mysql> show databases;";
	branco();
	getch();
}

void useNameBanco() {
	cout << "USE";
	gotoxy(T, 5);
	cout << "Para acessar um Banco de Dados que foi criado no MySQL insira o comando USE";
	gotoxy(T, 7);
	cout << "Em seguida digite o nome do banco que deseja acessar e finalize";
	gotoxy(T, 9);
	cout << "com ponto e v�rgula(;)";
	gotoxy(T, 11);
	cout << "Segue o exemplo:";
	gotoxy(T, 13);
	amarelo();
	cout << "mysql> use `nomedobanco`;";
	branco();
	gotoxy(T, 15);
	cout << "Ap�s executar o comando o servidor reponder� com a mensagem: \"Database changed\"";
	getch();
}

void dropDatabase() {
	cout << "DROP DATABASE";
	gotoxy(T, 5);
	cout << "DROP DATABASE � o comando usado para excluir um banco de dados";
	gotoxy(T, 7);
	cout << "Ap�s digitar comando \"drop database\",digite o nome do banco";
	gotoxy(T, 9);
	cout << "que deseja excluir e finalize com ponto e virgula(;)";
	gotoxy(T, 11);
	cout << "Segue o exemplo:";
	gotoxy(T, 13);
	amarelo();
	cout << "mysql> drop database `nomedobanco`;";
	branco();
	getch();
}

void tiposPrimitivos() {
	cout << "TIPOS PRIMITIVOS DO MYSQL";
	gotoxy(T, 5);
	cout << "TIPOS N�MERICOS:";
	gotoxy(T, 7);
	cout << "INTEIRO: TinyInt, SmallInt, Int, MediumInt, DigInt";
	gotoxy(T, 9);
	cout << "REAL: Decimal, Float, Double, Real";
	gotoxy(T, 11);
	cout << "LOGICO: Bit, Boolean";
	gotoxy(T, 12);
	linha();
	gotoxy(T, 14);
	cout << "TIPOS DATA/TEMPO:";
	gotoxy(T, 16);
	cout << "Date, DateTime, TimeStamp, Time, Year";
	gotoxy(T, 17);
	linha();
	gotoxy(T, 19);
	cout << "TIPO LITERAL:";
	gotoxy(T,21);
	cout << "CARACTERE: Char, VarChar";
	gotoxy(T, 23);
	cout << "O tipo Char sempre ocupara a quantidade definida de espa�os";
	gotoxy(T, 25);
	cout << "O tipo VarChar n�o precisar o ocupar a quantidade de espa�os definidas";
	gotoxy(T, 27);
	cout << "TEXTO: TinyText, Text, MediumText, LongText";
	gotoxy(T, 29);
	cout << "BIN�RIO: TinyBlob, Blob, MediumBlob, LongBlob";
	gotoxy(T, 31);
	cout << "COLE��O: Enum, Set";
	gotoxy(T, 32);
	linha();
	gotoxy(T, 34);
	cout << "ESPACIAL: Geometry, Point, Polygon, Multipolygon";
	getch();
}

void createTable() {
	cout << "CREATE TABLE";
	gotoxy(T, 5);
	cout << "CREATE TABLE � usado para criar tabelas dentro do Bando de Daos";
	gotoxy(T, 7);
	cout << "Ap�s digitar \"create table\" coloque um nome";
	gotoxy(T, 9);
	cout << "em seguida abra o parent�nses. ";
	gotoxy(T, 11);
	cout << "Dentro do parenteses ser�o nomeados os atributos e seu tipos primitivos";
	gotoxy(T, 13);
	cout << "separados por v�rgula";
	gotoxy(T, 15);
	cout << "Segue o exemplo:";
	gotoxy(T, 17);
	amarelo();
	cout << "mysql> create table `pessoa`(nome varchar(30), idade int(3), sexo char(1), altura decimal(3,2));";
	branco();
	gotoxy(T, 19);
	cout << "int(3) significa que esse tipo inteiro vai ter 3 bytes";
	gotoxy(T, 21);
	cout << "decimal(3,2) significa que o numero vai ter 3 casas e v�rgula ser� antes dos dois �ltimos";
	gotoxy(T, 23);
	cout << "O ultimo parametro n�o precisa de v�rgula. A v�rgula significa que outro parametro ser� declarado";
	getch();
}

void showTables() {
	cout << "SHOW TABLES";
	gotoxy(T, 5);
	cout << "SHOW TABLES � o comando usado para mostras as tabelas dispon�veis dentro de um Bando de Dados";
	gotoxy(T, 7);
	cout << "Ap�s digitar o comando \"show tables\" finalize com ponto e v�rgula(;)";
	gotoxy(T, 9);
	cout << "Segue o exemplo:";
	amarelo();
	gotoxy(T, 11);
	cout << "mysql> show tables;";
	branco();
	getch();
}

void describeNameTable() {
	cout << "DESCRIBE";
	gotoxy(T, 5);
	cout << "DESCRIBE � o comando usado para mostrar a estrutura de uma tabela";
	gotoxy(T, 7);
	cout << "como nome dos atributos e os tipos deles, entre outras coisas";
	gotoxy(T, 9);
	cout << "Ap�s digitar o comando \"describe\" digite o nome da tabela";
	gotoxy(T, 11);
	cout << "e finalize com ponto e v�rgula(;)";
	gotoxy(T, 13);
	cout << "Segue o exemplo:";
	amarelo();
	gotoxy(T, 15);
	cout << "mysql> describe `nomedatabela`;";
	branco();
	getch();
}

void dropTable() {
	cout << "DROP TABLE";
	gotoxy(T, 5);
	cout << "DROP TABLE � o comando usado para excluir uma tabela";
	gotoxy(T, 7);
	cout << "Ap�s digitar o comando \"drop table\" digite o nome da";
	gotoxy(T, 9);
	cout << "tabela que ser� apagada e finalize com ponto e v�rgula(;)";
    gotoxy(T, 11);
	cout << "Segue o exemplo:";
	gotoxy(T, 13);
	amarelo();
	cout << "mysql> drop table `nomedatabela`;";
	branco();
	getch();
}

void padraoUTF8() {
	cout << "PADR�O UTF8";
	gotoxy(T, 5);
	cout << "O PADR�O utf8 � usado para que o Bando de Dados ou a tabela aceitem as acentua��es";
	gotoxy(T, 7);
	cout << "Esse padr�o � definido na cri���o do banco e na cria��o da tabela";
	gotoxy(T, 9);
	cout << "Segue o exemplo:";
	amarelo();
	gotoxy(T, 11);
	cout << "mysql> create database `nomedobanco`";
	gotoxy(T, 13);
	cout << "default character set utf8";
	gotoxy(T, 15);
	cout << "default collate utf8_general_ci;";
	branco();
	gotoxy(T, 17);
	cout << "Exemplo com tabela:";
	gotoxy(T, 19);
	amarelo();
	cout << "mysql> create table `nomedatabela` ([atributos]) default charset = utf8;";
	gotoxy(T, 21);
	branco();
	cout << "A sigla utf8 deve ser escrita em min�scula";
	getch();
}

void chavePrimaria() {
	cout << "CHAVE PRIM�RIA + APRIMORAMENTOS";
	gotoxy(T, 5);
	cout << "Chave prim�ria � o atributo que identifica uma linha da tabela como �nica";
	gotoxy(T, 7);
	cout << "A linha ser� onde o usu�rio ir� preencher os campos de cada atributo";
	gotoxy(T, 9);
	cout << "Segue o exemplo:";
	gotoxy(T, 11);
	amarelo();
	cout << "mysql> create table `jogador`(";
	gotoxy(T, 13);
	cout << "id int not null auto_increment,";
	gotoxy(T, 15);
	cout << "nome varchar(20) not null,";
	gotoxy(T, 17);
	cout << "nascimento date default '2017-01-01',";
	gotoxy(T, 19);
	cout << "sexo enum('M','F'),";
	gotoxy(T, 21);
	cout << "primary key(id) )default charset=utf8;";
	branco();

	gotoxy(T, 23);
	cout << "NOT NULL indica que esse campo n�o aceita nulo. Ele precisar� ser preenchido obrigat�riamente.";
	gotoxy(T, 25);
	cout << "AUTO_INCREMENT indica que o atributo ser� incrementado de 1 em 1 a cada nova linha";
	gotoxy(T, 27);
	cout << "DATE indica que esse atributo vai receber ANO-M�S-DIA.";
	gotoxy(T, 29);
    cout<<"N�o se pode guardar `idade` num banco por que as idades mudam constantemente,";
	gotoxy(T, 31);
	cout <<"por isso � prefer�vel guardar a data de nascimento.";
	gotoxy(T, 33);
	cout << "DEFAULT � um par�mentro que vai ser colocado caso o campo n�o seja preenchido pelo usu�rio";
	gotoxy(T, 35);
	cout << "ENUM('M','F') indica que nesse campo ser� preenchido apenas o caractere 'M' ou 'F', mais nenhum outro ser� aceito";
	gotoxy(T, 37);
	cout << "PRIMARY KEY(id) est� definindo que o atributo `id` ser� a chave prim�ria da tabela.";
	getch();
}


// Fun��es para mudar a cor de uma frase

void amarelo() {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN);
}

void branco() {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void mensagem() {
	gotoxy(T, 5);
	cout << "S� UMA MENSAGEM  PARA O CASO DE ALGUEM USAR ISTO AL�M DE MIM.";
	gotoxy(T, 7);
	cout << "DESCULPE OS ERROS DE PORTUGU�S, EU DIGITEI TUDO SOZINHO.";
	gotoxy(T, 9);
	cout<<"MEU INTERESSE ERA S� ESTUDAR OS COMANDOS DO MYSQL.";
	getch();
	system("cls");
}