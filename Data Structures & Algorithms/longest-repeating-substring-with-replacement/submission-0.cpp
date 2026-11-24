class Solution {
   public:
    int maxFreq(unordered_map<char, int>& freq) {
        int maxFrequency = 0;
        for (auto& p : freq) {
            maxFrequency = max(maxFrequency, p.second);
        }
        return maxFrequency;
    }
    int characterReplacement(string s, int k) {
        int n = (int)s.size();
        int maxLen = INT_MIN;
        unordered_map<char, int> freq;
        int L = 0;

        for (int R = 0; R < n; R++) {
            freq[s[R]]++;
            while (R - L + 1 - maxFreq(freq) > k) {
                freq[s[L]]--;
                L++;
            }
            maxLen = max(maxLen, R - L + 1);
        }

        return maxLen;
    }
};
