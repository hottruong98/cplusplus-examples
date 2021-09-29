#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> pq;
    public:
        bool isEmpty() {
            return pq.size()==0;
        }
        int getSize() {
            return pq.size();
        }
        int getMin() {
            if(!isEmpty()) {
                return pq.at(0);
            }
            else {
                return -1; // priority queue is empty
            }
        }
        void insert(int data) {
            pq.push_back(data);
            int childIndex = pq.size() - 1;
            while(childIndex > 0) {
                int parentIndex = (childIndex - 1) / 2;
                if(pq[childIndex] < pq[parentIndex]) {
                    swap(pq[childIndex], pq[parentIndex]);
                    childIndex = parentIndex;
                }
                else {
                    break;
                }   
            }
        }
        int removeMin() {
            if(isEmpty()) {
                return -1; // Queue is empty
            }
            int minValue = pq[0];
            // Swap min and the last
            swap(pq[0], pq[pq.size() - 1]);
            // Remove min
            pq.pop_back();
            // Reorder the queue
            int size = pq.size();
            int parentIndex = 0;
            int minIndex = parentIndex;
            while(size > 0) {
                int leftChildIndex = 2 * parentIndex + 1;
                int rightChildIndex = 2 * parentIndex + 2;
                if(leftChildIndex < size && pq[leftChildIndex] < pq[minIndex]) {
                    minIndex = leftChildIndex;
                }
                if(rightChildIndex < size && pq[rightChildIndex] < pq[minIndex]) {
                    minIndex = pq[leftChildIndex] < pq[rightChildIndex] ? leftChildIndex : rightChildIndex;
                }
                if(minIndex == parentIndex) {
                    break;
                }
                // Down Heapify
                swap(pq[parentIndex], pq[minIndex]);
                parentIndex = minIndex;
            }
            return minValue;
        }
        void print() {
            for(int i = 0; i < pq.size(); i++) {
                cout << pq[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    vector<int> a = {12, 6, 5, 100, 1, 9, 0, 14};
    a = {100, 10, 15, 4, 17, 21, 67};
    PriorityQueue myQueue;
    for(int i = 0; i < a.size(); i++) {
        myQueue.insert(a[i]);
    }
    myQueue.print();
    cout << myQueue.getMin() << endl;
    while(!myQueue.isEmpty()) {
        cout << myQueue.removeMin() << " "; // also HEAP SORT O(NlogN)
    }
    cout << endl;
    return 0;
}

