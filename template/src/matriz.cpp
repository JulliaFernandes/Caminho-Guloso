#include"matriz.hpp"
using namespace std;

int matriz[TAM][TAM], linha = 0, coluna= 0, soma=0;

void GeraMatrizAleatorio(int matriz[TAM][TAM]){
    sleep(1);
    srand(time(nullptr));
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            matriz[i][j] = rand() %100; 
        }
    }
    
}

void ColocandoMatriz(){
    ofstream arquivo;
    int a = 0;
    int quantidadeMatrizes=3;
    srand(time(NULL));
    //quantidadeMatrizes = rand() %5 +1;
    //cout << quantidadeMatrizes <<endl;

    arquivo.open("matriz.txt");
    if(!arquivo){
        cout << "\nFALHA NA ABERTURA DO ARQUIVO" << endl;
    }
    else{
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
}

void LerArquivo(){
    ifstream arquivo;
    string linha_arq, elemento;
    int aux_linha=0, aux_coluna=0;
    string matriz_aux[TAM][TAM];
    
    arquivo.open("matriz.txt", ios::in);

    while(!arquivo.eof()){
        while(getline(arquivo, linha_arq, '\n')){
            if(linha_arq.empty()){
                for(int i=0; i<TAM; i++){
                    for(int j=0; j<TAM; j++){
                        matriz[i][j] = atoi(matriz_aux[i][j].c_str());
                    }
                }
                cout << "\n---Nova Matriz---" << endl;
                ImprimirMatriz();
                PercorrerMatriz();
                memset(matriz_aux, 0, sizeof(matriz_aux));
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
    arquivo.close();  

    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            matriz[i][j] = atoi(matriz_aux[i][j].c_str());
        }
    }
    cout << "\n---Nova Matriz---" << endl;
    ImprimirMatriz();
    PercorrerMatriz();

}

void ImprimirMatriz(){

    cout << endl;
    for (int i = 0; i <TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "VALOR DA SOMA: " << soma << endl;
}

void PercorrerMatriz(){
    soma += matriz[linha][coluna];

    while(linha < TAM && coluna < TAM){
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
            ImprimirMatriz();
        }
        else if(coluna > 0 && coluna < TAM-1){ //olhando quando estou nao estou nas colunas das extremidades
            if(linha < TAM-1 && linha != 0){ //olhando quando nao estou tmb nas linhas das extremidades, estou no meio
                if(matriz[linha+1][coluna] >= matriz[linha][coluna+1] && matriz[linha+1][coluna] >= matriz[linha][coluna-1] &&  matriz[linha+1][coluna] >= matriz[linha+1][coluna+1]){ //estaria descendo
                    soma += matriz[linha+1][coluna];
                    matriz[linha][coluna] = -1;
                    linha++;
                }
                else if(matriz[linha][coluna+1] >= matriz[linha+1][coluna] && matriz[linha][coluna+1] >= matriz[linha][coluna-1] && matriz[linha][coluna+1] >= matriz[linha+1][coluna+1]){//estaria indo a direita
                    soma += matriz[linha][coluna+1];
                    matriz[linha][coluna] = -1;
                    coluna++;
                }
                else if(matriz[linha][coluna-1] >= matriz[linha][coluna+1] && matriz[linha][coluna-1] >= matriz[linha+1][coluna] && matriz[linha][coluna-1] >= matriz[linha+1][coluna+1]){//estaria indo a esquerda
                    soma += matriz[linha][coluna-1];
                    matriz[linha][coluna] = -1;
                    coluna--;
                }
                else{ //estaria indo na diagonal
                    soma += matriz[linha+1][coluna+1];
                    matriz[linha][coluna] = -1;
                    linha++;
                    coluna++;
                    //cout << "\nfff" << endl;
                }
            }
            else if(linha == TAM-1){ //estaria na ultima linha
                //So posso ir pra frente
                soma += matriz[linha][coluna+1];
                matriz[linha][coluna] = -1;
                coluna++;
            }
            else{ // vendo na linha 0
                if(matriz[linha+1][coluna] >= matriz[linha][coluna-1] && matriz[linha+1][coluna] >= matriz[linha][coluna+1] && matriz[linha+1][coluna] >= matriz[linha+1][coluna+1]){ //estaria indo para baixo
                    soma += matriz[linha+1][coluna];
                    matriz[linha][coluna] = -1;
                    linha++;
                }
                else if(matriz[linha][coluna+1] >= matriz[linha][coluna-1] && matriz[linha][coluna+1] >= matriz[linha+1][coluna] && matriz[linha][coluna+1] >= matriz[linha+1][coluna+1]){ //estaria indo para a direita
                    soma += matriz[linha][coluna+1];
                    matriz[linha][coluna] = -1;
                    coluna++;
                }
                else if(matriz[linha+1][coluna+1] >= matriz[linha+1][coluna] && matriz[linha+1][coluna+1] >= matriz[linha][coluna+1] && matriz[linha+1][coluna+1] >= matriz[linha][coluna-1]){ //estaria indo para a diagonal
                    soma += matriz[linha+1][coluna+1];
                    matriz[linha][coluna] = -1;
                    linha++;
                    coluna++;
                }
                else{ //estaria indo para a esquerda
                    soma += matriz[linha][coluna-1];
                    matriz[linha][coluna] = -1;
                    coluna--;
                }

            }
            ImprimirMatriz();
        }
        else if(coluna == 0 && linha < TAM-1){ 
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
            else{ //andei na diagonal
                soma += matriz[linha+1][coluna+1];
                matriz[linha][coluna] = -1;
                linha++;
                coluna++;
            }
            ImprimirMatriz();
        }
        else if(linha == TAM-1){//estiver na ultima linha
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
            ImprimirMatriz();
        }
        else if(coluna == TAM -1){
            if(linha != TAM-1){
                if(linha == 0){//so posso descer
                    soma += matriz[linha+1][coluna];
                    matriz[linha][coluna] = -1;
                    linha++;
                }
                else if(linha != 0){
                    if(matriz[linha][coluna-1] >= matriz[linha+1][coluna]){ //andarei para a esquerda
                        soma += matriz[linha][coluna-1];
                        matriz[linha][coluna] = -1;
                        coluna--;
                    }
                    else{ //andarei para baixo
                        soma += matriz[linha+1][coluna];
                        matriz[linha][coluna] = -1;
                        linha++;
                    }
                }
            }
            ImprimirMatriz();
        }
    }
}
