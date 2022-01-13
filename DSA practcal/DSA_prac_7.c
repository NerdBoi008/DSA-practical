#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*start = NULL;

void insertToFront();
void insertAtMiddle();
void insertToLast();
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
    while (1)
    {
        printf("\n--- LinkList Operatoins --- \n1) Insert. \n2) Delete. \n3) Traversal. \n4) Exit. \nEnter choice: ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("--- Insert Operations --- \n1) At Front. \n2) At middle(specific). \n3) At End. \n4) Exit. \nEnter choice: ");
            scanf("%d",&choice);

            if(choice == 1) { insertToFront(); }
            else if(choice == 2) { insertAtMiddle(); }
            else if(choice == 3) { insertToLast(); }
            else { break; }
        }
        else if(choice == 2)
        {
            printf("--- Delete Operations --- \n1) Delete Frist. \n2) Delete Specific. \n3) Delete Last. \n4) Exit. \nEnter choice: ");
            scanf("%d",&choice);
            
            if(choice == 1) { deleteFirst(); }
            else if(choice == 2) { deleteSpecific(); }
            else if(choice == 3) { deleteLast(); }
            else { break; }
        }
        else if(choice == 3) { traversal(); }
        else { break; }
    }
    return 0;
}

void insertToFront()
{
    int value;
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if(!tmp) { 
        printf("Memory Error!"); 
    }

    printf("Enter value to insert: ");
    scanf("%d",&value);

    tmp->data = value; 
    tmp->next = NULL;

    if(start == NULL)
    {
        start = tmp;
        printf("\nElement Inserted.\n");
    }
    else
    {
        tmp->next = start;
        start = tmp;
        printf("\nElement Inserted.\n");
    }
}

void insertAtMiddle()
{
    int value;
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if(!tmp) { 
        printf("Memory Error!"); 
    }

    printf("\nEnter value to insert: ");
    scanf("%d",&value);

    tmp->data = value; 
    tmp->next = NULL;

    if(start == NULL)
    {
        start = tmp;
        printf("\nElement Inserted.\n");
    }
    else
    {
        int slctVal;
        struct node *trav = start;
        printf("Select node: ");
        scanf("%d",&slctVal);
        
        if(trav->data == slctVal)
        {
            printf("sdfag");
            tmp->next = trav->next;
            trav->next = tmp;
        }
        else
        {
            while(trav->next != NULL)
            {
                if(trav->data == slctVal)
                {
                    tmp->next = trav->next;
                    trav->next = tmp;
                    break;
                }
                trav = trav->next;
            }
            if(trav->next == NULL)
            {
                trav->next = tmp;
            }
        }
    }
}

void insertToLast()
{
    int value;
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if(!tmp) { 
        printf("Memory Error!"); 
    }

    printf("Enter value to insert: ");
    scanf("%d",&value);

    tmp->data = value; 
    tmp->next = NULL;

    if(start == NULL)
    {
        start = tmp;
        printf("\nElement Inserted.\n");
    }
    else
    {
        struct node *trav = start;
        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = tmp;
        printf("\nElement Inserted.\n");
    }
}

void deleteFirst()
{
    if(start == NULL)
    {
        printf("\nList is Empty.\n");
    }
    else
    {
        struct node *trav = start;
        start = start->next;
        printf("\nElement %d has been deleted.\n",trav->data);
        free(trav);
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
        int value;
        printf("Enter Element to delete: ");
        scanf("%d",&value);
        struct node *trav, *prev = start;

        if(prev->data == value)
        {
            deleteFirst();
        }
        else
        {
            trav = prev->next;
            while(trav->next != NULL)
            {
                if (trav->data == value)
                {
                    printf("\nElement %d has been deleted.\n",trav->data);
                    trav = trav->next;
                    prev->next = trav;
                    break;
                }                
                trav = trav->next;
                prev = prev->next;
            }
            if (trav->data == value)
            {
                deleteLast();
            }
            else { 
                printf("\nThere is no node like that.\n"); 
            }
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
        struct node *trav, *prev;
        prev = start;
        trav = prev->next;
        if(prev->next == NULL)
        {
            deleteFirst();
        }
        else{
            while(trav->next != NULL)
            {
                trav = trav->next;
                prev = prev->next;
            }
            prev->next = NULL;
            printf("\nElement %d has been deleted.\n",trav->data);
            free(trav);
        }  
    }
}

