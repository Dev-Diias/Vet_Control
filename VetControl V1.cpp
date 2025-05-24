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
#include <locale.h>


using namespace std;

struct CIDADE {
    int codigo;
    char nome[35];
    char uf[2];
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
			cin >> v[i].uf;
			cout << endl << endl;
		}
		else s=0;
	}
	cont_cid = i;
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

//-----------------------------------------------------tutores------------------------------------------------------------

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
    cout << "          CADASTRO DE INSTRUTOR        \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=======================================\n\n";

    for (; i < 5; ) {
        cout << "Digite o Codigo do Instrutor.....: ";
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

        cout << "Nome.............................: ";
        cin.getline(v[i].nome, 30);

            
            do {
        cout << "CPF..............................: ";
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

        cout << "Endereco.........................: ";
        cin.getline(v[i].endereco, 30);

            do {
    		cout << "Codigo da Cidade do Instrutor....: ";
   	 	cin >> v[i].codigoCidade;

    int achou_cid = buscaBinariaTutorCidade(cid, cont_cit, v[i].codigoCidade);

    if (achou_cid != -1) {
        cout << "Cidade...........................: " << cid[achou_cid].nome << endl;
        cout << "UF...............................: " << cid[achou_cid].uf << endl;
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


//
//
//void inclusao(struct TUTORES S[], int contS, struct TUTORES T[], int contT, struct TUTORES A[], int &contA) {
//    int i = 0, j = 0, k = 0; 
//    
//    // Mesclagem dos vetores S e T para A, ordenado por código
//    while (i < contS && j < contT) {
//        if (S[i].codigo < T[j].codigo) {
//            A[k] = S[i];
//            i++;
//        } else if (S[i].codigo > T[j].codigo) {
//            A[k] = T[j];
//            j++;
//        } else { 
//            // Se os códigos forem iguais, mantém um só
//            A[k] = S[i];
//            i++;
//            j++;
//        }
//        k++;
//    }
//    
//    // Copia o restante de S, se houver
//    while (i < contS) {
//        A[k] = S[i];
//        i++;
//        k++;
//    }
//    
//    // Copia o restante de T, se houver
//    while (j < contT) {
//        A[k] = T[j];
//        j++;
//        k++;
//    }
//
//    contA = k;
//}
//
//

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
    int j = 0;
int i = 0;
    cout << "\n=======================================\n";
    cout << "          INCLUIR NOVOS TUTORES        \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=========================================\n";
    cout << endl;

   for (; j < 20; j++) {
    cout << endl;

    while (true) {
        cout << "Digite o codigo do Tutor.....: ";
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
                cout << "|                                            |\n";
                cout << "|             CODIGO REPETIDO!!              |\n";
                cout << "|                                            |\n";
                cout << "+--------------------------------------------+\n";
                repetido = 1;
                break;
            }
        }
        if (repetido) {
            continue;  
        }

        
        int achou = buscaBinariaTutorCod(S, conts, T[j].codigo);
        if (achou > -1) {
            cout << "+--------------------------------------------+" << endl;
            cout << "|                                            |" << endl;
            cout << "|  CODIGO INVALIDO, ESSE TUTOR JA EXISTE     |" << endl;
            cout << "|                                            |" << endl;
            cout << "+--------------------------------------------+" << endl;
            continue;  
        }

        break;  
    }

   
            
        cout << "Nome.............................: ";
        cin.getline(T[j].nome, 50);
            
		while (true) {
    	cout << "Digite o CPF do Tutor............: ";
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
            cout << "|                                            |\n";
            cout << "|               CPF REPETIDO!!               |\n";
            cout << "|                                            |\n";
            cout << "+--------------------------------------------+\n";
            repetidoc = 1;
            break;
        }
    }

    if (repetidoc) {
        continue;  
    }

    
    int achou2 = buscaBinariaTutor(S, conts, T[j].cpf);

    if (achou2 > -1) {
        cout << "+--------------------------------------------+" << endl;
        cout << "|                                            |" << endl;
        cout << "|  CPF INVALIDO, ESSE USUARIO JA EXISTE      |" << endl;
        cout << "|                                            |" << endl;
        cout << "+--------------------------------------------+" << endl;
        continue;  
    }

    break;  
}


        cout << "Endereco.........................: ";
        cin.getline(T[j].endereco, 50);
            

           do {
    	cout << "Codigo da Cidade do Instrutor....: ";
    	cin >> T[j].codigoCidade;

    int achou_cid = buscaBinariaTutorCidade(cid, cont_cit, T[j].codigoCidade);

    if (achou_cid != -1) {
        cout << "Cidade...........................: " << cid[achou_cid].nome << endl;
        cout << "UF...............................: " << cid[achou_cid].uf << endl;
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
//---------------------------------------------------animais--------------------------------------------------------------
//3) Escreva uma função para permitir a inclusão de novos registros na tabela de animais.
//3.1) Quando o usuário digitar o código da raça, o programa deverá buscar este código na tabela de raças e exibir a descrição.
//3.2) Quando o usuário digitar o código do tutor, o programa deverá buscar este código na tabela de tutores e exibir o nome do tutor e o nome de sua cidade.
//struct RACAS {
//    int codigo;
//    char descricao[30];
//};
//struct ANIMAIS {
//    int codigo;
//    char nome[40];
//    int codigoRaca;
//    int idade;
//    float peso;
//    int codigoTutor;
//};


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
    cout << "          CADASTRO DE RAÇAS            \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=======================================\n";

    for (; i < 20; ) {
        cout << "\nDigite o Codigo da Raca " << i + 1 << " : ";
        cin >> v[i].codigo;

        if (v[i].codigo <= 0) {
            break;  // Finaliza o cadastro
        }

        // Verifica se o código já foi cadastrado
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
            continue;  // Código repetido, pede para digitar novamente
        } else {
            cin.ignore();
            cout << "Descricao...................: ";
            cin.getline(v[i].descricao, 30);
            i++;  // Passa para o próximo cadastro
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

        cout << "Nome.............................: ";
        cin.getline(v[i].nome, 30);

        
 do {
    		 cout << "Codigo da Raca....................: ";
                cin >> v[i].codigoRaca;
int achou_rc = buscaBinariaAnimal(V_rc, cont_rc, v[i].codigoRaca);

    if (achou_rc != -1) {
        cout << "Descricao...........................: " << V_rc[achou_rc].descricao << endl;
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
    	cout << "Codigo do Tutor...............: ";
   	 	cin >> v[i].codigoTutor;

    int achou_tutor = buscaBinariaTutorCod(tut, cont_tut, v[i].codigoTutor);

    if (achou_tutor != -1) {
        cout << "Nome do Tutor..................: " << tut[achou_tutor].nome << endl;
        //buscaBinariaTutorCidade(struct CIDADE city[], int &cont_tut, int cidade)
        int achou_cidade = buscaBinariaTutorCidade(cit, cont_cit, tut[achou_tutor].codigoCidade);
        
        
        if (achou_cidade != -1){
       	cout << "Cidade do Tutor................: " << cit[achou_cidade].nome << endl;
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
    cout << "          CADASTRO DE ANIMAIS          \n";
    cout << "  (Digite 0 para finalizar o cadastro) \n";
    cout << "=======================================\n\n";

    while (true) {
        cout << "Digite o codigo do Animal.....: ";
        int codigo;
        cin >> codigo;
        cin.ignore();

        if (codigo <= 0) {
            break;  // Finaliza o cadastro
        }

        // Verifica repetição no próprio vetor T
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
            continue;  // volta para pedir novamente
        }

        // Verifica se já existe no vetor S
        int achou = buscaBinariaAnimalCod(S, cont_aniS, codigo);
        if (achou != -1) {
            cout << "+--------------------------------------------+" << endl;
            cout << "|  CODIGO INVALIDO, ESSE ANIMAL JA EXISTE    |" << endl;
            cout << "+--------------------------------------------+" << endl;
            continue;
        }

        // Inserção
        T[cont_aniT].codigo = codigo;

        cout << "Nome.............................: ";
        cin.getline(T[cont_aniT].nome, 30);

        do {
            cout << "Codigo da Raca....................: ";
            cin >> T[cont_aniT].codigoRaca;
            int achou_rc = buscaBinariaAnimal(V_rc, cont_rc, T[cont_aniT].codigoRaca);

            if (achou_rc != -1) {
                cout << "Descricao........................: " << V_rc[achou_rc].descricao << endl;
                break;
            } else {
                cout << "+--------------------------------------------+\n";
                cout << "|  Codigo nao corresponde a uma raca!        |\n";
                cout << "+--------------------------------------------+\n";
            }
        } while (true);

        cout << "Idade.........................: ";
        cin >> T[cont_aniT].idade;

        cout << "Peso..........................: ";
        cin >> T[cont_aniT].peso;

        do {
            cout << "Codigo do Tutor...............: ";
            cin >> T[cont_aniT].codigoTutor;

            int achou_tutor = buscaBinariaTutorCod(tut, cont_tut, T[cont_aniT].codigoTutor);

            if (achou_tutor != -1) {
                cout << "Nome do Tutor..................: " << tut[achou_tutor].nome << endl;
                int achou_cidade = buscaBinariaTutorCidade(cit, cont_cit, tut[achou_tutor].codigoCidade);
                if (achou_cidade != -1) {
                    cout << "Cidade do Tutor................: " << cit[achou_cidade].nome << endl;
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

        cont_aniT++;  // Incrementa contador após inserção
    }
}









//   (struct ANIMAIS v[], struct RACAS V_rc[], int cont_rc, struct TUTORES tut[], int cont_tut,
//struct CIDADE cit[], int cont_cit, int &cont_ins

void mostrar_animais(struct ANIMAIS A[], int cont_ani, struct RACAS V_rc[], int cont_rc, struct TUTORES tut[], int cont_tut, struct CIDADE cit[], int cont_cit) {
    cout << "\n+------------------------+\n";
    cout << "|    DADOS DE ANIMAIS    |\n";
    cout << "+------------------------+\n";

    for (int i = 0; i < cont_ani; i++) {
        cout << "\nCodigo..........: " << A[i].codigo;
        cout << "\tNome............: " << A[i].nome;

        // Procurar raça
        int achou_rc = buscaBinariaAnimal(V_rc, cont_rc, A[i].codigoRaca);
        if (achou_rc != -1) {
            cout << "\tDescricao da Raca: " << V_rc[achou_rc].descricao;
        } else {
            cout << "\tDescricao da Raca: Nao encontrada";
        }

        cout << "\nIdade...........: " << A[i].idade;
        cout << "\tPeso............: " << A[i].peso;

        // Procurar tutor
        int achou_tutor = buscaBinariaTutorCod(tut, cont_tut, A[i].codigoTutor);
        if (achou_tutor != -1) {
            cout << "\tNome do Tutor...: " << tut[achou_tutor].nome;

            // Procurar cidade do tutor
            int achou_cidade = buscaBinariaTutorCidade(cit, cont_cit, tut[achou_tutor].codigoCidade);
            if (achou_cidade != -1) {
                cout << "\nCidade do Tutor.: " << cit[achou_cidade].nome;
                cout << "\tEstado..........: " << cit[achou_cidade].uf;
            } else {
                cout << "\nCidade do Tutor.: Nao encontrada";
            }
        } else {
            cout << "\tNome do Tutor...: Nao encontrado";
        }

        cout << endl;
    }
}









int main() {
	
//	
//            case CADASTRAR_INSTRUTORES:
//                ler_ins(AQs, ctS);
//                inclusao(AQs, ctS, AQt, ctT, AQa, contA);
//                break;
//                
//             case INCLUIR_INSTRUTORES:
//			    
//                ler_insT(AQt, ctT, AQs, ctS);
//                inclusao(AQs, ctS, AQt, ctT, AQa, contA);
//                break;
                
//	struct TUTORES T[], struct CIDADE cid[], int cont_cit, int &cont_tut, struct TUTORES S[], int conts
// inclusao(struct TUTORES S[], int contS, struct TUTORES T[], int contT, struct TUTORES A[], int &contA
//mostrar_tutor(struct TUTORES A[], int contA, struct CIDADE V[], int contC)
   	 struct CIDADE v_cit[3];
   	 
     struct TUTORES AQs[5], AQt[5], AQa[10];
     
     struct RACAS v_rc[4];
     
     struct ANIMAIS AQs_ani[5], AQt_ani[5], AQa_ani[10];
     
     int contC_s=0, contC_t=0, contC_a=0, cont_city=0, cont_rc=0, contS_ani=0, contT_ani=0, contA_ani=0;
    
     
     cout << "leitura de cidade." << endl;
     ler_cid(v_cit, cont_city);
     
     cout << "leitura de tutores." << endl;
     ler_tutores(AQs, v_cit, cont_city, contC_s);
     inclusao(AQs, contC_s, AQt, contC_t, AQa, contC_a);
     
//     cout << "Cadastrar novo tutor." << endl;
  //   CAD_TUTORES(AQt, v_cit, cont_city, contC_t, AQs, contC_s);
//    inclusao(AQs, contC_s, AQt, contC_t, AQa, contC_a);
//    
//    cout << "exibir tutores." << endl;
//    mostrar_tutor(AQa, contC_a, v_cit, cont_city);


cout << "Leitura de Racas: " << endl;
ler_racas(v_rc, cont_rc);
//void ler_animais(struct ANIMAIS v[], struct RACAS V_rc[], int cont_rc, struct TUTOR tut[], int cont_tut,
//struct CIDADE cit[], int cont_cit, int cont_cit, int &cont_ins)

//inclusao_ani(struct ANIMAIS S[], int contS, struct ANIMAIS T[], int contT, struct ANIMAIS A[], int &contA)




cout << "Leitura de Animais: " << endl;
ler_animais(AQs_ani, v_rc, cont_rc, AQa, contC_a, v_cit, cont_city, contS_ani);
cout << "contador dps de S A: " << contA_ani << endl;
inclusao_ani(AQs_ani, contS_ani, AQt_ani, contT_ani, AQa_ani, contA_ani);
cout << "contador dps de S A: " << contA_ani << endl;



CAD_ANIMAIS(AQt_ani, v_rc, cont_rc, AQa, contC_a, v_cit, cont_city, AQs_ani, contS_ani, contT_ani);
cout << "contador dps de T A: " << contA_ani << endl;
inclusao_ani(AQs_ani, contS_ani, AQt_ani, contT_ani, AQa_ani, contA_ani);
cout << "contador dps de T A: " << contA_ani << endl;



//mostrar_animais(struct ANIMAIS A[], int cont_ani, struct RACAS V_rc[], int cont_rc, struct TUTORES tut[], int cont_tut, struct CIDADE cit[], int cont_cit)

mostrar_animais(AQa_ani, contA_ani, v_rc, cont_rc, AQa, contC_a, v_cit, cont_city);
}



























