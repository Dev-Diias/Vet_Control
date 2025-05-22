//Escreva um programa para criar as seguintes estruturas que simularão arquivos sequenciais para uma aplicação de Controle Clínica Veterinária:
//
//Cidades: código (PK), nome, UF
//
//Raças: código (PK), descrição
//
//Animais: código (PK), nome, código da raça, idade, peso, código do tutor
//
//Tutores: código (PK), nome, CPF, endereço, código da cidade
//
//Veterinários: código (PK), nome, endereço, código da cidade
//
//Consultas: código (PK), código do Animal, código do Veterinário, data da consulta, valor da consulta
//
//
//1) Escreva funções específicas para a leitura dos dados das estruturas.
//
//2) Escreva uma função para permitir a inclusão de novos registros na tabela de tutores. 
//2.1) Quando o usuário digitar o CPF, o programa deverá realizar a validação do CPF.
//2.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e o estado.
//
//3) Escreva uma função para permitir a inclusão de novos registros na tabela de animais.
//3.1) Quando o usuário digitar o código da raça, o programa deverá buscar este código na tabela de raças e exibir a descrição.
//3.2) Quando o usuário digitar o código do tutor, o programa deverá buscar este código na tabela de tutores e exibir o nome do tutor e o nome de sua cidade.
//
//4) Escreva uma função para permitir ao usuário realizar uma consulta.
//4.1) O código da consulta (PK) deverá ser gerado automaticamente e sequencialmente a partir do último registro cadastrado.
//4.2) O usuário deverá informar o código do animal e o programa deverá buscar este código na tabela de Animais e exibir a seu nome, o nome da raça e o nome do tutor.
//4.3) O usuário deverá informar o código do veterinário e o programa deverá buscar este código na tabela de Veterinários e exibir seu nome e o nome de sua cidade.
//4.4) O usuário deverá informar a data da consulta e o valor da consulta.
//
//5) Escreva uma função para exibir todas as consultas realizadas em determinado intervalo de datas (data inicial e data final).
//5.1) Os seguintes dados devem ser exibidos: nome do animal, nome do veterinário, data da consulta, valor da consulta.
//5.2) Ao final, a função deverá exibir o valor total das consultas.
//
//6) Escreva uma função para exibir todas as consultas realizadas em determinado intervalo de datas (data inicial e data final) para determinado Veterinário.
//6.1) Os seguintes dados devem ser exibidos: nome do animal, nome do veterinário, data da consulta, valor da consulta.
//6.2) Ao final, a função deverá exibir o valor total das consultas.
//
//Todas as funções descritas acima deverão ser chamadas através de um menu de opções que será chamado a partir da função main().


#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>
#include <locale.h>
#include <cstdlib>

using namespace std;

struct CIDADE {
    int codigo;
    char nome[35];
};

struct RACAS {
    int codigo;
    char descricao[30];
};

struct TUTORES {
    int codigo;
    char nome[50];
    char cpf[15];
    char endereco[50];
    int codigoCidade;
};

struct ANIMAIS {
    int codigo;
    char nome[40];
    int codigoRaca;
    int idade;
    float peso;
    int codigoTutor;
};

struct VETERINARIOS {
    int codigo;
    char nome[50];
    char endereco[50];
    int codigoCidade;
};

struct CONSULTAS {
    int codigo;
    int codigoAnimal;
    int codigoVeterinario;
    char dataConsulta[11]; // formato: "dd/mm/yyyy"
    float valorConsulta;
};


//FUNCOES DE LEITURA

void ler_cid(struct CIDADE v[], int &cont_cid){
	int i=0;
		cout << "\n=======================================\n";
		cout << "          CADASTRO DE CIDADE             \n";
		cout << "  (Digite 0 para finalizar o cadastro)   \n";
		cout << "=========================================\n";
	
	
	for (int s=1; i<20 && s!=0; i++){
		cout << "\nDigite o Codigo da Cidade " << i+1 << " : ";
		cin >> v[i].codigo;
		if(v[i].codigo>0){
			
			cin.ignore();
			cout << "Nome........................: ";
			cin.getline(v[i].nome,30);	
				
			
			cout << "UF..........................: ";
			cin >> v[i].UF;
			cout << endl << endl;
		}
		else s=0;
	}
	cont_cid = i;
}



