

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

int Summation(PNODE Head)
{
    int iSum=0;
    while(Head!=NULL)
    {
        iSum=iSum+(Head->data);
        Head=Head->next;
    }
    return iSum;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//              Main Function
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main()
{
    PNODE First=NULL;
    int iRet=0;

    InsertFirst(&First,111);
    InsertFirst(&First,101);
    InsertFirst(&First,51);
    InsertFirst(&First,21);
    InsertFirst(&First,11);

    Display(First);

    iRet=Summation(First);
    printf("Summation is : %d\n",iRet);
    
    return 0;
}