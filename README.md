# Labirinto do Rato e do Queijo
O programa espera como entrada dados do tipo M x N sendo M as linhas e N as colunas.

Exemplo de entrada (inteiros sendo passados um por vez presionando enter) : 
* Entrada do tamanho da matriz: 10 10
* Entrada da posição do Rato: 1 2 
* Entradada da posição do Queijo: 9 8 

Uma matriz é gerada representado um labirinto, onde 'R' representara a posição do rato e 'Q' a posição do queijo. As casas com '-1' representam os muros (não se pode passar por eles). Uma segunda matriz é criada preenchendo todas as casas a partir do queijo até o rato com números crescentes partindo de 1 (o 'Q' será o 1). Esta segunda matriz é utilizada para encontrar o menor caminho do Rato ao Queijo. 

OBS: Foi um trabalho final realizado na primeira matéria de programação do curso. Não representa a melhor forma de se resolver o problema. Além, o algoritmo de randomização dos muros não é eficiente bem como outras partes do código.
