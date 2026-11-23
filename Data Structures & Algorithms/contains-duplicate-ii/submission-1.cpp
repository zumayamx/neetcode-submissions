// I think one approach is to use an fixed window
// and a hash set.
//
// We need to find if there are two equal elements
// in different positions (indices), the brute force
// approach could be, check if an element is duplicated
// in each window, but that could be O (n * k) complexity
//
// We could mantain a hash set, that saves the current
// elements in our window. Each time we move
// to a new element, we check if that element is present in
// the hash set. If it is we return true, if it's not
// we add it to our hash set.
// In each iteration, we check if our window
// is within the limints, in this case less or equal to k,
// if it is, we continue our algorithm
// but it is not, we need to remove the left-most element
// of our window from our hash set, because
// that element no longer belongs to our window and
// our hash set needs to save our current elements
// in our current window.
//
// Pseudocode:
// Initialize a hash set, to mantain the elements in our current window
// Initialize a left pointer that delimits the left side of our window
// Iterate over each element in our nums array (that is our right pointer)
// If the abs(R - L) is greater than K, we remove the most-left element in
// our window of our hash set and update L = L + 1, to mantain our window
// within limits.
//
// We check in the current element is alreay in our hash set, if it is
// we return true, if it is not, we add it to our hash set.
// If this for loops end without return true, that means there aren't
// two equal elements in different positions, return false.

class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        unordered_set<int> ocurr;
        int L = 0;

        for (int R = 0; R < n; R++) {
            if (abs(R - L) > k) {
                ocurr.erase(nums[L]);
                L += 1;
            }
            
            if (ocurr.find(nums[R]) != ocurr.end()) return true;
            ocurr.insert(nums[R]);
        }

        return false;
    }
};