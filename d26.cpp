#include<iostream>
#define maxsize 20
using namespace std;
class stack
{
    char st[maxsize];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    int isempty()
    {
        if(top==-1)
        return 1;
        else
        return 0;
    }
    int isfull()
    {
        if(top==maxsize-1)
        return 1;
        else
        return 0;
    }
    
    void push(char el)
    {
        if(isfull()==0)
        {
            top++;
            st[top]=el;
        }
    }

    char pop()
    {
        if(isempty()==0)
        {
            top--;
            return st[top+1];
        }
    }
};
int check(string exp)
{
    char ch;
    stack s;

    for(int i=0;i<=exp.size();i++)
    {
        ch=exp[i];
        if(ch=='(')
        {
            s.push(')');
        }
        else if(ch=='[')
        {
            s.push(']');
        }
        if(ch=='{')
        {
            s.push('}');
        }
        else if(ch==')' || ch=='}' || ch==']')
        {
            if(ch!=s.pop())
            {
                return 0;
                break;
            }
        }
    }
    if(s.isempty()==0)
    {
        return 0;
    }
    return 1;
}
int main()
{
    string exp;
    cout<<"Enter an expression to check its validity"<<endl;
    cin>>exp;
    int res=check(exp);
    if(res==0)
    {
        cout<<"Exprssion is invalid ";
    }
    else
    {
        cout<<"Expression is valid";
    }
}