void ler_racas(struct RACAS v[], int &cont_racas) {
    int i = 0;
    cout << "\n=======================================\n";
    cout << "          CADASTRO DE RAÇAS              \n";
    cout << "  (Digite 0 para finalizar o cadastro)   \n";
    cout << "=========================================\n";

    for (int s = 1; i < 20 && s != 0; i++) {
        cout << "\nDigite o Codigo da Raça " << i + 1 << " : ";
        cin >> v[i].codigo;

        if (v[i].codigo > 0) {
            cin.ignore();
            cout << "Descrição...................: ";
            cin.getline(v[i].descricao, 30);
        } else {
            s = 0;
        }
    }
    cont_racas = i;
}



void ler_tutores(struct TUTORES v[], int &cont_tutores) {
    int i = 0;
    cout << "\n=======================================\n";
    cout << "          CADASTRO DE TUTORES            \n";
    cout << "  (Digite 0 para finalizar o cadastro)   \n";
    cout << "=========================================\n";

    for (int s = 1; i < 20 && s != 0; i++) {
        cout << "\nDigite o Codigo do Tutor " << i + 1 << " : ";
        cin >> v[i].codigo;

        if (v[i].codigo > 0) {
            cin.ignore();
            cout << "Nome.........................: ";
            cin.getline(v[i].nome, 50);
            cout << "CPF..........................: ";
            cin.getline(v[i].cpf, 15);
            cout << "Endereço.....................: ";
            cin.getline(v[i].endereco, 50);
            cout << "Código da Cidade.............: ";
            cin >> v[i].codigoCidade;
        } else {
            s = 0;
        }
    }
    cont_tutores = i;
}



void ler_animais(struct ANIMAIS v[], int &cont_animais) {
    int i = 0;
    cout << "\n=======================================\n";
    cout << "          CADASTRO DE ANIMAIS            \n";
    cout << "  (Digite 0 para finalizar o cadastro)   \n";
    cout << "=========================================\n";

    for (int s = 1; i < 20 && s != 0; i++) {
        cout << "\nDigite o Codigo do Animal " << i + 1 << " : ";
        cin >> v[i].codigo;

        if (v[i].codigo > 0) {
            cin.ignore();
            cout << "Nome.........................: ";
            cin.getline(v[i].nome, 40);
            cout << "Código da Raça...............: ";
            cin >> v[i].codigoRaca;
            cout << "Idade........................: ";
            cin >> v[i].idade;
            cout << "Peso.........................: ";
            cin >> v[i].peso;
            cout << "Código do Tutor..............: ";
            cin >> v[i].codigoTutor;
        } else {
            s = 0;
        }
    }
    cont_animais = i;
}



void ler_veterinarios(struct VETERINARIOS v[], int &cont_veterinarios) {
    int i = 0;
    cout << "\n=======================================\n";
    cout << "        CADASTRO DE VETERINÁRIOS         \n";
    cout << "  (Digite 0 para finalizar o cadastro)   \n";
    cout << "=========================================\n";

    for (int s = 1; i < 20 && s != 0; i++) {
        cout << "\nDigite o Codigo do Veterinário " << i + 1 << " : ";
        cin >> v[i].codigo;

        if (v[i].codigo > 0) {
            cin.ignore();
            cout << "Nome.........................: ";
            cin.getline(v[i].nome, 50);
            cout << "Endereço.....................: ";
            cin.getline(v[i].endereco, 50);
            cout << "Código da Cidade.............: ";
            cin >> v[i].codigoCidade;
        } else {
            s = 0;
        }
    }
    cont_veterinarios = i;
}



void ler_consultas(struct CONSULTAS v[], int &cont_consultas) {
    int i = 0;
    cout << "\n=======================================\n";
    cout << "         CADASTRO DE CONSULTAS           \n";
    cout << "  (Digite 0 para finalizar o cadastro)   \n";
    cout << "=========================================\n";

    for (int s = 1; i < 20 && s != 0; i++) {
        cout << "\nDigite o Codigo da Consulta " << i + 1 << " : ";
        cin >> v[i].codigo;

        if (v[i].codigo > 0) {
            cout << "Código do Animal.............: ";
            cin >> v[i].codigoAnimal;
            cout << "Código do Veterinário........: ";
            cin >> v[i].codigoVeterinario;
            cin.ignore();
            cout << "Data da Consulta (dd/mm/yyyy): ";
            cin.getline(v[i].dataConsulta, 11);
            cout << "Valor da Consulta............: ";
            cin >> v[i].valorConsulta;
        } else {
            s = 0;
        }
    }
    cont_consultas = i;
}

