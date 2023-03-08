#include"matriz.hpp"
using namespace std;

int soma=0;


void TamanhoMatriz::setTam_max(int _tam){
    this->tam_max =  _tam;
}

int TamanhoMatriz :: getTam_max(){
    return tam_max;
}

/*void GeraMatrizAleatorio(int matriz[TAM][TAM]){
    sleep(1);
    srand(time(nullptr));
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            matriz[i][j] = rand() %100; 
        }
    }
}*/

int LePrimeraLinha(){
    ifstream arquivo;
    string linha, valor_str, aux_str, elemento;
    int aux=0, tam=0;

    arquivo.open("matriz.txt", ios::in);
    while (!arquivo.eof()){
        while(getline(arquivo, linha, '\n')){
            stringstream aux_str(linha);
            while(getline(aux_str, elemento, ' ')){
                if(aux == 0){
                    valor_str = elemento;
                    tam = atoi(valor_str.c_str());
                    //cout << tam << endl;
                    
                    aux++;
                }
            }
            
    }
    arquivo.close();
    }
    return tam;
}

int ContaQtdMatriz(){
    ifstream arquivo;
    string linha;
    int aux=0;

    arquivo.open("matriz.txt", ios::in);
    while (!arquivo.eof()){
        while(getline(arquivo, linha, '\n')){
            if(linha.empty()){
                aux++;
            }   
    }
    arquivo.close();
    }
    return aux;
}
/*void ColocandoMatriz(){
    ofstream arquivo;
    int a = 0;
    int quantidadeMatrizes=0;
    srand(time(NULL));
    quantidadeMatrizes = rand() %5 +1;
    cout << "\n--Quantidade de matrizes geradas:" << quantidadeMatrizes << "--" << endl;

    arquivo.open("matriz.txt");
    if(!arquivo){
        cout << "\nFALHA NA ABERTURA DO ARQUIVO" << endl;
    }
    else{
        arquivo << TAM << "x" << TAM << endl;
        while(quantidadeMatrizes>0){
            GeraMatrizAleatorio(matriz);

            for(int i=0; i<TAM; i++){
                for(int j=0; j<TAM; j++){
                    if(a<TAM){
                        arquivo << matriz[i][j] << " ";
                        a++;
                        //se meu 'a' for menor que 3 significa que aunda nao preenchi toda linha da matriz
                    }
                    else{ //meu 'a' é 3, significa que tenho de ir para proxima linha entao devo pular uma linha inserir o primeiro elemento e aumentar meu 'a' novamente
                        a = 0;
                        arquivo << "\n";
                        arquivo << matriz[i][j] << " ";
                        a++;
                    }
                }
            }
            arquivo << "\n";
            quantidadeMatrizes--;
        }
        
    }
    arquivo.close();
}*/

void LerArquivo(int **matriz, int tam_matriz){
    ifstream arquivo;
    string linha_arq, elemento;
    int aux_linha=0, aux_coluna=0, aux_tam=0, linha=0, coluna=0;
    //string **matriz_aux;
    string **matriz_aux=new string*[tam_matriz];
    for(int i = 0; i < tam_matriz; i++){
        matriz_aux[i]=new string[tam_matriz];
    }
    
    arquivo.open("matriz.txt", ios::in);

    while(!arquivo.eof()){
        while(getline(arquivo, linha_arq, '\n')){
            if(aux_tam==0){
                aux_tam++;
            }
            else{
                if(linha_arq.empty()){
                    for(int i=0; i<tam_matriz; i++){
                        for(int j=0; j<tam_matriz; j++){
                            matriz[i][j] = atoi(matriz_aux[i][j].c_str());
                        }
                    }
                    cout << "\n---Nova Matriz---" << endl;
                    ImprimirMatriz(matriz, tam_matriz);
                    PercorrerMatriz(matriz, linha, coluna, tam_matriz);
                    //memset(matriz_aux, 0, sizeof(matriz_aux));
                    matriz[TAM][TAM] = {0};
                    aux_coluna = 0;
                    aux_linha = 0;
                    soma = 0;
                    linha = 0;
                    coluna = 0;
                }
                else{
                    //está criando um fluxo de caracteres para que a função getline possa ler e manipular os dados
                    stringstream aux(linha_arq);

                    //lendo a cada elemento presente na minha linha armazena para minha variavel elemento e tendo o delimitador ''
                    while(getline(aux, elemento, ' ')){
                        matriz_aux[aux_linha][aux_coluna] = elemento;
                        aux_coluna++;
                    }

                    if(aux_coluna>0){
                        aux_linha++;
                        aux_coluna=0;
                    }
                }
            }    
        }
    }
    arquivo.close();  

    for(int i=0; i<tam_matriz; i++){
        for(int j=0; j<tam_matriz; j++){
            matriz[i][j] = atoi(matriz_aux[i][j].c_str());
        }
    }
    cout << "\naa---Nova Matriz---" << endl;
    ImprimirMatriz(matriz, tam_matriz);
    PercorrerMatriz(matriz, linha, coluna, tam_matriz);
}

