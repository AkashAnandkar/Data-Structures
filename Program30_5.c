/*

        Write a program which returns smallest number from linked list.

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

int Minimum(PNODE Head)
{
    int iMinimum=Head->data;

    while(Head!=NULL)
    {
        if(Head->data<iMinimum)
        {
            iMinimum=Head->data;
        }
        Head=Head->next;
        
    }
    return iMinimum;

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

    InsertFirst(&First,640);

    InsertFirst(&First,240);
    InsertFirst(&First,20);
    InsertFirst(&First,230);
    InsertFirst(&First,110);

    Display(First);

    iRet=Minimum(First);
    printf("Smallest element  of linked list is  :%d",iRet);


    return 0;
}
