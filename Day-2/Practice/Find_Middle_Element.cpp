//To find the middle element of the linked list while traversing 

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

//Function to find the middle element of the linked list 
int middleElement(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next)
    {
        //One pointer reaches to the end while the other pointer at the same time reaches half the length of the linked list 
        //And is the middle element
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->value;
}

int main()
{
    //Making a new list for allocating the memory
    LinkedList* llist = new LinkedList();
    int lcnt = 0;
    cout << endl;
    cout << "Enter the size of linked list : ";
    cin >> lcnt;
    if(lcnt==0)
    {
        cout << "The linked list is empty" << endl;
        cout << endl;
        return 0;
    }

    cout << "Enter the values of linkedlist : ";
    for(int i=0;i<lcnt;i++)
    {
        int data;
        cin >> data;
        llist->add_node(data);
    }

    int ans = middleElement(llist->head);
    cout << "Middle element of the linked list is : " << ans << endl;
    cout << endl;
    return 0;
}