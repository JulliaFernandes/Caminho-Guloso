# Caminho-Guloso

Atividade realizada no 3º periodo para a disciplina de Algoritmos e Estrutura de Dados.

<strong>Instruções para a realização da atividade:</strong>

1 - Criar um sistema que leia K matrizes quadradas no tamanho NxN.<br>
2 - Seu programa deve enumerá-las, de forma a deixa-las organizadas para processamento.<br>
3 - Partindo da primeira matriz, você deve iniciar do ponto preestabelecido[0,0] em cada matriz.<br>
4 - A partir da primeira matriz, você tem como regras: (a) avançar para a próxima coluna; (b) retroceder para coluna anterior; (c)  saltar para a linha de baixo; (d) ir em diagonal para baixo. Todas essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já processada.<br>
5 - Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra para adotar sempre uma mesma decisão de caminhamento.<br>
6 - Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado.<br>

# Resolução do Problema

<strong>Programa feito na linguagem c++.</strong>

<strong>Main.cpp:</strong> É chamada a 2 funções iniciais, a função 'LePrimeiraLinha' que ira retornar a variavel 'tam_matriz' o tamanho da matriz e a função 'ContaQtdMatriz' que sera retornada a quantidade de matrizes presente no arquivo .txt. É feita a alocação dinamica da matriz que sera usada durante todo o codigo utilizando 'tam_matriz' e por fim e feita a chamada da função 'LerArquivo' que nela sera realizado todas as instruçoes para o funcionamemento do codigo. <br>
<strong>Matriz.hpp:</strong> É onde é criada todas as funções que sera utlizadas durante o codigo.
O desenvolvimento da função 'LerArquivo' de maneira geral é feita de modo que é lido uma matriz por vez e ja é feita a chamada da função que ira realizar a soma e o caminho que sera percorrido, sendo feito isso ate o final do arquivo.<br>
<strong>Matriz.cpp:</strong> Chamada das funções criadas e onde é feito todo o codigo e seu desenvolvimento.<br>
<strong>Terminal:</strong> Aparece ao usuario as matrizes ja percorridas com o valor da soma individual de cada matriz e o valor da soma de todas as matrizes.<br>

<strong>Explicação detalhada da função 'LerArquivo':</strong>
<ul>
  <li>Primeiramente é feita a alocação de uma matriz de string pois é ela que ira armazenar as matrizes lidas do arquivo e depois essa matriz é passada para uma matriz de inteiros.</li>
  <li>É aberto o arquivo e dentro do loop while que vou percorrendo linha por linha tenho um if para que pule a primeria linha que é a que possui o tamanho da matriz.</li>
  <li>Enquanto nao chegamos a uma linha vazia no arquivo é feito a passagem da linha lida para a matriz de string.</li>
  <li>Se achado uma linha vazia é porque ja foi percorrida uma matriz inteira e desse modo posso transformar minha matriz de string para a matriz de inteiros, feito isso é chamada a funçao 'PercorrerMatriz' que é nela que ira ser feita a verificação de qual o maior caminho dentro de todas as regras que devem ser cumpridas e logo apos a de 'ImprimirMatriz' que ira mostrar a matriz formada e percorrida.</li>
  <li>Na função 'PercorrerMatriz' o criterio de decisao para valores iguais é ir para baixo</li>
  <li>Apos tudo isso é zerado todas as variaveis que sao utilizadas, para que possa perorrer a proxima matriz de forma correta sem erros e segmentaion fault.</li>
  <li>Quando é lida a ultima matriz como nao ha uma linha vazia ao final, o arquivo é fechado e é chamado logo apos novamente as funçoes de imprimir e percorrer matriz e desse forma todas as matrizes sao lidas e percorridas.</li>
</ul>

<strong>Explicação detalhada da função 'PercorrerMatriz':</strong>
<ul>
   <li>É passado por parametros a matriz que ira ser percorrida, a linha e coluna de onde sera inicializado a matriz e o tamanho da matriz(foi decidido o começo de cada matriz na posição [0,0])</li>
   <li>Assim que chamada a função ja é feita a soma da posição inicial da matriz à variavel 'soma'</li>
   <li>Entramos em um loop while sendo a condição de funcionamento enquanto linha e coluna forem menores que o tamanho da matriz, pois assim nos percorremos toda a matriz</li>
   <li>Sao utlizadas 5 condiçoes para comparação de qual posiçao esta na matriz, sendo elas:</li>
      <ul>
        <li>Se estivermos na linha e coluna [0,0]</li>
        <li>Se estivermos na coluna maior que zero e menor que o tamanho da matriz </li>
        <li>Se estivermos na coluna 0 mas linha diferente da ultima</li>
        <li>Se estivermos na ultima linha</li>
        <li>Se estivermos na ultima coluna</li>
    </ul>
   <li>Em cada uma dessas condiçoes ha as mais condições para a avaliação de qual o maior valor e qual direção deve ser tomada, respeitando os casos de extremidades da matriz e tendo como criterio quando encontrado valores igual a decisão de ir para baixo</li>
   <li>Em cada posição percorrida é trocado o valor para '-1'</li>
   <li>Sempre que tomado uma decisão é somado à variavel 'soma' o valor correspondente a aquela posição especifica</li>
</ul>

# Exemplificação do codigo:
