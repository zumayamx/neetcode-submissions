// O(n) Time and O(n) Space solution

class Solution {
   public:
    int trap(vector<int>& height) {
        int n = (int)height.size();
        vector<int> leftsMax(n);
        vector<int> rightsMax(n);

        int leftMax = 0;
        for (int i = 0; i < n; i++) {
            leftsMax[i] = leftMax;
            leftMax = max(leftMax, height[i]);
        }

        int rightMax = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightsMax[i] = rightMax;
            rightMax = max(rightMax, height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            int w = min(leftsMax[i], rightsMax[i]) - height[i];
            if (w > 0) water += w;
        }

        return water;
    }
};
