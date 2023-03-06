# Caminho-Guloso

Atividade realizada no 3º perido para a disciplina de Algoritmos e Estrutura de Dados.

<strong>Instruções para a realização da atividade:</strong>

1 - Criar um sistema que leia K matrizes quadradas no tamanho NxN.

2 - Seu programa deve enumerá-las, de forma a deixa-las organizadas para processamento. 

3 - Partindo da primeira matriz, você deve iniciar de um ponto preestabelecido, esse pode ser fornecido pelo usuário ou estar contido em arquivos extras de configuração. Não é permitido definir diretamente no código. 

4 - A partir da primeira matriz, você tem como regras: (a) avançar para a próxima coluna; (b) retroceder para coluna anterior; (c)  saltar para a linha de baixo; (d) ir em diagonal para baixo. Todas essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já processada. 

5 - Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra para adotar sempre uma mesma decisão de caminhamento. 

6 - Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado. 

<strong>Como foi realizado:</strong>

