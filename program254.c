#include<stdio.h>
#include<stdlib.h>

 struct Node
{
    int data;
    struct Node *next;
};

typedef  struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

/////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE Head)
{
    printf("Elements of LinkedList are : \n");
    while(Head!=NULL)
    {
        printf("|%d| ->",Head->data);
        Head=Head->next;
    }
    printf("NULL\n");


}

//////////////////////////////////////////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////////////////////////////////////////

void InsertFirst(PPNODE Head,int No)
{

    PNODE newn =NULL;
    newn=(PNODE)malloc(sizeof(NODE));    //Allocate memory for node
 
    //Initilaze the node
    newn->data=No;
    newn->next=NULL;

    if(*Head == NULL)    //LL is empty
    {
        *Head=newn;
    }
    else                //LL contains one node
    {
        newn->next=*Head;
        *Head=newn;
    }



}

//////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head,int No)
{

    
    PNODE newn =NULL;
    newn=(PNODE)malloc(sizeof(NODE));    //Allocate memory for node
 
    //Initilaze the node
    newn->data=No;
    newn->next=NULL;

    if(*Head == NULL)    //LL is empty
    {
        *Head=newn;
    }
    else                //LL contains atleast one node
    {
        PNODE temp=*Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;

    }



}

///////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE Head,int No,int Pos)
{

}

//////////////////////////////////////////////////////////////////////////////////////////

void DeleteFirst(PPNODE Head)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE Head,int Pos)
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet=0;
    PNODE First =NULL;
    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);
   iRet= Count(First);
   printf("\nNumber of Nodes in LinkedList are :%d \n",iRet);

    InsertLast(&First,121);
    InsertLast(&First,151);
    
    Display(First);
   iRet= Count(First);
   printf("\nNumber of Nodes in LinkedList are :%d \n",iRet);

    return 0;
}