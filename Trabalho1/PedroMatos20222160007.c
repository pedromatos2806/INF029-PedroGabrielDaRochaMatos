// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Pedro Gabriel da Rocha Matos	
//  email: pedrogabriel_r@hotmail.com
//  Matrícula:20222160007
//  Semestre:2023-1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "PedroMatos20222160007.h" 
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){	// ler até a barra 
		if(data[i] >=	48 && data[i] <= 57){
			sDia[i] = data[i];
		} else{
			dq.valido	=	0;
			return dq;
		}
	}
	
	if(i == 1 || i == 2){	// testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
		return dq;
  }
	
	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for (; data[j] != '/'; j++){	//ler até a barra
		if(data[j] >=	48 && data[j] <= 57){
			sMes[i] = data[j];
			i++;
		} else{
			dq.valido	=	0;
			return dq;
		}
	}

	if(i == 1 || i == 2){	// testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

	
	j = j + 1;	//anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){	//coloca \0 no final  
		 if(	data[j] >=	48 && data[i] <= 57	){
			sAno[i] = data[j];
		 	i++;
	 }else{
			dq.valido = 0;
	    return dq;
	 } 
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	
  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  //quebrar a string data em strings sDia, sMes, sAno
	//printf("%s\n", data);
  DataQuebrada dataQuebrada = quebraData(data); // está separada e já virou inteiro
  if (dataQuebrada.valido == 0){
		return 0;
	}
 return ValidacaoDataQuebrada (dataQuebrada); // retorno vai ser direto da função criada!
}

