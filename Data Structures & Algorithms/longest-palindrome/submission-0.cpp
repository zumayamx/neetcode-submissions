class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> ocurr;
        int maxLen = 0;

        for (char c : s)
        {
            ocurr[c]++;
            if (ocurr[c] % 2 == 0)
            {
                maxLen += 2;
            }
        }

        for(auto p : ocurr)
        {
            if (p.second % 2 == 1)
            {
                maxLen++;
                break;
            }
        }

        return maxLen;
    }
};