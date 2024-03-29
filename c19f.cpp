#include <iostream>
using namespace std;

// node defination
class node
{
public:
    string prn;
    string name;
    node *next;
    // constructors
    node()
    {
        prn = "";
        name = "";
        next = NULL;
    }
    node(string prn, string name)
    {
        this->prn = prn;
        this->name = name;
        this->next = NULL;
    }
};


int member_count(node *);
void display_list(node *head)
{
    node *temp = head;

    if (member_count(head) >= 1)
    {
        int count = 1;//display the position of each member
        while (temp != NULL)
        {
            cout << count << ". PRN: " << temp->prn;
            cout << " NAME: " << temp->name << endl;
            temp = temp->next;
            count++;
        }
    }
    else
    {
        cout << "Empty List" << endl;
    }
}

// fucntion to add president to list
void add_president(node* head, string prn, string name)
{
    node* pre = new node(prn, name);
    pre->next = head;
    head = pre;
}

void add_secretary(node *head, string prn, string name)
{
    node *sec = new node(prn, name);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = sec;
    sec->next=NULL;
}

void add_member(node *head, string prn, string name)
{
    node *mem = new node(prn, name);
    node *temp = head;

    while (temp->next->next != NULL)
    /*This while loop is used to traverse the linked list until temp reaches the second-to-last node (temp->next->next == NULL).
     The loop condition ensures that temp stops at the node before the last one.*/
    {
        temp = temp->next;
    }
    mem->next = temp->next;
    temp->next = mem;
}

int member_count(node *head)
{
    node *temp = head;
    // temp = temp->next;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void delete_president(node *&head)
{
    node *tofree = head;
    head = head->next;
    delete tofree;
}
void delete_secretory(node *head)
{
    node *temp = new node;
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *tofree = temp->next;
    temp->next = NULL;
    delete tofree;
}
void delete_member(node *head, string prn)
{
    node *temp = new node;
    temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->prn == prn)
        {
            node *tofree = temp->next;
            temp->next = temp->next->next;
            delete tofree;
        }
        temp = temp->next;
    }
}

node *start()
{
    string prn, name;
    cout << "Enter Details for Class " << endl;

    cout << "Enter the PRN of President:";
    cin >> prn;
    cout << "Enter the Name of President:";
    cin>>name;
    node *list = new node(prn, name);

    cout << "Enter the PRN of Secretory:";
    cin >> prn;
    cout << "Enter the Name of Secretory:";
   cin>>name;
    add_secretary(list, prn, name);

    return list;
}
int main()
{
   node* list1 = start();
    int ch;
    string prn,name;
    cout << "\nWelcome to the Pinnacle Club. Choose from the following to perform an operation:\n" << endl;
    cout << "1. Add president" << endl;
    cout << "2. Add secretary" << endl;
    cout << "3. Add a new member" << endl;
    cout << "4. Remove president" << endl;
    cout << "5. Remove secretary" << endl;
    cout << "6. Remove club members" << endl;
    cout << "7. View number of members part of the club" << endl;
    cout << "8. View members of the club" << endl;
    cout<<"9.Exit";

    do
    {
    cout<<"\n Enter your choice\n";
    cin>>ch;


    switch (ch)
    {
        case 1:
                cout << "Enter the PRN of President:";
                cin >> prn;
                cout << "Enter the Name of President:";
                cin>>name;
                add_president(list1, prn, name);
                cout << "President added sucessfully to Class " << endl;
                break;
        case 2:
                cout << "Enter the PRN of Secretory:";
                cin >> prn;
                cout << "Enter the Name of Secretory:";
                cin>>name;
                add_secretary(list1, prn, name);
                cout << "Secretory added sucessfully to Class "  << endl;
                break;

       case 3:
                cout << "Enter the PRN:";
                cin >> prn;
                cout << "Enter the Name :";
                cin>>name;
                add_member(list1, prn, name);
                cout << "Member added sucessfully to Class " << endl;
                break; 

        case 4:
                delete_president(list1);
                cout << "President deleted sucessfully from Class "  << endl;
                break;
            
        case 5:
                delete_secretory(list1);
                cout << "Secretory deleted sucessfully from Class " << endl;
                break;
        case 6:
                cout << "Enter PRN to delete:";
                cin >> prn;
                delete_member(list1, prn);
                cout << "Member deleted sucessfully from Class " << endl;
                break;
        case 7:
            cout << "\nMembers in list  are " << member_count(list1) << endl;
            break;
        case 8:
        display_list(list1);
        break;
        case 9:
        cout<<"Thankyou for using the program";
        break;
        default:
        cout<<"Invalid choice";
        break;

    }
    }
    while(ch!=9);
    return 0;
}
    