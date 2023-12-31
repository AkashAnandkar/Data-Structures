
/*

        Write a program which reverse each element of  singly linear linked list.


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
int Count(PNODE Head)
{
    int iCount=0;
    while(Head!=NULL)
    {
        iCount++;
        Head=Head->next;
    }
    return iCount;
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

void Reverse(PNODE Head)
{
    printf("Linked List after making each element reverse : ");

    int iLength=0;
    iLength=Count(Head);
    int iCnt=0;

    int iDigit=0;
    int iReverse=0;
    int iNo1=0;
    int iNo2=0;
    PNODE temp=Head;
    for(iCnt=1;iCnt<=iLength;iCnt++)
    {
        iNo1=temp->data;
        iNo2=iNo1;
        while(iNo2!=0)
        {
            iDigit=iNo2%10;
            iReverse=(iReverse *10)+iDigit;
            iNo2=iNo2/10;
        }
        printf("| %d |->",iReverse);


        temp=temp->next;
        iReverse=0;
    }
}


int main()
{

    PNODE First=NULL;
    int iRet=0;

    
    InsertFirst(&First,89);
    InsertFirst(&First,6);

    InsertFirst(&First,41);

    InsertFirst(&First,17);
    InsertFirst(&First,28);
    InsertFirst(&First,11);
    
    iRet=Count(First);
    printf("Number of elements in linkedlist are : %d\n",iRet);
    

    

    Display(First);
    Reverse(First);
    
    Display(First);
    
    
   
    

    return 0;
}
