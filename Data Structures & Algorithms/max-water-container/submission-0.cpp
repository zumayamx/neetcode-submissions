class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0, R = (int)heights.size() - 1;

        int maxArea = 0;
        while (L < R)
        {
            int area = (R - L) * min(heights[L], heights[R]);
            maxArea = max(maxArea, area);
            if (heights[L] < heights[R]) L++;
            else R--;
        }

        return maxArea;
    }
};
