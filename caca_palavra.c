#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAM 200

bool ProcuraMatriz(char *MatrizFormada, int linha, int coluna, char *palavra, int L, int C){
    int dir;
    int a[] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int b[] = { -1,  0,  1, -1, 1, -1, 0, 1 };
    
    if (*(MatrizFormada+linha*C+coluna) != palavra[0]){
        
        return false;
    }
    
    int len = strlen(palavra);
    for (dir= 0; dir < 8; dir++) {
        // seguindo em uma mesma direção
        int c, rd = linha + a[dir], cd = coluna + b[dir];
    
        // primeira letra ja foi verificada, irá olhar as restantes
        for (c = 1; c < len; c++) {
            // se estiver fora do limite da matriz
            
            if (rd >= L||rd<0||cd>=C||cd<0){

                break;
            }
                    
            // se n for a letra certa
            if (*(MatrizFormada+rd*C+cd) != palavra[c]){
                break;
            }
            // se movendo nas 8 direçoes
            rd += a[dir], cd += b[dir];
        }
    
        // se todas as letras forem iguais então c devera ser igual ao comprimento da palavra
        if (c == len){
            return true;
        }
           
    }
    return false;
}
void ProcuraPalavra(char *MatrizFormada, char *palavra, int L, int C){   
    int linha, coluna;
    // Considerando cada ponto como ponto de partida, pesquisa a palavra dada 
    
    for (linha = 0; linha < L; linha++)
        for (coluna = 0; coluna < C; coluna++)
            if (ProcuraMatriz(MatrizFormada, linha, coluna, palavra, L, C))
                printf("palavra %s, encontrada  em {%i, %i} \n",palavra,linha,coluna);
                     
}

int main(void){

    int i,m,n,j,cont;
    char **matriz;
    
    //entrada da dimensão da matriz de onde irá surgir o caça palavras
    scanf("%d %d",&m,&n);

    char* matrix = (char*)malloc((m*n)*sizeof(char));
    for(i=0;i<(m*n);i++){
        char aux;
        scanf("%c",&aux);
        if(aux!='\n'){
            matrix[i]=aux;
        }
            
        else{
            i--;
        }
    }

    //entrada de palavras m vezes
    fflush(stdin); 
    char *palavra =(char *)malloc(TAM*sizeof(char)); ;
    fflush(stdin);

    for(i=0;i<m;i++){
        fflush(stdin);
        scanf("%s", palavra);
        ProcuraPalavra(matrix, palavra, m, n);
        printf("\n"); 
 
    }
    
   return 0;
}
