#include <stdio.h>
#include <stdlib.h>

int **aloca(int M, int N){
    int **matriz, i;
    matriz = (int**)calloc(M,sizeof(int*));
    for (i=0; i<M; i++){
        matriz[i] = (int*)calloc(N,sizeof(int));
    } return matriz;
}

void preecheM(int **matriz, int M, int N, int rat1, int rat2, int qj1, int qj2, int x){
    int i, j;
    for (i=0; i<M; i++){
            for (j=0; j<N; j++){
                    if (rand()%10<x){
                    matriz[i][j] = -1;
                }}}
    matriz[rat1][rat2]=-2;
    matriz[qj1][qj2]=1;
}

int marcaMatriz(int **matriz, int M, int N, int k){
    int i, j, x=1, Lim = (M*N)*2;

    for (i=0; i<M; i++){
        for (j=0; j<N; j++){
            if ((matriz[i][j]==-2 && ((i+x)<M && matriz[i+x][j]==k)) || (matriz[i][j]==-2 && (0<=(i-x) && matriz[i-x][j]==k)) ||
                (matriz[i][j]==-2 && ((j+x)<N && matriz[i][j+x]==k)) || (matriz[i][j]==-2 && (0<=(j-x) && matriz[i][j-x]==k)) ||
                (k==Lim)){
                    if (k==Lim){
                        return k;
                    } else return 1;}
           else if (matriz[i][j]==k){
                if ((i+x)<M && matriz[i+x][j]==0){//Linha de baixo
                    matriz[i+x][j] = k+1;}
                if ((j+x)<N && matriz[i][j+x]==0){//Coluna direta
                    matriz[i][j+x] = k+1;}
                if (0<=(i-x) && matriz[i-x][j]==0){//Linha de Cima
                    matriz[i-x][j] = k+1;}
                if (0<=(j-x) && matriz[i][j-x]==0){//Coluna esquerda
                    matriz[i][j-x] = k+1;}
    }}}
       return marcaMatriz(matriz, M, N, k=k+1);
       return **matriz;}

int Numero(int **matriz, int M, int N){
    int i, j, num=0, x=1;
    for (i=0; i<M; i++){
        for (j=0; j<N; j++){
     if (matriz[i][j] == -2){
         if(((i+x)<M) && (matriz[i+x][j]!= -1)){
            num = matriz[i+x][j];
            if (num!=0){break;}
         }
         if((0<=(i-x)) && (matriz[i-x][j]!= -1)){
            num = matriz[i-x][j];
            if (num!=0){break;}
         }
         if(((j+x)<N) && (matriz[i][j+x]!= -1)){
            num = matriz[i][j+x];
            if (num!=0){break;}
         }
         if((0<=(j-x))&& (matriz[i][j-x]!= -1)){
            num = matriz[i][j-x];
            if (num!=0){break;}
         }
}}}
    return num;
}

int MenorCaminho(int **matriz, int **mtrz, int M, int N, int rat1, int rat2, int qj1, int qj2){
    int i=rat1, j=rat2, aux=M*N, auxI, auxJ, jose=0;
    while(i!=qj1 || j!=qj2){
       if (((i+1)<M) && (matriz[i+1][j]>0)){
            if (aux>matriz[i+1][j]){
                aux = matriz[i+1][j];
                auxI = i+1;
                auxJ= j;
            }
       }
       if ((0<=(i-1)) && (matriz[i-1][j]>0)){
            if (aux>matriz[i-1][j]){
                aux=matriz[i-1][j];
                auxI = i-1;
                auxJ= j;
            }
       }
       if (((j+1)<N) && (matriz[i][j+1]>0)){
            if (aux>matriz[i][j+1]){
                aux=matriz[i][j+1];
                auxI = i;
                auxJ= j+1;
            }
        }
       if (((j-1)>=0) && (matriz[i][j-1]>0)){
            if (aux>matriz[i][j-1]){
                aux=matriz[i][j-1];
                auxI = i;
                auxJ= j-1;
            }
        }
       if (matriz[auxI][auxJ]!=1){
            matriz[auxI][auxJ]= -3;
        }
       i = auxI;
       j = auxJ;
       aux = M*N;
       mtrz[jose][0] = i;
       mtrz[jose][1] = j;
       jose++;
    }

   return **mtrz;
}

