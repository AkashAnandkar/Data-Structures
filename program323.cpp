/*

   Queqe

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

class Queqe
{
    private:
        PNODE First;
        int iCount;

    public:
        Queqe();
        void Enqueqe(int no);   //InsertLast
        int Dequeqe();           //DeleteFirst
        void Display();
        int Count();
};

Queqe::Queqe()
{
    First=NULL;
    iCount=0;
}
 void Queqe:: Enqueqe(int no)  
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
 int Queqe::  Dequeqe()   //DeleteFirst
 {
    int Value=0;

    if(iCount==0)
    {
        cout<<"Queqe is empty \n";
        return -1;

    }
    else if(iCount==1)
    {
        Value=First->data;
        PNODE temp=First;
        First=First->next;
        delete temp;
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
 void Queqe::  Display()
 {
    PNODE temp=First;
    cout<<"Elements of Queqe are  :\n";

    for(int iCnt=1 ;iCnt<=iCount ; iCnt++)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
 }
 int Queqe:: Count()
 {
    return iCount;
 }




int main()
{

    int iChoice=1;
    int iValue=0;
    int iRet=0;

    Queqe obj;
    
        cout<<"------------------------------------------------------------\n";


        cout<<"Dynamic implmentaion of Queqe \n";
        cout<<"------------------------------------------------------------\n";
        

    while(iChoice!=0)
    {
        cout<<"------------------------------------------------------------\n";

        cout<<"1 : Insert  element in Queue : \n";
        cout<<"2:  remove element from Queqe \n";
        cout<<"3 : Display Queqe\n";
        cout<<"4 : Count number of elements from stack \n";
        
        
        cout<<"0 : Terminate the application\n";
        cout<<"------------------------------------------------------------\n";
        
        cout<<"Please Enter the option  :\n";
        cin>>iChoice;


        switch(iChoice)
        {

            case 1:
                cout<<"Enter the element that we want to insert \n";
                cin>>iValue;
                obj.Enqueqe(iValue);
                break;

            case 2 : 
                iRet=obj.Dequeqe();
                if(iRet!=1)
                {
                    cout<<"Remove element from Queqe is : "<<iRet<<"\n";
                }
                break;

            case 3:
              obj.Display();
              break;

            case 4:
                iRet=obj.Count();
                cout<<"Number of elements in Queqe are  : "<<iRet<<"\n";
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