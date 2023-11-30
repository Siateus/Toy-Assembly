# Interpretador Toy Assembly

## Introdução

Este Programa visa a construção de um interpretador para uma linguagem de programação assembly simples, denominada "Toy Assembly". Essa linguagem de programação é de baixo nível, operando em um nível de abstração próximo à arquitetura da máquina, e permite a execução de programas escritos em instruções específicas.

## Especificação

O interpretador "Toy Assembly" suporta as seguintes instruções:

1. `MOV RX INTEIRO`: Atribui o valor inteiro INTEIRO ao registrador RX.
2. `MOV RX RY`: Atribui o valor do registrador RY ao registrador RX.
3. `ADD RX RY RZ`: Soma os valores de RY e RZ e armazena o resultado em RX.
4. `SUB RX RY RZ`: Subtrai RZ de RY e armazena o resultado em RX.
5. `MUL RX RY RZ`: Multiplica RY por RZ e armazena o resultado em RX.
6. `DIV RX RY RZ`: Divide RY por RZ e armazena o resultado em RX (divisão inteira).
7. `MOD RX RY RZ`: Calcula o módulo de RY por RZ e armazena o resultado em RX.
8. `BEQ RX RY ENDERECO`: Direciona o fluxo do programa para a instrução na linha de número ENDERECO se RX for igual a RY.
9. `BLT RX RY ENDERECO`: Direciona o fluxo do programa para a instrução na linha de número ENDERECO se RX for menor que RY.
10. `JMP ENDERECO`: Direciona o fluxo do programa para a instrução na linha de número ENDERECO.
11. `LOAD RX RY`: Carrega o conteúdo da memória[RY] para o registrador RX.
12. `STORE RX RY`: Armazena o conteúdo de RX na memória[RY].
13. `PRINT RX`: Imprime o valor de RX na tela.
14. `EXIT`: Encerra o programa.

---
## Entrada

A entrada é lida a partir do teclado (stdin). A primeira linha da entrada contém um inteiro N (1 ≤ N ≤ 100), indicando o número de linhas do programa. As próximas N linhas contêm as instruções do programa. 

## Instruções de Compilação e Execução

Para compilar e executar o interpretador Toy Assembly, siga as etapas a seguir:

- Certifique-se de ter o GCC (GNU Compiler Collection) instalado em seu sistema. Você pode verificar isso executando `gcc --version` no terminal.


- Abra um terminal e navegue até o diretório onde estão os arquivos de código-fonte e o Makefile.

- Compile o programa usando o Makefile executando o seguinte comando: `make`


Isso vai compilar os arquivos fonte e gerar o executável conforme definido no Makefile.

- Após a compilação ser concluída com sucesso, você terá um executável chamado `./main` 



- O programa interpretador executará as instruções especificadas no arquivo de entrada e dará saída de acordo com as instruções Toy Assembly, como impressões e resultados de operações.

- Quando o programa terminar de executar ou encontrar a instrução `EXIT`, ele encerrará a execução.

- Se necessário, você pode executar o comando `make clean` para remover os arquivos gerados durante a compilação.


---
**Autor:** **Matheus Silva Pinheiro**
