
/*

        Write a program which will display all pallindrome elements of  singly linear linked list.


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

void DisplayPallindrome(PNODE Head)
{
    printf("Pallindrome number in linklist are : \n");
    int iLength=0;
    int iCnt=0;
    int iDigit=0;
    int iReverse=0;
    iLength=Count(Head);

    int iNo=0;
    int iNo1=0;

    PNODE temp=Head;
    for(iCnt=1;iCnt<=iLength;iCnt++)
    {
        iNo=temp->data;
        iNo1=iNo;

        while(iNo1!=0)
        {

        iDigit=(iNo1)%10;

        iReverse=(iReverse * 10)+iDigit;

        iNo1=(iNo1)/10;
        }
        if(iNo==iReverse)
        {
            printf("%d  \t",iNo);
        }
        
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

    InsertFirst(&First,414);

    InsertFirst(&First,17);
    InsertFirst(&First,28);
    InsertFirst(&First,11);

    iRet=Count(First);
    printf("Number of elements in linkedlist are : %d",iRet);
    

    Display(First);
    DisplayPallindrome(First);

    Display(First);


    
    
   
    

    return 0;
}
