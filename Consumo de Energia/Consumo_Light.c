
#include <stdio.h>
#include <stdlib.h>
#define size 20

struct eletros {
    int codigo;
    char eletrodomestico[30];
    int quantidade;
    int potencia;
    int tempoDia;
    int diasMes;
    double consumo;
};

struct eletros eletro[size];

void main(){
    menu();
}

void menu(void)
{
    int opcao;

    printf("1° Inserir elemento inteiro.\n");
    printf("2° Gerar simulado.\n");
    printf("3° Listar eletrodomesticos");
    printf("0º Finalizar.\n");
    printf("\nEscolha: ");
    scanf("%d",&opcao);

    do{
        switch (opcao){
            case 1:
                system("cls");
                inserir();
                break;
            case 2:
                system("cls");
                geraCalculo();
                break;
            case 3:
                system("cls");
                listar();
                break;
            default:
            printf("\n\nOpcão invalida!!!");
        }
    }while(opcao != 0);
    printf("\nFIM!!!!!");

}

void inserir(void){

    int codigo_auxiliar;
    int quantidade_auxiliar;
    int potencia_auxiliar;
    int tempoDia_auxiliar;
    int diasMes_auxiliar;
    float consumoDoObjeto;

    int i=0;
    for(i=1; i<=size; ++i){
        eletro[i].codigo = i; // pego a primeira posição e coloco os dados nela, seguindo a estrutura que criei acima.
        codigo_auxiliar = eletro[i].codigo; // codigo de referencia para aquele eletrodomestico

        printf("Informe o nome eletrodomestico ");
        scanf("%s",&eletro[i].eletrodomestico);

        printf("Informe sua quantidade ");
        scanf("%d",&eletro[i].quantidade);
        quantidade_auxiliar = eletro[i].quantidade; // jogo pra uma variavel auxiliar pra fazer calculo de potencia desse eletro

        printf("Informe a potencia ");
        scanf("%d",&eletro[i].potencia);
        potencia_auxiliar = eletro[i].potencia;

        printf("Informe seu tempo diário ");
        scanf("%d",&eletro[i].tempoDia);
        tempoDia_auxiliar = eletro[i].tempoDia;

        printf("Informe os dias no mes ");
        scanf("%d",&eletro[i].diasMes);
        diasMes_auxiliar = eletro[i].diasMes;

        eletro[i].consumo = calculaConsumo(codigo_auxiliar, potencia_auxiliar, quantidade_auxiliar, tempoDia_auxiliar, diasMes_auxiliar); // metodo para fazer o calculo
        geraCalculo(codigo, eletro[i].consumo); // passa o consumo do objeto para o metodo ir somando com os outros a serem colocados
        printf("\n");
    }
}

double calculaConsumo(int codigo, int potencia, int quantidade, int tempoDia, int diasMes){ // aqui é feito o calculo de consumo para cada eletro e vc retorna esse valor em double(ou float)
    // faz o calculo com o que esta recebendo
    // armazena na estrutura em consumo
}


void geraCalculo(int codigo, double consumoDoObjeto){
    // pera o somatorio de todo o consumo de cada codigo
}



void listar(void){

    int i;
    printf("Eletrodomesticos cadastrados:\n");

    for(i=1; i<=size; ++i){
        if(pessoa[i].codigo != 0){ // avalia pelo codigo se possui um eletrodomestico na estrutura

            printf("Nome eletrodomestico: %s\n", eletro[i].eletrodomestico);
            printf("Quantidade: %d\n",&eletro[i].quantidade);
            printf("Potencia: %d\n",&eletro[i].potencia);
            printf("Tempo diário: %d\n",&eletro[i].tempoDia);
            printf("Dias no mes: %d\n", eletro[i].diasMes);
            printf("\n");
            printf("----------------------\n");
        }
    }
}

