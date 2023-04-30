#include <stdio.h>
#include <stdlib.h>
#include <string>

typedef struct List
{
    int maxSize;
    int listSize;
    int curr;
    string *listArray;
} List;

List *create_list(int size)
{
    List *l = (List *)malloc(sizeof(List));
    l->maxSize = size;
    l->listSize = 0;
    l->curr = 0;
    l->listArray = (string *)malloc(size * sizeof(string));
    return l;
}
void insert(List *l, string it)
{
    if (l->listSize >= l->maxSize)
    {
        printf("Erro ao tenta inserir!\n");
    }
    else
    {
        int i = l->listSize;
        do
        {
            l->listArray[i] = l->listArray[i - 1];
            i--;
        } while (i > l->curr);
        l->listArray[l->curr] = it;
        l->listSize++;
        printf("Insercao Bem Sucedida!\n");
    }
}
void moveToStart(List *l)
{
    l->curr = 0;
}
void moveToEnd(List *l)
{
    l->curr = l->listSize;
}
void prev(List *l)
{
    if (l->curr != 0)
    {
        l->curr--;
        printf("Sucesso ao retornar para posicao %d\n", l->curr);
    }
    else
    {
        printf("Impossivel retorna para posicao %d\n", l->curr - 1);
    }
}
void next(List *l)
{
    if (l->curr < l->listSize)
    {
        l->curr++;
        printf("Sucesso ao avancar para posicao %d\n", l->curr);
    }
    else
    {
        printf("Impossivel avancar para posicao %d\n", l->curr + 1);
    }
}
void delete (List *l)
{
    if (l->curr < 0 || l->curr >= l->listSize)
    {
        printf("Erro ao tentar remover!\n");
    }
    else
    {
        int i = l->curr;
        do
        {
            l->listArray[i] = l->listArray[i + 1];
            i++;
        } while (i < l->listSize - 1);
        l->listSize--;
        printf("Remocao Bem Sucedida!\n");
    }
}

int count(List *l, int it)
{
    int total = 0;
    for (int i = 0; i < l->listSize; i++)
    {
        if (l->listArray[i] == it)
        {
            total++;
        }
    }
    return total;
}

void showInfoArray(List *l)
{
    printf("Tamanho Maximo: %d \n Tamanho Atual: %d \n Localizacao do Ponteiro: %d \n Array : ", l->maxSize, l->listSize, l->curr);
    for (int i = 0; i < l->listSize; i++)
    {
        printf("%d - ", l->listArray[i]);
    }
    printf("\n");
}

int main()
{
    int cases;

    printf("Numero de Casos: ");
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++)
    {
        int numOpe;

        printf("Numero de Operacoes: (%d) ", i + 1);
        scanf("%d", &numOpe);

        List *l = create_list(numOpe);

        for (int j = 0; j < numOpe; j++)
        {
            char ope[7];
            int value;

            printf("Operacao e valor: (%d) ", j + 1);
            scanf("%s", ope);

            // strcmp("insert", ope[0])
            if ('i' == ope[0])
            {
                scanf("%d", &value);
                insert(l, value);
                showInfoArray(l);
            }
            else if ('r' == ope[0])
            {
                delete (l);
                showInfoArray(l);
            }
            else if ('c' == ope[0])
            {
                scanf("%d", &value);
                int aux = count(l, value);
                printf("%d \n", aux);
            }
            else if ('p' == ope[0])
            {
                prev(l);
            }
            else if ('n' == ope[0])
            {
                next(l);
            }
        }
        showInfoArray(l);
        free(l);
    }
    return 0;
}