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
//------FEITO-------1) Escreva funções específicas para a leitura dos dados das estruturas.
//
//------FEITO-------2) Escreva uma função para permitir a inclusão de novos registros na tabela de tutores. 
//------FEITO-------2.1) Quando o usuário digitar o CPF, o programa deverá realizar a validação do CPF.
//------FEITO-------2.2) Quando o usuário digitar o código da cidade, o programa deverá buscar este código na tabela de Cidades e exibir o nome da cidade e o estado.
//
//------FEITO-------3) Escreva uma função para permitir a inclusão de novos registros na tabela de animais.
//------FEITO-------3.1) Quando o usuário digitar o código da raça, o programa deverá buscar este código na tabela de raças e exibir a descrição.
//------FEITO-------3.2) Quando o usuário digitar o código do tutor, o programa deverá buscar este código na tabela de tutores e exibir o nome do tutor e o nome de sua cidade.
//
//------FEITO-------4) Escreva uma função para permitir ao usuário realizar uma consulta.
//------FEITO-------4.1) O código da consulta (PK) deverá ser gerado automaticamente e sequencialmente a partir do último registro cadastrado.
//------FEITO-------4.2) O usuário deverá informar o código do animal e o programa deverá buscar este código na tabela de Animais e exibir a seu nome, o nome da raça e o nome do tutor.
//------FEITO-------4.3) O usuário deverá informar o código do veterinário e o programa deverá buscar este código na tabela de Veterinários e exibir seu nome e o nome de sua cidade.
//------FEITO-------4.4) O usuário deverá informar a data da consulta e o valor da consulta.
//
//------FEITO-------5) Escreva uma função para exibir todas as consultas realizadas em determinado intervalo de datas (data inicial e data final).
//------FEITO-------5.1) Os seguintes dados devem ser exibidos: nome do animal, nome do veterinário, data da consulta, valor da consulta.
//------FEITO-------5.2) Ao final, a função deverá exibir o valor total das consultas.
//
//------FEITO-------6) Escreva uma função para exibir todas as consultas realizadas em determinado intervalo de datas (data inicial e data final) para determinado Veterinário.
//------FEITO-------6.1) Os seguintes dados devem ser exibidos: nome do animal, nome do veterinário, data da consulta, valor da consulta.
//------FEITO-------6.2) Ao final, a função deverá exibir o valor total das consultas.
//
//------FEITO-------Todas as funções descritas acima deverão ser chamadas através de um menu de opções que será chamado a partir da função main().


#include <iostream>
#include <conio.h>
#include <string>
#include <cstring>
#include <locale.h>
#include <cstdlib>
#include <locale.h>


using namespace std;

struct CIDADE {
    int codigo;
    char nome[35];
    char uf[3];
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
    char dataConsulta[11]; 
    float valorConsulta;
};



void ler_cid(struct CIDADE v[], int &cont_cid){
    int i = 0;
    int s = 1;
    cout << "\n=======================================\n";
    cout << "          CADASTRO DE CIDADE             \n";
    cout << "  (Digite 0 para finalizar o cadastro)   \n";
    cout << "=========================================\n";

    while (i < 20 && s != 0) {
        cout << "\nDigite o Codigo da Cidade " << i + 1 << " : ";
        cin >> v[i].codigo;

        if (v[i].codigo == 0) {
            s = 0;
            break;
        }

        
        bool repetido = false;
        for (int j = 0; j < i; j++) {
            if (v[i].codigo == v[j].codigo) {
                cout << "+--------------------------------------------+\n";
                cout << "|                                            |\n";
                cout << "|             CODIGO REPETIDO!!              |\n";
                cout << "|                                            |\n";
                cout << "+--------------------------------------------+\n";
                repetido = true;
                break;
            }
        }

        if (repetido) {
            
            continue;
        }

       
        cin.ignore();
        cout << "Nome........................: ";
        cin.getline(v[i].nome, 30);

        cout << "UF..........................: ";
        cin >> v[i].uf;
        cout << endl << endl;

        i++; 
    }

    cont_cid = i;
}



