#include <stdio.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} DataNas;

typedef struct {
  DataNas dataNas;
  int matricula;
  char nome[51]; // contém 50 caract
  char sexo;
  int cpf[11];
} aluno; // nome da stuct

typedef struct {
  DataNas dataNas;
  int matricula;
  char nome[51]; // contém 50 caract
  char sexo;
  int CPF[11];
} professor; // nome da struct

typedef struct {
  char nome[51];
  int codigo;
  int semestre;
  char professor[51] // contém 50 caract
} disciplina;        // nome da struct