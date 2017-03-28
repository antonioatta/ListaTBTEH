#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*-------------------------------------- Funcoes Aritmeticas ----*/
int soma(int x, int y)
{
    return(x+y);
}

float opera(float a, float b, int op)
{
    switch (op)
    {
    case 0:
        return(a+b);   // breaks nos cases desnecessarios pelo
    case 1:            // uso do return em cada um deles
        return(a-b);
    case 2:
        return(a*b);
    case 3:
        return(a/b);
    default:
        return 0;


    }
}

int divisores(int num, int div[])
{
    int i, metade, cont=1;

    metade = num/2;
    div[0] = num;
    for (i=2; i<=metade; i++)
    {
        if (num%i == 0)
        {
            div[cont]=i;
            cont++;
        }
    }
    div[cont]=1;
    cont++;
    return cont;
}


int converte(int binario[], int numDig)
{
    int i;
    int decimal=0;
    int potencia=0;

    for (i=numDig-1; i>0; i++)
    {
        decimal += binario[i]*pow(2, potencia);
        potencia++;
    }
    return decimal;
}

float compoe(int parteInt, int parteDec, int ajuste)
{
    float composto, pInt, pDec;

    pInt=parteInt;              // converte para float
    pDec=parteDec;              // converte para float
    while (pDec>1) pDec /= 10;  // divide ateh ficar 0,...
    while (ajuste>0)
    {
        pDec /= 10;             // acrescenta zeros depois da virgula
        ajuste--;
    }
    composto=pInt+pDec;
    return composto;
}

/*-------------------------------------- Funcoes Comparacoes ----*/

int maior_de_dois(int a, int b)
{
    return (a>b?a:b);
}


int menor_de_tres(int a, int b, int c)
{
    if ((a<=b) && (a<=c)) return a;
    if (b<=c) return b;
    return c;
}


int maior_de_quatro(int a, int b, int c, int d)
{
    int maior;

    maior=a;
    if (b>maior) maior=b;
    if (c>maior) maior=c;
    if (d>maior) maior=d;
    return maior;
}


int maior_de_todos(int valores[], int tam)
{
    int maior, pos, i;

    maior=valores[0];
    pos=0;
    for (i=1; i<tam-1; i++)
    {
        if (valores[i]>maior)
        {
            maior=valores[i];
            pos=i;
        }
    }
    return pos;
}


int existe(int valores[], int tam, int buscado)
{
    int i, vezes=0;

    for (i=0; i<tam; i++)
    {
        if (valores[i]==buscado) vezes++;
    }
    return vezes;
}


int conjuntos_iguais(int conjunto1[], int conjunto2[], int tam)
{
    int i, j, achou;
    int jaTratou[tam];

    for (j=0; j<tam; j++) jaTratou[j]=0;

    for (i=0; i<tam; i++)
    {
        achou=0;
        for (j=0; j<tam; j++)
        {
            if (jaTratou[j]) continue;
            if (conjunto1[i]==conjunto2[j])
            {
                achou=jaTratou[j]=1;
                break;
            }
        }
        if (!achou) return 0;
    }
    return 1;
}


int rodada_palitinhos(int palitosEmJogo[], int palpites[], int jogadores)
{
    int i, somaDasMaos=0;

    for (i=0; i<jogadores; i++)
    {
        somaDasMaos += palitosEmJogo[i];
    }
    for (i=0; i<jogadores; i++)
    {
        if (palpites[i]==somaDasMaos) return i;
    }
    return -1;
}

/*-------------------------------------- Funcoes Matrizes ----*/

int mais_preenchida(char matriz[10][10])
{
    const int TAM=10;
    int i, j, contador, linha=0;
    int maior=-1;

    for (i=0; i<TAM; i++)
    {
        contador=0;
        for (j=0; j<TAM; j++)
            if (matriz[i][j]=='*') contador++;
        if (contador>maior)
        {
            maior=contador;
            linha=i;
        }

    }
    return linha;
}


int mais_preenchida_2(char matriz[10][10])
{
    const int TAM=10;
    int i, j, contador, linha=0, coluna=0;
    int maior_linha, maior_coluna=-1;


    linha = mais_preenchida(matriz);
    maior_linha=0;
    for (j=0; j<TAM; j++)
        if (matriz[linha][j]=='*') maior_linha++;

    for (j=0; j<TAM; j++)
    {
        contador=0;
        for (i=0; i<TAM; i++)
            if (matriz[i][j]=='*') contador++;
        if (contador>maior_coluna)
        {
            maior_coluna=contador;
            coluna=j;
        }

    }
    return (maior_coluna>maior_linha?-(coluna+1):linha);
}


void diagonal_invertida(int matriz[10][10])
{

    const int TAM=10;
    int i, j, aux;

    for (i=0; i<TAM; i++)
    {
        for (j=i+1; j<TAM; j++)
        {
            if (j!=i)
            {
                aux=matriz[i][j];
                matriz[i][j]=matriz[j][i];
                matriz[j][i]=aux;
            }
        }
    }
}

void calcula_media(int notas[][3], float medias[], int numAlunos)
{
    const int NUM_NOTAS=3;
    int i, j;

    for (i=0; i<numAlunos; i++)
    {
        medias[i]=0;
        for (j=0; j<NUM_NOTAS; j++) medias[i] += notas[i][j];
        medias[i] /= NUM_NOTAS;
    }
}

