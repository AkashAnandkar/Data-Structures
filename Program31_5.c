
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


void SumDigit(PNODE Head)
{
    
    int iSum=0;
    int iDigit=0;
    int iNo;

    printf("Sum of Digits of each element is : \n");

    while(Head!=NULL)
    {
        while((Head->data)!=0)
        {   
            iDigit=((Head->data)%10);
            iSum=iSum+iDigit;
            Head->data=((Head->data)/10);
        }
        printf("%d\t",iSum);
        Head=Head->next;
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
   SumDigit(First);
    

    return 0;
}
