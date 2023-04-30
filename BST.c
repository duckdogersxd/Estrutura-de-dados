#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLNode{
    int key;
    int element;
    struct AVLNode *left;
    struct AVLNode *right;
}AVLNode;

typedef struct AVL{
    struct AVLNode *root;
    int nodecount;
}AVL;

AVL *create_avl(){
    AVL *bst = (AVL *)malloc(sizeof(AVL));
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

AVLNode *create_bstnode(int k,int e){
    AVLNode *n = (AVLNode *)malloc(sizeof(AVLNode));
    n->key = k;
    n->element = e;
    n->left=n->right= NULL;
    return n;
}

AVLNode *getmin(AVLNode *rt){
    if (rt->left == NULL){
        return rt;
    }
    return getmin(rt->left);
}
AVLNode *deletemin(AVLNode *rt){
    if (rt->left == NULL){
        return rt->right;
    }
    rt->left=deletemin(rt->left);
    return rt;
}
int findhelp(AVLNode *rt,int k){
    if (rt==NULL){
        return -1;
    }
    if (rt->key>k){
        return findhelp(rt->left,k);
    }
    else if (rt->key == k){
        return rt->element;
    }
    else {
        return findhelp(rt->right,k);
    }
}

int find(AVL *bst,int k){
    return findhelp(bst->root,k);
}

AVLNode *inserthelp(AVLNode *rt,int k, int e){
    if (rt==NULL){
        return create_bstnode(k,e);
    }
    if (rt->key > k){
        rt->left = inserthelp(rt->left,k,e);
    }
    else{
        rt->right=inserthelp(rt->right,k,e);
    }
    return rt;
}

void insert(AVL *bst,int k, int e)
{   
    bst->root = inserthelp(bst->root,k,e);
    bst->nodecount++;
}
AVLNode *removehelp(AVLNode *rt,int k){
    if (rt==NULL){
        return NULL;
    }
    if (rt->key>k){
        rt->left=removehelp(rt->left,k);
    }
    else if(rt->key<k){
        rt->right=removehelp(rt->right,k);
    }
    else{
        if (rt->left==NULL){
            return rt->right;
        }
        else if(rt->right==NULL){
            return rt->left;
        }
        else{
            AVLNode *temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right=deletemin(rt->right);
        }
    }
    return rt;
}

int remover(AVL *bst,int k)
{
    int temp = findhelp(bst->root,k);
    if (temp!=-1){
        bst->root=removehelp(bst->root,k);
        bst->nodecount--;
    }
    return temp;
}





void preorder(AVLNode *rt){
    if (rt != NULL){
        printf("%d ",rt->key);
        preorder(rt->left);
        preorder(rt->right);
    }
        //printf("\n");
}
void inorder(AVLNode *rt){
    if (rt!=NULL){
        inorder(rt->left);
        printf("%d ",rt->key);    
        inorder(rt->right);
    }
    //printf("\n");
}

void posorder(AVLNode *rt){
    if (rt!= NULL){
        posorder(rt->left);
        posorder(rt->right);
        printf("%d ",rt->key);
    }
        //printf("\n");
}

int main()
{
    
        int numOpe;

        printf("Numero de Operacoes: ");
        scanf("%d", &numOpe);

        AVL *bst = create_avl();

        for (int j = 0; j < numOpe; j++)
        {
            char *ope;
            int value;

            printf("Operacao e valor: (%d) ", j + 1);
            scanf("%s", ope);

            // strcmp("insert", ope[0])
            if (strcmp("insert", ope)==0)
            {
                scanf("%d", &value);
                insert(bst,value,0);
            }
            else if (strcmp("remove", ope)==0)
            {
                scanf("%d", &value);
                remover(bst,value);
            }
            else if (strcmp("pre", ope)==0)
            {
                preorder(bst->root);
            }
            else if (strcmp("in", ope)==0)
            {
                inorder(bst->root);
            }
            else if (strcmp("post", ope)==0)
            {
                posorder(bst->root);
            }
        }
        free(bst);
    
    return 0;
}