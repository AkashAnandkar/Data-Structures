/*

        Write a program which returns addition of all element from singly linear linked list

*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef  struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE Head,int No)
{
    PNODE newn =NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    
    newn->data=No;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
       newn->next=*Head;
       *Head=newn; 
    }
}

    
int Addition(PNODE Head)
{
    int iSum=0;
    while(Head!=NULL)
    {
        iSum=iSum +(Head->data);
        Head=Head->next;
    }
    return iSum;
}

void Display(PNODE Head)
{
    printf("\n Elements of LinkedList are : \n");
    while(Head!=NULL)
    {
        printf("| %d |->",Head->data);
        Head=Head->next;
    }
    printf("NULL\n");
}


int main()
{

    PNODE First=NULL;
    int iRet=0;

    InsertFirst(&First,40);

    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);

    iRet=Addition(First);
    printf("Addition of elements of linked list is  :%d",iRet);


    return 0;
}
