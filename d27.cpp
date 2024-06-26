/* Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format.
3. Only '+', '-', '*' and '/ ' operators are expected.
*/


#include <iostream>
using namespace std;
#define arr_size 20
template <class T>

class stack
{
public:
    int top = -1;
    T arr[arr_size];
    int isempty()
    {
        return (top == -1) ? 1 : 0;
    }
    int isfull()
    {
        return (top >= arr_size) ? 1 : 0;
    }
    void push(T x)
    {
        if (isfull() != 1)
        {
            top++;
            arr[top] = x;
        }
    }
    T pop()
    {
        if (isempty() != 1)
        {
            top--;
            return arr[top + 1];
        }
    }
    T peek()//returns the top most element of the stack
    {
        return arr[top];
    }
};
int priority(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
//to convert 
string in_post(string exp)//infix exp jo input kiya he
{
    char ch;
    string post;//postfix exp store hoga
    stack<char> s;//object create kiya he
    for (int i = 0; i < exp.size(); i++)
    {
        ch = exp[i];//(a+b)
        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (s.peek() != '(')
            {
                post += s.pop();
            }
            s.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while (s.isempty() != 1 && priority(ch) <= priority(s.peek()))
            {
                post += s.pop();
            }
            s.push(ch);
        }
        else
        {
            post += ch;
        }
    }
    while (s.isempty() != 1)
    {
        post += s.pop();
    }
    return post;
}

int check(string post){
    char ch;
    stack<int>s;
    int val[10];
    int c=0,val1,val2,temp;
    for(int i=0;i<post.size();i++){
        ch=post[i];
        if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'){
            cout<<"Enter value for "<<ch<<" ";
            cin>>val[c];
            c++;
        }
    }
    c=0;
    for(int i=0;i<post.size();i++){
        ch=post[i];
        switch(ch){
            case '+':
                val2=s.pop();
                val1=s.pop();
                temp=val1+val2;
                s.push(temp);
                break;
            case '-':
                val2=s.pop();
                val1=s.pop();
                temp=val1-val2;
                s.push(temp);
                break;
            case '*':
                val2=s.pop();
                val1=s.pop();
                temp=val1*val2;
                s.push(temp);
                break;
            case '/':
                val2=s.pop();
                val1=s.pop();
                temp=val1/val2;
                s.push(temp);
                break;
            case ' ':
                break;
            default:
                s.push(val[c]);
                c++;
                break;
        }
    }
    return s.pop();
}
int main(){
    int ch;
    char ch1;
    string exp,a;
    do{
        cout<<" 1)Infix to postfix conversion\n 2)Postfix calculation"<<endl;
        cout<<"enter your choice ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter infix expression ";
            cin>>exp;
            a=in_post(exp);
            cout<<"Postfix expression is "<<a<<endl;
            break;
        case 2:
            cout<<"Calculated value of postfix is "<<check(a)<<endl;
            break;
        default:
            cout<<"Enter valid choice "<<endl;
            break;
        }
        cout<<"Do you want to continue(y/n) : ";
        cin>>ch1;
    }while(ch1=='y'||ch1=='Y');
    return 0;
}