int buscaBinariaTutorCod(struct TUTORES Tut[], int &cont_tut, int cod){
	int i = 0, f = cont_tut - 1; 
    int m = (i + f) / 2;
    for (; f >= i && cod != Tut[m].codigo; m = (i + f) / 2){
        if (cod > Tut[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
	
	if (f >= i) {
        return m; 
    } else {
        return -1; 
    }
}



int buscaBinariaTutorCidade(struct CIDADE city[], int &cont_tut, int cidade){
	int i = 0, f = cont_tut - 1; 
    int m = (i + f) / 2;
    for (; f >= i && cidade != city[m].codigo; m = (i + f) / 2){
        if (cidade > city[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
	
	if (f >= i) {
        return m; 
    } else {
        return -1; 
    }
}



int buscaBinariaTutor(struct TUTORES Tut[], int cont_tut, const char cpfBusca[]) {
    int i = 0, f = cont_tut - 1;
    int m;

    while (i <= f) {
        m = (i + f) / 2;

        int cmp = strcmp(cpfBusca, Tut[m].cpf);

        if (cmp == 0) {
            return m;  
        } else if (cmp > 0) {
            i = m + 1;  
        } else {
            f = m - 1;  
        }
    }

    return -1; 
}



void ler_tutores(struct TUTORES v[], struct CIDADE cid[], int cont_cit, int &cont_ins){
    int i = 0;
    cout << "\n=======================================\n";
    cout << "          CADASTRO DE TUTOR              \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=======================================\n\n";

    for (; i < 5; ) {
        cout << "Digite o Codigo do Tutor........: ";
        cin >> v[i].codigo;

        if (v[i].codigo <= 0) {
            break;
        }

        
        int j = 0;
        for (; j < i; j++) {
            if (v[i].codigo == v[j].codigo) {
                cout << "+--------------------------------------------+\n";
                cout << "|                                            |\n";
                cout << "|             CODIGO REPETIDO!!              |\n";
                cout << "|                                            |\n";
                cout << "+--------------------------------------------+\n";
                break;
            }
        }

        if (j != i) {
            continue;  
        } else {
            cin.ignore();

        cout << "Nome............................: ";
        cin.getline(v[i].nome, 30);

            
            do {
        cout << "CPF.............................: ";
                cin.getline(v[i].cpf, 30);

                if (buscaBinariaTutor(v, i, v[i].cpf) != -1) {
                    cout << "+--------------------------------------------+\n";
                    cout << "|                                            |\n";
                    cout << "|              CPF REPETIDO!!                |\n";
                    cout << "|                                            |\n";
                    cout << "+--------------------------------------------+\n";
                } else {
                    break;  
                }
            } while (true);

        cout << "Endereco........................: ";
        cin.getline(v[i].endereco, 30);

            do {
    	cout << "Codigo da Cidade do Tutor.......: ";
   	 	cin >> v[i].codigoCidade;

    int achou_cid = buscaBinariaTutorCidade(cid, cont_cit, v[i].codigoCidade);

    if (achou_cid != -1) {
    	cout << endl;
    	cout << "===============" << endl;
		cout << "Dados da Cidade|" << endl;
		cout << "===============" << endl;
		cout << cid[achou_cid].nome <<  endl;
		cout << cid[achou_cid].uf << endl;
	

        
        break;  
    } else {
        cout << "+--------------------------------------------+\n";
        cout << "|                                            |\n";
        cout << "|  Codigo nao corresponde a uma cidade!      |\n";
        cout << "|  Por favor, digite novamente.              |\n";
        cout << "|                                            |\n";
        cout << "+--------------------------------------------+\n";
    }
} while (true);

            cout << "\n\n";
            i++;
        }
    }

    cont_ins = i;
}



void inclusao(struct TUTORES S[], int contS, struct TUTORES T[], int contT, struct TUTORES A[], int &contA) {
    int k = 0;

    
    for (int i = 0; i < contS; i++) {
        A[k++] = S[i];
    }

    
    for (int j = 0; j < contT; j++) {
        A[k++] = T[j];
    }

    contA = k;  

     
    for (int i = 1; i < contA; i++) {
        struct TUTORES temp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j].codigo > temp.codigo) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}



void CAD_TUTORES(struct TUTORES T[], struct CIDADE cid[], int cont_cit, int &cont_tut, struct TUTORES S[], int conts) {
    int j = cont_tut; 
	cout << "\n=======================================\n";
    cout << "          CADASTRAR NOVOS TUTORES        \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=========================================\n";
    cout << endl;

    for (; j < 20; j++) {
        cout << endl;

        while (true) {
            cout << "Digite o codigo do Tutor......: ";
            cin >> T[j].codigo;
            cin.ignore();

            if (T[j].codigo <= 0) {
                cont_tut = j;  
                return;
            }

         
            int repetido = 0;
            for (int q = 0; q < j; q++) {
                if (T[j].codigo == T[q].codigo) {
                    cout << "+--------------------------------------------+\n";
                    cout << "|             CODIGO REPETIDO!!              |\n";
                    cout << "+--------------------------------------------+\n";
                    repetido = 1;
                    break;
                }
            }
            if (repetido) continue;

            
            int achou = buscaBinariaTutorCod(S, conts, T[j].codigo);
            if (achou > -1) {
                cout << "+--------------------------------------------+" << endl;
                cout << "|  CODIGO INVALIDO, ESSE TUTOR JA EXISTE     |" << endl;
                cout << "+--------------------------------------------+" << endl;
                continue;
            }

            break;
        }

        cout << "Nome..........................: ";
        cin.getline(T[j].nome, 50);

        while (true) {
            cout << "CPF...........................: ";
            cin >> T[j].cpf;
            cin.ignore();

            if (strcmp(T[j].cpf, "0") == 0) {
                cont_tut = j;
                return;
            }

            int repetidoc = 0;
            for (int f = 0; f < j; f++) {
                if (strcmp(T[j].cpf, T[f].cpf) == 0) {
                    cout << "+--------------------------------------------+\n";
                    cout << "|               CPF REPETIDO!!               |\n";
                    cout << "+--------------------------------------------+\n";
                    repetidoc = 1;
                    break;
                }
            }
            if (repetidoc) continue;

            int achou2 = buscaBinariaTutor(S, conts, T[j].cpf);
            if (achou2 > -1) {
                cout << "+--------------------------------------------+" << endl;
                cout << "|  CPF INVALIDO, ESSE USUARIO JA EXISTE      |" << endl;
                cout << "+--------------------------------------------+" << endl;
                continue;
            }

            break;
        }

        cout << "Endereco......................: ";
        cin.getline(T[j].endereco, 50);

        do {
            cout << "Codigo da Cidade do Tutor.....: ";
            cin >> T[j].codigoCidade;

            int achou_cid = buscaBinariaTutorCidade(cid, cont_cit, T[j].codigoCidade);

            if (achou_cid != -1) {
            cout << "===============" << endl;
			cout << "Dados da Cidade|" << endl;
			cout << "===============" << endl;
                cout << cid[achou_cid].nome << endl;
                cout << cid[achou_cid].uf << endl;
                
                break;
            } else {
                cout << "+--------------------------------------------+\n";
                cout << "|  Codigo nao corresponde a uma cidade!      |\n";
                cout << "+--------------------------------------------+\n";
            }
        } while (true);

        cout << endl << endl;
    }

    cont_tut = j;  
}



void mostrar_tutor(struct TUTORES A[], int contA, struct CIDADE V[], int contC){
     cout << "\n+---------------------+\n";
    cout << "|  DADOS DE TUTORES   |\n";
    cout << "+------------------------+\n";
    for (int i = 0; i < contA; i++) {
        cout << "\nCodigo..........: " << A[i].codigo;
        cout << "\tNome............: " << A[i].nome;
        cout << "\tCPF.............: " << A[i].cpf;
        cout << "\tEndereco........: " << A[i].endereco;
        
        int j = 0;
        for (; j<contC; j++){
        if(A[i].codigoCidade == V[j].codigo){
        
        cout << "\tNome Da Cidade..: " << V[j].nome;
        cout << "\tEstado Da Cidade: " << V[j].uf;
        	break;
		} 
		
	}
	if(j==contC){
		cout <<  "\tNao Existe Cidade Com o Codigo " << A[i].codigoCidade;
	}
       cout << endl; 
 }
}



int buscaBinariaAnimal(struct RACAS rc[], int &cont_rc, int cod){
	int i = 0, f = cont_rc - 1; 
    int m = (i + f) / 2;
    for (; f >= i && cod != rc[m].codigo; m = (i + f) / 2){
        if (cod > rc[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
	
	if (f >= i) {
        return m; 
    } else {
        return -1; 
    }
}



int buscaBinariaAnimalCod(struct ANIMAIS ani[], int &cont_ani, int cod){
	int i = 0, f = cont_ani - 1; 
    int m = (i + f) / 2;
    for (; f >= i && cod != ani[m].codigo; m = (i + f) / 2){
        if (cod > ani[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
	
	if (f >= i) {
        return m; 
    } else {
        return -1; 
    }
}



void inclusao_ani(struct ANIMAIS S[], int contS, struct ANIMAIS T[], int contT, struct ANIMAIS A[], int &contA) {
    int k = 0;

    
    for (int i = 0; i < contS; i++) {
        A[k++] = S[i];
    }

    
    for (int j = 0; j < contT; j++) {
        A[k++] = T[j];
    }

    contA = k;  

     
    for (int i = 1; i < contA; i++) {
        struct ANIMAIS temp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j].codigo > temp.codigo) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}



void ler_racas(struct RACAS v[], int &cont_racas) {
    int i = 0;
    cout << "\n=======================================\n";
    cout << "          CADASTRO DE RACAS            \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=======================================\n";

    for (; i < 20; ) {
        cout << "\nDigite o Codigo da Raca " << i + 1 << "...: ";
        cin >> v[i].codigo;

        if (v[i].codigo <= 0) {
            break;  
        }

        
        int j = 0;
        for (; j < i; j++) {
            if (v[i].codigo == v[j].codigo) {
                cout << "+--------------------------------------------+\n";
                cout << "|                                            |\n";
                cout << "|             CODIGO REPETIDO!!              |\n";
                cout << "|                                            |\n";
                cout << "+--------------------------------------------+\n";
                break;
            }
        }

        if (j != i) {
            continue;  
        } else {
            cin.ignore();
        cout << "Descricao...................: ";
            cin.getline(v[i].descricao, 30);
            i++;  
        }
    }

    cont_racas = i;
}



void ler_animais(struct ANIMAIS v[], struct RACAS V_rc[], int cont_rc, struct TUTORES tut[], int cont_tut,
struct CIDADE cit[], int cont_cit, int &cont_ins){
    int i = 0;
    cout << "\n=======================================\n";
    cout << "          CADASTRO DE ANIMAIS            \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=======================================\n\n";

    for (; i < 5; ) {
        cout << "Digite o Codigo do Animal.....: ";
        cin >> v[i].codigo;

        if (v[i].codigo <= 0) {
            break;
        }

        
        int j = 0;
        for (; j < i; j++) {
            if (v[i].codigo == v[j].codigo) {
                cout << "+--------------------------------------------+\n";
                cout << "|                                            |\n";
                cout << "|             CODIGO REPETIDO!!              |\n";
                cout << "|                                            |\n";
                cout << "+--------------------------------------------+\n";
                break;
            }
        }

        if (j != i) {
            continue;  
        } else {
            cin.ignore();

        cout << "Nome..........................: ";
        cin.getline(v[i].nome, 30);

        
 do {
    	cout << "Codigo da Raca................: ";
                cin >> v[i].codigoRaca;
int achou_rc = buscaBinariaAnimal(V_rc, cont_rc, v[i].codigoRaca);

    if (achou_rc != -1) {
        cout << "Descricao.....................: " << V_rc[achou_rc].descricao << endl;
        break;  
    } else {
        cout << "+--------------------------------------------+\n";
        cout << "|                                            |\n";
        cout << "|  Codigo nao corresponde a uma raca!        |\n";
        cout << "|  Por favor, digite novamente.              |\n";
        cout << "|                                            |\n";
        cout << "+--------------------------------------------+\n";
    }
} while (true);

        cout << "Idade.........................: ";
       cin >> v[i].idade;
       
		cout << "Peso..........................: ";
       cin >> v[i].peso;
       
            do {
        cout << endl;
    	cout << "Codigo do Tutor...............: ";
   	 	cin >> v[i].codigoTutor;

    int achou_tutor = buscaBinariaTutorCod(tut, cont_tut, v[i].codigoTutor);

    if (achou_tutor != -1) {
        cout << "Nome do Tutor.................: " << tut[achou_tutor].nome << endl;
        
        int achou_cidade = buscaBinariaTutorCidade(cit, cont_cit, tut[achou_tutor].codigoCidade);
        
        
        if (achou_cidade != -1){
       	cout << "Cidade do Tutor...............: " << cit[achou_cidade].nome << endl;
		} else{
		cout << "+--------------------------------------------+\n";
        cout << "|                                            |\n";
        cout << "|      Cidade nao encontrada                 |\n";
        cout << "|  Por favor, digite novamente.              |\n";
        cout << "|                                            |\n";
        cout << "+--------------------------------------------+\n";
		}
	
        break;
		 
    } else {
        cout << "+--------------------------------------------+\n";
        cout << "|                                            |\n";
        cout << "|  Codigo nao corresponde a uma Tutor!       |\n";
        cout << "|  Por favor, digite novamente.              |\n";
        cout << "|                                            |\n";
        cout << "+--------------------------------------------+\n";
    }
} while (true);

            cout << "\n\n";
            i++;
        }
    }

    cont_ins = i;
}



void CAD_ANIMAIS(struct ANIMAIS T[], struct RACAS V_rc[], int cont_rc, struct TUTORES tut[], int cont_tut,
                 struct CIDADE cit[], int cont_cit, struct ANIMAIS S[], int cont_aniS, int &cont_aniT) {

    cout << "\n=======================================\n";
    cout << "          CADASTRAR DE NOVOS ANIMAIS      \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=======================================\n\n";

    while (true) {
        cout << "Digite o codigo do Animal.........: ";
        int codigo;
        cin >> codigo;
        cin.ignore();

        if (codigo <= 0) {
            break;  
        }

       
        bool repetido = false;
        for (int q = 0; q < cont_aniT; q++) {
            if (codigo == T[q].codigo) {
                cout << "+--------------------------------------------+\n";
                cout << "|             CODIGO REPETIDO!!              |\n";
                cout << "+--------------------------------------------+\n";
                repetido = true;
                break;
            }
        }
        if (repetido) {
            continue;  
        }

        
        int achou = buscaBinariaAnimalCod(S, cont_aniS, codigo);
        if (achou != -1) {
            cout << "+--------------------------------------------+" << endl;
            cout << "|  CODIGO INVALIDO, ESSE ANIMAL JA EXISTE    |" << endl;
            cout << "+--------------------------------------------+" << endl;
            continue;
        }

        
        T[cont_aniT].codigo = codigo;
			
        	cout << "Nome..............................: ";
        cin.getline(T[cont_aniT].nome, 30);

        do {
            cout << "Codigo da Raca....................: ";
            cin >> T[cont_aniT].codigoRaca;
            int achou_rc = buscaBinariaAnimal(V_rc, cont_rc, T[cont_aniT].codigoRaca);

            if (achou_rc != -1) {
            cout << "Descricao.........................: " << V_rc[achou_rc].descricao << endl;
                break;
            } else {
                cout << "+--------------------------------------------+\n";
                cout << "|  Codigo nao corresponde a uma raca!        |\n";
                cout << "+--------------------------------------------+\n";
            }
        } while (true);

        	cout << "Idade.............................: ";
        cin >> T[cont_aniT].idade;

        	cout << "Peso..............................: ";
        cin >> T[cont_aniT].peso;

        do {
        	cout << endl;
            cout << "Codigo do Tutor...................: ";
            cin >> T[cont_aniT].codigoTutor;

            int achou_tutor = buscaBinariaTutorCod(tut, cont_tut, T[cont_aniT].codigoTutor);

            if (achou_tutor != -1) {
            cout << "Nome do Tutor.....................: " << tut[achou_tutor].nome << endl;
                int achou_cidade = buscaBinariaTutorCidade(cit, cont_cit, tut[achou_tutor].codigoCidade);
                if (achou_cidade != -1) {
            cout << "Cidade do Tutor...................: " << cit[achou_cidade].nome << endl;
                } else {
                    cout << "+--------------------------------------------+\n";
                    cout << "|      Cidade nao encontrada                 |\n";
                    cout << "+--------------------------------------------+\n";
                }
                break;
            } else {
                cout << "+--------------------------------------------+\n";
                cout << "|  Codigo nao corresponde a um Tutor!        |\n";
                cout << "+--------------------------------------------+\n";
            }
        } while (true);
		cout << "\n\n";
        cont_aniT++;  
    }
}



void mostrar_animais(struct ANIMAIS A[], int cont_ani, struct RACAS V_rc[], int cont_rc, struct TUTORES tut[], int cont_tut, struct CIDADE cit[], int cont_cit) {
    cout << "\n+------------------------+\n";
    cout << "|    DADOS DE ANIMAIS    |\n";
    cout << "+------------------------+\n";

    for (int i = 0; i < cont_ani; i++) {
    	cout << endl;
        	cout << "\nCodigo...........: " << A[i].codigo;
        	cout << "\tNome.............: " << A[i].nome;

        int achou_rc = buscaBinariaAnimal(V_rc, cont_rc, A[i].codigoRaca);
        if (achou_rc != -1) {
            cout << "\tDescricao da Raca: " << V_rc[achou_rc].descricao;
        } else {
            cout << "\tDescricao da Raca: Nao encontrada";
        }

        	cout << "\nIdade............: " << A[i].idade;
        	cout << "\tPeso.............: " << A[i].peso;


        int achou_tutor = buscaBinariaTutorCod(tut, cont_tut, A[i].codigoTutor);
        if (achou_tutor != -1) {
            cout << "\tNome do Tutor....: " << tut[achou_tutor].nome;

            int achou_cidade = buscaBinariaTutorCidade(cit, cont_cit, tut[achou_tutor].codigoCidade);
            if (achou_cidade != -1) {
            cout << "\nCidade do Tutor..: " << cit[achou_cidade].nome;
            cout << "\tEstado...........: " << cit[achou_cidade].uf;
            } else {
            cout << "\nCidade do Tutor..: Nao encontrada";
            }
        } else {
            cout << "\tNome do Tutor....: Nao encontrado";
        }

        cout << endl;
    }
}



void consultar_ani(struct ANIMAIS A[], int cont_A, struct RACAS V_rc[], int cont_C, struct TUTORES I[], int cont_tut,
 struct CIDADE CI[], int cont_cit, int vet[], int cont_aux3){

		cout << "\n=======================================\n";
		cout << "          CONSULTA POR ANIMAIS           \n";
		cout << "=========================================\n";
		cout << endl;
		

for ( int i = 0,  cont = 1; i < cont_aux3; i++, cont++) {
	
        int animal_codigo = vet[i];
        
        cout << "\n\nConsultando Animal..." << endl;
        
int acho_b;

acho_b = buscaBinariaAnimalCod(A, cont_A, animal_codigo);


cout << "Nome Do Animal " << A[acho_b].codigo << "..: "<< A[acho_b].nome;

	
	
	if (acho_b > -1){
		int i_c = 0, f_c = cont_C - 1;
        int m_c = (i_c + f_c)/2;
        for (;f_c >= i_c && A[acho_b].codigoRaca != V_rc[m_c].codigo; m_c = (i_c + f_c) / 2){
        if(A[acho_b].codigoRaca > V_rc[m_c].codigo){
        	
          i_c = m_c + 1;
          
         }else{
		
            f_c = m_c - 1;
		}
	}
        
       if(A[acho_b].codigoRaca == V_rc[m_c].codigo){ 
        
        cout << "\nDescricao Da Raca.: " << V_rc[m_c].descricao;
		} 
		else {
			cout <<  "\nNao Existe Raca Com o Codigo " << A[acho_b].codigoRaca;;	
		} 
	
		
		int i_i = 0, f_i = cont_tut - 1;
        int m_i = (i_i + f_i)/2;
        for (;f_i >= i_i && A[acho_b].codigoTutor != I[m_i].codigo; m_i = (i_i + f_i) / 2){
        if(A[acho_b].codigoTutor > I[m_i].codigo){
        	
          i_i = m_i + 1;
          
         }else{
		
            f_i = m_i - 1;
		}
	}
        
       if(A[acho_b].codigoTutor == I[m_i].codigo){ 
        
        cout << "\nNome Do Tutor.....: " << I[m_i].nome;
        	
        int achou = -1;
        achou = buscaBinariaTutorCidade(CI, cont_cit, I[m_i].codigoCidade);
        	
        if(achou > -1){
        cout << "\nCidade Do Tutor...: " << CI[achou].nome;
		}
}
	
		 else {
			cout <<  "\nNao Existe Tutor Com o Codigo " << A[acho_b].codigoTutor;	
		} 
		
		
		
	}
	
	else {
            cout << "\nCodigo De Animal Nao Existente ";
        } 

	}
}



void ler_veterinarios(struct VETERINARIOS v[], int &cont_veterinarios, struct CIDADE cid[], int cont_cit) {
    int i = 0;
    cout << "\n=======================================\n";
    cout << "        CADASTRO DE VETERINARIOS         \n";
    cout << "  (Digite 0 para finalizar o cadastro)   \n";
    cout << "=========================================\n";

    for (int s = 1; i < 20 && s != 0; i++) {
        cout << "\nDigite o Codigo do Veterinario..." << ": ";
        cin >> v[i].codigo;
       int j = 0;
        for (; j < i; j++) {
            if (v[i].codigo == v[j].codigo) {
                cout << "+--------------------------------------------+\n";
                cout << "|                                            |\n";
                cout << "|             CODIGO REPETIDO!!              |\n";
                cout << "|                                            |\n";
                cout << "+--------------------------------------------+\n";
                break;
            }
        }

        if (j != i) {
            continue;  
        } else {
           

        if (v[i].codigo > 0) {
            cin.ignore();
            cout << "Nome.............................: ";
            cin.getline(v[i].nome, 50);
            cout << "Endereco.........................: ";
            cin.getline(v[i].endereco, 50);
            
            do {
            	cout << endl;
    		cout << "Codigo da Cidade do Veterinario..: ";
   	 	cin >> v[i].codigoCidade;

    int achou_cid = buscaBinariaTutorCidade(cid, cont_cit, v[i].codigoCidade);

    if (achou_cid != -1) {
    	
    	cout << "===============" << endl;
		cout << "Dados da Cidade|" << endl;
		cout << "===============" << endl;;
        cout << cid[achou_cid].nome << endl;
        cout << cid[achou_cid].uf << endl;
        break;
    } else {
        cout << "+--------------------------------------------+\n";
        cout << "|                                            |\n";
        cout << "|  Codigo nao corresponde a uma cidade!      |\n";
        cout << "|  Por favor, digite novamente.              |\n";
        cout << "|                                            |\n";
        cout << "+--------------------------------------------+\n";
    }
} while (true);
cout << endl << endl;

        } else {
            s = 0;
        }
    }
    cont_veterinarios = i;
}

}



int buscaBinariaVeterinarioCod(struct VETERINARIOS vet[], int &cont_vet, int cod){
	int i = 0, f = cont_vet - 1; 
    int m = (i + f) / 2;
    for (; f >= i && cod != vet[m].codigo; m = (i + f) / 2){
        if (cod > vet[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
	
	if (f >= i) {
        return m; 
    } else {
        return -1; 
    }
}



int buscaSequencialVeterinarioCod(struct VETERINARIOS A[], int cont_A, int codigo) {
    for (int i = 0; i < cont_A; i++) {
        if (A[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}



void consultar_vet(struct VETERINARIOS A[], int cont_A, struct CIDADE CI[], int cont_cit, int vet[], int cont_aux3) {
    cout << "\n=======================================\n";
    cout << "         CONSULTA POR VETERINARIO       \n";
    cout << "=========================================\n\n";

    for (int i = 0, cont = 1; i < cont_aux3; i++, cont++) {
        int veterinario_codigo = vet[i];
        cout << "\n\nConsultando Veterinario com codigo " << veterinario_codigo << "...\n";

        int acho_b = buscaSequencialVeterinarioCod(A, cont_A, veterinario_codigo);

        if (acho_b > -1) {
            cout << "Nome do Veterinario......: " << A[acho_b].nome << endl;
            cout << "Endereco.................: " << A[acho_b].endereco << endl;

           
            int pos_cidade = buscaBinariaTutorCidade(CI, cont_cit, A[acho_b].codigoCidade);

            if (pos_cidade != -1) {
                cout << "Descricao Da Cidade......: " << CI[pos_cidade].nome << endl;
            } else {            				            	
                cout << "Nao Existe Cidade Com o Codigo " << A[acho_b].codigoCidade << endl;
            }
        } else {
         
        	cout << "+--------------------------------------+\n";
    	 	cout << "| Codigo De Veterinario Nao Existente  |\n";
         	cout << "+--------------------------------------+\n";
        	
        }
    }
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



void cadastrar_consulta(struct CONSULTAS v[], int &cont_consultas,
                        struct ANIMAIS A[], int cont_A,
                        struct RACAS V_rc[], int cont_C,
                        struct TUTORES I[], int cont_tut,
                        struct VETERINARIOS V[], int cont_vet,
                        struct CIDADE CI[], int cont_cit) {

    int opcao = 1;

    cout << "\n=======================================\n";
    cout << "         CADASTRO DE CONSULTAS          \n";
    cout << "  (Digite 0 para finalizar o cadastro)  \n";
    cout << "=========================================\n";

    while (cont_consultas < 20 && opcao != 0) {
        v[cont_consultas].codigo = cont_consultas + 1;
        cout << "\nCodigo gerado da Consulta.....: " << v[cont_consultas].codigo << endl;

        
        int pos_animal = -1;
        do {
        	cout << "Informe o Codigo do Animal......: ";
            cin >> v[cont_consultas].codigoAnimal;

            pos_animal = buscaBinariaAnimalCod(A, cont_A, v[cont_consultas].codigoAnimal);

            if (pos_animal == -1) {
             
            cout << "+--------------------------------------+\n";
    	 	cout << "|        ANIMAL NAO ENCONTRADO!!       |\n";
         	cout << "+--------------------------------------+\n";
            	
            }
        } while (pos_animal == -1);
        
        	cout << "Nome do Animal..................: " << A[pos_animal].nome << endl;

        
        int pos_raca = -1;
        int i = 0, f = cont_C - 1, m;
        while (i <= f) {
            m = (i + f) / 2;
            if (A[pos_animal].codigoRaca == V_rc[m].codigo) {
                pos_raca = m;
                break;
            } else if (A[pos_animal].codigoRaca > V_rc[m].codigo) {
                i = m + 1;
            } else {
                f = m - 1;
            }
        }
        if (pos_raca != -1) {
            cout << "Descricao da Raca...............: " << V_rc[pos_raca].descricao << endl;
            
        } else {
         
        	cout << "+--------------------------------------+\n";
    	 	cout << "|        RACA NAO ENCONTRADA!!         |\n";
         	cout << "+--------------------------------------+\n";
        	
        }

       
        int pos_tutor = -1;
        i = 0, f = cont_tut - 1;
        while (i <= f) {
            m = (i + f) / 2;
            if (A[pos_animal].codigoTutor == I[m].codigo) {
                pos_tutor = m;
                break;
            } else if (A[pos_animal].codigoTutor > I[m].codigo) {
                i = m + 1;
            } else {
                f = m - 1;
            }
        }
        if (pos_tutor != -1) {
            cout << "Nome do Tutor...................: " << I[pos_tutor].nome << endl << endl;
        } else {
         
        	cout << "+--------------------------------------+\n";
    	 	cout << "|        TUTOR NAO ENCONTRADO!!        |\n";
         	cout << "+--------------------------------------+\n";
        	
        }

        
        int pos_vet = -1;
        do {
        
            cout << "Informe o Codigo do Veterinario.: ";
            cin >> v[cont_consultas].codigoVeterinario;

            pos_vet = buscaSequencialVeterinarioCod(V, cont_vet, v[cont_consultas].codigoVeterinario);

            if (pos_vet == -1) {
            	
         cout << "+--------------------------------------------+\n";
    	 cout << "|        VETERINARIO NAO ENCONTRADO!!        |\n";
         cout << "+--------------------------------------------+\n";
            }
        } while (pos_vet == -1);
        cout << "Nome do Veterinario.............: " << V[pos_vet].nome << endl << endl;

       
        int pos_cidade = buscaBinariaTutorCidade(CI, cont_cit, V[pos_vet].codigoCidade);
        if (pos_cidade != -1) {
            cout << "Nome da Cidade..................: " << CI[pos_cidade].nome << endl;
        } else {
            cout << "Cidade nao encontrada!" << endl << endl;
        }

        cin.ignore();
        cout << "Data da Consulta (dd/mm/yyyy)...: ";
        cin.getline(v[cont_consultas].dataConsulta, 11);
        cout << "Valor da Consulta...............: ";
        cin >> v[cont_consultas].valorConsulta;

        cont_consultas++;

        cout << "\nDeseja cadastrar outra consulta? (1-Sim / 0-Nao): ";
        cout << endl << endl;
        cin >> opcao;
    }
}



bool dataNoIntervalo(const char data[], const char dataInicial[], const char dataFinal[]) {
    return strcmp(data, dataInicial) >= 0 && strcmp(data, dataFinal) <= 0;
}


int dataParaInt(char data[]) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    return ano * 10000 + mes * 100 + dia;
}

void exibir_consultas_intervalo(struct CONSULTAS v[], int cont_consultas,
                                struct ANIMAIS A[], int cont_A,
                                struct VETERINARIOS V[], int cont_vet) {
    
    char dataInicial[11], dataFinal[11];
    float totalConsultas = 0.0;

    cout << "\n=======================================\n";
    cout << " EXIBIR CONSULTAS POR INTERVALO DE DATAS \n";
    cout << "=========================================\n";

    cout << "Informe a Data Inicial (dd/mm/yyyy): ";
    cin.ignore();
    cin.getline(dataInicial, 11);
    cout << "Informe a Data Final   (dd/mm/yyyy): ";
    cin.getline(dataFinal, 11);

    int data_ini = dataParaInt(dataInicial);
    int data_fim = dataParaInt(dataFinal);

    cout << "\nConsultas realizadas de " << dataInicial << " a " << dataFinal << ":\n";

    bool encontrou = false;

    for (int i = 0; i < cont_consultas; i++) {
        int data_consulta = dataParaInt(v[i].dataConsulta);

        if (data_consulta >= data_ini && data_consulta <= data_fim) {

            int pos_animal = buscaBinariaAnimalCod(A, cont_A, v[i].codigoAnimal);
            const char* nomeAnimal = (pos_animal != -1) ? A[pos_animal].nome : "Desconhecido";

            int pos_vet = buscaSequencialVeterinarioCod(V, cont_vet, v[i].codigoVeterinario);
            const char* nomeVet = (pos_vet != -1) ? V[pos_vet].nome : "Desconhecido";

            cout << "\n-------------------------------\n";
            cout << "Nome do Animal......: " << nomeAnimal << endl;
            cout << "Nome do Veterinario.: " << nomeVet << endl;
            cout << "Data da Consulta....: " << v[i].dataConsulta << endl;
            cout << "Valor da Consulta...: " << v[i].valorConsulta << endl;

            totalConsultas += v[i].valorConsulta;
            encontrou = true;
        }
    }

    if (!encontrou) {
        cout << "\n+------------------------------------------------+\n";
        cout << "| Nenhuma consulta encontrada nesse intervalo!   |\n";
        cout << "+------------------------------------------------+\n";
    }

    cout << "\n=======================================\n";
    cout << "Valor Total das Consultas: " << totalConsultas << endl;
}



void exibir_cons_vet(struct CONSULTAS v_consult[], int cont_consult,
                     struct ANIMAIS A[], int cont_A,
                     struct VETERINARIOS V[], int cont_vet) {
    
    char data_inicial[11], data_final[11];
    int codigo_vet;

    cout << "\n=============================================\n";
    cout << " CONSULTAS POR VETERINARIO E INTERVALO DE DATAS\n";
    cout << "===============================================\n";

    cout << "Informe o Codigo do Veterinario: ";
    cin >> codigo_vet;
    cin.ignore();  

    int achou_vet = buscaSequencialVeterinarioCod(V, cont_vet, codigo_vet);

    if (achou_vet == -1) {
        cout << "+--------------------------------------+\n";
        cout << "| Codigo De Veterinario Nao Existente  |\n";
        cout << "+--------------------------------------+\n";
        return;
    }

    cout << "Informe a Data Inicial (dd/mm/yyyy): ";
    cin.getline(data_inicial, 11);

    cout << "Informe a Data Final (dd/mm/yyyy): ";
    cin.getline(data_final, 11);

    int data_ini = dataParaInt(data_inicial);
    int data_fim = dataParaInt(data_final);

    float valor_total = 0.0;
    bool encontrou = false;

    cout << "\nConsultas realizadas pelo Veterinario: " << V[achou_vet].nome << endl;
    cout << "De " << data_inicial << " ate " << data_final << endl;

    for (int i = 0; i < cont_consult; i++) {

        if (v_consult[i].codigoVeterinario == codigo_vet) {
            int data_consulta = dataParaInt(v_consult[i].dataConsulta);

            if (data_consulta >= data_ini && data_consulta <= data_fim) {
                int pos_animal = buscaBinariaAnimalCod(A, cont_A, v_consult[i].codigoAnimal);

                cout << "\n-------------------------------\n";
                cout << "Nome do Animal......: ";
                if (pos_animal != -1) {
                    cout << A[pos_animal].nome << endl;
                } else {
                    cout << "+------------------------------+\n";
                    cout << "|        NAO ENCONTRADO!!      |\n";
                    cout << "+------------------------------+\n";
                }

                cout << "Nome do Veterinario.: " << V[achou_vet].nome << endl;
                cout << "Data da Consulta....: " << v_consult[i].dataConsulta << endl;
                cout << "Valor da Consulta...: R$ " << v_consult[i].valorConsulta << endl;

                valor_total += v_consult[i].valorConsulta;
                encontrou = true;
            }
        }
    }

    if (!encontrou) {
        cout << "+-----------------------------------------------------------------------------+\n";
        cout << "|  Nenhuma consulta encontrada nesse intervalo para o veterinario informado!  |\n";
        cout << "+-----------------------------------------------------------------------------+\n";
    } else {
        cout << "\nValor total das consultas: R$ " << valor_total << endl;
    }
}





int main() {
    setlocale(LC_ALL, "Portuguese");

    struct CIDADE v_cit[3];
    struct TUTORES AQs[50], AQt[20], AQa[70];
    struct RACAS v_rc[4];
    struct ANIMAIS AQs_ani[5], AQt_ani[5], AQa_ani[10];
    struct VETERINARIOS v_vet[6];
    struct CONSULTAS v_consult[6];

    int cont_CON = 0;
    int cont_vet = 0;
    int contC_s = 0, contC_t = 0, contC_a = 0, cont_city = 0, cont_rc = 0;
    int contS_ani = 0, contT_ani = 0, contA_ani = 0; 
     
    int cont_aux3=0;
    int consul[20];
    int codLeitura = 1;

    int cont_aux4=0;
    int consul_2[20];
    int codLeitura2 = 1;

    const int CADASTRAR_CIDADE = 1;
    const int CADASTRAR_TUTORES = 2;
    const int CADASTRAR_TUTORES2 = 3;
    const int EXIBIR_TUTORES =4;
    const int CADASTRAR_RACAS = 5;
    const int CADASTRAR_ANIMAIS = 6;
    const int CADASTRAR_ANIMAIS2 = 7;
    const int EXIBIR_ANIMAIS = 8;
    const int CONSULTAR_ANIMAIS = 9;
    const int CADASTRAR_VETERINARIOS = 10;
    const int CONSULTAR_VETERINARIOS = 11;
    const int CADASTRAR_CONSULTAS = 12;
    const int EXIBIR_CONSULTAS = 13;
    const int EXIBIR_CONSULTAS2 = 14;

    const int LIMPAR_TELA = 0;
    const int SAIR = 99;

    int opcao = -1;

    do {
    cout << endl;
    cout << "=======================================" << endl;
    cout << "|     Sistema de Clinica Veterinaria   |" << endl;
    cout << "=======================================" << endl << endl;

    cout << "============ CIDADES ==================" << endl;
    cout << "| [1]  Cadastrar Cidades               |" << endl;
    cout << "======================================="  << endl << endl;

    cout << "============ TUTORES ==================" << endl;
    cout << "| [2]  Cadastrar Tutores               |" << endl;
    cout << "|--------------------------------------|" << endl;
    cout << "| [3]  Cadastrar Novos Tutores         |" << endl;
    cout << "|--------------------------------------|" << endl;
    cout << "| [4]  Exibir Tutores                  |" << endl;
    cout << "======================================="  << endl << endl;

    cout << "============ RACAS ====================" << endl;
    cout << "| [5]  Cadastrar Racas                 |" << endl;
    cout << "======================================="  << endl << endl;

    cout << "============ ANIMAIS ==================" << endl;
    cout << "| [6]  Cadastrar Animais               |" << endl;
    cout << "|--------------------------------------|" << endl;
    cout << "| [7]  Cadastrar Novos Animais         |" << endl;
    cout << "|--------------------------------------|" << endl;
    cout << "| [8]  Exibir Animais                  |" << endl;
    cout << "|--------------------------------------|" << endl;
    cout << "| [9]  Consultar Animais               |" << endl;
    cout << "======================================="  << endl << endl;

    cout << "=========== VETERINARIOS ==============" << endl;
    cout << "| [10]  Cadastrar Veterinarios          |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "| [11]  Consultar Veterinarios          |" << endl;
    cout << "=======================================" << endl << endl;

    cout << "=========== CONSULTAS =================" << endl;
    cout << "| [12] Cadastrar Consultas             |" << endl;
    cout << "|--------------------------------------|" << endl;
    cout << "| [13] Exibir Consultas Por Data       |" << endl;
    cout << "|--------------------------------------|" << endl;
    cout << "| [14] Exibir Consultas Por Veterinario|" << endl;
    cout << "======================================="  << endl << endl;

    cout << "=======================================" << endl;
    cout << "| [0]  Limpar Tela                     |" << endl;
    cout << "|--------------------------------------|" << endl;
    cout << "| [99] Sair                            |" << endl;
    cout << "=======================================" << endl << endl;

    cout << "Escolha uma opcao: ";
    cin >> opcao;
    cout << endl;

    

        switch(opcao) {
            case CADASTRAR_CIDADE:
                ler_cid(v_cit, cont_city);
                break;

            case CADASTRAR_TUTORES:
                ler_tutores(AQs, v_cit, cont_city, contC_s);
                inclusao(AQs, contC_s, AQt, contC_t, AQa, contC_a);
                break;
                
            case CADASTRAR_TUTORES2:    
                CAD_TUTORES(AQt, v_cit, cont_city, contC_t, AQs, contC_s);
                inclusao(AQs, contC_s, AQt, contC_t, AQa, contC_a);
                break;

            case EXIBIR_TUTORES:
                mostrar_tutor(AQa, contC_a, v_cit, cont_city);
                getch();
                break;

            case CADASTRAR_RACAS:
                ler_racas(v_rc, cont_rc);
                break;

            case CADASTRAR_ANIMAIS:
                ler_animais(AQs_ani, v_rc, cont_rc, AQa, contC_a, v_cit, cont_city, contS_ani);
                inclusao_ani(AQs_ani, contS_ani, AQt_ani, contT_ani, AQa_ani, contA_ani);
                break;
                
            case CADASTRAR_ANIMAIS2:    
                CAD_ANIMAIS(AQt_ani, v_rc, cont_rc, AQa, contC_a, v_cit, cont_city, AQs_ani, contS_ani, contT_ani);
                inclusao_ani(AQs_ani, contS_ani, AQt_ani, contT_ani, AQa_ani, contA_ani);
                break;

            case EXIBIR_ANIMAIS:
                mostrar_animais(AQa_ani, contA_ani, v_rc, cont_rc, AQa, contC_a, v_cit, cont_city);
                getch();
                break;

			case CONSULTAR_ANIMAIS: {
				codLeitura = 1;
                for (cont_aux3 = 0; cont_aux3 < 20 && codLeitura > 0; cont_aux3++) {
                	cout << "\nInforme o Codigo da Animal que deseja Consultar (finalize com 0): ";
                	cin >> codLeitura;
                		if (codLeitura != 0) {
                	consul[cont_aux3] = codLeitura;
                    }
                }
                cont_aux3--;
                consultar_ani(AQa_ani, contA_ani, v_rc, cont_rc, AQa, contC_a, v_cit, cont_city, consul, cont_aux3);
				getch();
                break;
				}

            case CADASTRAR_VETERINARIOS:
                ler_veterinarios(v_vet, cont_vet, v_cit, cont_city);
                break;

			case CONSULTAR_VETERINARIOS:{
				codLeitura2 = 1;
                for (cont_aux4 = 0; cont_aux4 < 20 && codLeitura2 > 0; cont_aux4++) {
                    cout << "\nInforme o Codigo do Veterinario que deseja Consultar (finalize com 0): ";
                    cin >> codLeitura2;
                    if (codLeitura2 != 0) {
                        consul_2[cont_aux4] = codLeitura2;
                    }
                }
                cont_aux4--;
				consultar_vet(v_vet, cont_vet, v_cit, cont_city, consul_2, cont_aux4);
				getch();
                break;
				}

            case CADASTRAR_CONSULTAS:
                cadastrar_consulta(v_consult, cont_CON, AQa_ani, contA_ani, v_rc, cont_rc, AQa, contC_a, v_vet, cont_vet, v_cit, cont_city);
                break;

            case EXIBIR_CONSULTAS:
                exibir_consultas_intervalo(v_consult, cont_CON, AQa_ani, contA_ani, v_vet, cont_vet);
                getch();
                break;
				
			case EXIBIR_CONSULTAS2:	
                exibir_cons_vet(v_consult, cont_CON, AQa_ani, contA_ani, v_vet, cont_vet);
                getch();
                break;

            case LIMPAR_TELA:
                system("cls");
                break;

            case SAIR:
                 cout << " =======================================" << endl;
                cout << "||    Sistema de Clinica Encerrado!    ||\n";
                 cout << " =======================================" << endl;
                break;

            default:
                cout << "Opcao invalida! Tente novamente.\n";
                break;
        }
    } while (opcao != SAIR);

    return 0;
}
