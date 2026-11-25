class Solution {
   public:
    bool isPalindrome(string s) {
        int L = 0, R = (int)s.size() - 1;

        while (L < R) {
            if (!isalnum(s[R])) {
                R--;
                continue;
            }
            if (!isalnum(s[L])) {
                L++;
                continue;
            }
            if (tolower(s[L]) != tolower(s[R])) return false;
            R--;
            L++;
        }
        return true;
    }
};