void Imprime(int **matriz, int M, int N){
    int i, j;
    printf("\n");
  for (i=0; i<M; i++){
        for (j=0; j<N; j++){
            if(matriz[i][j]==-2){
                printf(" R\t");
            } else {
                if (matriz[i][j]==1){
                    printf(" Q\t");
                } else {
                if (matriz[i][j]==-1){
                    printf("%d\t", matriz[i][j]);
                } else {
                    printf(" %d\t", matriz[i][j]);
                    }
                }
            }
        }printf("\n");
    }printf("\n");
  }

void ImprimeFinal(int **matriz, int M, int N){
    int i, j;
    printf("\n");
  for (i=0; i<M; i++){
        for (j=0; j<N; j++){
                if (matriz[i][j]==-3){
                    printf(" *\t");
                } else { if (matriz[i][j]==1){
                    printf(" Q\t");

                }else {
                    if(matriz[i][j] >=0){
                        printf(" 0\t");
                    } else{
                        if(matriz[i][j]== -2){
                            printf(" R\t");
                        } else {
                            printf("%d\t", matriz[i][j]);
                        }
                    }
                }
            }
        } printf("\n");
    }printf("\n");
  }

void ImprimePosicoes(int **mtrz, int L, int C){
    for (int i=0; i<L; i++){
            printf("[%d][%d] ", mtrz[i][0]+1, mtrz[i][1]+1);
    }
}
int main(){
    int repeticao=1;

    while (repeticao != 0){
    int **labirinto, **posicoes, m, n, rat1, rat2, qj1, qj2, K, maxm, porcent;
    printf("Digite a ordem da matriz M x N: \n");
    scanf("%d %d", &m, &n);

    labirinto = aloca(m, n);

    printf("Digite a posicao do RATO em ordem Linha por Coluna, com a matriz comecando em 1 x 1: \n");
    scanf("%d %d", &rat1, &rat2);
    printf("Digite a posicao do QUEIJO da mesma forma: \n");
    scanf("%d %d", &qj1, &qj2);
    printf("Agora digite a porcentagem de muros gerados em sua matriz de 1 a 10, sendo 1=10%% e 10=100%% (recomendavel 2=20%%)\n");
    scanf("%d", &porcent);
    rat1=rat1-1; rat2=rat2-1;
    qj1=qj1-1; qj2=qj2-1;

    preecheM(*&labirinto, m, n, rat1, rat2, qj1, qj2, porcent);
    Imprime(labirinto, m, n);

    system("pause");

    K=marcaMatriz(labirinto, m , n, 1);

    if (K>1){
        printf("\nO rato nao consegue chegar ate o queijo :(.\n");
    } else {
    Imprime(labirinto, m, n);

    system("pause");

    maxm = Numero(labirinto, m, n);
    posicoes = aloca(maxm, 2);

    printf("\nO numero indicado por -1 sao os muros do labirinto\n");
    printf("\nRato na posicao [%d][%d]\nE Queijo na posicao[%d][%d]\n", rat1+1, rat2+1, qj1+1, qj2+1);
    printf("\nO menor caminho para o rato segue as casas em sequencia:\n");

    MenorCaminho(labirinto, posicoes, m, n, rat1, rat2, qj1, qj2);

    ImprimePosicoes(posicoes, maxm, 2);
    printf("\n");
    printf("\nO caractere '*' representa o caminho a ser percorrido pelo rato \n ate a posicao do queijo indicado por Q\n");

    ImprimeFinal(labirinto, m, n);

    printf("\nSao percorridas %d casas ate o queijo\n", maxm);
    }

    free(labirinto);
    free(posicoes);

    system("pause");

    printf("\n\n. . .Para reiniciar basta digitar 1, caso contrario digite 0. . .\n");
    scanf("%d", &repeticao);
    system("cls"); //limpa o console

    }
    return 0;
}
