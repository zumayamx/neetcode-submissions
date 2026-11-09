class Solution {
   public:
    int searchNumberInList(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target > arr[mid]) {
                left = mid + 1;
            } else if (target < arr[mid]) {
                right = mid - 1;
            } else
                return mid;
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if (searchNumberInList(matrix[i], target) != -1) return true;
        }
        return false;
    }
};
