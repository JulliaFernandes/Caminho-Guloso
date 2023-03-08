#ifndef MATRIZ_HPP__
#define MATRIZ_HPP__

#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<stdbool.h>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
#define TAM 4

using namespace std;

class TamanhoMatriz{
    private:
        int tam_max;
    public:
        void setTam_max(int tam_max);
        int getTam_max();
};

//void GeraMatrizAleatorio(int matriz[TAM][TAM]);
//void ColocandoMatriz();
int LePrimeraLinha();
int ContaQtdMatriz();
void LerArquivo(int **matriz, int tam_matriz);
void ImprimirMatriz(int **matriz, int tam_matriz);
void PercorrerMatriz(int **matriz, int linha, int coluna, int tam_matriz);


#endif