# Caminho-Guloso
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> </br>
Atividade realizada no 3º periodo para a disciplina de Algoritmos e Estrutura de Dados.

<strong>Instruções para a realização da atividade:</strong>

1 - Criar um sistema que leia K matrizes quadradas no tamanho NxN.<br>
2 - Seu programa deve enumerá-las, de forma a deixa-las organizadas para processamento.<br>
3 - Partindo da primeira matriz, você deve iniciar do ponto preestabelecido[0,0] em cada matriz.<br>
4 - A partir da primeira matriz, você tem como regras: (a) avançar para a próxima coluna; (b) retroceder para coluna anterior; (c)  saltar para a linha de baixo; (d) ir em diagonal para baixo. Todas essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já processada.<br>
5 - Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra para adotar sempre uma mesma decisão de caminhamento.<br>
6 - Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado.<br>

# Explicação do Problema

Um algoritmo de caminho guloso tem como objetivo partir de uma certa posição dada e percorrer ate o final escolhendo a cada iteração o de maior valor presente em seu entorno e logo apos se tornando assim a nova posição atual, esse é um tipo de algoritmo que não olha para as posições passadas e nem olha as consequencias que teram para a execução.

# Resolução do Problema

<strong>Programa feito na linguagem c++.</strong>

<strong>Main.cpp:</strong> É chamada a 2 funções iniciais, a função 'LePrimeiraLinha' que ira retornar a variavel 'tam_matriz' o tamanho da matriz e a função 'ContaQtdMatriz' que sera retornada a quantidade de matrizes presente no arquivo input.data. É feita a alocação dinamica da matriz que sera usada durante todo o codigo utilizando 'tam_matriz' e por fim e feita a chamada da função 'LerArquivo' que nela sera realizado todas as instruçoes para o funcionamemento do codigo. <br>
<strong>Matriz.hpp:</strong> É onde é criada todas as funções que sera utlizadas durante o codigo.<br>
<strong>Matriz.cpp:</strong> Chamada das funções criadas e onde é feito todo o codigo e seu desenvolvimento.<br>
<strong>Terminal:</strong> Aparece ao usuario as matrizes ja percorridas com o valor da soma individual de cada matriz e o valor da soma de todas as matrizes.<br>
<strong>dataset/input.data:</strong> Arquivo contendo o tamanho da matriz e a(s) matriz(s), sendo ela(s) de numeros inteiros somente.
<ul>
  <li>Na primeira linha do arquivo é necessário ter o tamanho da matriz sendo implementado dessa maneira: '5 5' e a existencia de ao mínimo uma matriz de inteiros do tamanho correspondente, para a boa execução do código</li>
</ul>

<strong>Explicação detalhada da função 'LerArquivo':</strong>
<ul>
  <li>Primeiramente é feita a alocação de uma matriz de string pois é ela que ira armazenar as matrizes lidas do arquivo e depois essa matriz é passada para uma matriz de inteiros.</li>
  <li>É aberto o arquivo e dentro do loop while que vou percorrendo linha por linha tenho um if para que pule a primeria linha que é a que possui o tamanho da matriz.</li>
  <li>Enquanto nao chegamos a uma linha vazia no arquivo é feito a passagem da linha lida para a matriz de string.</li>
  <li>Se achado uma linha vazia é porque ja foi percorrida uma matriz inteira e desse modo posso transformar minha matriz de string para a matriz de inteiros, feito isso é chamada a funçao 'PercorrerMatriz' que é nela que ira ser feita a verificação de qual o maior caminho dentro de todas as regras que devem ser cumpridas e logo apos a de 'ImprimirMatriz' que ira mostrar a matriz formada e percorrida.</li>
  <li>Apos tudo isso é zerado todas as variaveis que sao utilizadas, para que possa perorrer a proxima matriz de forma correta sem erros e segmentation fault.</li>
  <li>Quando é lida a ultima matriz como nao ha uma linha vazia ao final, o arquivo é fechado e é chamado logo apos novamente as funçoes de imprimir e percorrer matriz e desse forma todas as matrizes sao lidas e percorridas.</li>
</ul>

<strong>Explicação detalhada da função 'PercorrerMatriz':</strong>
<ul>
   <li>É passado por parametros a matriz que ira ser percorrida, a linha e coluna de onde sera inicializado a matriz e o tamanho da matriz(foi decidido o começo de cada matriz na posição [0,0])</li>
   <li>Assim que chamada a função ja é feita a soma da posição inicial da matriz à variavel 'soma'</li>
   <li>Entramos em um loop while sendo a condição de funcionamento enquanto linha e coluna forem menores que o tamanho da matriz, pois assim nos percorremos toda a matriz</li>
   <li>Sao utlizadas 5 condiçoes para comparação de qual posiçao esta na matriz, sendo elas:</li>
      <ul>
        <li>Se estivermos na linha e coluna [0,0](Verde)(Linha 151)</li>
        <li>Se estivermos na coluna maior que zero e menor que o tamanho da matriz(Azul)(Linha 170)</li>
        <li>Se estivermos na coluna 0 mas linha diferente da ultima(Roxo)(Linha 236)</li>
        <li>Se estivermos na ultima linha(Rosa)(Linha 254)</li>
        <li>Se estivermos na ultima coluna(Amarelo)(Linha 266)</li>
    </ul>
    <p align="center">
      <img src="/imgs/MatrizColorida (2).png">
    </p>
   <li>Em cada uma dessas condiçoes ha as mais condições para a avaliação de qual o maior valor e qual direção deve ser tomada, respeitando os casos de extremidades da matriz e tendo como criterio quando encontrado valores igual a decisão de ir para baixo</li>
   <li>Em cada posição percorrida é trocado o valor para '-1'</li>
   <li>Sempre que tomado uma decisão é somado à variavel 'soma' o valor correspondente a aquela posição especifica</li>
</ul>

# Exemplificação do codigo:
<p align="center">
   <em><ins>Matriz para fins explicativos:</ins></em>
</p>

<p align="center">
  <img src="/imgs/MatrizEx.png">
</p>

<p align="center">
   Possiveis caminhos a serem percorridos:
</p>

<p align="center">
  <img src="/imgs/MatrizEx.1.png">
</p>

<p align="center">
  <img src="/imgs/MatrizEx.2.png">
</p>


<p align="center">
   Esse processo se repete ate chegar ao fim da matriz.<br><br>
</p>


# Resultados Esperados
Em uma matriz [7,7], para fins de teste, essas matrizes foram feitas e executadas e esse é o resultado esperado do codigo.

<p align="center">
   <em><ins>Entrada de dados no arquivo input.data:</ins></em>
</p>

<p align="center">
  <img src="/imgs/DadosEntrada.png">
</p>

<p align="center">
   Terminal do usuario: 
</p>

<p align="center">
  <img src="/imgs/Terminal.png">
</p>

# Compilação e Execução

O codigo disponibilizado foi criado e executado em notebook Acer core i5 Aspire M com sistema operacional Windowns 10 e utlizado um terminal de comando com WSL.

O codigo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

