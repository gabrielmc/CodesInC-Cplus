#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define size 20

#include "dllAluno.h"
/*
void menu();
void cadastrar();
void buscar();
void deletar();
*/
struct alunos {
    int matricula;
    char nome[30];
    char curso[30];
};
struct alunos aluno[5];
int sizeAluno = -1;
int control = 0;
int posicoes[5];

/*
void main(){
	zerarPosicoes();
    menu();
}
*/
void menu(){
    int opcao;

    do{
    	printf("1 - Cadastrar aluno.\n");
	    printf("2 - Buscar Aluno. \n");
	    printf("3 - Excluir.\n");
	    printf("0 - Finalizar.\n");
	    printf("\nEscolha: ");
	    scanf("%d",&opcao);
    	
        switch (opcao){
        	case 0:
        		break;
            case 1:
                system("cls");
                cadastrar();
                break;
            case 2:
                system("cls");
                buscar();
                break;
            case 3:
                system("cls");
                deletar();
                break;
            default:
            	printf("\n\nOpcão invalida!!!\n"); 
        }
    }while(opcao != 0);
    printf("\nFIM!!!!!");

}

//refinar este cógigo para reutizar na função deletar
void zerarPosicoes(){
	int i;
	for(i = 0; i < 5; i++){
		aluno[i].nome[0] = 'v';
		aluno[i].matricula = 0;
		aluno[i].curso[0] = 'v';
	}
	for(i = 0; i < 5; i++){
		posicoes[i] = -1;
	}
	
}

void cadastrar(){
    int i;
    if(control > 0){ //verifica se existe alguma posição vazia antes da posição atual ja preechida
    	for(i=0; i<sizeAluno; i++){
    		if(posicoes[i] != -1){
    			//printf("%d\n", posicoes[i]); mostra a posição onde o aluno será cadastrado na struct
    			printf("Informe o nome do aluno: ");
	            scanf("%s",&aluno[i].nome);
	
	            printf("Informe a matricula: ");
	            scanf("%d",&aluno[i].matricula);
	
	            printf("Informe o curso: ");
	            scanf("%s",&aluno[i].curso);
	            printf("\n");
	            control = 0;//zera o controlador de posições
	         	break;   
			}
		}
	} else {
	    sizeAluno++;
		//printf("%d\n", sizeAluno); mostra a posição onde o aluno será cadastrado na struct
	    for(i=sizeAluno; i<5; i++){//cadastra aluno se todas as posições anteriore estiverem preenchidas
	    	if(aluno[i].matricula == 0){
	    	
	            printf("Informe o nome do aluno: ");
	            scanf("%s",&aluno[sizeAluno].nome);
	
	            printf("Informe a matricula: ");
	            scanf("%d",&aluno[sizeAluno].matricula);
	
	            printf("Informe o curso: ");
	            scanf("%s",&aluno[sizeAluno].curso);
	            printf("\n");
	         	break;   
	    	} else {
	    		printf("Cheio!");	
			}	
	    }
	}
    system("cls");	
    menu();
}

void buscar(){
    int matricula, i;
    printf("Informe o matricula do aluno: ");
    scanf("%d",&matricula);
    for(i=0; i < 5; i++){
        if(aluno[i].matricula == matricula){
            printf("NOME DO ALUNO: [ %s]\n", aluno[i].nome);
            printf("MATRICULA: [ %d]\n",     aluno[i].matricula);
            printf("CURSO: [ %s]\n",         aluno[i].curso);
            printf("\n");
            printf("----------------------\n");
            break;
        } 
    }
    printf("nao existe aluno com esta matricula\n");
    menu();
}

void deletar(){
        int matricula, i;
        printf("Informe a matricula do aluno: ");
        scanf("%d",&matricula);

        for(i=0; i<sizeAluno; i++){
            if(aluno[i].matricula == matricula){
				aluno[i].nome[0] = 'v';
                aluno[i].matricula = 0;
                aluno[i].curso[0] = 'v';
                printf("Aluno deletado com sucesso! \n\n");
                posicoes[i] = i;
                control++;
                break;
            } 
        } 
    menu();
}



