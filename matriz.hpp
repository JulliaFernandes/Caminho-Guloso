#ifndef MATRIZ_HPP__
#define MATRIZ_HPP__
#include<iostream>
#include<fstream>
#include <sstream>
#include <cstring>
#include<stdbool.h>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#define TAM 4

using namespace std;

void GeraMatrizAleatorio(int matriz[TAM][TAM]);
void ColocandoMatriz();
void LerArquivo();
void ImprimirMatriz();
void PercorrerMatriz();

#endif