void ImprimirMatriz(int **matriz, int tam_matriz){
    cout << endl;
    for (int i=0; i<tam_matriz; i++) {
        for (int j=0; j<tam_matriz; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "VALOR DA SOMA: " << soma << endl;
}

void PercorrerMatriz(int **matriz, int linha, int coluna, int tam_matriz){
    soma += matriz[linha][coluna];

    while(linha < tam_matriz && coluna < tam_matriz){
        cout << "\nLINHA: " << linha;
        cout << "\nCOLUNA: " << coluna << endl;

        if((linha == 0) && (coluna == 0)){
            //olho se é o que esta abaixo da posicao [0][0] é o maior e atualizo os passos
            if(matriz[linha+1][coluna] >= matriz[linha][coluna+1] && matriz[linha+1][coluna] >= matriz[linha+1][coluna+1]){
                soma += matriz[linha+1][coluna];
                matriz[linha][coluna] = -1;
                linha++;
            }
            else if(matriz[linha+1][coluna+1] >= matriz[linha+1][coluna] && matriz[linha+1][coluna+1] >= matriz[linha][coluna+1]){ //a minha diagonal é a maior
                soma += matriz[linha+1][coluna+1];
                matriz[linha][coluna] = -1;
                linha++;
                coluna++;
            }
            else{ // se nao for o de baixo nem a diagonal é o da coluna a direita logo atualizo tmb 
                soma += matriz[linha][coluna+1];
                matriz[linha][coluna] = -1;
                coluna++;
            }
            ImprimirMatriz(matriz, tam_matriz);
        }
        else if(coluna > 0 && coluna < tam_matriz-1){ //olhando quando estou nao estou nas colunas das extremidades
            if(linha < tam_matriz-1 && linha != 0){ //olhando quando nao estou tmb nas linhas das extremidades, estou no meio
                if(matriz[linha+1][coluna] >= matriz[linha][coluna+1] && matriz[linha+1][coluna] >= matriz[linha][coluna-1] &&  matriz[linha+1][coluna] >= matriz[linha+1][coluna+1] && matriz[linha+1][coluna] >= matriz[linha+1][coluna-1]){ //estaria descendo
                    soma += matriz[linha+1][coluna];
                    matriz[linha][coluna] = -1;
                    linha++;
                }
                else if(matriz[linha][coluna+1] >= matriz[linha+1][coluna] && matriz[linha][coluna+1] >= matriz[linha][coluna-1] && matriz[linha][coluna+1] >= matriz[linha+1][coluna+1] && matriz[linha][coluna+1] >= matriz[linha+1][coluna-1]){//estaria indo a direita
                    soma += matriz[linha][coluna+1];
                    matriz[linha][coluna] = -1;
                    coluna++;
                }
                else if(matriz[linha][coluna-1] >= matriz[linha][coluna+1] && matriz[linha][coluna-1] >= matriz[linha+1][coluna] && matriz[linha][coluna-1] >= matriz[linha+1][coluna+1] && matriz[linha][coluna-1] >= matriz[linha+1][coluna-1]){//estaria indo a esquerda
                    soma += matriz[linha][coluna-1];
                    matriz[linha][coluna] = -1;
                    coluna--;
                }
                else if(matriz[linha+1][coluna-1] >= matriz[linha][coluna+1] && matriz[linha+1][coluna-1] >= matriz[linha][coluna-1] && matriz[linha+1][coluna-1] >= matriz[linha+1][coluna] && matriz[linha+1][coluna-1] >= matriz[linha+1][coluna+1]){ //estaria indo para a diagonal posterior(indo para a esquerda)
                    soma += matriz[linha+1][coluna-1];
                    matriz[linha][coluna] = -1;
                    linha++;
                    coluna--;
                }
                else{ //estaria indo na diagonal inferior(para a direita)
                    soma += matriz[linha+1][coluna+1];
                    matriz[linha][coluna] = -1;
                    linha++;
                    coluna++;
                    //cout << "\nfff" << endl;
                }
            }
            else if(linha == tam_matriz-1){ //estaria na ultima linha
                //So posso ir pra frente
                soma += matriz[linha][coluna+1];
                matriz[linha][coluna] = -1;
                coluna++;
            }
            else{ // vendo na linha 0
                if(matriz[linha+1][coluna] >= matriz[linha][coluna-1] && matriz[linha+1][coluna] >= matriz[linha][coluna+1] && matriz[linha+1][coluna] >= matriz[linha+1][coluna+1] && matriz[linha+1][coluna] >= matriz[linha+1][coluna-1]){ //estaria indo para baixo
                    soma += matriz[linha+1][coluna];
                    matriz[linha][coluna] = -1;
                    linha++;
                }
                else if(matriz[linha][coluna+1] >= matriz[linha][coluna-1] && matriz[linha][coluna+1] >= matriz[linha+1][coluna] && matriz[linha][coluna+1] >= matriz[linha+1][coluna+1] && matriz[linha][coluna+1] >= matriz[linha+1][coluna-1]){ //estaria indo para a direita
                    soma += matriz[linha][coluna+1];
                    matriz[linha][coluna] = -1;
                    coluna++;
                }
                else if(matriz[linha+1][coluna+1] >= matriz[linha+1][coluna] && matriz[linha+1][coluna+1] >= matriz[linha][coluna+1] && matriz[linha+1][coluna+1] >= matriz[linha][coluna-1] && matriz[linha+1][coluna+1] >= matriz[linha+1][coluna-1]){ //estaria indo para a diagonal inferior(para a direita)
                    soma += matriz[linha+1][coluna+1];
                    matriz[linha][coluna] = -1;
                    linha++;
                    coluna++;
                }
                else if(matriz[linha+1][coluna-1] >= matriz[linha][coluna+1] && matriz[linha+1][coluna-1] >= matriz[linha][coluna-1] && matriz[linha+1][coluna-1] >= matriz[linha+1][coluna] && matriz[linha+1][coluna-1] >= matriz[linha+1][coluna+1]){//estaria indo para a diagonal posterior(para a esquerda)
                    soma += matriz[linha+1][coluna-1];
                    matriz[linha][coluna] = -1;
                    linha++;
                    coluna--;
                }
                else{ //estaria indo para a esquerda
                    soma += matriz[linha][coluna-1];
                    matriz[linha][coluna] = -1;
                    coluna--;
                }

            }
            ImprimirMatriz(matriz, tam_matriz);
        }
        else if(coluna == 0 && linha < tam_matriz-1){ 
            if(matriz[linha][coluna+1] >= matriz[linha+1][coluna] && matriz[linha][coluna+1] >= matriz[linha+1][coluna+1]){ // andei para o lado direito
                soma += matriz[linha][coluna+1];
                matriz[linha][coluna] = -1;
                coluna++;
            }
            else if(matriz[linha+1][coluna] >= matriz[linha][coluna+1] && matriz[linha+1][coluna] >= matriz[linha+1][coluna+1]){ //andei para baixo
                soma += matriz[linha+1][coluna];
                matriz[linha][coluna] = -1;
                linha++;
            }
            else{ //andei na diagonal inferior(para a direita)
                soma += matriz[linha+1][coluna+1];
                matriz[linha][coluna] = -1;
                linha++;
                coluna++;
            }
            ImprimirMatriz(matriz, tam_matriz);
        }
        else if(linha == tam_matriz-1){//estiver na ultima linha
            if(coluna == 0){ //so posso ir para a direita
                soma += matriz[linha][coluna+1];
                matriz[linha][coluna]  = -1;
                coluna++;
            }
            else{
                printf("\nVOCE CHEGOU AO FINAL!!");
                matriz[linha][coluna] = -1;
                linha++;
                coluna++;
            }
            ImprimirMatriz(matriz, tam_matriz);
        }
        else if(coluna == tam_matriz -1){
            if(linha != tam_matriz-1){
                if(linha == 0){
                    if(matriz[linha+1][coluna] >= matriz[linha+1][coluna-1]){ //estaria descendo
                        soma += matriz[linha+1][coluna];
                        matriz[linha][coluna] = -1;
                        linha++;
                    }
                    else{ //estaria indo na diagonal posterior(para a esquereda)
                        soma += matriz[linha+1][coluna-1];
                        matriz[linha][coluna] = -1;
                        linha++;
                        coluna--;
                    }
                }
                else if(linha != 0){
                    if(matriz[linha][coluna-1] >= matriz[linha+1][coluna] && matriz[linha][coluna-1] >= matriz[linha+1][coluna-1]){ //andarei para a esquerda
                        soma += matriz[linha][coluna-1];
                        matriz[linha][coluna] = -1;
                        coluna--;
                    }
                    else if(matriz[linha+1][coluna-1] >= matriz[linha+1][coluna] && matriz[linha+1][coluna-1] >= matriz[linha][coluna-1]){ //estaria indo para a diagonal posterior(para a esquerda)
                        soma += matriz[linha+1][coluna-1];
                        matriz[linha][coluna] = -1;
                        linha++;
                        coluna--;
                    }
                    else{ //andarei para baixo
                        soma += matriz[linha+1][coluna];
                        matriz[linha][coluna] = -1;
                        linha++;
                    }
                }
            }
            ImprimirMatriz(matriz, tam_matriz);
        }
    }
}
