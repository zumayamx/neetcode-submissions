class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int size = (int)s.size();
        int maxLen = INT_MIN;
        unordered_set<char> ocurr;
        int L = 0;

        for (int R = 0; R < size; R++) {
            while (ocurr.find(s[R]) != ocurr.end()) {
                ocurr.erase(s[L]);
                L++;
            }
            ocurr.insert(s[R]);
            maxLen = max(maxLen, R - L + 1);
        }

        return maxLen == INT_MIN ? 0 : maxLen;
    }
};
