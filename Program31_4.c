
/*

        Write a program which displays all elements which which will return
         second maximum number from singly linear linked list.


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


int SecondMaximum(PNODE Head)
{
    int iCnt=0;
    int iMaximum=0;
    int iSecMaximum=0;
    PNODE temp=Head;
    while(temp!=NULL)
    {   
    
        if((temp->data)>iMaximum)
        {
            iMaximum=temp->data;
            
        }
        temp=temp->next;
       
    }
    printf("Maximum is : %d\n",iMaximum);
    while(Head!=NULL)
    {
        if(((Head->data)>iSecMaximum) &&((Head->data)!=iMaximum))
        {
            iSecMaximum=Head->data;
        }
        Head=Head->next;

    }
    return iSecMaximum;
    

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


    InsertFirst(&First,240);

    InsertFirst(&First,320);

    InsertFirst(&First,230);
    InsertFirst(&First,110);
    

    Display(First);
   iRet= SecondMaximum(First);
   printf("Second Maximum fromm LinkedList is : %d",iRet);
    Display(First);


    return 0;
}
