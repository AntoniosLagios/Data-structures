// Max Heap using priority_queue (STL)
#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> maxHeap;  // Max Heap

    maxHeap.push(50);
    maxHeap.push(30);
    maxHeap.push(40);
    maxHeap.push(10);

    cout << "Max Heap Top: " << maxHeap.top() << endl; // Output: 50

    maxHeap.pop();
    cout << "Max Heap Top after pop: " << maxHeap.top() << endl; // Output: 40

    return 0;
}
//Min Heap using priority queue
#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min Heap

    minHeap.push(50);
    minHeap.push(30);
    minHeap.push(40);
    minHeap.push(10);

    cout << "Min Heap Top: " << minHeap.top() << endl; // Output: 10

    minHeap.pop();
    cout << "Min Heap Top after pop: " << minHeap.top() << endl; // Output: 30

    return 0;
}
//Custom Heap using struct and priority_queue
#include <iostream>
#include <queue>

using namespace std;

// Custom structure
struct Job {
    int id;
    int priority;

    // Custom comparator for Min Heap
    bool operator>(const Job& j) const {
        return priority > j.priority;
    }
};

int main() {
    priority_queue<Job, vector<Job>, greater<Job>> jobQueue;  // Min Heap for Jobs

    jobQueue.push({1, 5});
    jobQueue.push({2, 2});
    jobQueue.push({3, 8});

    cout << "Job with Highest Priority: " << jobQueue.top().id << endl; // Output: 2 (lowest priority value)

    return 0;
}
//Manual Heap Implementation (Heapify)
#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    MinHeap h;
    h.push(40);
    h.push(20);
    h.push(30);
    h.push(10);

    cout << "Min Heap Top: " << h.top() << endl; // Output: 10
    h.pop();
    cout << "Min Heap Top after pop: " << h.top() << endl; // Output: 20

    return 0;
}
//Max Heap (Manual Implementation)
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap h;
    h.push(10);
    h.push(40);
    h.push(30);
    h.push(50);

    cout << "Max Heap Top: " << h.top() << endl; // Output: 50
    h.pop();
    cout << "Max Heap Top after pop: " << h.top() << endl; // Output: 40

    return 0;
}
//Kth Largest Element in a Stream using Min Heap (STL)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min Heap
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int num) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop(); // Keep only k largest elements
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {3, 1, 5, 12, 2, 8};
    KthLargest kl(3, nums); // 3rd largest element

    cout << "3rd largest after adding 10: " << kl.add(10) << endl; // Output: 5
    cout << "3rd largest after adding 15: " << kl.add(15) << endl; // Output: 8

    return 0;
}
