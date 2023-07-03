#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node **PPNODE;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE Head)
{
    printf("\nElements of LL are : \n");
    while(Head!=NULL)
    {
        printf("| %d | -> ",Head->data);
         Head=Head->next;
    }
    printf("NULL\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
void DeleteFirst(PPNODE Head)
{
    PNODE temp=*Head;
    if(*Head==NULL)     //LL is empty
    {
        return;
    }
    else if((*Head) -> next == NULL)   //One Node   IMP
    {
        free(*Head);
        *Head=NULL;

    }
    else                //More than one Node
    {
        *Head=(*Head)->next;
        free(temp);

    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE Head)
{
    PNODE temp=*Head;
    if(*Head==NULL)     //LL is empty
    {
        return;
    }
    else if((*Head) -> next == NULL)   //One Node
    {
        free(*Head);
        *Head=NULL;

    }
    else                //More than one Node
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;

    }
}

void InsertAtPos(PPNODE Head,int No,int iPos)
{
    int iLenth=0;
    int iCnt=0;
    iLenth=Count(*Head);   //Calculate lenth of LL

    PNODE newn=NULL;
    PNODE temp=*Head;

    if((iPos<1)||(iPos>iLenth+1))
    {
        printf("Invalid Position \n");      //Filter
        return;
    }
    if(iPos==1)
    {
        InsertFirst(Head,No);

    }
    else if(iPos==iLenth+1)
    {
        InsertLast(Head,No);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NULL));
        newn->data=No;
        newn->next=NULL;

        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }

        //Sequence is important
        newn->next=temp->next;
        temp->next=newn;


    }


}

void DeleteAtPos(PPNODE Head,int iPos)
{
    int iLenth=0;
    PNODE temp=*Head;
    PNODE tempx=NULL;
    int iCnt=0;
    iLenth=Count(*Head);   //Calculate lenth of LL

    if((iPos<1)||(iPos>iLenth))
    {
        printf("Invalid Position \n");      //Filter
        return;
    }
    if(iPos==1)
    {
        DeleteFirst(Head);

    }
    else if(iPos==iLenth)
    {
        DeleteLast(Head);
    }
    else
    {
         for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }

        //Sequence is important
        tempx=temp->next;
        temp->next=temp->next->next;
        free(tempx);

    }


}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//              Main Function
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main()
{
    PNODE First=NULL;
    int iiRet=0;

    InsertLast(&First,11);
    
    InsertLast(&First,21);
    
    InsertLast(&First,51);
    
    InsertLast(&First,101);


    Display(First);
    iiRet=Count(First);

    printf("Number of elements in LL are : %d\n",iiRet);

    InsertFirst(&First,10);
    InsertFirst(&First,20);

     Display(First);
    iiRet=Count(First);

    printf("Number of elements in LL are : %d\n",iiRet);
    
    

    InsertAtPos(&First,25,5);
     Display(First);
    iiRet=Count(First);

    printf("Number of elements in LL are : %d\n",iiRet);

    DeleteAtPos(&First,5);
    Display(First);
    iiRet=Count(First);

    printf("Number of elements in LL are : %d\n",iiRet);


    DeleteFirst(&First);
    DeleteFirst(&First);
    
    Display(First);
    
    iiRet=Count(First);
    printf("Number of elements in LL are : %d\n",iiRet);
    DeleteLast(&First);
    
    Display(First);
    
    iiRet=Count(First);
    printf("Number of elements in LL are : %d\n",iiRet);



    
    return 0;
}