class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ocurr;
        for (char c : s)
        {
            ocurr[c]++;
        }

        for (char c : t)
        {
            ocurr[c]--;
        }

        for (auto p : ocurr)
        {
            if (p.second > 0 || p.second < 0) return false;
        }

        return true;
    }
};
