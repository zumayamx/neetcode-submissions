class MaxHeap {
    vector<int> heap_;

   private:
    void push_(int val) {
        heap_.push_back(val);
        int i = (int)heap_.size() - 1;
        while (i / 2 > 0 && heap_[i] > heap_[i / 2]) {
            int tmp = heap_[i];
            heap_[i] = heap_[i / 2];
            heap_[i / 2] = tmp;
            i = i / 2;
        }
    }
    void pop_() {
        if ((int)heap_.size() == 1) return;
        if ((int)heap_.size() == 2) {
            heap_.pop_back();
            return;
        }

        heap_[1] = heap_.back();
        heap_.pop_back();

        int i = 1;
        while (i * 2 < (int)heap_.size()) {
            if (i * 2 + 1 < (int)heap_.size() && heap_[i * 2 + 1] > heap_[i * 2] &&
                heap_[i * 2 + 1] > heap_[i]) {
                int tmp = heap_[i];
                heap_[i] = heap_[i * 2 + 1];
                heap_[i * 2 + 1] = tmp;
                i = i * 2 + 1;
            } else if (heap_[i * 2] > heap_[i]) {
                int tmp = heap_[i];
                heap_[i] = heap_[i * 2];
                heap_[i * 2] = tmp;
                i = i * 2;
            } else
                break;
        }
    }

    void heapify_(vector<int>& arr) {
        if (arr.empty()) return;
        arr.push_back(arr[0]);
        heap_ = arr;

        int curr = (int)arr.size() - 1 / 2;
        while (curr > 0) {
            int i = curr;
            while (i * 2 < (int)heap_.size()) {
                if (i * 2 + 1 < (int)heap_.size() && heap_[i * 2 + 1] > heap_[i * 2] &&
                    heap_[i * 2 + 1] > heap_[i]) {
                    int tmp = heap_[i];
                    heap_[i] = heap_[i * 2 + 1];
                    heap_[i * 2 + 1] = tmp;
                    i = i * 2 + 1;
                } else if (heap_[i * 2] > heap_[i]) {
                    int tmp = heap_[i];
                    heap_[i] = heap_[i * 2];
                    heap_[i * 2] = tmp;
                    i = i * 2;
                } else
                    break;
            }
            curr--;
        }
    }

    int top_() {
        if ((int)heap_.size() > 1)
            return heap_[1];
        else
            return 0;
    }

    int size_() { return (int)heap_.size() - 1; }

   public:
    MaxHeap() { heap_.push_back(0); }
    void push(int val) { push_(val); }
    void pop() { pop_(); }
    void heapify(vector<int>& arr) { heapify_(arr); }
    int top() { return top_(); }
    int size() { return size_(); }
};

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        MaxHeap* maxHeap = new MaxHeap();
        maxHeap->heapify(nums);
        for (int i = 1; i < k; i++)
        {
            maxHeap->pop();
        }
        return maxHeap->top();
    }
};
