/*Get Max element from the stack */
/*Perform various operations of push, pop, getting max element etc. on the stack according to the choice of the user */

/*Date : 25/01/2022*/
/**************************************************************************/


#include<bits/stdc++.h>
using namespace std;

#define MAX 100

//Declaration ofvariables and functions for performing various operations on stacks
class Stack{
    int top;

public :
    int arr[MAX]; //Maximum size of the stack
    Stack()
    {
        top = -1;
    }
    void push(int x);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    void printStack();
    int getMax();
};

//Push operation to insert an element in a stack
void Stack :: push(int data)
{
    //Check if the stack is full or not
    if(isFull())
        cout << "Stack is already full" << endl;
    ++top;
    arr[top] = data;
}

//Pop operation to remove the element from the stack
int Stack :: pop()
{
    if(top < 0)
    {
        cout << "Stack is already empty!" << endl;
        return 0;
    }
    else
    {
        int ele = arr[top];
        top--;
        return ele;
    } 
}

//Peek operation to return the top element from the stack
int Stack :: peek()
{
    if(top < 0)
    {
        cout << "Stack is already empty!" << endl;
        return 0;
    }
    else
    {
        int ele = arr[top];
        return ele;
    } 
}

//isEmpty operation to check if the stack is empty
bool Stack :: isEmpty()
{
    if(top < 0)
        return true;
    return false;
}

//isFull operation to check if the stack is already full
bool Stack :: isFull()
{
    if(top == (MAX-1))
        return true;
    else
        return false;
}

//printStack operation to print the elements of the Stack
void Stack :: printStack()
{
    cout << "Elements of the Stack are : ";
    for(int i=top;i>=0;i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//getMax operation to print the maximum element of the Stack
int Stack :: getMax()
{
    int maxele = INT_MIN;
    if(top < 0)
    {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            if(maxele < arr[i])
            {
                maxele = arr[i];
            }
        }
    }
    return maxele;
}

int main()
{
    string f;
    cout << "Enter the number of operations you want to perform : ";
    //cin >> n;
    getline(cin,f);
    int n = stoi(f);
    cout << "Query 1 x : Push the element x into stack" << endl;
    cout << "Query 2 : Delete the element present at the top of the stack" << endl;
    cout << "Query 3 : Print the maximum element in the stack" << endl;
    cout << endl;

    class Stack stk;

    string query;
    //for(int i=0;i<n;)
    do
    {
        cout << "Enter the choice of query : ";
        getline(cin,query);

        if(query[0]=='1')
        {
            if(query[1]!=' ' || query.length()<3)
                cout << "Enter the valid choice of query along with required element to push if any!" << endl;
            else
            {
                string temp = query.substr(2);
                int num = stoi(temp);
                stk.push(num);
                n--;
            }
        }
        else if(query[0]=='2')
        {
            stk.pop();
            n--;
        }
        else if(query[0]=='3')
        {
            cout << "Max element of the current stack is : " << stk.getMax() << endl;
            n--;
        }
        else
            cout << "Please enter a valid number of query!" << endl;
    }while(n>0);

    /*stk.push(23);
    stk.push(22);
    stk.push(21);
    stk.push(16);
    stk.printStack();
    cout << stk.pop() << " element is popped out from stack" << endl;
    cout << "Now, the top element of the stack is : " << stk.peek() << endl; 

    cout << "The entire stack at the end of operations is : ";*/
    cout << endl;
    stk.printStack();
    cout << endl;
    return 0;
}