class Solution {
public:
    int count(int n)
    {
        int count = 0;
        while (n > 0)
        {
            if ((n & 1) == 1) count++;
            n = n >> 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++)
        {
            res.push_back(count(i));
        }
        return res;
    }
};
