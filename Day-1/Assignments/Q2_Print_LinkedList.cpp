/*Print Linked List*/

/*This is a good way to get some practise with traversing a linked list. Print each node's data element, one per line, given a pointer to the head node of a linked list. There is nothing to output if the head reference is null (meaning the list is empty).

Create a function to print LinkedLists.

The parameter(s) for printLinkedList are as follows:
SinglyLinkedList The head of the list is referred to as the node head.
Print the value of each node in a new line

Input format
The first line of input contains p, which is the number of linked list entries. The data values for each node are contained in the next p lines, each with one element.


Complete the  printlinkedlist  in any programming language or your choice or you may write sudo code for the same

Constraints
1<=P<=1000
1<=list[i]<=1000 where list [i] is the ith element of the linked list

**********************************************************************/


#include<bits/stdc++.h>
using namespace std;

//Individual nodes of a linked list
class Node {
    public:
        int value;
        Node* next;

        Node(int node_value)
        {
            this->value = node_value;
            this->next = NULL;
        }
};

//Class to implement various functions of a linked list
class LinkedList {
    public:
        Node* head;
        Node* tail;

        LinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }

        //Function to indert new node in a linked list with various values
        void add_node(int node_value)
        {
            Node* node = new Node(node_value);
            if(this->head==NULL)
                this->head = node;
            else
                this->tail->next = node;

            this->tail = node;
        } 
};

//Function to print the entire LinkedList
void printLinkedList(Node* head)
{
    //Check if the list is empty
    if(head==NULL)
    {
        cout <<"The list is empty" << endl;
        return;
    }

    //If the list is not empty, print the entire list
    cout << "The Linked List is as follows : ";
    while(head!=NULL)
    {
        int temp = head->value;
        cout << temp;
        head = head->next;
        if(head!=NULL)
            cout << " -> ";
    }
    cout << endl;
}

int main()
{
    //Making a new list for allocating the memory
    LinkedList* llist = new LinkedList();
    int lcnt = 0;
    cout << "Enter the size of linked list : ";
    cin >> lcnt;

    cout << "Enter the values of linkedlist : ";
    for(int i=0;i<lcnt;i++)
    {
        int data;
        cin >> data;
        llist->add_node(data);
    }

    printLinkedList(llist->head);
    return 0;
}