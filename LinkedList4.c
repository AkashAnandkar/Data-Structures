#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;


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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Para/meters    : Address of Pointer and data of node
//  Description   : Insert at First position of LinkedList
//  Return Value  : Void
//  Author        :Akash Subhash Anandkar
//  Date          : 14/06/2023
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head,int No)
{
    PNODE newn=NULL;
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

void InsertAtPos(PPNODE Head,int No,int iPos)
{
    int iLength=0;
    int iCnt=0;
    iLength=Count(*Head);
    PNODE temp=*Head;
    PNODE  newn=NULL;

    if((iPos<1)  || (iPos>iLength+1))
    {
        printf("Invalid Input \n");
        return;
    }
    if(iPos==1)
    {
        InsertFirst(Head,No);
    }
    else if(iPos==iLength+1)
    {
        InsertLast(Head,No);
    }
    else
    {
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
void DeleteAtPos(PPNODE Head,int iPos)
{
    int iLength=0;
    iLength=Count(*Head);
    int iCnt=0;
    PNODE temp=*Head;
    PNODE tempX=NULL;

    if((iPos<1) || (iPos>iLength))
    {
        printf("Invalid Position\n");
    }

    if(iPos==1)
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
    int iRet=0;
    PNODE First=NULL;

    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);
    iRet=Count(First);
    printf("Number of elements in Linked List are : %d",iRet);

    InsertLast(&First,101);
    InsertLast(&First,121);
    
    Display(First);
    iRet=Count(First);
    printf("Number of elements in Linked List are : %d",iRet);

    InsertAtPos(&First,55,3);
     
    Display(First);
    iRet=Count(First);
    printf("Number of elements in Linked List are : %d",iRet);

    DeleteFirst(&First);
     
    Display(First);
    iRet=Count(First);
    printf("Number of elements in Linked List are : %d",iRet);

    DeleteLast(&First);
    
    Display(First);
    iRet=Count(First);
    printf("Number of elements in Linked List are : %d",iRet);

    DeleteAtPos(&First,3);
    
    Display(First);
    iRet=Count(First);
    printf("Number of elements in Linked List are : %d",iRet);








    return 0;
}