//Basic implementation of Stack and various operations that can be performed on Stacks using arrays

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

int main()
{
    class Stack stk;
    stk.push(23);
    stk.push(22);
    stk.push(21);
    stk.push(16);
    stk.printStack();
    cout << stk.pop() << " element is popped out from stack" << endl;
    cout << "Now, the top element of the stack is : " << stk.peek() << endl;
    stk.printStack();
    cout << endl;
    return 0;
}