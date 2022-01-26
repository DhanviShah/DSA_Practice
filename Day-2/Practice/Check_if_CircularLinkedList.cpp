//To check if the linked list is circular linked list 

//The only constraint is that the user needs to enter all the unique values in the linked list, 
//Because, as the linked list is formed according to the user inputs the value, the below code checks if any node have same value 
//as the head value, then it detects as a Circular Linked List!

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

//isCircular function to check if the linked list formed is a Circular Linked List
int isCircular(Node* head)
{
    if(head==NULL || head->next==NULL)
        return 1;
    
    Node* temp = head->next;
    //The temp node is pointed to the next node until the value of the temp node equals the head node value or temp node points to NULL
    while(temp && temp->value!=head->value)
        temp = temp->next;

    if(temp && temp->next)
        return 0;
    else if(temp)
        return 1;
    return 0;
}

int main()
{
    //Making a new list for allocating the memory
    LinkedList* llist = new LinkedList();
    int lcnt = 0;
    cout << "Enter the size of linked list : ";
    cin >> lcnt;
    if(lcnt==0)
    {
        cout << "Yes, the linked list is a circular linked list" << endl;
        return 0;
    }

    cout << "Enter the values of linkedlist : ";
    for(int i=0;i<lcnt;i++)
    {
        int data;
        cin >> data;
        llist->add_node(data);
    }

    int ans = isCircular(llist->head);
    //cout << ans << endl;
    if(ans==1)
        cout << "Yes, the linked list is a circular linked list" << endl;
    else
        cout << "No, the linked list is not a circular linked list" << endl;

    return 0;
}