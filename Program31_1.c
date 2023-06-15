/*

        Write a program which displays all elements which are perfect from singly linear linked list.


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

void DisplayPerfect(PNODE Head)
{
    int iCnt=0;
    int iSum=0;
    printf("Perfect Number from Linked List are : ");

    while(Head!=NULL)
    {
        for(iCnt=1;iCnt<=((Head->data)/2);iCnt++)
        {
            if(((Head->data)%iCnt)==0)
            {
                iSum=iSum+iCnt;
            }
            
            
        }
        if((Head->data)==iSum)
        {
            printf("%d\t",Head->data);
        }
      

       Head=Head->next;
       iSum=0;
        

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
    InsertFirst(&First,6);

    InsertFirst(&First,41);

    InsertFirst(&First,17);

    InsertFirst(&First,28);
    InsertFirst(&First,11);
    

    Display(First);
    DisplayPerfect(First);
    
    Display(First);


    return 0;
}
