#include<iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE,*PNODE,**PPNODE;

class SinglyLL
{
    private:
        PNODE First;     //Charcterstics
        int iCount;      //Charcterstics
        

    public:
        SinglyLL();
        ~SinglyLL(); 

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int ipos);      

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int  Count();

    
    
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL:: InsertFirst(int no)
{
    PNODE newn=NULL;
    newn =new NODE;
    newn->data=no;
    newn->next=NULL;

    if(First==NULL)  //LL is empty
    {
        First=newn;

    }
    else            //LL contain atleast one node
    {
        newn->next=First;
        First=newn;

    }
    iCount++;


}

//////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL:: InsertLast(int no)
{
    
    PNODE newn=NULL;
    newn =new NODE;
    newn->data=no;
    newn->next=NULL;

    if(First==NULL)  //LL is empty
    {
        First=newn;

    }
    else            //LL contain atleast one node
    {
        PNODE temp=First;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
    iCount++;


}

////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL:: DeleteFirst()
{

    if(First==NULL)  //LL is empty
    {
        return;

    }
    else if(First->next==NULL)   //single node in LL
    {
        delete First;  //free(First)
        First=NULL;

    }
    else                             //More than node in LL
    {
        PNODE temp=temp;
        First=First->next;
        delete temp;

    }
    iCount--;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLL:: DeleteLast()
{
    
    if(First==NULL)  //LL is empty
    {
        return;

    }
    else if(First->next==NULL)   //single node in LL
    {
        delete First;  
        First=NULL;

    }
    else                             //More than node in LL
    {
        PNODE temp=First;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;

    }
    iCount--;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////

void SinglyLL:: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp=First;
    while(temp!=NULL)
    {
        cout<<" | "<<temp->data<<" |->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";

}

//////////////////////////////////////////////////////////////////////////////////////////////

int SinglyLL:: Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

SinglyLL:: SinglyLL()
{
    cout<<"Inside Constrcuctor \n";
    First=NULL;
     iCount=0;
}

SinglyLL:: ~SinglyLL()
{
    cout<<"Inside Destructor"<<"\n";
}


void SinglyLL:: InsertAtPos(int no,int ipos)
{
    if((ipos<1)||(ipos>iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE temp=First;
        int iCnt=0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;
        }
        PNODE newn=new NODE;
        newn->data=no;
        newn->next=NULL;

        newn->next=temp->next;
        temp->next=newn;
    }
    iCount++;

    

}

void SinglyLL:: DeleteAtPos(int ipos)
{
    if((ipos<1)||(ipos>iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp=First;
        PNODE tempX=NULL;
        for(int iCnt=1; iCnt<ipos-1;iCnt++)
        {
            temp=temp->next;
        }
        tempX=temp->next;
        temp->next=temp->next->next;
        delete tempX;
    }
    iCount--;

}

int main()
{
    int iRet=0;

    SinglyLL obj1;
    

    obj1.InsertFirst(51);
     obj1.InsertFirst(21);
      obj1.InsertFirst(11);

      obj1.InsertLast(101);
      obj1.InsertLast(111);

      obj1.InsertAtPos(55,4);
      
      obj1.Display();
      iRet=obj1.Count();

      cout<<"Number of elements in LL are : "<<iRet<<"\n";

      obj1.DeleteAtPos(4);

      obj1.Display();
      iRet=obj1.Count();

      cout<<"Number of elements in LL are : "<<iRet<<"\n";

      obj1.DeleteFirst();
      obj1.DeleteLast();
       obj1.Display();
      iRet=obj1.Count();

      cout<<"Number of elements in LL are : "<<iRet<<"\n";

     



      

    
    return 0;
}