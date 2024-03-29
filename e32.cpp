#include <iostream>
#define maxsize 5
using namespace std;
class queue
{
    int que[maxsize];
    int front,rear;
    public:
    queue()
    {
        front=-1;
        rear=-1;
    }
    int isempty()
    {
        if(front==-1 && rear==-1)
        return 1;
        else
        return 0;
    }
    int isfull()
    {
        if( (rear+1)%maxsize==front)
        return 1;
        else
        return 0;
    }
    void enqueue(int el)
    {
        if(isfull()==1)
        {
            cout<<"Queue overflow .Cannot add a job"<<endl;
        }
        else
        {
            if(front==-1)
            {
                front++;
                rear++;
                que[rear]=el;
            }
            else{
                rear=(rear+1)%maxsize;
                que[rear]=el;
            }
        }
    }

    int dequeue()
    {
        int el=0;
        if(isempty()==1)
        {
            cout<<"Queue underflow .Cannot delete the job"<<endl;
        }
        else
        {
            el=que[front];
            if(front==rear)
            {
                front=rear=-1;
            }
            else{
                front=(front+1)%maxsize;
            }
        }
        return el;
    }

    void display()
    {
        if(isempty()==1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            int i=front;
            while(i<rear)
            {
                cout<<que[i]<<" ";
                i=(i+1)%maxsize;
            }
            cout<<que[i]<<" ";
        }
    }
};

int main()
{
    queue obj;
    int ch,el;

    do
    {
        cout<<"\n************MENU**********";
        cout<<"\n1.ADD An item";
        cout<<"\n2.DELETE AN ITEM";
        cout<<"\n3.DISPLAY THE ORDER";
        cout<<"\n4.EXIT";
        cout<<"\nEnter your choice";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter the item to be added"<<endl;
            cin>>el;
            obj.enqueue(el);
            cout<<"\nItem dded to the order";
            break;
            case 2:
            cout<<"\n"<<obj.dequeue()<<" is deleted"<<endl;
            break;
            case 3:
            cout<<"The order list is"<<endl;
            obj.display();
            break;
            case 4:
            cout<<"Thankyou for using the program"<<endl;
            break;
        }
    }while(ch!=4);
    return 0;
    
}
