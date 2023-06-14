#include<Stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

 typedef struct Node NODE;
 typedef struct Node *  PNODE;
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
    PNODE  newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
   
    newn->data=No;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
         PNODE temp = *Head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }

 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
//      Date          : 14/06/2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    void InsertAtPos(PPNODE Head,int No,int iPos)
    {
        int iLength=0;
        iLength=Count(*Head);
        int iCnt=0;
        PNODE  temp=*Head;
        PNODE newn=NULL;

        if((iPos<1)|| (iPos>iLength+1))
        {
            printf("Invalid Position\n");
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name : DeleteAtPos
//      Descrption    : Delete at given position in LL
//      Parameters    : First Pointer and position to be deleted
//      Return Value  : void
//      Author Name   : Akash Subhash Anandkar
//      Date          : 14/06/2023
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,int iPos)
{
    int iLength=0;
     PNODE temp=*Head;
     PNODE tempX=NULL;

    iLength=Count(*Head);

    if((iPos<1) ||(iPos>iLength))
    {
        printf("Invalid Input\n ");
        return;
    }



    if(*Head==NULL)
    {
        return;
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
        int iCnt=0;
       
        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;

        }
        tempX=temp->next;
        temp->next=temp->next->next;
        free(tempX);
        
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
    printf("\nElements of LinkedList are  : \n");
    while(Head !=NULL)
    {
        printf("%d\t",Head->data);
        Head=Head->next;


    }
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
    PNODE First=NULL;
    int iRet=0;

    InsertFirst(&First,300);
    InsertFirst(&First,200);
    InsertFirst(&First,100);

    Display(First);
    iRet=Count(First);
    printf("\nNumber of Nodes present are : %d",iRet);

    InsertLast(&First,400);
    InsertLast(&First,500);

    Display(First);
    iRet=Count(First);
    printf("\nNumber of Nodes present are : %d",iRet);

    DeleteFirst(&First);
    DeleteLast(&First);
    
    Display(First);
    iRet=Count(First);
    printf("\nNumber of Nodes present are : %d",iRet);

    InsertAtPos(&First,55,4);


    
    Display(First);
    iRet=Count(First);
    printf("\nNumber of Nodes present are : %d",iRet);

    
    DeleteAtPos(&First,3);

    
    Display(First);
    iRet=Count(First);
    printf("\nNumber of Nodes present are : %d",iRet);





    return 0;
 }
