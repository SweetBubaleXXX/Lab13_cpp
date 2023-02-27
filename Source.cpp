#include <iostream>
#include <iomanip>

#define INSERT_VALUE 33

using namespace std;

struct Node
{
    int value = 0;
    Node* next = nullptr;

    Node(Node* nextNode = nullptr)
    {
        this->next = nextNode;
    }

    Node(int value, Node* nextNode = nullptr)
    {
        this->value = value;
        this->next = nextNode;
    }
};

struct Stack
{
    Node* top = nullptr;

    int getSize()
    {
        return size;
    }

    void push(int value)
    {
        top = new Node(value, top);
        size++;
    }

    void insertAfter(int value, Node* curNode)
    {
        curNode->next = new Node(value, curNode->next);
        size++;
    }

    void pop()
    {
        Node* nodeToDelete = top;
        top = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }

    void clear()
    {
        while (getSize()) pop();
    }

    void print()
    {
        int rowWidth = 11;
        Node* curNode = top;
        cout << "-----------" << '\n';
        cout.setf(ios::right);
        while (curNode)
        {
            if (curNode->value == INSERT_VALUE)
                cout << "\033[4m";
            else
                cout << "\033[0m";
            cout << setw(rowWidth) << curNode->value << '\n';
            curNode = curNode->next;
        }
        cout << "===========" << endl;
    }

    Node* findMax()
    {
        if (!top) return nullptr;
        Node* maxNode = top;
        Node* curNode = top->next;
        while (curNode)
        {
            if (curNode->value > maxNode->value) maxNode = curNode;
            curNode = curNode->next;
        }
        return maxNode;
    }

private:
    int size = 0;
};

void fillStack(Stack*, int);

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    if (cin.fail() || n < 1)
    {
        cout << "Invalid number" << endl;
        return 1;
    }
    cin.clear();
    cin.ignore(INT16_MAX, '\n');

    Stack* stack = new Stack();
    fillStack(stack, n);
    cout << "Size: " << stack->getSize() << endl;
    stack->print();

    auto maxElem = stack->findMax();
    stack->insertAfter(INSERT_VALUE, maxElem);
    cout << "Size: " << stack->getSize() << endl;
    stack->print();

    stack->clear();

    return 0;
}

void fillStack(Stack* stack, int numberOfElements)
{
    int value;
    for (int i = 0; i < numberOfElements; i++)
    {
        cout << "Push element << ";
        cin >> value;
        stack->push(value);
    }
    cin.clear();
    cin.ignore(INT16_MAX, '\n');
}
