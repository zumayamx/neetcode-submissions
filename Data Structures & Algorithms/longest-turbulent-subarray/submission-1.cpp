/*
SLIDING WINDOW APPROACH

The idea of this problem, is to find the max streak
of alternating signs between a pair of elements.

For example:
arr = [2,4,3,2,2,5,1,4]
The signs between the pairs are,
[<, >, >, =, <, >, <]

The longest sub-array with alternate sings,
is [2,5,1,4]
*/

class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = (int)arr.size();
        int prevSign = -1;
        int maxLen = 1;
        int L = 0, R = 1;

        while (R < n) {
            if (arr[R - 1] > arr[R] && prevSign != 1) {
                maxLen = max(maxLen, R - L + 1);
                R++;
                prevSign = 1;
            } else if (arr[R - 1] < arr[R] && prevSign != 0) {
                maxLen = max(maxLen, R - L + 1);
                R++;
                prevSign = 0;
            } else {
                R = arr[R - 1] == arr[R] ? R + 1 : R;
                L = R - 1;
                prevSign = -1;
            }
        }
        return maxLen;
    }
};