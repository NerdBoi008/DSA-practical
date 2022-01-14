#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
}*root = NULL;

void insert();
void inOrder(struct node *trav);
void postOrder(struct node *trav);
void preOrder(struct node *trav);

int main(void)
{
    int choice, value;
    while(1)
    {
        printf("--- BST Operatoins --- \n1) Insert. \n2) Traversal. \n3) Exit. \nEnter choice: ");
        scanf("%d",&choice);
        if(choice == 1) { 
            printf("Enter value to insert: ");
            scanf("%d",&value);
            insert(value); 
        }
        else if(choice == 2)
        {
            printf("\n--- BST Traversals --- \n1) InOrder. \n2) PostOrder. \n3) PreOrder \n4) Exit. \nEnter choice:  ");
            scanf("%d",&choice);
            if(choice == 1) { inOrder(root); printf("\n");}
            else if(choice == 2) { postOrder(root); printf("\n");}
            else if(choice == 3) { preOrder(root); printf("\n");}
            else { break; }            
        }
        else { break; }
    }
    return 0;
}

void insert(int value){
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if(!tmp)
    {
        printf("Memory Error!");
    }
    tmp->data = value;
    tmp->left = tmp->right = NULL;

    if(root == NULL)
    {
        root = tmp;
        printf("\nelement inserted \n");
    }
    else
    {
        struct node *trav = root;
        while(1)
        {
            if(value == trav->data)
            {
                printf("\nSame value can't be inserted.\n ");
                break;
            }
            else
            {
                if(value < trav->data)
                {
                    if(trav->left != NULL)
                    {
                        trav = trav->left;
                    }
                    else
                    {
                        trav->left = tmp;
                        break;
                    }
                }
                else
                {
                    if(trav->right != NULL)
                    {
                        trav = trav->right;
                    }
                    else
                    {
                        trav->right = tmp;
                        break;
                    }
                }
            }
        }
        printf("\nelement inserted  \n");
    }
}

void inOrder(struct node *trav)
{
    if(trav != NULL)
    {
        inOrder(trav->left);
        printf("%d ",trav->data);
        inOrder(trav->right);
    }
    else
    {
        return ;
    }
}

void preOrder(struct node *trav)
{
    if(trav != NULL)
    {
        printf("%d ",trav->data);
        preOrder(trav->left);
        preOrder(trav->right);
    }
    else
    {
        return ;
    }
}

void postOrder(struct node *trav)
{
    if(trav != NULL)
    {
        postOrder(trav->left);
        postOrder(trav->right);
        printf("%d ",trav->data);
    }
    else
    {
        return ;
    }
}