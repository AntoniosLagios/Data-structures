//Queue Operations Using std::queue
#include <iostream>
#include <queue>
int main() {
    std::queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front element: " << q.front() << std::endl;
    std::cout << "Back element: " << q.back() << std::endl;

    // Dequeue elements
    q.pop();
    std::cout << "After popping, front element: " << q.front() << std::endl;

    return 0;
}
//Queue with Custom Data Type (Struct)
struct Person {
    std::string name;
    int age;
};

int main() {
    std::queue<Person> q;

    // Enqueue custom objects
    q.push({"Alice", 25});
    q.push({"Bob", 30});

    // Access front element
    std::cout << "Front: " << q.front().name << " (" << q.front().age << " years old)" << std::endl;

    // Remove element
    q.pop();
    std::cout << "After popping, new front: " << q.front().name << std::endl;

    return 0;
}
//Priority Queue (std::priority_queue)
int main() {
    std::priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(20);
    // Elements will be retrieved in descending order
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
//Min-Heap Priority Queue
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    minHeap.push(30);
    minHeap.push(10);
    minHeap.push(20);

    // Elements will be retrieved in ascending order
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}
// Implementing a Queue Using std::deque
#include <deque>
int main() {
    std::deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    std::cout << "Front: " << dq.front() << std::endl;
    std::cout << "Back: " << dq.back() << std::endl;

    dq.pop_front();
    std::cout << "After popping, front: " << dq.front() << std::endl;

    return 0;
}
//Implementing a Queue Using a Custom Linked List
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node *front, *rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (!front) return;
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }

    int peek() {
        return front ? front->data : -1;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front: " << q.peek() << std::endl;
    q.dequeue();
    std::cout << "Front after dequeue: " << q.peek() << std::endl;

    return 0;
}
//Circular Queue Implementation (Array-Based)
#include <iostream>
#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue() : front(0), rear(-1), count(0) {}

    bool isFull() { return count == SIZE; }
    bool isEmpty() { return count == 0; }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % SIZE;
        count--;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    
    std::cout << "Front: " << q.peek() << "\n";
    q.dequeue();
    q.enqueue(60);
    
    std::cout << "Front after dequeue: " << q.peek() << "\n";
    return 0;
}
// Implementing a Queue Using Two Stacks
#include <iostream>
#include <stack>

class QueueUsingStacks {
private:
    std::stack<int> s1, s2;

public:
    void enqueue(int value) {
        s1.push(value);
    }

    void dequeue() {
        if (s1.empty() && s2.empty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int peek() {
        if (s1.empty() && s2.empty()) return -1;
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front: " << q.peek() << "\n";
    q.dequeue();
    std::cout << "Front after dequeue: " << q.peek() << "\n";

    return 0;
}
//Thread-Safe Queue Using std::mutex
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>

class ThreadSafeQueue {
private:
    std::queue<int> q;
    std::mutex mtx;

public:
    void enqueue(int value) {
        std::lock_guard<std::mutex> lock(mtx);
        q.push(value);
    }

    void dequeue() {
        std::lock_guard<std::mutex> lock(mtx);
        if (!q.empty()) q.pop();
    }

    int peek() {
        std::lock_guard<std::mutex> lock(mtx);
        return q.empty() ? -1 : q.front();
    }
};

void producer(ThreadSafeQueue& q) {
    for (int i = 0; i < 5; i++) {
        q.enqueue(i);
        std::cout << "Produced: " << i << "\n";
    }
}

void consumer(ThreadSafeQueue& q) {
    for (int i = 0; i < 5; i++) {
        std::cout << "Consumed: " << q.peek() << "\n";
        q.dequeue();
    }
}

int main() {
    ThreadSafeQueue q;
    std::thread t1(producer, std::ref(q));
    std::thread t2(consumer, std::ref(q));

    t1.join();
    t2.join();

    return 0;
}

