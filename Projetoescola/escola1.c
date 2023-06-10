#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

// Constantes Globais:
#define TAM 4 

#define CAD_SUCESSO -1
#define MAT_INVALIDA -2 
#define LISTA_CHEIA -3 
#define SEXO_INVALIDO -4
#define EXC_INVALIDO -5
#define EXC_SUCESSO	-6
#define POS_INVALIDA -7 
#define ATU_INVALIDA -8
#define CAD_INVALIDO	-9
#define TAM_MAX_ULTRA -10
// definindo as structs de ALUNO e DATA
typedef struct datas{
  int dia;
  int mes;
  int ano;
} DataNas;

typedef struct	alun {
  DataNas dataNas;
  int matricula;
  char nome[51]; // contém 50 caract
  char sexo;     // Usa-se F - p/ feminino e M p/ masculino
  char cpf[15];
} Aluno; // nome da stuct

typedef struct prof{
  DataNas dataNas;
  int matricula;
  char nome[51]; // contém 50 caract
  char sexo;
  char cpf[15];
} Professor; // nome da struct

typedef struct disc{
int codigo;
int semestre;
char nome[51];
int matriculaProfessor;
int matriculaAluno[TAM];
} Disciplina; // nome da struct 

// protótipo das funções (as funções estão ao final do código!)
void menuGeral();
void menuAluno();
void menuatualizar();
void menuProfessor();
void menuDisciplina();
void ListarDisciplina();
int  cadastrarAluno	(Aluno listaAluno[],int lnAluno,int qtdAluno);
void listarAluno	(Aluno	listaAluno[],int qtdAluno);
int  excluirAluno (Aluno listaAluno[],int qtd);
int  atualizarAluno(Aluno listaAluno[], int qtdAluno, int lnAluno);
int  cadastroProfessor(Professor	listaProfessor[],int qtdProfessor, int lnProfessor);
void listarProfessor (Professor listaProfessor[], int qtdProfessor);
int  excluirProfessor (Professor listaProfessor[],int qtdProfessor);
int  atualizarProfessor( Professor listaProfessor[], int qtdProfessor, int lnProfessor);
int  cadastrarDisciplina(int qtdDisciplina,Disciplina listaDisciplina[], int lnDisciplina);
int inserirAlunoDisciplina(int qtdDisciplina,int qtdAluno,Disciplina listaDisciplina[], Aluno listaAluno[],int codigoDisciplina);
void listarDisciplina(int qtdDisciplina,Disciplina listaDisciplina[]);
int excluirDisciplina (int qtdDisciplina, Disciplina listaDisciplina[],int codigoDisciplina, int qtdAluno);
int main(void) {
	setlocale(LC_ALL, "Portuguese");
	// Variáveis de Aluno
	Aluno listaAluno[TAM]; // váriavel listaAuluno do tipo Struct Aluno          
	int qtdAluno = 0;
	int lnAluno; // usado no cadatro de aluno e atualizar

	// Variáveis de Professor
	Professor listaProfessor[TAM]; // váriavel listaAuluno do tipo Struct Aluno                  
	int qtdProfessor = 0;
	int lnProfessor; // usado no cadastro de professor e no atualizar

	// Variáveis Disciplina
	Disciplina listaDisciplina[TAM];
	int qtdDisciplina	=	0;
	int opcao;
	
	do{
		menuGeral();
		scanf("%d",&opcao);
		setbuf(stdin,0);
		switch (opcao) {
			case 0: {
				break;
			}
			case 1: {
				printf("\n>  MÓDULO DOS ALUNOS:\n"); // aqui dentro vou fazer as opções do modulo aluno
				int opcaoAluno;
				do{
					menuAluno();
					scanf("%d", &opcaoAluno);
					setbuf(stdin,0);
					switch (opcaoAluno){
						case 0: {
							opcaoAluno	=	0;
							break;
						}	
						case 1: {
							int retorno	=	cadastrarAluno	(listaAluno, lnAluno, qtdAluno);
							if (retorno == LISTA_CHEIA)
								printf("Lista cheia!\n");
							if(retorno	==	MAT_INVALIDA)
								printf("matricula invalida!\n");
							else if( retorno == SEXO_INVALIDO)
								printf("Sexo inválido!\n");
							else{
								qtdAluno =+retorno;
								printf("Cadastro realizado!\n");
							}
							break;
						}
						case 2: {
							printf("\n>  LISTAR ALUNO:\n");
							listarAluno	(listaAluno,qtdAluno);
							
							break;
						}
						case 3: {
							int retorno	=	excluirAluno (listaAluno, qtdAluno);
							if(	retorno	==	EXC_INVALIDO)
								printf("Exclusão inválida!\n");
							else if (retorno == EXC_SUCESSO){
								printf("Exclusão feita com sucesso!");
								qtdAluno--;
							}
							break;
						}
						case 4:	{
							int	retorno	=	atualizarAluno(listaAluno,qtdAluno, lnAluno);
							if (retorno == POS_INVALIDA ){
								printf("A posição digitada é inválida!\n");
							}
							else if (retorno	==	ATU_INVALIDA){
								printf("opção do menu escolhida foi inválida!\n");
							}
							else {
								printf("Cadastro realizado com sucesso!\n");
							}
							break;
						}
					}
				} while (opcaoAluno	!=	0);
				break;
			}
			case 2: {
				printf("\n>  MÓDULO DOS PROFESSORES:\n"); // aqui dentro vou fazer as opções do módulo de professores
					int opcaoProfessor;   
				do{
					menuProfessor();
					scanf("%d", &opcaoProfessor);
					setbuf(stdin,0);
					switch (opcaoProfessor){
						case 0: {
							break;
						}
						case 1: {
							int retorno	=	cadastroProfessor(listaProfessor	,qtdProfessor	,lnProfessor);
							if (retorno == LISTA_CHEIA)
								printf("Lista cheia!\n");
							else if (retorno	==	MAT_INVALIDA)
								printf("matricula invalida!\n");
							else if( retorno == SEXO_INVALIDO)
								printf("Sexo inválido!\n");
							else{
								qtdProfessor =+retorno;
								printf("Cadastro realizado!\n");
							}
							break;
						}
						case 2: {
							printf(">  LISTAR PROFESSOR:\n");
							listarProfessor(listaProfessor,	qtdProfessor);
							break;
						}
						case 3: {
							int retorno	= excluirProfessor (listaProfessor,qtdProfessor);
							if(	retorno	==	EXC_INVALIDO)
								printf("Exclusão inválida!\n");
							else if (retorno == EXC_SUCESSO){
								printf("Exclusão feita com sucesso!");
								qtdProfessor--;
							}
							break;
						}
						case 4: {
							int retorno =	atualizarProfessor(listaProfessor,qtdProfessor,lnProfessor);
							if (retorno == POS_INVALIDA ){
								printf("A posição digitada é inválida!\n");
							}
							else if (retorno	==	ATU_INVALIDA){
								printf("opção do menu escolhida foi inválida!\n");
							}
							else {
								printf("Cadastro realizado com sucesso!\n");
							}
							break;
						}
					}
				}while (opcaoProfessor !=	0);
				break;
			}
			case 3: {
				printf("\n>  MÓDULO DAS DISCIPLINAS:\n"); // aqui dentro vou fazer as opções do módulo de disciplinas
				int	opcaoDisciplina;
				int codigoDisciplina;
				int lnDisciplina;
				do {
					menuDisciplina();
					scanf("%d", &opcaoDisciplina);
					switch(opcaoDisciplina){
							case	0:{
								break;
							}
							case	1:{
								printf("-	CADASTRAR DISCIPLINA	-\n");
								int retorno =	cadastrarDisciplina(qtdDisciplina, listaDisciplina, lnDisciplina);
								if (retorno	== CAD_INVALIDO){
									printf("A quantidade de disciplinas permitida foi ultrapassada!\n");	
								}
								else {
								qtdDisciplina+=retorno;
								printf("Disciplina cadastrada com sucesso!\n");
								}
								break;
							}
							case	2:{
								printf("-	INSERIR ALUNO NA DISCIPLINA:\n");
								int retorno	= inserirAlunoDisciplina(qtdDisciplina, qtdAluno, listaDisciplina,listaAluno, codigoDisciplina);
								if(retorno == TAM_MAX_ULTRA){
									printf("quantidade de alunos excede o máximo permitido.\n");
								}
								else if (retorno == CAD_INVALIDO){
										printf("Não há disciplina com esse código\n");
								}
								else if( retorno	==	MAT_INVALIDA){
									printf("Não existe nenhuma matricula de aluno com esse codigo!\n");
								}
								else{
								printf("Cadastro do aluno na disciplina feito com sucesso\n");	
								}				
								break;
							}
							case	3:{
								listarDisciplina(qtdDisciplina, listaDisciplina);
								break;
							}
							case	4:{
								int retorno	=	excluirDisciplina (qtdDisciplina, listaDisciplina,codigoDisciplina, qtdAluno);
								if(retorno == EXC_INVALIDO){
									printf("Nã há disciplinas cadastradas com esse codigo!\n");
								}
								else{
									printf("A disciplina foi excluida com sucesso!\n");
								}
								break;
							}
					}
				}while(opcaoDisciplina != 0);
				break;
			}
		}
	}while(opcao	!=	0);
}
// Funções:
void menuGeral(){
  printf("\n>    PROJETO ESCOLA\n");
  printf("---	MENU GERAL	---	\n");
	printf("0	-	Sair.\n");
  printf("1	-	Aluno.\n");
  printf("2	-	Professor.\n");
  printf("3	-	Disciplina.\n");
}
void menuAluno(){
printf("\n---	MENU DO ALUNO	---\n");
	printf("0	-	Voltar.\n");
  printf("1	-	Cadastrar Aluno.\n");
  printf("2	-	Listar Alunos.\n");
  printf("3	-	Excluir Aluno.\n");
  printf("4	-	Atualizar Aluno.\n");
}
void menuatualizar() {
  printf("\n---	MENU DO ATUALIZAR:	---\n");
	printf("0	-	Voltar\n");
	printf("1	-	Mudar a matrícula\n");
  printf("2	-	Mudar o nome\n");
  printf("3	-	Mudar o sexo\n");
  printf("4	-	Mudar a data de nascimento\n");
  printf("5	-	Mudar o CPF\n");
  printf("6	-	Refazer Cadastro\n");
}
void menuProfessor()	{
	printf("\n---	MENU DO PROFESSOR	---\n");
	printf("0 -  Voltar.\n");
	printf("1 -  Cadastrar Professor.\n");
	printf("2 -  Listar Professores.\n");
	printf("3 -  Excluir Professor.\n");
	printf("4 -  Atualizar Professor.\n");	
}
void menuDisciplina(){
	printf("\n---	MENU DA DISCIPLINA:	---\n");
	printf("0	-	Voltar.\n");
	printf("1	-	Cadastrar Disciplina.\n");
	printf("2	-	Inserir Aluno na Disciplina\n");
	printf("3	-	Listar Disciplina.\n");
	printf("4	-	Excluir Disciplina.\n");
	printf("5	-	Atualizar Disciplina.\n");	
}
int cadastrarAluno	(Aluno listaAluno[],int lnAluno,int qtdAluno){
	int corretoCPFAluno =	0; 
	char validaCPFAluno[15];

	
	printf("Digite a quantidade de alunos que irá ser cadastrado:\n");
	scanf("%d", &qtdAluno);
	getchar(); // isso é pra limpar o buffer , usa-se sempre após o scanf
	
	if (qtdAluno > TAM) {
		return LISTA_CHEIA;
	} 
	else {
		for (int i = 0; i < qtdAluno; i++) {
			printf("Digite a matricula do aluno:\n");
			scanf("%d", &listaAluno[i].matricula);

			if (listaAluno[i].matricula <= 0){
				return MAT_INVALIDA;
			}

			printf("Digite o nome do aluno:");
			getchar();
			fgets(listaAluno[i].nome, 51, stdin); // - Aqui estava DANDO DUAS IDENTAÇÕES tirei o getchar!!!!!!!
			lnAluno = strlen(listaAluno[i].nome) - 1;  
			// na função fgets o ultimo termo é o '\n' por isso fica com mais uma identação
			if (listaAluno[i].nome[lnAluno] == '\n')
			listaAluno[i].nome[lnAluno] = '\0';
			
		
		
			printf("Digite F se for Feminino e M se for Masculino:\n");
			fflush(stdin);									
			scanf("	%c" , &listaAluno[i].sexo );
			if(listaAluno[i].sexo != 'm' && listaAluno[i].sexo !='M'	&& listaAluno[i].sexo	!= 'f'	&& listaAluno[i].sexo != 'F')
				return  SEXO_INVALIDO;
			//Quando for puxar nome por sexo terá que puxar 'M' e 'm' da mesma forma com o 'F' e 'f'
		

			do{
				printf("Digite  CPF do Aluno com '.' e'-':");
				getchar();
				fgets(validaCPFAluno, 15, stdin);
				
				lnAluno = strlen(validaCPFAluno) - 1;  // na função fgets o ultimo termo é o '\n' por isso fica com mais uma identação
				if (validaCPFAluno[lnAluno] == '\n'){
					validaCPFAluno[lnAluno] = '\0';
				}
						
				if(	validaCPFAluno[3]	==	'.'	&&	validaCPFAluno[7]	==	'.' && validaCPFAluno[11] ==	'-'){
					strcpy (listaAluno[i].cpf	,validaCPFAluno ); // essa função copia a strcpy(destino,	copiada)
					corretoCPFAluno = 1;
				}
			}	while	(!corretoCPFAluno);
											
			do {
				printf("Digite a Data de Nascimento do Aluno:\n");
				scanf("%d %d %d", &listaAluno[i].dataNas.dia,&listaAluno[i].dataNas.mes, &listaAluno[i].dataNas.ano);
				printf("\n");
			}while(listaAluno[i].dataNas.dia	 < 1 || listaAluno[i].dataNas.dia > 31  || listaAluno[i].dataNas.mes <	1 ||	listaAluno[i].dataNas.mes >	12 || listaAluno[i].dataNas.ano	> 2023 );
		}
	return qtdAluno;}
}
void listarAluno	(Aluno	listaAluno[],int qtdAluno){
	for (int i = 0; i < qtdAluno; i++) {
		if (listaAluno[i].matricula > 0){
			printf("Matricula: %d\n", listaAluno[i].matricula);
			printf("Nome: %s\n", listaAluno[i].nome);
			printf("Sexo: %c\n", listaAluno[i].sexo);
			printf("CPF: %s\n", listaAluno[i].cpf);
			printf("Posição do vetor do aluno: %d\n", i);
			printf("\n");
		}
	}
}
int excluirAluno (Aluno listaAluno[],int qtdAluno){
	int ExcluirAluno; 
	int posicaoExcluirAluno;
	int opcaoExcluirAluno;
	Aluno copiaAluno;
	printf("\n>    EXCLUIR ALUNO:\n");
		for(int i =	0; i	<	qtdAluno;	i++){
			if(listaAluno[i].matricula	>	0){
				printf("A posicao do aluno é:%d\nSua Matrícula é:%d\n",i	,listaAluno[i].matricula);
			}	
		}
		printf("Digite a posição do vetor que deseja excluir:\n");
		scanf("%d", &posicaoExcluirAluno);
		if (posicaoExcluirAluno < 0){
			return EXC_INVALIDO;
		}

	printf( "\nA posição tem nome: %s\nA matricula é:%d\nDeseja excluir?\n1- para Sim!\n0 - para Não!\n",listaAluno[posicaoExcluirAluno].nome, listaAluno[posicaoExcluirAluno].matricula);
	scanf("%d", &ExcluirAluno);
	if (ExcluirAluno ==	1) {
		listaAluno[posicaoExcluirAluno].cpf[0] = '\0';
		listaAluno[posicaoExcluirAluno].dataNas.ano = 0;
		listaAluno[posicaoExcluirAluno].dataNas.mes = 0;
		listaAluno[posicaoExcluirAluno].dataNas.dia = 0;
		listaAluno[posicaoExcluirAluno].nome[0] = '\0';
		listaAluno[posicaoExcluirAluno].sexo = '\0'; 
		for(int j = posicaoExcluirAluno; posicaoExcluirAluno < qtdAluno-1; j++){ // reordenação do vetor!
			copiaAluno = listaAluno[j];
			listaAluno[j] = listaAluno[j	+	1];
			listaAluno[j	+	1] = copiaAluno;		
		}
		return EXC_SUCESSO;
	}  
	else{
		return EXC_INVALIDO;
	}
}
int atualizarAluno(Aluno listaAluno[], int qtdAluno, int lnAluno){
	int opcaoAtualizarAluno;
	int posicaoDoAtualizarAluno;
	int confirmaAtualizarAluno;
	printf(">    ATUALIZAR	ALUNO:\n");
	menuatualizar();
	scanf("%d", &opcaoAtualizarAluno);
	do{
		switch (opcaoAtualizarAluno) {
			case 0:	{
				break;
			}
			case 1:	{
				printf("-  Nova Matricula:\n");
				listarAluno	(listaAluno,qtdAluno);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				scanf("%d", &posicaoDoAtualizarAluno);
					if (posicaoDoAtualizarAluno<0	|| posicaoDoAtualizarAluno >= qtdAluno){
						return POS_INVALIDA;
					}	
				scanf("%d", &listaAluno[posicaoDoAtualizarAluno].matricula);
				return CAD_SUCESSO;
				break;
			}
			case 2:	{
				printf("-  Novo Nome:\n");
				listarAluno	(listaAluno,qtdAluno);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarAluno);
				if (posicaoDoAtualizarAluno<0	|| posicaoDoAtualizarAluno >= qtdAluno){
						return POS_INVALIDA;
					}	
				fgets(listaAluno[posicaoDoAtualizarAluno].nome,  50  ,  stdin);
				lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].nome) - 1;
				if (listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] == '\n')
				listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] = '\0';
				getchar();
				return CAD_SUCESSO;
				break;
			}
			case 3:	{
				printf("-  Novo sexo:\n");
				listarAluno	(listaAluno,qtdAluno);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarAluno);
				if (posicaoDoAtualizarAluno<0	|| posicaoDoAtualizarAluno >= qtdAluno){
						return POS_INVALIDA;
					}	
				scanf("%c", &listaAluno[posicaoDoAtualizarAluno].sexo);
	
				return CAD_SUCESSO;
				break;
			}
			case 4:	{
				printf("-  Nova Data de nascimento:\n");
				listarAluno	(listaAluno,qtdAluno);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarAluno);
				if (posicaoDoAtualizarAluno<0	|| posicaoDoAtualizarAluno >= qtdAluno){
						return POS_INVALIDA;
					}	
				scanf("%d %d %d", &listaAluno[posicaoDoAtualizarAluno].dataNas.dia  , &listaAluno[posicaoDoAtualizarAluno].dataNas.mes ,  &listaAluno[posicaoDoAtualizarAluno].dataNas.ano );
	
				return CAD_SUCESSO;
				break;
			}
			case 5:	{
				printf("-  Novo CPF:\n");
				listarAluno	(listaAluno,qtdAluno);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarAluno);
				if (posicaoDoAtualizarAluno<0	|| posicaoDoAtualizarAluno >= qtdAluno){
						return POS_INVALIDA;
					}	
				fgets(listaAluno[posicaoDoAtualizarAluno].cpf,  15  ,  stdin);
				lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].cpf) - 1;
				if (listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] == '\n')
				listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] = '\0';
				return CAD_SUCESSO;
				 break;
			}
			case 6:	{
				printf("---  Refazer cadastro:  ---\n");
				listarAluno	(listaAluno,qtdAluno);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarAluno);
				if (posicaoDoAtualizarAluno<0	|| posicaoDoAtualizarAluno >= qtdAluno){
						return POS_INVALIDA;
					}	
				printf("-  Nova Matricula:\n");
				scanf("%d", &listaAluno[posicaoDoAtualizarAluno].matricula);
				
				
				printf("\n");
				printf("-  Novo Nome:\n");
				getchar();
				fgets(listaAluno[posicaoDoAtualizarAluno].nome,  50  ,  stdin);
				
				lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].nome) - 1;
				if (listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] == '\n')
				listaAluno[posicaoDoAtualizarAluno].nome[lnAluno] = '\0';
				
		
				printf("-  Novo sexo:\n");
				getchar();
				scanf("%c", &listaAluno[posicaoDoAtualizarAluno].sexo);
				
				
				printf("-  Nova Data de nascimento:\n");
				
				scanf("%d %d %d", &listaAluno[posicaoDoAtualizarAluno].dataNas.dia  , &listaAluno[posicaoDoAtualizarAluno].dataNas.mes ,  &listaAluno[posicaoDoAtualizarAluno].dataNas.ano );
				
				printf("-  Novo CPF:\n");
				getchar();
				fgets(listaAluno[posicaoDoAtualizarAluno].cpf,  15  ,  stdin);
				lnAluno = strlen(listaAluno[posicaoDoAtualizarAluno].cpf) - 1;
				if (listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] == '\n')
				listaAluno[posicaoDoAtualizarAluno].cpf[lnAluno] = '\0';
				getchar();
				return CAD_SUCESSO;
				break;
			}
			default:{ 
				break;
			}	
		}
	}while(opcaoAtualizarAluno!=0);
}
int cadastroProfessor(Professor listaProfessor[], int	 qtdProfessor , int lnProfessor){
	int corretoCPFProfessor =	0; 
	char validaCPFProfessor[15];

	
	printf("Digite a quantidade de professores que irá ser cadastrado:\n");
	scanf("%d", &qtdProfessor);
	getchar(); // isso é pra limpar o buffer , usa-se sempre após o scanf
	
	if (qtdProfessor > TAM) {
		return LISTA_CHEIA;
	} 
	else {
		for (int i = 0; i < qtdProfessor; i++) {
			printf("Digite a matricula do professor:\n");
			scanf("%d", &listaProfessor[i].matricula);

			if (listaProfessor[i].matricula <= 0){
				return MAT_INVALIDA;
			}

			printf("Digite o nome do professor:");
			getchar();
			fgets(listaProfessor[i].nome, 51, stdin); // - Aqui estava DANDO DUAS IDENTAÇÕES tirei o getchar!!!!!!!
			lnProfessor = strlen(listaProfessor[i].nome) - 1;  
			// na função fgets o ultimo termo é o '\n' por isso fica com mais uma identação
			if (listaProfessor[i].nome[lnProfessor] == '\n')
			listaProfessor[i].nome[lnProfessor] = '\0';
			
		
		
			printf("Digite F se for Feminino e M se for Masculino:\n");
			fflush(stdin);									
			scanf("	%c" , &listaProfessor[i].sexo );
			if(listaProfessor[i].sexo != 'm' && listaProfessor[i].sexo !='M'	&& listaProfessor[i].sexo	!= 'f'	&& listaProfessor[i].sexo != 'F')
				return  SEXO_INVALIDO;
			//Quando for puxar nome por sexo terá que puxar 'M' e 'm' da mesma forma com o 'F' e 'f'
		

			do{
				printf("Digite  CPF do professor com '.' e'-':");
				getchar();
				fgets(validaCPFProfessor, 15, stdin);
				
				lnProfessor = strlen(validaCPFProfessor) - 1;  // na função fgets o ultimo termo é o '\n' por isso fica com mais uma identação
				if (validaCPFProfessor[lnProfessor] == '\n'){
					validaCPFProfessor[lnProfessor] = '\0';
				}
						
				if(	validaCPFProfessor[3]	==	'.'	&&	validaCPFProfessor[7]	==	'.' && validaCPFProfessor[11] ==	'-'){
					strcpy (listaProfessor[i].cpf	,validaCPFProfessor ); // essa função copia a strcpy(destino,	copiada)
					corretoCPFProfessor = 1;
				}
			}	while	(!corretoCPFProfessor);
											
			do {
				printf("Digite a Data do professor :\n");
				scanf("%d %d %d", &listaProfessor[i].dataNas.dia,&listaProfessor[i].dataNas.mes, &listaProfessor[i].dataNas.ano);
				printf("\n");
			}while(listaProfessor[i].dataNas.dia	 < 1 || listaProfessor[i].dataNas.dia > 31  || listaProfessor[i].dataNas.mes <	1 ||	listaProfessor[i].dataNas.mes >	12 || listaProfessor[i].dataNas.ano	> 2023 );
		}
		return qtdProfessor;
	}
}
void listarProfessor (Professor listaProfessor[], int qtdProfessor){
		for (int i = 0; i < qtdProfessor; i++) {
		if (listaProfessor[i].matricula > 0){
			printf("Matricula: %d\n", listaProfessor[i].matricula);
			printf("Nome: %s\n", listaProfessor[i].nome);
			printf("Sexo: %c\n", listaProfessor[i].sexo);
			printf("CPF: %s\n", listaProfessor[i].cpf);
			printf("A posicao do Professor é:%d", i);
			printf("\n");
		}
	}
}
int excluirProfessor (Professor listaProfessor[],int qtdProfessor){
	int ExcluirProfessor; 
	int posicaoExcluirProfessor;
	int opcaoExcluirProfessor;
	Professor copiaProfessor;
	
	printf("\n>    EXCLUIR Professor:\n");
		for(int i =	0; i	<	qtdProfessor;	i++){
			if(listaProfessor[i].matricula	>	0){
				printf("A posicao do professor é:%d\nSua Matrícula é:%d\n",i	,listaProfessor[i].matricula);
			}	
		}
		printf("Digite a posição do vetor que deseja excluir:\n");
		scanf("%d", &posicaoExcluirProfessor);
		if (posicaoExcluirProfessor < 0){
			return EXC_INVALIDO;
		}

	printf( "\nA posição tem nome: %s\nA matricula é:%d\nDeseja excluir?\n1- para Sim!\n0 - para Não!\n",listaProfessor[posicaoExcluirProfessor].nome, listaProfessor[posicaoExcluirProfessor].matricula);
	scanf("%d", &ExcluirProfessor);
	if (ExcluirProfessor ==	1) {
		listaProfessor[posicaoExcluirProfessor].cpf[0] = '\0';
		listaProfessor[posicaoExcluirProfessor].dataNas.ano = 0;
		listaProfessor[posicaoExcluirProfessor].dataNas.mes = 0;
		listaProfessor[posicaoExcluirProfessor].dataNas.dia = 0;
		listaProfessor[posicaoExcluirProfessor].nome[0] = '\0';
		listaProfessor[posicaoExcluirProfessor].sexo = '\0'; 
		for(int j = posicaoExcluirProfessor; posicaoExcluirProfessor < qtdProfessor-1; j++){ // reordenação do vetor!
			copiaProfessor = listaProfessor[j];
			listaProfessor[j] = listaProfessor[j	+	1];
			listaProfessor[j	+	1] = copiaProfessor;		
		}
		return EXC_SUCESSO;
	}  
	else{
		return EXC_INVALIDO;
	}
}
int atualizarProfessor( Professor listaProfessor[], int qtdProfessor, int lnProfessor){
	int opcaoAtualizarProfessor;
	int posicaoDoAtualizarProfessor;
	int confirmaAtualizarProfessor;
	printf(">    ATUALIZAR	Professor:\n");
	menuatualizar();
	scanf("%d", &opcaoAtualizarProfessor);
	do{
		switch (opcaoAtualizarProfessor) {
			case 0:	{
				break;
			}
			case 1:	{
				printf("-  Nova Matricula:\n");
				listarProfessor	(listaProfessor,qtdProfessor);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				scanf("%d", &posicaoDoAtualizarProfessor);
					if (posicaoDoAtualizarProfessor<0	|| posicaoDoAtualizarProfessor >= qtdProfessor){
						return POS_INVALIDA;
					}	
				scanf("%d", &listaProfessor[posicaoDoAtualizarProfessor].matricula);
				return CAD_SUCESSO;
				break;
			}
			case 2:	{
				printf("-  Novo Nome:\n");
				listarProfessor	(listaProfessor,qtdProfessor);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarProfessor);
				if (posicaoDoAtualizarProfessor<0	|| posicaoDoAtualizarProfessor >= qtdProfessor){
						return POS_INVALIDA;
					}	
				
				fgets(listaProfessor[posicaoDoAtualizarProfessor].nome,  50  ,  stdin); // Não está lendo!!!!
				
				lnProfessor = strlen(listaProfessor[posicaoDoAtualizarProfessor].nome) - 1;
				if (listaProfessor[posicaoDoAtualizarProfessor].nome[lnProfessor] == '\n')
				listaProfessor[posicaoDoAtualizarProfessor].nome[lnProfessor] = '\0';
				return CAD_SUCESSO;
				break;
			}
			case 3:	{
				printf("-  Novo sexo:\n");
				listarProfessor	(listaProfessor,qtdProfessor);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarProfessor);
				if (posicaoDoAtualizarProfessor	<0	|| posicaoDoAtualizarProfessor >= qtdProfessor){
						return POS_INVALIDA;
					}	
				scanf("%c", &listaProfessor[posicaoDoAtualizarProfessor].sexo);
	
				return CAD_SUCESSO;
				break;
			}
			case 4:	{
				printf("-  Nova Data de nascimento:\n");
				listarProfessor	(listaProfessor,qtdProfessor);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarProfessor);
				if (posicaoDoAtualizarProfessor	|| posicaoDoAtualizarProfessor>= qtdProfessor){
						return POS_INVALIDA;
					}	
				scanf("%d %d %d", &listaProfessor[posicaoDoAtualizarProfessor].dataNas.dia  , &listaProfessor[posicaoDoAtualizarProfessor].dataNas.mes ,  &listaProfessor[posicaoDoAtualizarProfessor].dataNas.ano );
	
				return CAD_SUCESSO;
			}
			case 5:	{
				printf("-  Novo CPF:\n");
				listarProfessor	(listaProfessor,qtdProfessor);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarProfessor);
				if (posicaoDoAtualizarProfessor<0	|| posicaoDoAtualizarProfessor >= qtdProfessor){
						return POS_INVALIDA;
					}	
				fgets(listaProfessor[posicaoDoAtualizarProfessor].cpf,  15  ,  stdin);
				lnProfessor = strlen(listaProfessor[posicaoDoAtualizarProfessor].cpf) - 1;
				if (listaProfessor[posicaoDoAtualizarProfessor].cpf[lnProfessor] == '\n')
				listaProfessor[posicaoDoAtualizarProfessor].cpf[lnProfessor] = '\0';
				return CAD_SUCESSO;
				 break;
			}
			case 6:	{
				printf("---  Refazer cadastro:  ---\n");
				listarProfessor	(listaProfessor,qtdProfessor);
				printf("Qual posição do vetor você deseja  atualizar?\n");
				getchar();
				scanf("%d", &posicaoDoAtualizarProfessor);
				if (posicaoDoAtualizarProfessor<0	|| posicaoDoAtualizarProfessor >= qtdProfessor){
						return POS_INVALIDA;
					}	
				printf("-  Nova Matricula:\n");
				scanf("%d", &listaProfessor[posicaoDoAtualizarProfessor].matricula);
				
				
				printf("\n");
				printf("-  Novo Nome:\n");
				getchar();
				fgets(listaProfessor[posicaoDoAtualizarProfessor].nome,  50  ,  stdin);
				
				lnProfessor = strlen(listaProfessor[posicaoDoAtualizarProfessor].nome) - 1;
				if (listaProfessor[posicaoDoAtualizarProfessor].nome[lnProfessor] == '\n')
				listaProfessor[posicaoDoAtualizarProfessor].nome[lnProfessor] = '\0';
				
				do {
					printf("-  Novo sexo:\n");
					getchar();
					scanf("%c", &listaProfessor[posicaoDoAtualizarProfessor].sexo);
				}while(listaProfessor[posicaoDoAtualizarProfessor].sexo != 'm' ||	listaProfessor[posicaoDoAtualizarProfessor].sexo != 'M' ||listaProfessor[posicaoDoAtualizarProfessor].sexo != 'f' ||listaProfessor[posicaoDoAtualizarProfessor].sexo != 'F' );

				printf("-  Nova Data de nascimento:\n");
				
				scanf("%d %d %d", &listaProfessor[posicaoDoAtualizarProfessor].dataNas.dia  , &listaProfessor[posicaoDoAtualizarProfessor].dataNas.mes ,  &listaProfessor[posicaoDoAtualizarProfessor].dataNas.ano );
				
				printf("-  Novo CPF:\n");
				getchar();
				fgets(listaProfessor[posicaoDoAtualizarProfessor].cpf,  15  ,  stdin);
				lnProfessor = strlen(listaProfessor[posicaoDoAtualizarProfessor].cpf) - 1;
				if (listaProfessor[posicaoDoAtualizarProfessor].cpf[lnProfessor] == '\n')
				listaProfessor[posicaoDoAtualizarProfessor].cpf[lnProfessor] = '\0';
				getchar();
				return CAD_SUCESSO;
				break;
			}
			default:{
						return ATU_INVALIDA; 
					}	
		}
	}while(opcaoAtualizarProfessor!=0);
}
int cadastrarDisciplina(int qtdDisciplina,Disciplina listaDisciplina[], int lnDisciplina){
	int contDis;
	do{
		printf("- Digite a quantidade de disciplinas que gostaria de cadastrar:\n");
		scanf("%d", &contDis);
	}while(contDis <	0);
	
	if (qtdDisciplina	+ contDis < TAM){
		for(int i	=	qtdDisciplina	; i	<	qtdDisciplina	+	contDis ;	i++){
			printf("\n");
			do{
				printf("Digite o código da disciplina:\n");
				scanf("%d", &listaDisciplina[i].codigo);
			}while(listaDisciplina[i].codigo	<	0);

			printf("Digite o nome da disciplina:\n");
			getchar();
			fgets(listaDisciplina[i].nome,	51	,stdin);
			lnDisciplina	=	strlen(listaDisciplina[i].nome	-1);
			if(listaDisciplina[i].nome[lnDisciplina]	==	'\n'){
				listaDisciplina[i].nome[lnDisciplina]	=	'\0';
			}

			do{
				printf("Digite o semestre da disciplina:\n");
				scanf("%d", &listaDisciplina[i].semestre);
			}while(listaDisciplina[i].semestre	<	0);
		
			printf("Digite a matricula do professor da disciplina:\n");
			scanf("%d",	&listaDisciplina[i].matriculaProfessor);
			// está bugando nesse ultimo scanf Não está armazenando essa matricula do professor!
			getchar();
		}
	return contDis;
	}
	else{
		return CAD_INVALIDO;
	}	
}
int inserirAlunoDisciplina(int qtdDisciplina,int qtdAluno,Disciplina listaDisciplina[], Aluno listaAluno[], int codigoDisciplina){
int temdisciplina =	0;
int validaExistematriculaAluno	=	0;
	
	for(int i=0;	i	<	qtdDisciplina;	i++){
		printf("Nome da Disciplina:	%s\n", listaDisciplina[i].nome);
		printf("Código da Disciplina:	%d\n", listaDisciplina[i].codigo);
	}
	printf("Digite o código da disciplina que você quer cadastrar o aluno:\n");
	scanf("%d", &codigoDisciplina);
	
	for(int i=0;	i	<	qtdDisciplina;	i++){
		if(	codigoDisciplina ==	listaDisciplina[i].codigo){
			temdisciplina++;
			
				printf("Digite quantos aluno deseja cadastrar:\n");
				scanf("%d", &qtdAluno);
				if(qtdAluno > TAM){
					return	TAM_MAX_ULTRA;
				}
			
			for(int j;	j	<	qtdAluno	;	j++){
				listarAluno	(listaAluno, qtdAluno);
				printf("Digite a matricula do aluno:");
				scanf("%d", &listaDisciplina[i].matriculaAluno[j]);
				for(int h=0;	h <	qtdAluno	; h++){
					if(listaDisciplina[i].matriculaAluno[j]	==	listaAluno[h].matricula){
						validaExistematriculaAluno++;
					}
				}
				if(validaExistematriculaAluno	==	0){
					return MAT_INVALIDA;
				}
			}
		return CAD_SUCESSO;}
	}
	if (temdisciplina	==	0){
		return CAD_INVALIDO;
	}
}
void listarDisciplina(int qtdDisciplina,Disciplina listaDisciplina[]){
	for(int i	=	0;	i	<	qtdDisciplina;	i++){
		if(listaDisciplina[i].codigo != 0 ){
		printf("Nome da Disciplina:	%s\n", listaDisciplina[i].nome);
		printf("Código da Disciplina:	%d\n", listaDisciplina[i].codigo);
		printf("Semestre da Disciplina: %d\n", listaDisciplina[i].semestre);
		printf("Matricula do professor na disciplina:	%c\n", listaDisciplina[i].matriculaProfessor);
		}
	}
}
int excluirDisciplina (int qtdDisciplina, Disciplina listaDisciplina[], int codigoDisciplina, int qtdAluno) {
    int confirmarExcluirDisciplina;
    int existecodigoDisciplina = 0;
    do {
        printf("Digite o código da disciplina:\n");
        scanf("%d", &codigoDisciplina);
        for(int i = 0 ; i < qtdDisciplina ; i++) {
            if(codigoDisciplina == listaDisciplina[i].codigo) {
                existecodigoDisciplina++;
                printf("O nome da disciplina é: %s\nDeseja excluir?\n0 - Não\n1 - Sim\n", listaDisciplina[i].nome);
                scanf("%d", &confirmarExcluirDisciplina);
                if(confirmarExcluirDisciplina == 1) {
                    listaDisciplina[i].codigo = 0;
                    listaDisciplina[i].semestre = 0;
                    listaDisciplina[i].nome[0] = '\0';
                    listaDisciplina[i].matriculaProfessor = 0;
                    for(int j = 0; j <= qtdAluno; j++) {
                        listaDisciplina[i].matriculaAluno[j] = 0;
                    }
                }
            }
        }
        if(existecodigoDisciplina == 0) {
          return EXC_INVALIDO;
        }
    } while(confirmarExcluirDisciplina != 1);

    return CAD_SUCESSO;
}