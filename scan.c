#include <stdio.h>
#include<stdbool.h>

int contaLinhaCod = 0;


int mapeamento(char caracter){
    if(((caracter >= 65) && (caracter <= 90)) || ((caracter >= 97) && (caracter <= 122))){
        return (0);
    }
    else if((caracter>=48)&&(caracter<=57)){
        return(1);
    }
    else if((caracter == 42)||(caracter == 43)||(caracter == 45)||(caracter == 47)||(caracter == 59)||(caracter == 60)||(caracter == 40)||(caracter == 41)){
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
    else if((caracter == 32)||(caracter == 0)||((caracter >= 7)&&(caracter <= 13))||(caracter < 0)){
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
    char buffer[200];
    int cont = 0;
    int estadoAtual = 0;
    int aux = 0;
    bool consome;
    int tabelaTransicao[5][9];
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
    tabelaTransicao[4][6] = 11;
    tabelaTransicao[4][7] = 4;
    tabelaTransicao[4][8] = 4;

    fp0 = fopen("programa.txt", "r");
    fp1 = fopen("tokens.txt", "w");
    if ((fp0 == NULL) || (fp1 == NULL))
        printf("deu ruim\n");

    while(temp >= 0){
        cont = 0;
        estadoAtual = 0;
        buffer[0] = '\0';
        
        if (!consome)
        {
            buffer[cont] = temp;
            cont++;
            aux = mapeamento(temp);
            estadoAtual = tabelaTransicao[estadoAtual][aux];
            temp = '\0';
        }
        while((estadoAtual < 5)&&(temp != -1)){
            temp = fgetc(fp0);
            if (temp == 10)
            {
                contaLinhaCod++;
            }
            
            printf("%d", temp);
            aux = mapeamento(temp);
            estadoAtual = tabelaTransicao[estadoAtual][aux];
            if (estadoAtual < 5)
            {
                buffer[cont] = temp;
                cont++;
            }
        }

        if (estadoAtual == 5)
        {
            buffer[cont] = temp;
            buffer[cont + 1] = '\0';
            //fprintf(fp1, "<OP, %s>", buffer);
            fprintf(fp1, "<%s, %s>", buffer,buffer);
            consome = true;
        }
        else if (estadoAtual == 6)
        {
            buffer[cont] = temp;
            buffer[cont + 1] = '\0';
            fprintf(fp1, "<Erro, %s>", buffer);
            consome = true;
        }
        else if (estadoAtual == 7){
            buffer[cont] = '\0';
            fprintf(fp1, "<ID, %s>", buffer);
            consome = false;
        }
        else if (estadoAtual == 8){
            buffer[cont] = '\0';
            fprintf(fp1, "<Num, %s>", buffer);
            consome = false;
        }
        else if (estadoAtual == 9){
            buffer[cont] = temp;
            buffer[cont + 1] = '\0';
            fprintf(fp1, "<%s, %s>", buffer,buffer);
            consome = true;
        }
        else if (estadoAtual == 10){
            if (temp >= 0)
            {
                buffer[cont] = temp;
                buffer[cont + 1] = '\0';
                fprintf(fp1, "%s", buffer);   
                consome = true;
            }
        }
        else if (estadoAtual == 11)
        {
            buffer[cont] = temp;
            buffer[cont + 1] = '\0';
            consome = true;
        }
        
        printf("%d\n", estadoAtual);
        printf("%s\n", buffer);
    }
    printf("%d\n", contaLinhaCod);
    return 0;
}
