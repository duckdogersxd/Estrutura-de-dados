#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int element;
    struct Link *next;
} Link;
typedef struct List
{
    Link *head;
    Link *tail;
    Link *curr;
    int cnt;
} List;

Link *create_link(int it,Link* nextval)
{   
    Link *n = (Link *)malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}
List *create_list(){
    List *l = (List *)malloc(sizeof(List));
    l->curr = l->tail = l->head = create_link(0,NULL);
    l->cnt = 0;
    return l;
}
void insert(List *l, int it)
{   
    l->curr->next = create_link(it,l->curr->next);
    if (l->tail == l->curr)
    {
        l->tail = l->curr->next;
    }
    l->cnt++;
}
void moveToStart(List *l)
{
    l->curr = l->head;
}
void prev(List *l)
{
    if (l->curr == l->head)
    {
        printf("Nao e possivel retornar para posicao");
    }
    Link *temp = l->head;
    do{
        temp = temp->next;
    }while(temp->next!=l->curr);
    l->curr=temp;
}
void next(List *l)
{
    if (l->curr != l->tail)
    {
        l->curr=l->curr->next;
    }
}
void delete (List *l)
{
    if (l->curr->next == NULL)
    {
        printf("Erro ao tentar remover!\n");
    }
    int it = l->curr->next->element;
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    l->curr->next=l->curr->next->next;
    l->cnt--;
}

/* int count(List *l, int it)
{
    int total = 0;
    Link *curr2 = l->head;
    while( curr2 != NULL){
        total+=l->curr2->element;
        curr2=curr2->next;
    }
    for (int i = 0; i < l->ctn; i++)
    {
        if (l->listArray[i] == it)
        {
            total++;
        }
    }
    return total;
}
*/

void showInfoArray(List *l)
{
    /*printf("Tamanho Maximo: %d \n Tamanho Atual: %d \n Localizacao do Ponteiro: %d \n Array : ", l->maxSize, l->listSize, l->curr);
    for (int i = 0; i < l->listSize; i++)
    {
        printf("%d - ", l->listArray[i]);
    }*/
    Link *curr2 = l->head->next;
    while(curr2!= NULL){
    printf(" %d -", curr2->element);
    curr2=curr2->next;
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

        List *l = create_list();

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
            /*else if ('c' == ope[0])
            {
                scanf("%d", &value);
                int aux = count(l, value);
                printf("%d \n", aux);
            }*/
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