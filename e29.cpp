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
        if( rear==maxsize-1)
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
                rear++;
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
                front++;
            }
        }
        return el;
    }

    void display()
    {
        for(int i=front;i<=rear;i++)
        {
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
        cout<<"\n1.ADD A JOB";
        cout<<"\n2.DELETE A JOB";
        cout<<"\n3.DISPLAY THE QUEUE";
        cout<<"\n4.EXIT";
        cout<<"\nEnter your choice";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter the job to be added"<<endl;
            cin>>el;
            obj.enqueue(el);
            cout<<"\nJob added";
            break;
            case 2:
            cout<<"\n"<<obj.dequeue()<<" is deleted"<<endl;
            break;
            case 3:
            cout<<"The queue is"<<endl;
            obj.display();
            break;
            case 4:
            cout<<"Thankyou for using the program"<<endl;
            break;
        }
    }while(ch!=4);
    return 0;
    
}