// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
private:
    void merge(vector<Pair>& pairs, int start, int middle, int end)
    {   
        vector<Pair> sorted;
        int p1 = start;
        int p2 = middle + 1;
        while (p1 <= middle && p2 <= end)
        {
            if (pairs[p1].key <= pairs[p2].key)
            {
                sorted.push_back(pairs[p1]);
                p1++;
            }
            else
            {
                sorted.push_back(pairs[p2]);
                p2++;
            }
        }

        while (p1 <= middle) sorted.push_back(pairs[p1++]);
        while (p2 <= end) sorted.push_back(pairs[p2++]);

        for (int i = 0; i < (int)sorted.size(); i++)
        {
            pairs[start + i] = sorted[i];
        }
    }
    void mergeSortHelper(vector<Pair>& pairs, int start, int end)
    {
        if (end - start + 1 <= 1) return;
        
        int middle = (start + end) / 2;
        mergeSortHelper(pairs, start, middle); // 0 - 2 (izq), 0 - 1 (izq), 2 - 2 (der)
        mergeSortHelper(pairs, middle + 1, end); // 3 - 4 (der), 3 - 3 (izq), 4 - 4 (der)

        merge(pairs, start, middle, end);
    }
public:
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        mergeSortHelper(pairs, 0, (int)pairs.size() - 1);
        return pairs;
    }
};
