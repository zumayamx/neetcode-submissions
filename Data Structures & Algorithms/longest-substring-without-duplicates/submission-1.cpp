class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int size = (int)s.size();
        int maxLen = INT_MIN;
        unordered_map<char, int> charIndex;
        int L = 0;

        for (int R = 0; R < size; R++) {
            if (charIndex.find(s[R]) != charIndex.end()) {
                while (L <= charIndex[s[R]]) {
                    charIndex.erase(s[L]);
                    L++;
                }
            }
            charIndex[s[R]] = R;
            maxLen = max(maxLen, R - L + 1);
        }

        return maxLen == INT_MIN ? 0 : maxLen;
    }
};
