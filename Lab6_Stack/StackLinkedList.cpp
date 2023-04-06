#include <iostream>
#include <chrono>
using namespace std;
using  namespace std::chrono;

// creating a class for node
class Node
{
    public:   
        int value;
        Node* next; // pointer to the next node

        Node(int value)   // to construct a node with the input value
        {
            this->value = value;
            this->next = NULL;
        }
};

// creating a class for stack
class Stack
{
    private:
        Node* top; // pointer to the top node
    
    public:
        Stack()
        {
            top = NULL; // initially top points to null
        }

        void Push(int num)
        {
            Node* tempNode = new Node(num); // creating a temporary node to store the value
            tempNode->next = top; // pointing the current node as the next node of the new node
            top = tempNode; // pointing the new node as the top
        }

        void Pop()
        {
            if(top == NULL) // to check if the stack is empty
            {
                cout<<"Stack is empty!"<<endl;
            }
            else
            {
                Node* tempNode = top; // creating a temporary pointer to the top
                top = top->next;  // pointing the second node as the new top node
                cout<<"Popped "<<tempNode->value<<endl;
            }
        }

        bool isEmpty()
        {
            return (top == NULL); // to check if the stack is empty
        }

        void StackTop()
        {
            if(top == NULL) // to check if the stack is empty
            {
                cout<<"Stack is empty!"<<endl;
            }
            else
            {
                cout<<"Top value is "<<top->value<<endl; // printing the current value that is pointed by top
            }
        }

        void Display()
        {
            Node* tempNode = top; // initially tempNode pointing the top node
            while(tempNode != NULL) // checking if the stack is not empty
            {
                cout<<tempNode->value<<" ";
                tempNode = tempNode->next; // tempNode pointing the next node 
            }
            cout<<endl;
        }
};

int main()
{
    auto start = high_resolution_clock::now();

    Stack stackLinkedList;

    for(int i=0; i<10; i++)
    {
        stackLinkedList.Push(rand() % 100);
    }

    stackLinkedList.Display();

    for(int i=0; i<5; i++)
    {
        stackLinkedList.Pop();
    }

    stackLinkedList.Display();

    for(int i=0; i<5; i++)
    {
        stackLinkedList.Push(rand() % 100);
    }

    stackLinkedList.Display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken is: "<< duration.count() << endl;
}