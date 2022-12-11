//exemplo de uma struct. 
#include <stdio.h>
#include <stdlib.h>

// Struct
struct ficha_aluno{ //tipo de dado
        int numero;
        float nota;
        char nome[40]; 
    };//definição da struct

//-----------------------------
int main(){
    
    struct ficha_aluno aluno;

    printf("\n ------------ Cadastro de aluno ---------------\n");

    printf("Nome de aluno.....:\n");
    fgets(aluno.nome,40,stdin);

    printf("Digite o numero do aluno: \n");
    scanf("%d",&aluno.numero);

    printf("Informe a nota do aluno: \n");
    scanf("%f",&aluno.nota);

    printf("\n\n --------- lendo os dados da struct ------------\n\n");
    printf("Nome ...............: %s", aluno.nome);
    printf("Numero .............: %d\n", aluno.numero);
    printf("Nota ...............: %.2f \n",aluno.nota);

    return 0;

}