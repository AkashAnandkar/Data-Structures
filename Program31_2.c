/*

        Write a program which displays all elements which are 
         from singly linear linked list.


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

void DisplayPrime(PNODE Head)
{
    printf("Prime Numbers from linked List are :  ");
    int iCnt=0;
    int iSum=0;
    while(Head!=NULL)
    {
        
        
        for(iCnt=2;iCnt<=((Head->data)/2);iCnt++)
        {
            if(((Head->data)%iCnt)==0)
            {
                break;
            }
            
            
        }
        if(iCnt==((Head->data)/2)+1)
        {
            printf("%d\t",Head->data);
        }
       
      

       Head=Head->next;
       iCnt=0;
        
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

    InsertFirst(&First,89);
    InsertFirst(&First,22);

    InsertFirst(&First,41);

    InsertFirst(&First,17);

    InsertFirst(&First,20);
    InsertFirst(&First,11);
    

    Display(First);
    DisplayPrime(First);
     Display(First);


    return 0;
}
