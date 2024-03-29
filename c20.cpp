#include <iostream>
#include<stdlib.h>
using namespace std;

class node
{
    public:
    node* next;
    node* prev;
    int seat;
    string id;
    int status;
};
class cinemax
{
public:

node* tail,* temp,* head;

cinemax()
{
    head=NULL;
}

void create_list();
void display();
void book();
void cancel();
void avail();

};

void cinemax::create_list()
{
    int i=1;
    temp=new node;
    temp->seat=1;
    temp->status=0;
    temp->id="null";
    head=tail=temp;
    for(int i=2;i<=70;i++)
    {
        node* p;
        p=new node;
        p->seat=i;
        p->status=0;
        p->id="null";
        tail->next=p;
        p->prev=tail;
        tail=p;
        tail->next=head;
        head->prev=tail;
    }
}
void cinemax::display()
{
    int r=1;
    node* temp;
    temp=head;
    int count=0;
    cout<<"\n-------------------------------------------------\n";
    cout<<"Screen this way";
    cout<<"\n--------------------------------------------------\n";
    while(temp->next!=head)
    {
        if(temp->seat/10==0)
        {
            cout<<"S0"<<temp->seat<<":";
        }
        else
        {
            cout<<"S"<<temp->seat<<":";
        }

        if(temp->status==0)
        {
            cout<<"|___|";
        }
        else
        {
            cout<<"|_B_|";
        }

        count++;

        if(count%7==0)
        {
            cout<<endl;
            r=r+1;
        }

        temp=temp->next;

    }

    cout<<"S"<<temp->seat<<":";
    if(temp->status==0)
        {
            cout<<"|___|";
        }
        else
        {
            cout<<"|_B_|";
        }
    
}
void cinemax::book()
{
    int x;
    string y;
    label:
    cout<<"\nEnter the seat number to be booked\n";
    cin>>x;
    cout<<"\nEnter the id\n";
    cin>>y;
    if(x<1 || x>70)
    {
        cout<<"enter the correct seat number"<<endl;
        goto label;
    }
    node* temp;
    temp=head;
    while(temp->seat!=x)
    {
        temp=temp->next;
    }
    if(temp->status==1)
    {
        cout<<"Seat is already booked"<<endl;
    }
    else
    {
        temp->status=1;
        temp->id=y;
        cout<<"Seat"<<x<<" booked!!\n";
    }
}
void cinemax::cancel()
{
    int x;
    string y;
    label1:
    cout<<"\nEnter the seat number to be cancelled\n";
    cin>>x;
    cout<<"\nEnter the id\n";
    cin>>y;
    if(x<1 || x>70)
    {
        cout<<"enter the correct seat number"<<endl;
        goto label1;
    }
    node* temp;
    temp=head;
    while(temp->seat!=x)
    {
        temp=temp->next;
    }
    if(temp->status==0)
    {
        cout<<"Seat is not booked"<<endl;
    }
    else
    {
        if(temp->id==y)
        {
        temp->status=0;
        
        cout<<"Seat"<<x<<" cancelled!!\n";
        }
        else
        cout<<"Seat cannot be cancelled!!!\n";
    }
}

void cinemax::avail()
{
    int r=1;
    node* temp;
    temp=head;
    int count=0;
    cout<<"\n-------------------------------------------------\n";
    cout<<"Screen this way";
    cout<<"\n--------------------------------------------------\n";
    while(temp->next!=head)
    {
        if(temp->seat/10==0)
        {
            cout<<"S0"<<temp->seat<<":";
        }
        else
        {
            cout<<"S"<<temp->seat<<":";
        }

        if(temp->status==0)
        {
            cout<<"|___|";
        }
        else
        {
            cout<<"     ";
        }

        count++;

        if(count%7==0)
        {
            cout<<endl;
            r=r+1;
        }

        temp=temp->next;

    }

    cout<<"S"<<temp->seat<<":";
    if(temp->status==0)
        {
            cout<<"|___|";
        }
        else
        {
            cout<<"     ";
        }
    
}

int main()
{
    int ch;
    cout<<"\n------------------------------------------------\n";
    cout<<"WELCOME TO CINEMAX THEATRE";
    cout<<"\n-------------------------------------------------\n";
    cinemax obj;
    obj.create_list();
    do
    {
    cout<<"\n\n***************MENU*********************\n"<<endl;
    cout<<"\n1)current seat status";
    cout<<"\n2)book ";
    cout<<"\n3)cancel";
    cout<<"\n4)availibiliy";
    cout<<"\n5)exit";
    cout<<"\nEnter your choice"<<endl;
    cin>>ch;

    switch(ch)
    {
        case 1:
        obj.display();
        break;
        case 2:
        obj.book();
        break;
        case 3:
        obj.cancel();
        break;
        case 4:
        obj.avail();
        break;
        case 5:
        cout<<"Thankyou for using the program"<<endl;
        break;
        default:
        cout<<"Invalid choice"<<endl;
    }
    }while(ch!=5);
    return 0;
}

