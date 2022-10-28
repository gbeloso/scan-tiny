#include <stdio.h>

int mapeamento(char caracter){
    if(((caracter >= 65) && (caracter <= 90)) || ((caracter >= 97) && (caracter <= 122))){
        return (48);
    }
    else if((caracter>=48)&&(caracter<=57)){
        return(49);
    }
    else if((caracter == 42)||(caracter == 43)||(caracter == 45)||(caracter == 47)||(caracter == 59)||(caracter == 60)){
        return(50);
    }
    else if(caracter == 58){
        return(51);
    }
    else if(caracter == 61){
        return(52);
    }
    else if(caracter == 123){
        return(53);
    }
    else if(caracter == 125){
        return(54);
    }
    else if(caracter == 32){
        return(55);
    }
    else {
        return(56);
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

  fp0 = fopen("programa.txt", "r");
  fp1 = fopen("tokens.txt", "w");
  if ((fp0 == NULL) || (fp1 == NULL))
    printf("deu ruim\n");

while(temp != EOF){
    temp = fgetc(fp0);
    retorno = mapeamento(temp);
    fputc(retorno, fp1);
}
  
  return 0;
}
