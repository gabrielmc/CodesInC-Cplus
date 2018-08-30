
#include <stdio.h>
#include <stdlib.h>
#define size 20

void menu();
void cadastrar();
void buscar();
void deletar();

struct alunos {
    int matricula[30];
    char nome[30];
    int curso[30];
};
struct alunos aluno[size];
int sizeAluno = 0;

void main(){
    menu();
}

void menu(){
    int opcao;
    printf("1 - Cadastrar aluno.\n");
    printf("2 - Buscar Aluno. \n");
    printf("3 - Excluir.\n");
    printf("0 - Finalizar.\n");
    printf("\nEscolha: ");
    scanf("%d",&opcao);

    do{
        switch (opcao){
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
            printf("\n\nOpcÃ£o invalida!!!");
        }
    }while(opcao != 0);
    printf("\nFIM!!!!!");

}

void cadastrar(){
    int i=0;
    sizeAluno++;
    if(sizeAluno == size){
        for(i=0; i<sizeAluno; i++){
            printf("Informe o nome do aluno: ");
            scanf("%s",&aluno[i].nome);

            printf("Informe a matricula: ");
            scanf("%d",&aluno[i].matricula);

            printf("Informe o curso: ");
            scanf("%d",&aluno[i].curso);
            printf("\n");
        }
    }
    system("cls");
    menu();
}

void buscar(){
    if(sizeAluno > 0 ){
        char matricula[30];
        printf("Informe o matricula do aluno: ");
        scanf("%s",&matricula);
        for(i=0; i<=sizeAluno; i++){
            if(aluno[i].matricula == matricula){
                printf("NOME DO ALUNO: [ %s]\n", aluno[i].nome);
                printf("MATRICULA: [ %d]\n",     aluno[i].matricula);
                printf("CURSO: [ %d]\n",         aluno[i].curso);
                printf("\n");
                printf("----------------------\n");
            }
        }
    }else{
        printf("Voce nao cadastrou nenhum aluno! \n\n");
    }
    menu();
}

void deletar(){
    if(sizeAluno > 0 ){
        char matricula[30];
        int cont=0;
        printf("Informe a matricula do aluno: ");
        scanf("%s",&matricula);

        for(i=0; i<=sizeAluno; i++){
            if(aluno[i].matricula == matricula){
                aluno[i]
                printf("Aluno deletado com sucesso! \n\n");
                break;
            }
        }
    }else{
        printf("Voce nao cadastrou nenhum aluno! \n\n");
    }
    menu();
}

void deletar(){
    printf("Qual a posição a excluir?");
    int pos;
    scanf("%d", &pos);
    pos-- ;
    if (pos >= 0 && pos < num){
        int i;
        for (i = pos;i < num - 1; ++i){
            p[i] = p[i + 1];
        }
        p = realloc(p, --num * sizeof(cadastro)); //reduzir o tamanho do array em 1 unidade
    }
}





