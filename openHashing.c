#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[MAX_NAME];
    int age;
} person;

typedef struct Dictionary
{
    int m;
    int cnt;
    person *H[m];
    int key;
}Dictionary;

Dictionary create_dict(int size,int key){
    Dictionary *d = (Dictionary *)malloc(sizeof(Dictionary));
    d->cnt = 0;
    d->H = person *H[size];
    for (int i = 0; i < size; i++)
    {
        d->H[i] = c
    }
    

}

int h(char* K){
    int m = 1000;
    int intLenght = sizeof(K)/(sizeof(char)*4);
    int sum = 0;
    char *sub;
    int mult;
    for (int i = 0; i < intLenght; i++)
    {
        sub = strncpy(K,i*4,(i*4)+4);
        mult = 1;
        for (int j = 0; j < 4; j++)
        {
            sum += sub[j]*mult;
            mult *= 256;
        }
    }
    sub = strncpy(K,intLenght*4);
    mult = 1;
    int s = sizeof(sub)/sizeof(char);
    for (int j = 0; j < s; j++)
    {
        sum += sub[j]*mult;
        mult = mult*256;
    }
    return abs(sum)%m;
}

int main(){
    char *nome[1000];

    int index = h("Igor");
    nome[h("Igor")]="Igor";

    print("%s",nome[index]);

    return 0;
}