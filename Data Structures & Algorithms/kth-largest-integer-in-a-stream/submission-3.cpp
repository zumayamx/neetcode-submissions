#include <iostream>
#include <vector>
using namespace std;

/*
 * I think one approach could be to use a heap, specifically a min
 * heap, because in each call we need to know the min number from
 * a top of k numbers, so that k defines the size of the heap.
 *
 * I would like to go more deep in the implementation of add
 * function, because it needs to do some operations,
 * when it recieves a new value, that value needs to be compared
 * with the top of the heap (the kth largest integer so far), if the number
 * is less than o equal the top, it doesn't even go into the top
 * of the k largest numbers, but if it is greater, it goes into
 * the top, so is added to the heap. But we need to remove one element first
 * to keep the size of the heap equals to k. That element is the top
 * of the heap (the min element between the top largest k elements). Then
 * we can insert the new element and return the top (the kth largets element).
 *
 */

class MinHeap {
    vector<int> heap;

   private:
    void push_(int val) {
        heap.push_back(val);
        int i = (int)heap.size() - 1;
        while (i / 2 > 0 && heap[i] < heap[i / 2]) {
            int tmp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = tmp;
            i = i / 2;
        }
        cout << "[push] val=" << val << " heap=[";
        for (int x : heap) cout << x << " ";
        cout << "] size=" << size_() << "\n";
    }

    void pop_() {
        if ((int)heap.size() == 1) return;
        if ((int)heap.size() == 2) {
            heap.pop_back();
            return;
        }

        heap[1] = heap.back();
        heap.pop_back();

        int i = 1;
        while (i * 2 < (int)heap.size()) {
            if (i * 2 + 1 < (int)heap.size() && heap[i * 2 + 1] < heap[i * 2] &&
                heap[i * 2 + 1] < heap[i]) {
                int tmp = heap[i];
                heap[i] = heap[i * 2 + 1];
                heap[i * 2 + 1] = tmp;
                i = i * 2 + 1;
            }
            else if (heap[i * 2] < heap[i]) {
                int tmp = heap[i];
                heap[i] = heap[i * 2];
                heap[i * 2] = tmp;
                i = i * 2;
            } else {
                break;
            }
        }
    }

    int top_() {
        if ((int)heap.size() > 1)
            return heap[1];
        else
            return -1001;
    }

    int size_() { return (int)heap.size() - 1; }

   public:
    MinHeap() { heap.push_back(0); }
    void push(int val) { push_(val); }
    void pop() { return pop_(); }
    int top() { return top_(); }
    int size() { return size_(); }
};
class KthLargest {
    int k;
    vector<int>& nums;
    MinHeap* minHeap;

   private:
    void insert(int val) {
        int size = minHeap->size();
        if (size < k)
            minHeap->push(val);
        else {
            if (val > minHeap->top()) {
                minHeap->pop();
                minHeap->push(val);
            }
        }
    }

   public:
    KthLargest(int k, vector<int>& nums) : k(k), nums(nums) {
        minHeap = new MinHeap();
        for (int& e : nums) {
            insert(e);
        }
    }

    int add(int val) {
        insert(val);
        return minHeap->top();
    }
};
