/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int binarySearch(int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (guess(mid) > 0)
            {
                low = mid + 1;
            }
            else if (guess(mid) < 0)
            {
                high = mid - 1;
            }
            else return mid;
        }
    }
    int guessNumber(int n) {
        return binarySearch(1, n);
    }
};