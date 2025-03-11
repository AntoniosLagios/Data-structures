//Using std::stack from the STL
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Access the top element
    std::cout << "Top element: " << s.top() << std::endl;

    // Pop elements
    s.pop();
    std::cout << "Top after pop: " << s.top() << std::endl;

    // Check if stack is empty
    if (s.empty())
        std::cout << "Stack is empty\n";
    else
        std::cout << "Stack is not empty\n";

    return 0;
}
//Manually implementing a stack using an array
#define MAX 100

class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool push(int x) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element: " << s.peek() << std::endl;
    s.pop();
    std::cout << "Top after pop: " << s.peek() << std::endl;

    return 0;
}
//Implementing a stack using a inked list

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == nullptr) {
            std::cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element: " << s.peek() << std::endl;
    s.pop();
    std::cout << "Top after pop: " << s.peek() << std::endl;

    return 0;
}
//Reverse a string using a Stack

void reverseString(std::string str) {
    std::stack<char> s;

    for (char ch : str) {
        s.push(ch);
    }

    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }
}

int main() {
    std::string str = "Hello, World!";
    std::cout << "Reversed String: ";
    reverseString(str);
    std::cout << std::endl;
    return 0;
}
//Checking for balanced parentheses using a stack

bool isBalanced(std::string expr) {
    std::stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    std::string expr = "{[()]}";
    if (isBalanced(expr))
        std::cout << "Balanced\n";
    else
        std::cout << "Not Balanced\n";
    return 0;
}
//Implementing two stacks in one array
#define MAX 100

class TwoStacks {
private:
    int arr[MAX];
    int top1, top2;

public:
    TwoStacks() {
        top1 = -1;
        top2 = MAX;
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            std::cout << "Stack Overflow\n";
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            std::cout << "Stack Overflow\n";
        }
    }

    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        }
        std::cout << "Stack Underflow\n";
        return -1;
    }

    int pop2() {
        if (top2 < MAX) {
            return arr[top2++];
        }
        std::cout << "Stack Underflow\n";
        return -1;
    }
};

int main() {
    TwoStacks ts;
    ts.push1(10);
    ts.push2(20);
    ts.push1(30);
    ts.push2(40);

    std::cout << "Popped from Stack1: " << ts.pop1() << std::endl;
    std::cout << "Popped from Stack2: " << ts.pop2() << std::endl;

    return 0;
}
