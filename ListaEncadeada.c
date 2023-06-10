/* observe a questão EP006 que tem duas abordagens
  - EP006-ListaEncadeadaAPartirdeN-comcabecote-icaro.c usa cabeçote (inicio). Cabeçote é um elemento que não tem valor serve só para ter acesso ao início da lista. ELe é definido no main(). A função crialista() usa um ponteiro
  Por outro lado,
  - EP006-ListaEncadeadaAPartirdeN.c NÃO usa cabeçote. O primeiro elemento já é um elemento válido da lista. Ele é definido dentro da função. Neste caso, é preciso usar ponteiro para ponteiro.
*/


#include <stdio.h>
#include <stdlib.h>

int tam = 0;
typedef struct reg {
	int conteudo;
  struct reg *prox;
} No;


//############################


//funcao para inserir um elemento na lista

void inserirElemento(No **inicioSemCabecote, int valor){
	
	//criar o elemento
	No *novo = (No *)malloc(sizeof(No));
	//preencher o conteudo
	novo->conteudo = valor;
	//apontar para null
	novo->prox = NULL;

	No *atual;
	
	if (*inicioSemCabecote == NULL)
		//apontar inicio para esse novo elemento
		*inicioSemCabecote = novo; 
	else{
		//varrer a lista até o final
		atual = *inicioSemCabecote;
		while (atual->prox != NULL)
			atual = atual->prox;

		//neste momento, atual aponta para o último elemento

		//fazer atual apontar para novo
		atual->prox = novo;
	}
}

void inserirElementoOrdenado(No **inicioSemCabecote, int valor){
	
	//criar o elemento
	No *novo = (No *)malloc(sizeof(No));
	//preencher o conteudo
	novo->conteudo = valor;
	//apontar para null
	novo->prox = NULL;

	No *atual, *anterior;
	
	if (*inicioSemCabecote == NULL)
		//apontar inicio para esse novo elemento
		*inicioSemCabecote = novo; 
	else{
		
		//varrer a lista até o achar o primeiro maior ou chegar no final
		atual = *inicioSemCabecote;
		anterior = *inicioSemCabecote;
		while (atual != NULL && atual->conteudo < valor){
			anterior = atual;
			atual = atual->prox;
		}

		//neste momento, atual aponta para 
		//o primeiro elemento maior que o novo

		//fazer anterior apontar para novo
		anterior->prox = novo;

		//fazer novo->prox apontar para atual
		novo->prox = atual;
	}
}

void listarElementos(No *inicioSemCabecote){

	if (inicioSemCabecote == NULL)
		printf("Lista Vazia\n", );
	else {
		printf("Elementos da lista:\n", );

		No *atual = inicioSemCabecote;
		
		while (atual != NULL){
			printf("%d", atual->conteudo);
			atual = atual->prox;
		}
	}	
}


int excluirElemento(No** inicio, int valor){
	if (*inicio == NULL)
		return LISTA_VAZIA; // lista vazia

	No* anterior = *inicio;
	No* atual = *inicio;
	No* proximo = atual->prox;
	int achou = 0;

	while(atual != NULL){
		if (atual->conteudo == valor){
			achou = 1;
			break;
		}
		anterior = atual;
		atual = proximo;
		if (atual != NULL)
			proximo = atual->prox;
	}

	if (achou){
		if (atual == *inicio)
			*inicio = proximo;
		else
			anterior->prox = atual->prox;
		free(atual);
		return SUCESSO_EXCLUSAO;
	}else
		return NAO_ENCONTRADO;
}

//############################


int main(){
	
	int idade = 8;
	int *pInt = &idade;
	*pInt = 10; 
	
}

int printValor(int valor){

	printf("%d", valor);

}

















No* criarElemento(int valor){
	No *novo = (No *)malloc(sizeof(No));
	if(novo == NULL){
        printf("Falta Memoria\n");
        exit(1);
	}
	novo->conteudo = valor;
	novo->prox = NULL;
	return novo;
}

void inserirNoFinalSemCabecote(No **inicioSemCabecote, int val){
    No *novo;
    No *atual;

    novo = criarElemento(val);

    if(*inicioSemCabecote == NULL)
        *inicioSemCabecote = novo;
    else{
        atual = *inicioSemCabecote;

        while(atual->prox != NULL)
            atual = atual->prox;

        atual->prox = novo;
    }
}


void inserirNoFinalComCabecote(No *inicio, int val){

	No* tmp;
	No* novo = criarElemento(val);

	if(inicio->prox == NULL){
		inicio->prox = novo;
	}
	else{
		tmp = inicio->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void listarElementos(No* inicio){
	No *p;
	printf ("lista\n");
    for (p = inicio; p != NULL; p = p->prox)
      printf ("%d\n", p->conteudo);
}

void liberarLista(No* inicio){

	No* atual = inicio;
	No* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}

int main()
{
	int n, i;
	
	int idade = 5;
	No *inicioListaSemCabecote = NULL;
	inicioListaSemCabecote = (No *)malloc(sizeof(No));

	inserirElemento(inicioListaSemCabecote, idade);



    No *inicioListaComCabecote = (No*) malloc(sizeof(No));
	inicioListaComCabecote->prox = NULL;
	printf("Digite um número!\n");
	scanf("%d", &n);
	if (n <= 0){
		printf("valor inválido\n");
		exit(0);
	}

	for (i = 1; i <= n; i++){
		inserirNoFinalSemCabecote(&inicioListaSemCabecote, i);
        inserirNoFinalComCabecote(inicioListaComCabecote, i);
    }

	listarElementos(inicioListaSemCabecote);
    listarElementos(inicioListaComCabecote->prox);

	liberarLista(inicioListaSemCabecote);
	liberarLista(inicioListaComCabecote);

}
