class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = (int)numbers.size() - 1;

        while (L < R) {
            if (numbers[L] + numbers[R] > target)
                R--;
            else if (numbers[L] + numbers[R] < target)
                L++;
            else
                return {L+1, R+1};
        }
    }
};
