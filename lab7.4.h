/*Header file program*/
#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node * next;
    Node(char value): data(value), next(nullptr){}
};

class StackSLL{
private:
    Node* top;
public:
    StackSLL(); 
    bool isEmpty();
    void Push(char value);
    void display();
    char Pop();
    char Peek();
};

// Constructor
StackSLL::StackSLL()
{
    top = nullptr;
}

// Function to check if the stack is empty or not
bool StackSLL::isEmpty()
{
    return top == nullptr;
}

// Function to Push the element in the stack
void StackSLL::Push(char value)
{
    Node* newnode = new Node(value);
    newnode->next = top;
    top = newnode;
    cout << value << " pushed to the stack.\n";
}

// Function to Pop the element from the Stack
char StackSLL::Pop()
{
    if (isEmpty()){
        cout << "Stack is empty.\n";
        return '\0';
    }
    char popV = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    cout << popV << " popped from the stack.\n";
    return popV;
}

// Function to Peek or get the top element from the stack
char StackSLL::Peek()
{
    if (isEmpty()){
        cout << "Stack is empty.\n";
        return '\0';
    }
    return top->data;
}

// Function to display all the elements of the stack
void StackSLL::display()
{
    if (isEmpty()){
        cout << "Stack is empty.\n";
        return;
    }
    Node* current = top;
    cout << "Stack Element: ";
    while(current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}