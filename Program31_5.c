
/*

        Write a program which displays all elements which which will display addition of  
        digits  of element  from singly linear linked list.


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


void SumDigit(PNODE Head)
{
    int iLength=0;
    int iCnt=0;
    int iSum=0;
    int iDigit=0;
    int iNo1=0;
    int iNo2=0;
    PNODE temp=Head;
    iLength=Count(Head);

    printf("Sum of Digits of each element is : \n");

    for(iCnt=1;iCnt<=iLength;iCnt++)
    {
        iNo1=temp->data;
        iNo2=iNo1;
        while(iNo2!=0)
        {
            iDigit=iNo2%10;
            iSum=iSum+iDigit;
            iNo2=iNo2/10;
        }
        printf("%d\t",iSum);


        temp=temp->next;
        iSum=0;
    }
    

   
}

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

    PNODE First=NULL;
    int iRet=0;

    
    InsertFirst(&First,640);
    InsertFirst(&First,240);

    InsertFirst(&First,20);

    InsertFirst(&First,230);
    InsertFirst(&First,110);
    

    Display(First);

    iRet=Count(First);
    printf("Number of elements of linkedlist are : %d",iRet);

    SumDigit(First);
    
    Display(First);

    

    return 0;
}
