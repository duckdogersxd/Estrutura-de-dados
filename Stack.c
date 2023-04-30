#include <stdio.h>
#include <stdlib.h>

typedef struct Link
{
    int element;
    struct Link *next;
} Link;
typedef struct Stack
{
    Link *top;
    int size;
}Stack;

Link *create_link(int it,Link* nextval)
{   
    Link *n = (Link *)malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Stack *create_stack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack *s, int it){
    s->top = create_link(it,s->top);
    s->size++;
}

void pop(Stack *s){
    if(s->top==NULL){
        printf("Erro!");
    }
    s->top=s->top->next;
    s->size--;
}

void showInfoArray(Stack *s)
{
    /*printf("Tamanho Maximo: %d \n Tamanho Atual: %d \n Localizacao do Ponteiro: %d \n Array : ", l->maxSize, l->listSize, l->curr);
    for (int i = 0; i < l->listSize; i++)
    {
        printf("%d - ", l->listArray[i]);
    }*/
    Link *curr2 = s->top;
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

        Stack *s = create_stack();

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
                push(s, value);
                showInfoArray(s);
            }
            else if ('r' == ope[0])
            {
                pop (s);
                showInfoArray(s);
            }
            /*else if ('c' == ope[0])
            {
                scanf("%d", &value);
                int aux = count(l, value);
                printf("%d \n", aux);
            }*/
        }
        showInfoArray(s);
        free(s);
    }
    return 0;
}