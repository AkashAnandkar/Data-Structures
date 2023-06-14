# include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node *PNODE;
typedef struct Node **PPNODE; 

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

void InsertLast(PPNODE Head, int no)
{
    PNODE newn =NULL;
    

    newn = (PNODE)malloc(sizeof(NODE));   //Allocate memory

    newn ->data=no;   //Initialize data
    newn ->next=NULL;  //Initialize Pointer

    if(*Head==NULL)   //LinkedList is empty
    {
        *Head=newn;
    }
    else
    {
        PNODE temp =*Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
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
    printf("\nElements of a LinkedList are : \n");
    while (Head!=NULL)
    {
        printf("|%d|->",Head->data);
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//          Main Function
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int iRet=0;
    PNODE First=NULL;

    InsertFirst(&First,4);
    InsertFirst(&First,3);
    InsertFirst(&First,2);
    InsertFirst(&First,1);
     
    Display(First);
    iRet=Count(First);

    printf("Number of Nodes are  : %d",iRet);

    
    InsertLast(&First,5);
    InsertLast(&First,6);
     
    Display(First);
    
    return 0;
}