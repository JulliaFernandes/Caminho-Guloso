#include"matriz.hpp"

using namespace std;

int main(){
    
    int tam_matriz, qtd_matriz=0;

    tam_matriz = LePrimeraLinha();
    qtd_matriz = ContaQtdMatriz()+1;
    cout << qtd_matriz << endl << endl;
    cout << tam_matriz << endl;
    
    //alocaçao da matriz
    int** matriz=new int*[tam_matriz];
    for(int i = 0; i < tam_matriz; i++){
        matriz[i]=new int[tam_matriz];
    }

    LerArquivo(matriz, tam_matriz);

    return 0;
}