#include <stdio.h>
#include <string.h>

typedef struct{char nome[30];} string;

void OrdLista(string *alunos, int tamanho){
    int i = 1, j;
    string pivo;
    while (i < tamanho){
        j = i - 1;
        pivo = alunos[i];
        while (j >= 0 && strcmp(alunos[j].nome, pivo.nome) > 0)
        {
            alunos[j + 1] = alunos[j];
            j--;
        }
        alunos[j + 1] = pivo;
        i++;
    }
}

int main (){
    int i;
    int qtsAlunos, alunoPremiado;
    scanf("%d %d", &qtsAlunos, &alunoPremiado);
    string alunos[qtsAlunos];
    for (i = 0; i < qtsAlunos; i++)
        scanf("%s", alunos[i].nome);
    OrdLista(alunos, qtsAlunos);    
    printf("%s\n", alunos[alunoPremiado - 1].nome);
    return 0;
}