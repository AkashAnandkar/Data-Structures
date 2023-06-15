
/*

        Write a program which displays all elements which which will return addition of
         all even numbers from singly linear linked list.


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

int AddEven(PNODE Head)
{
    int iSum=0;
    
    
    while(Head!=NULL)
    {

        if(((Head->data)%2)==0)
        {
            iSum=iSum+(Head->data);
        }
        
        Head=Head->next;
    }
    return iSum;
        
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


    InsertFirst(&First,41);

    InsertFirst(&First,32);

    InsertFirst(&First,20);
    InsertFirst(&First,11);
    

    Display(First);
   iRet= AddEven(First);
   printf("Addition of all even numbers form LinkedList is : %d",iRet);
   
    Display(First);


    return 0;
}
