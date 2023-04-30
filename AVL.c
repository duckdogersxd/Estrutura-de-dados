#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

typedef struct AVLNode
{
    int key;
    int element;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

typedef struct AVL
{
    struct AVLNode *root;
    int nodecount;
} AVL;

AVL *create_avl()
{
    AVL *bst = (AVL *)malloc(sizeof(AVL));
    bst->root = NULL;
    bst->nodecount = 0;
    return bst;
}

AVLNode *create_bstnode(int k, int e)
{
    AVLNode *n = (AVLNode *)malloc(sizeof(AVLNode));
    n->key = k;
    n->element = e;
    n->height = 0;
    n->left = n->right = NULL;
    return n;
}

AVLNode *getmin(AVLNode *rt)
{
    if (rt->left == NULL)
    {
        return rt;
    }
    return getmin(rt->left);
}

AVLNode *deletemin(AVLNode *rt)
{
    if (rt->left == NULL)
    {
        return rt->right;
    }
    rt->left = deletemin(rt->left);
    return rt;
}

int findhelp(AVLNode *rt, int k)
{
    if (rt == NULL)
    {
        return -1;
    }
    if (rt->key > k)
    {
        return findhelp(rt->left, k);
    }
    else if (rt->key == k)
    {
        return rt->element;
    }
    else
    {
        return findhelp(rt->right, k);
    }
}

int find(AVL *bst, int k)
{
    return findhelp(bst->root, k);
}

int h(AVLNode *rt)
{
    if (rt == NULL)
    {
        return -1;
    }
    return rt->height;
}

int getBalance(AVLNode *rt)
{
    if (rt == NULL)
    {
        return 0;
    }
    return h(rt->left) - h(rt->right);
}

AVLNode *rightRotate(AVLNode *rt)
{
    AVLNode *l = rt->left;
    AVLNode *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    l->height = max(h(l->left), h(l->right)) + 1;
    return l;
}

AVLNode *leftRotate(AVLNode *rt)
{
    AVLNode *r = rt->right;
    AVLNode *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = max(h(rt->left), h(rt->right)) + 1;
    r->height = max(h(r->left), h(r->right)) + 1;
    return r;
}

AVLNode *inserthelp(AVLNode *rt, int k, int e)
{
    if (rt == NULL)
    {
        return create_bstnode(k, e);
    }
    if (rt->key > k)
    {
        rt->left = inserthelp(rt->left, k, e);
    }
    else
    {
        rt->right = inserthelp(rt->right, k, e);
    }
    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);
    if (balance < -1 && k >= rt->right->key)
    {
        return leftRotate(rt);
    }
    if (balance > 1 && k < rt->left->key)
    {
        return rightRotate(rt);
    }
    if (balance > 1 && k >= rt->left->key)
    {
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }
    if (balance < -1 && k < rt->right->key)
    {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }
    return rt;
}

void insert(AVL *bst, int k, int e)
{
    bst->root = inserthelp(bst->root, k, e);
    bst->nodecount++;
}

AVLNode *removehelp(AVLNode *rt, int k)
{
    if (rt == NULL)
    {
        return NULL;
    }
    if (rt->key > k)
    {
        rt->left = removehelp(rt->left, k);
    }
    else if (rt->key < k)
    {
        rt->right = removehelp(rt->right, k);
    }
    else
    {
        if (rt->left == NULL)
        {
            return rt->right;
        }
        else if (rt->right == NULL)
        {
            return rt->left;
        }
        else
        {
            AVLNode *temp = getmin(rt->right);
            rt->element = temp->element;
            rt->key = temp->key;
            rt->right = deletemin(rt->right);
        }
    }
    return rt;
}

int remover(AVL *bst, int k)
{
    int temp = findhelp(bst->root, k);
    if (temp != -1)
    {
        bst->root = removehelp(bst->root, k);
        bst->nodecount--;
    }
    return temp;
}

void preorder(AVLNode *rt)
{
    if (rt != NULL)
    {
        printf("%d ", rt->key);
        preorder(rt->left);
        preorder(rt->right);
    }
    // printf("\n");
}

void inorder(AVLNode *rt)
{
    if (rt != NULL)
    {
        inorder(rt->left);
        printf("%d ", rt->key);
        inorder(rt->right);
    }
    // printf("\n");
}

void posorder(AVLNode *rt)
{
    if (rt != NULL)
    {
        posorder(rt->left);
        posorder(rt->right);
        printf("%d ", rt->key);
    }
    // printf("\n");
}

int main()
{

    /*int numOpe;

    printf("Numero de Operacoes: ");
    scanf("%d", &numOpe);

    BST *bst = create_bst();

    for (int j = 0; j < numOpe; j++)
    {
        char *ope;
        int value;

        printf("Operacao e valor: (%d) ", j + 1);
        scanf("%s", ope);

        // strcmp("insert", ope[0])
        if (strcmp("insert", ope) == 0)
        {
            scanf("%d", &value);
            insert(bst, value, 0);
        }
        else if (strcmp("remove", ope) == 0)
        {
            scanf("%d", &value);
            remover(bst, value);
        }
        else if (strcmp("pre", ope) == 0)
        {
            preorder(bst->root);
        }
        else if (strcmp("in", ope) == 0)
        {
            inorder(bst->root);
        }
        else if (strcmp("post", ope) == 0)
        {
            posorder(bst->root);
        }
    }
    free(bst);*/

    AVL *bst = create_avl();
    insert(bst, 4, 0);
    insert(bst, 6, 0);
    insert(bst, 8, 0);
    insert(bst, 3, 0);
    insert(bst, 2, 0);
    insert(bst, 5, 0);
    preorder(bst->root);
    printf("\n");
    inorder(bst->root);
    printf("\n");
    posorder(bst->root);
    printf("\n");
    free(bst);
    
    return 0;
}