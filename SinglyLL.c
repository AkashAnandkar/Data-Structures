#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct  Node NODE;
typedef struct Node * PNODE;
typedef struct Node **PPNODE;

 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Parameters    : First Pointer
//  Description   : Used to count the number of elements in LinkList
//  Return Value  : int 
//  Author        : Akash Subhash Anandkar
//  Date          : 15/06/2023
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
//  Function Name : Display
//  Parameters    : First Pointer 
//  Description   : Used to Display elements of LinkedList
//  Return Value  : Void
//  Author        : Akash Subhash Anandkar
//  Date          : 15/06/2023
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Display(PNODE Head)
{
    printf("\n Elements of LinkedList are : \n");
    while(Head!=NULL)
    {
        printf("| %d | ->",Head->data);
        Head=Head->next;

    }
    printf("NULL\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Para/meters    : Address of Pointer and data of node
//  Description   : Insert at First position of LinkedList
//  Return Value  : Void
//  Author        :Akash Subhash Anandkar
//  Date          : 16/06/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 void InsertFirst(PPNODE Head,int No)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=No;
    newn->next=NULL;

    if(*Head==NULL)   // when LL is empty
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
//  Date          : 15/06/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void InsertLast(PPNODE Head,int No)
{
    
    PNODE newn=NULL;
    PNODE temp=*Head;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=No;
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

void DeleteFirst(PPNODE Head)
{

    PNODE temp=*Head;
    if(*Head==NULL)
    {
        return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        *Head=(*Head)->next;
        free(temp);

    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp=*Head;
    if(*Head==NULL)
    {
        return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name : InsertAtPos
//      Descrption    : Insert at given position in LL
//      Parameters    : First Pointer,data to be inserted and position to be Inserted
//      Return Value  : void
//      Author Name   : Akash Subhash Anandkar
//      Date          : 15/06/2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,int No,int iPos)
{
    int iLength=0;
    int iCnt=0;
    PNODE temp=*Head;

    iLength=Count(*Head);

    if((iPos<1)||(iPos>iLength+1))
    {
        printf("Invalid Position\n");
        return;
    }
    else if(iPos==1)
    {
        InsertFirst(Head,No);
    }
    else if(iPos==iLength+1)
    {
        InsertLast(Head,No);
    }
    else
    {
        PNODE newn=NULL;
        newn=(PNODE)malloc(sizeof(NODE));

        newn->data=No;
        newn->next=NULL;
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;


    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name : DeleteAtPos
//      Descrption    : Delete at given position in LL
//      Parameters    : First Pointer and position to be deleted
//      Return Value  : void
//      Author Name   : Akash Subhash Anandkar
//      Date          : 15/06/2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


 void DeleteAtPos(PPNODE Head,int iPos)
{
    int iLength=0;
    int iCnt=0;
    PNODE temp=*Head;
    PNODE tempX=NULL;
    iLength=Count(*Head);

    if((iPos<1)||(iPos>iLength))
    {
        printf("Invalid Position \n");
        return;
    }
    else if(iPos==1)
    {
        DeleteFirst(Head);
    }
    else if(iPos==iLength)
    {
        DeleteLast(Head);
    }
    else
    {
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        tempX=temp->next;
        temp->next=temp->next->next;
        free(tempX);

        
    }
}

int main()
{
    PNODE First=NULL;
    int iRet=0;

    InsertFirst(&First,3000);
    InsertFirst(&First,2000);
    InsertFirst(&First,1000);

    Display(First);
    iRet=Count(First);
    printf("Number of elements in LinkedList are : %d\n",iRet);

    InsertLast(&First,4000);
    InsertLast(&First,5000);
    
    Display(First);
    iRet=Count(First);
    printf("Number of elements in LinkedList are : %d\n",iRet);

    DeleteFirst(&First);

    printf("Linked List after Deleting First Element : \n");
     
    Display(First);
    iRet=Count(First);
    printf("Number of elements in LinkedList are : %d\n",iRet);

     InsertFirst(&First,1000);
      
    Display(First);
    iRet=Count(First);
    printf("Number of elements in LinkedList are : %d\n",iRet);

    DeleteLast(&First);
    Display(First);
    iRet=Count(First);
    printf("Number of elements in LinkedList are : %d\n",iRet);
    InsertLast(&First,5000);

    InsertAtPos(&First,3500,4);
     Display(First);
    iRet=Count(First);
    printf("uNmber of elements in LinkedList are : %d\n",iRet);

    DeleteAtPos(&First,4);
    
    Display(First);
    iRet=Count(First);
    printf("Number of elements in LinkedList are : %d\n",iRet);









    return 0;
}