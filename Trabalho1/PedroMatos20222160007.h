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
//  Nome:Pedro Gabriel Da Rocha Matos
//  email:pedrogabriel_r@hotmail.com
//  Matrícula:2022160007
//  Semestre:2023-1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#ifndef TRABALHO1_PEDROMATOS2022160007_H
#define TRABALHO1_PEDROMATOS2022160007_H

typedef struct DQ
{
    int iDia;
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

int somar(int x, int y); //função utilizada para testes
int fatorial(int x); //função utilizada para testes
int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
DataQuebrada quebraData(char data[]);
int QdtDiasMes(int mes, int ano);
int QtdDiasAno(int mes,int ano	);
int ValidacaoDataQuebrada (DataQuebrada dataQuebrada);
int q3(char *texto, char c, int isCaseSensitive);
int  QtdLetrasTexto (char c,	char *texto, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int QtdPalavras(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int inverterNumero (int num);
int q6(int numerobase, int numerobusca);
int qtdNumeros(int numerobase, int numerobusca);
int numerodeDigitos (int num);
int FuncaoQ6(int numerobase, int numerobusca );
#endif  // TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H