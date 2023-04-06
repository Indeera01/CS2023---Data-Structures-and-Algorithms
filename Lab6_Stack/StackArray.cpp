#include <iostream>
#include <chrono>
using namespace std;
using  namespace std::chrono;

#define size 10  // max size of the stack

// creating a class for stack
class Stack
{
    private:
        int top;   // index of the top element
        int stack_array[size];  // creating a array to implement the stack

    public:
        Stack() 
        {
            top = -1; // initially makiing the top index as -1
        }

        void Push(int num) 
        {
            if(top >= size-1)  // checking if the array used is full
            {
                cout<<"Stack is full!"<<endl;
            }
            else
            {
                stack_array[++top] = num; // incrementing the top and assigning the new value
            }
        }

        void Pop()
        {
            if(top < 0)  // checking if the stack is empty
            {
                cout<<"Stack is empty!"<<endl;
            }
            else
            {
                int num = stack_array[top--]; // assigning the value in the top of the stack to the variable num
                cout<<"Popped "<<num<<endl;
            }
        }

        bool isEmpty()
        {
            return (top<0); // checking if the stack is empty 
        }

        bool isFull()
        {
            return (top >= size-1); // checking if the stack is full
        }

        void StackTop()
        {
            if(top < 0) // checking if stack is empty
            {
                cout<<"Stack is empty!"<<endl;
            }
            else
            {
                int num = stack_array[top];  // assigning the value of top to the num variable
                cout<<"Top is "<<num<<endl;
            }
        }

        void Display()
        {
            if(top < 0) // checking if the stack is empty
            {
                cout<<"Stack is empty!"<<endl;
            }
            else
            {
                for(int i=top; i>=0; i--) // iterating through the array to print the elements in the stack
                {
                    cout<<stack_array[i]<<" ";
                }
            }
            cout<<endl;
        }
};

int main()
{
    auto start = high_resolution_clock::now();

    Stack stackArray;

    for(int i=0; i<10; i++)
    {
        stackArray.Push(rand() % 100);
    }

    stackArray.Display();

    for(int i=0; i<5; i++)
    {
        stackArray.Pop();
    }
    
    stackArray.Display();

    for(int i=0; i<5; i++)
    {
        stackArray.Push(rand() % 100);
    }

    stackArray.Display();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken is: "<< duration.count() << endl;
}


