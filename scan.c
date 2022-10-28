#include <stdio.h>

int contaLinhaCod = 0;

int tabelaTransicao[5][9];



int mapeamento(char caracter){
    if(((caracter >= 65) && (caracter <= 90)) || ((caracter >= 97) && (caracter <= 122))){
        return (0);
    }
    else if((caracter>=48)&&(caracter<=57)){
        return(1);
    }
    else if((caracter == 42)||(caracter == 43)||(caracter == 45)||(caracter == 47)||(caracter == 59)||(caracter == 60)){
        return(2);
    }
    else if(caracter == 58){
        return(3);
    }
    else if(caracter == 61){
        return(4);
    }
    else if(caracter == 123){
        return(5);
    }
    else if(caracter == 125){
        return(6);
    }
    else if((caracter == 32)||(caracter == 0)||(caracter >= 7)&&(caracter <= 13)){
        if(caracter == 10){
            contaLinhaCod++;
        }
        return(7);
    }
    else {
        return(8);
    }
}

int main(int argc, char ** argv) {
    FILE * fp0;
    FILE * fp1;
    char temp = 0;
    char buffer[50];
    int cont;
    int estadoAtual = 0;
    int retorno = 0;

    tabelaTransicao[0][0] = 1;
    tabelaTransicao[0][1] = 2;
    tabelaTransicao[0][2] = 5;
    tabelaTransicao[0][3] = 3;
    tabelaTransicao[0][4] = 5;
    tabelaTransicao[0][5] = 4;
    tabelaTransicao[0][6] = 6;
    tabelaTransicao[0][7] = 10;
    tabelaTransicao[0][8] = 6;
    tabelaTransicao[1][0] = 1;
    tabelaTransicao[1][1] = 7;
    tabelaTransicao[1][2] = 7;
    tabelaTransicao[1][3] = 7;
    tabelaTransicao[1][4] = 7;
    tabelaTransicao[1][5] = 7;
    tabelaTransicao[1][6] = 7;
    tabelaTransicao[1][7] = 7;
    tabelaTransicao[1][8] = 7;
    tabelaTransicao[2][0] = 8;
    tabelaTransicao[2][1] = 2;
    tabelaTransicao[2][2] = 8;
    tabelaTransicao[2][3] = 8;
    tabelaTransicao[2][4] = 8;
    tabelaTransicao[2][5] = 8;
    tabelaTransicao[2][6] = 8;
    tabelaTransicao[2][7] = 8;
    tabelaTransicao[2][8] = 8;
    tabelaTransicao[3][0] = 6;
    tabelaTransicao[3][1] = 6;
    tabelaTransicao[3][2] = 6;
    tabelaTransicao[3][3] = 6;
    tabelaTransicao[3][4] = 9;
    tabelaTransicao[3][5] = 6;
    tabelaTransicao[3][6] = 6;
    tabelaTransicao[3][7] = 6;
    tabelaTransicao[3][8] = 6;
    tabelaTransicao[4][0] = 4;
    tabelaTransicao[4][1] = 4;
    tabelaTransicao[4][2] = 4;
    tabelaTransicao[4][3] = 4;
    tabelaTransicao[4][4] = 4;
    tabelaTransicao[4][5] = 6;
    tabelaTransicao[4][6] = 0;
    tabelaTransicao[4][7] = 4;
    tabelaTransicao[4][8] = 4;

    fp0 = fopen("programa.txt", "r");
    fp1 = fopen("tokens.txt", "w");
    if ((fp0 == NULL) || (fp1 == NULL))
        printf("deu ruim\n");

    while(temp != EOF){
        temp = fgetc(fp0);
        retorno = mapeamento(temp);
        if(retorno == 7){
            fputc(temp, fp1);
        }
        else{
            fputc(retorno+48, fp1);
        }

    }
    
    printf("%d\n", contaLinhaCod);
    return 0;
}
