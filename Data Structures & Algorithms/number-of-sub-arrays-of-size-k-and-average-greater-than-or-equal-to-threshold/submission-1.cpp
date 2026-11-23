/*
I think, one approach could be
to check all sub-arrays and its averange
but that would be O (n * k), plus compute the
average for each sub-array.

We can do it in one pass, because our window
has a fixed size, we could verify first if
our window has the size of k, if it is
then we compute the average and compare it,
if that result is greater than threshold
we count one subarray. In reality, I think
first we need a condition, to guarantee
or window is size k, if our window exceeds
our limits, we need to remove the left-most
element from our calculation of the average
then we add our current element to our general
sum and finally check if our window is size k
if it is we compare the averange with our threshold

Pseudocode:
Initialize a currentSum variable to save the sum of
elements in our window
Initialize left pointer to delimit the left side of
our window

Iterate over each element in our window
check if the window size has exceeded its limits (k)
if it is, then substract the leftmost element
from our currentSum and update left pointer + 1,
if not continue the algorithm
add the current element to our current sum
if our current window size is equal to k
compute the average and comparte it againts
our threshold, if the averange is greater
than our threshold, add one to our
sub-counter

*/

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = (int)arr.size();
        int currSum = 0;
        int count = 0;
        int L = 0;

        for (int R = 0; R < n; R++) {
            if (R - L + 1 > k) {
                currSum -= arr[L];
                L += 1;
            }

            currSum += arr[R];
            if (R - L + 1 == k) {
                int averange = currSum / k;
                if (averange >= threshold) count++;
            }
        }
        return count;
    }
};