
// nums=[-1,0,2,4,6,8]
// target=3

// left = 0; right = 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (target > nums[mid])
            {
                left = mid + 1;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else 
            {
                return mid;
            }
        }

        return -1;
    }
};
