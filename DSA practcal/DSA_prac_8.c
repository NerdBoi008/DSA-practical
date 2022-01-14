#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*start = NULL;

struct node* newNode(int value)
{
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if (!tmp)
    {
        printf("Memory Error!");
        exit(0);
    }
    tmp->data = value;
    tmp->next = tmp->prev = NULL;

    return tmp;
}


void insertAtFront();
void insertAtMiddle();
void insertAtLast();
void deleteFirst();
void deleteSpecific();
void deleteLast();

void traversal()
{
    struct node *trav = start;
    if(start == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {
        printf("Start: ");
        while(trav->next != NULL)
        {
            printf("%d -> ", trav->data);
            trav = trav->next;
        }
        printf("%d -> NULL ", trav->data);
    }
}

int main(void)
{
    int choice;
    while(1)
    {
        printf("\n--- Doubly_LinkList Operations --- \n1) 'i' = Insert. \n2) 'd' = Delete. \n3) 't' = Traversal. \n4) 'e' = Exit. \nEnter choice: ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("\n--- Insert Operations --- \n1) 'f' = Front. \n2) 'm' = Middle. \n3) 'l' = Last. \n4) 'e' = Exit. \nEnter choice: ");
            scanf("%d",&choice);
            if(choice == 1) { insertAtFront(); }
            else if(choice == 2) { insertAtMiddle(); }
            else if(choice == 3) { insertAtLast(); }
            else { break; }
        }
        else if(choice == 2)
        {
            printf("\n--- delete Operations --- \n1) 'f' = Front. \n2) 'm' = Middle. \n3) 'l' = Last. \n4) 'e' = Exit. \nEnter choice: ");
            scanf("%d",&choice);
            if(choice == 1) { deleteFirst(); }
            else if(choice == 2) { deleteSpecific(); }
            else if(choice == 3) { deleteLast(); }
            else { break; }
        }
        else if(choice == 3 ) { traversal(); }
        else { break; }
    }
}

void insertAtFront()
{
    int value;
    printf("Enter element to insert: ");
    scanf("%d",&value);

    struct node *tmp = newNode(value);

    if(start == NULL)
    {
        start = tmp;
    }
    else
    {
        tmp->next = start;
        start->prev = tmp;
        start = tmp;
    }
    printf("\nElement Inserted.\n");
}

void insertAtMiddle()
{
    int value;
    printf("Enter element to insert: ");
    scanf("%d",&value);

    struct node *tmp = newNode(value);

    if(start == NULL)
    {
        start = tmp;
    }
    else
    {
        struct node *trav = start;
        int inVal;
        printf("Select node: ");
        scanf("%d",&inVal);
        while(trav->next != NULL)
        {
            if(trav->data == inVal)
            {
                tmp->next = trav->next;
                tmp->prev = trav;
                trav->next = tmp;
                tmp->next->prev = tmp;
                goto exit;
            }
            trav = trav->next;
        }
        if(trav->next == NULL)
        {
            trav->next = tmp;
            tmp->prev = trav;
        }
    }
    exit:
    printf("\nElement Inserted.\n");
}

void insertAtLast()
{
    int value;
    printf("Enter element to insert: ");
    scanf("%d",&value);

    struct node *tmp = newNode(value);

    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        struct node *trav = start;
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = tmp;
        tmp->prev = trav;
    }
    printf("\nElement Inserted.\n");
}

void deleteFirst()
{
    if(start == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {
        printf("\nElement %d deleted.\n",start->data);
        start->prev = NULL;
        start = start->next;
    }
}

void deleteSpecific()
{
    if(start == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {
        int value, flag = 0;
        printf("Enter element to delete: ");
        scanf("%d",&value);

        struct node *trav = start;
        if(trav->data == value && trav->next != NULL) { deleteFirst(); }
        else
        {
            while (trav->next != NULL)
            {
                if(trav->data == value)
                {
                    printf("\nElement %d has been deleted.\n",trav->data);
                    trav->prev->next = trav->next;
                    trav->next->prev = trav->prev;
                    free(trav);
                    flag = 1;
                    break;
                }
                trav = trav->next;
            }
            if(trav->data == value && trav->next == NULL) { 
                deleteLast();
                flag = 1;
             }
            if(flag == 0) { printf("\nThere is no node like that.\n"); }
        }
    }
}

void deleteLast()
{
    if(start == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {
        struct node *trav = start, *temp;
        if(trav->next == NULL) { deleteFirst(); }
        else
        {
            while (trav->next != NULL)
            {
                trav = trav->next;
            }
                temp = trav->prev;
                temp->next = NULL;
                printf("\nElement %d deleted\n",trav->data);
        }
    }
}
