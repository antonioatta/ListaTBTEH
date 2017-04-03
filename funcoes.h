#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*-------------------------------------- Funcoes Aritmeticas ----*/
int soma(int, int);

float opera(float, float, int);

int divisores(int, int []);

int converte(int [], int);

float compoe(int, int, int);


/*-------------------------------------- Funcoes Comparacoes ----*/

int maior_de_dois(int, int);

int menor_de_tres(int, int, int);

int maior_de_quatro(int, int, int, int);

int maior_de_todos(int [], int);

int existe(int [], int, int);

int conjuntos_iguais(int [], int [], int);

int rodada_palitinhos(int [], int [], int);


/*-------------------------------------- Funcoes Matrizes ----*/

int mais_preenchida(char [][10]);

int mais_preenchida_2(char [][10]);

void diagonal_invertida(int [][10]);

void calcula_media(int [][3], float [], int );


#endif // FUNCOES_H_INCLUDED
