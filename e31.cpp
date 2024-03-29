#include <iostream>
#define maxsize 5
using namespace std;
class queue
{
    int que[maxsize];
    int front,rear,count;
    public:
    queue()
    {
        front=-1;
        rear=-1;
        count=0;
    }
    int isempty()
    {
        if(front==-1 )
        return 1;
        else
        return 0;
    }
    int isfull()
    {
        if(rear==maxsize-1)
        return 1;
        else
        return 0;
    }
    void addend(int el)
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

    void addbeg(int el)
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
                count++;
                que[front]=el;
            }
            else{
                int i;
                for( i=count;i>0;i--)
                {
                    que[i]=que[i-1];
                }
                que[i]=el;
                count++;
                front--;
                
            }
        }
    }


    int delbeg()
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

    int delend()
    {
        int el=0;
        if(isempty()==1)
        {
            cout<<"Queue underflow .Cannot delete the job"<<endl;
        }
        else
        {
            el=que[rear];
            if(front==rear)
            {
                front=rear=-1;
            }
            else{
                rear--;
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
int main(){
    int ch,item;
    queue d;
    do{
        cout<<"\n1.Add at begin\n2.Add at end\n3.display\n4.Delete from begin\n5.delete from end\n6.Exit";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter element to be insert : ";
                cin>>item;
                d.addbeg(item);
                break;
            case 2:
                cout<<"enter elements at end : ";
                cin>>item;
                d.addend(item);
                break;

            case 3:
                d.display();
                break;

            case 4:
                d.delbeg();
                break;
            case 5:
                d.delend();
                break;
            
            case 6:
                cout<<"Thankyou for using the program";
                break;
            default:
            cout<<"Invalid choice";
                break;
        }


    }while(ch!=6);

return 0;
}