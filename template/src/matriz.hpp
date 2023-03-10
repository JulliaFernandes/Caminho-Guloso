#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<stdbool.h>
#include<ctime>
#include<cstdlib>
#include<unistd.h>
#include<string>

using namespace std;

int LePrimeraLinha();
bool linhaVazia(const string& linha);
int ContaQtdMatriz();
void LerArquivo(int **matriz, int tam_matriz);
void ImprimirMatriz(int **matriz, int tam_matriz);
void PercorrerMatriz(int **matriz, int linha, int coluna, int tam_matriz);


#endif