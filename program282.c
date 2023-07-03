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

int Minimum(PNODE Head)
{
    int iMin=0;

    if(Head==NULL)
    {
        return -1;
    }
    iMin=Head->data;
    while(Head!=NULL)
    {
        if(Head->data<iMin)
        {
            iMin=Head->data;
        }

        Head=Head->next;
    }
    return iMin;
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
    iRet=Minimum(First);
    printf("Minimum is : %d\n",iRet);
    
    return 0;
}