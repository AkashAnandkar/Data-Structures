/*

        Write a program which  search last  occurance of a particular element from
        singly linear linked list.
        Function should return position at which elemnt is found.


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

int SearchLastOccurance(PNODE Head,int No)
{
    int iCnt=0;
    int iPos=0;
    while(Head!=NULL)
    {
         iCnt++;
        if(Head->data==No)
        {
             iPos=iCnt;  
        }
       
        Head=Head->next;
    }
    return iPos;

    
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

    InsertFirst(&First,70);
    InsertFirst(&First,30);

    InsertFirst(&First,50);

    InsertFirst(&First,40);

    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    Display(First);

    iRet=SearchLastOccurance(First,30);
    printf("Last occcurance of 30 is at position :%d",iRet);


    return 0;
}
