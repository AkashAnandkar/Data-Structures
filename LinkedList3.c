#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Para/meters    : Address of Pointer and data of node
//  Description   : Insert at First position of LinkedList
//  Return Value  : Void
//  Author        :Akash Subhash Anandkar
//  Date          : 13/06/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE Head,char ch)
{

    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=ch;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Parameters    : First Pointer 
//  Description   : Used to Display elements of LinkedList
//  Return Value  : Void
//  Author        : Akash Subhash Anandkar
//  Date          : 13/06/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE Head)
{   
    printf("\nElements of Linked List are  : \n");
    while(Head!=NULL)
    {
        printf("|%c|->",Head->data);
        Head=Head->next;
    }
    printf("NULL\n");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Parameters    : First Pointer
//  Description   : Used to count the number of elements in LinkList
//  Return Value  : int 
//  Author        : Akash Subhash Anandkar
//  Date          : 13/06/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Count(PNODE Head)
{
    int iCnt=0;
    while(Head!=NULL)
    {
        iCnt++;
        Head=Head->next;
    }
    return iCnt;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Parameters    : Address of Pointer and data of node
//  Description   : Insert at Last position of LinkedList
//  Return Value  : Void
//  Author        : Akash Subhash Anandkar
//  Date          : 13/06/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE Head,char ch)
{
    PNODE newn=NULL;
    PNODE temp=*Head;
    newn=(PNODE)malloc(sizeof(NODE));
    
    newn->data=ch;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          Main Function
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    PNODE First=NULL;
    int iRet=0;

    InsertFirst(&First,'C');
    InsertFirst(&First,'B');
    InsertFirst(&First,'A');

    Display(First);
    iRet=Count(First);

    printf("Number of nodes in LinkList are  : %d\n",iRet);

    InsertLast(&First,'D');
    InsertLast(&First,'E');
    Display(First);
    iRet=Count(First);

    printf("Number of nodes in LinkList are  : %d",iRet);



    return 0;
}