int ValidacaoDataQuebrada (DataQuebrada dataQuebrada){
	if(dataQuebrada.iAno < 100 && dataQuebrada.iAno >=	10){
		dataQuebrada.iAno = dataQuebrada.iAno	+	2000; // isso aqui é para adicionar o 20 na frente ,caso a pessoa ,por exemplo,  digite 95 no ano.
	}
		switch (dataQuebrada.iMes){
			case 1:{
				//janeiro
				if(dataQuebrada.iDia >= 1 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 2:{
				//fevereiro
				// condição p/ ser bissexto 
				//tem que ser multiplo de 4 , não pode ser multiplo de 100, porém se for multiplo de 400 é bissexto!
				if (	(	(dataQuebrada.iAno	%	4	== 0) && (dataQuebrada.iAno	%	100	!=	0)	) || (dataQuebrada.iAno	%	400	==	0)	){
					if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 29){
						dataQuebrada.valido = 1;
						return dataQuebrada.valido;
					}else{
						dataQuebrada.valido = 0;
						return dataQuebrada.valido;
					}
			}else {
					if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 28){
						dataQuebrada.valido = 1;
						return dataQuebrada.valido;
					}else{
						dataQuebrada.valido = 0;
						return dataQuebrada.valido;
					}
			}
				break;
			}
			case 3:{
				//março
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 4:{
				//abril
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 30){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 5:{
				//maio
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 6:{
				//junho
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 30){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 7:{
				//julho
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 8:{
				//agosto
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 9:{
				//setembro
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 30){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 10:{
				//outubro
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 11:{
				//novembro 
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 30){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			case 12:{
				//dezembro
				if(dataQuebrada.iDia > 0 && dataQuebrada.iDia <= 31){
					dataQuebrada.valido = 1;
					return dataQuebrada.valido;
				}else{
					dataQuebrada.valido = 0;
					return dataQuebrada.valido;
				}
				break;
			}
			default:
			dataQuebrada.valido = 0;
			return dataQuebrada.valido;
		}
	
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2; // aqui já está testando se a data inicial é inválida
      return dma; 
    }else if (q1(datafinal) == 0){
      dma.retorno = 3; // aqui já está testando se a data final é invalida 
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
			DataQuebrada dmai	=	quebraData(datainicial);
			DataQuebrada dmaf	= quebraData(datafinal);

			if(	(dmai.iAno > dmaf.iAno) || (dmai.iAno == dmaf.iAno && dmai.iMes > dmaf.iMes) ||(dmai.iAno == dmaf.iAno && dmai.iMes == dmaf.iMes && dmai.iDia > dmaf.iDia)	){
    dma.retorno = 4;
    return dma;
			}else {
				/*
				dma.qtdDias	=	dmaf.iDia	-	 dmai.iDia;
				dma.qtdMeses	=	dmaf.iMes	-	dmai.iMes;
				dma.qtdAnos	=	dmaf.iAno	-	dmaf.iAno;
				dma.retorno	=	1;
				*/			
				int mes	=	 QdtDiasMes( dmai.iMes, dmai.iAno);
				dma.retorno	=	1; //retorno colocado na struct 
				int datai	=	 QtdDiasAno(dmai.iMes , dmai.iAno) +	dmai.iDia;
				datai	=	datai	+	dmai.iAno	*	365;
				int dataf	=	QtdDiasAno(dmaf.iMes	,	dmaf.iAno)	+	dmaf.iDia;
				dataf	=	dataf	+	dmaf.iAno	*	365;
				int difdata	=	dataf	-	datai;
				dma.qtdAnos	=	difdata/365;
				 difdata +=  QtdDiasAno(dmai.iMes, dmai.iAno) == QtdDiasAno(dmaf.iMes, dmaf.iAno);
					difdata	=	difdata	-	dma.qtdAnos*365;
					dma.qtdMeses	=	difdata	/	mes;
					dma.qtdDias	=	difdata	%	mes;
					
				return dma;
			}
				
			}
				
			/* Criar uma função para comparar as datas
	 			1° transformar em inteiros 
	 			2° comparar se o ano inicial é maior que o ano final 
		 		
		 		SE N FOR 
		 		3° comparar se o mês inicial é maior que o mês final 
		 		
		 		SE N FOR 
		 		4° comparar se o dia inicial é maior que o dia final 
		 		SE N FOR 
		 		calcular a distancia entre as datas
			*/
      
			//calcule a distancia entre as datas


      //se tudo der certo
			
      dma.retorno = 1;
      return dma;
    }
    


int QdtDiasMes(int mes, int ano) {
  switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:{
      if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) {
        return 29;
      } else {
        return 28;
      }
    }
  }
}
int QtdDiasAno(int mes,int ano	){
	int dias	=	0;
	int MESES	=	1;
	while(mes	>	MESES){
		dias	=	dias + QdtDiasMes(MESES, ano);
		MESES++;
	}
	return dias;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
return  QtdLetrasTexto ( c,	texto, isCaseSensitive);
}

int QtdLetrasTexto (char c,	char *texto, int isCaseSensitive){
	int qtdOcorrencias = 0;

		if(isCaseSensitive	==	1){
			for(int i =	0	;	texto[i]	!='\0'	;	i++){
				if(texto[i]	==	c)
					qtdOcorrencias++;
			}
			return qtdOcorrencias;
		}else {
			for(int i	=	0	;	texto[i]	!=	'\0'	;	i++){
				if(texto[i]	==	c	||	texto[i]+ 32 == c || texto[i]	==	c	+	32) // tentei pelo tolower porém n foi, foi apenas pela ASCII 
					qtdOcorrencias++;
			}
			return qtdOcorrencias;	
		}
}
/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
return  QtdPalavras( strTexto, strBusca,posicoes);
}

int QtdPalavras(char *strTexto, char *strBusca, int posicoes[30]){
	// "Laboratorio de programacao: para ratos de programação" 55
	// "rato" 4
	int tampalavra, tamtexto;
	tamtexto	=	strlen(strTexto);
	tampalavra = strlen(strBusca);
	int pos	=	0;
	int qtdOcorrencias = 0;
	int i,	j	=	0;
	int qtdletraspalavras=0;
	//for (int	k=0;strTexto[k]	!=	'\0';	k++)
		//qtdletraspalavras++;
	
		//if( tampalavra == 2 && qtdletraspalavras == tampalavra ){}
			// estão conseguindo ver ai?? to ouvindo vcsss!!!!!
			// meu problema ta aqui!!! no teste 
		    /*strcpy(strTexto,"maraaaavilha, meu prograaaama funcionou");
    strcpy(strBusca,"aa");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 4);*/
			
			for(i=0	;	strTexto[i]	!=	'\0'	;	i++){ //ESSE FOR É PRA PERCORRER TEXTO
					if(strBusca[j]	==	strTexto[i]) // SE ACHAR INCREMENTA O J++
						j++;
					else // SE N ACHAR O J VOLTA A SER 0
						j=0;
					if(j	==	tampalavra){ // SE O J FOR IGUAL AO TAM PALAVRA ACHOU UMA PALAVRA
						j=0;
						posicoes[pos]	=	i+1	- (tampalavra-1); /// isso aqui é pra ajustar as posiçoes do i que sao difentes // tampalavra - 1 é pq se fizer o calculo ele diminui sempre uma a menos que a palavra
						pos++;
						posicoes[pos]	=	i+1; // essa soma aqui tbm é pra ajustar a posicao do vetor com a posicao q ele deu q é uma posicao a mais
						pos++;
						qtdOcorrencias++;
					}
				}
			
	return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
	return inverterNumero(num);
}

int inverterNumero (int num){
	int undCenMilhar	=	0, undDezMilhar	=	0, undMilhar =0, undCentena =0 , undDezena = 0, und = 0;
	int r;
	
	undCenMilhar = num	/ 100000;
	if (undCenMilhar != 0){
		r = num % 100000;
		undDezMilhar = r	/ 10000;
		r	=	 r % 10000;
		undMilhar = r / 1000;
		r = r % 1000;
		undCentena = r / 100;
		r = r % 100;
		undDezena = r / 10;
		und	=	 r % 10;

		num = undCenMilhar	+	(undDezMilhar*10)+(undMilhar*100)+(undCentena*1000)+(undDezena*10000)+(und*100000);
		return num;
	}
	undDezMilhar = num / 10000;
	if(undDezMilhar !=0 ){
		r = num % 10000;
		undMilhar = r / 1000;
		r = num % 1000;
		undCentena = r / 100;
		r = r % 100; 
		undDezena =  r	/ 100;
		und	=	 r % 10;
		
		num = (undDezMilhar*1)+(undMilhar*10)+(undCentena*100)+(undDezena*1000)+(und*10000);
		return num;
	}
	undMilhar = num / 1000;
		if(undMilhar !=0 ){
			r	= num % 1000;
			undCentena = r / 100;
			r = r % 100;
			undDezena = r / 10;
			und	=	 r % 10;
			
			num = (undMilhar*1)+(undCentena*10)+(undDezena*100)+(und*1000);
			return num;
		}
	undCentena = num / 100;
	if(undCentena !=0 ){
		r = num % 100;
		undDezena = r / 10;
		und	=	 num % 10; 
		num = undCentena	+	(undDezena*10)+(und*100);
		return num;
	}
	undDezena	=	 num / 10;
	if(undDezena !=0 ){
			und	=	 num % 10; 
			num = (undDezena*1)+(und*10);
			return num;
	}
	r	= num % 10;
		if(r !=0)
			return num;
	
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  return FuncaoQ6(numerobase,numerobusca);
}

/*-	LÓGICA Q6	-
Calcular quantas vezes um número inteiro tem dentro de outro inteiro  sem transformá-los em Strings

-	Passos:
1°	-	calcular quantos dígitos tem no numerobase 
2° 	-	calcular quantos dígitos tem o numerobusa
3°	-	calcular quantos dígitos tem o numerobase - numero busca, para saber de quantos em quantos dígitos iremos dividir
4°	-	pega inicialmente o numerobase multiplicar por 10  elevador diferença de (dígitos do número base - numero busca) depois disso dividir esse resultado pelo numerobusca
5°	-	se o resultado for 1 já se tem um incremento na quantidade de ocorrências, se não, não incrementa nada
6°	-	para continuar nesse processo deve pegar o resto da divisão 
7°	-	diminuir o valor da potência na quantidade de digitos do numero busca 
8° 	-	dividir novamente o resto multiplicado pelo valor da potência pelo numero busca
9°	-	repetir o 7 e 8 enquanto o resto seja maior ou igual ao numero busca */
int FuncaoQ6(int numerobase, int numerobusca ){
  if(numerobase<numerobusca){
		return 0;
	}
	int qtdocorrencias = 0;
  int digitosnumerobase = numerodeDigitos(numerobase);
  int digitosnumerobusca = numerodeDigitos(numerobusca);
  //printf("qtd dig busca:%d\n",digitosnumerobusca);
  int auxbase = numerobase;
  int auxbusca  = numerobusca;
  int digit =  0;
  
  while(auxbase !=  0){
    int digitosauxbase = numerodeDigitos(auxbase);
    int rbase,rbusca;
    rbase=auxbase % 10;
    //printf("restobase:%d\n",rbase);
    auxbase /= 10;
    //printf("auxbase:%d\n",auxbase);
    if(auxbusca / 10  !=  0){
      rbusca  = auxbusca%10;
      auxbusca  /= 10;
    }else{
      rbusca  = auxbusca%10;
      auxbusca  = numerobusca;
    }
      
    //printf("rbusca:%d rbase:%d\n",rbusca ,rbase);
    //printf("auxbusca:%d auxbase:%d\n",auxbusca ,auxbase);
    if(rbusca ==  rbase){
      digit++;
      //printf("digit:%d\n",digit);
    }else{
      auxbusca  = numerobusca;
			digit=0;
    }
    
    if(digit == digitosnumerobusca){
      qtdocorrencias++;
      digit=0;
      //printf("qtdocorrencias:%d\n",qtdocorrencias);
    }
    if(digitosnumerobusca ==  1){
      digit=0;
    }
  }
  //printf("*** OCORRENCIAS:%d ***",qtdocorrencias);
  return qtdocorrencias;
}

int numerodeDigitos (int num){
  int contador = 1;
  while(num > 9){
    num /= 10;
    contador++;
  }
  return contador;
}