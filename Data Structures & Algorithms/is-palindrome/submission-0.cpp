class Solution {
   public:
    bool isPalindrome(string s) {
        string clean;
        for (auto& c : s) {
            if (isalnum(c)) clean += tolower(c);
        }

        int L = 0, R = (int)clean.size() - 1;

        while (L < R) {
            if (clean[L] != clean[R]) return false;
            L++;
            R--;
        }

        return true;
    }
};
