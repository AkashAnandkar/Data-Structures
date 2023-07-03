/*

   Stack

*/

#include<iostream>

using namespace std;



typedef class node
{
    public :
        int data;
       struct node *next;

       node(int value)
       {
         data=value;
         next=NULL;
       }

}NODE,*PNODE;

class Stack
{
    private:
        PNODE First;
        int iCount;

    public:
        Stack();
        void Push(int no);   //InsertLast
        int Pop();           //DeleteLast
        void Display();
        int Count();
};

Stack::Stack()
{
    First=NULL;
    iCount=0;
}
 void Stack:: Push(int no)  
 {
    PNODE newn =new NODE(no);

    if(First==NULL)
    {
        First=newn;
    }
    else
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
 int Stack::  Pop()   //DeleteLast
 {
    int Value=0;

    if(iCount==0)
    {
        cout<<"Stack is empty \n";
        return -1;

    }
    else if(iCount==1)
    {
        Value=First->data;
        delete First;
        First=NULL;

    }
    else
    {
        PNODE temp=First;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        Value= temp->next->data;
        delete temp->next;
        temp->next=NULL;

    }
    iCount--;
    return Value;
 }          
 void Stack::  Display()
 {
    PNODE temp=First;
    cout<<"Elements of Stack are  :\n";

    for(int iCnt=1 ;iCnt<=iCount ; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
 }
 int Stack:: Count()
 {
    return iCount;
 }




int main()
{

    int iChoice=1;
    int iValue=0;
    int iRet=0;

    Stack obj;
    
        cout<<"------------------------------------------------------------\n";


        cout<<"Dynamic implmentaion of Stack \n";
        cout<<"------------------------------------------------------------\n";
        

    while(iChoice!=0)
    {
        cout<<"------------------------------------------------------------\n";

        cout<<"1 : Push element in stack : \n";
        cout<<"2:  Pop element from stack \n";
        cout<<"3 : Display stack\n";
        cout<<"4 : Count number of elements from stack \n";
        
        
        cout<<"0 : Terminate the application\n";
        cout<<"------------------------------------------------------------\n";
        
        cout<<"Please Enter the option  :\n";
        cin>>iChoice;


        switch(iChoice)
        {

            case 1:
                cout<<"Enter the element that we want to push \n";
                cin>>iValue;
                obj.Push(iValue);
                break;

            case 2 : 
                iRet=obj.Pop();
                if(iRet!=1)
                {
                    cout<<"Poped element from stack is : "<<iRet<<"\n";
                }
                break;

            case 3:
              obj.Display();
              break;

            case 4:
                iRet=obj.Count();
                cout<<"Number of elements in Stack are  : "<<iRet<<"\n";
                break;


            case 5:
                cout<<"Thank you for using application \n";
                break;

            default : 
                cout<<"Please Enter valid option \n";    

        }  //End of switch

        
}   //End of while

    return 0;
}