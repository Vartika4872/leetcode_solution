/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// Forward declaration of guess API.
// int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left = 1;
        long right = n;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;  // Prevent overflow
            int result = guess(mid);
            
            if (result == 0) {
                return mid;        // Found the number
            } 
            else if (result < 0) { 
                right = mid - 1;   // Guess was too high
            } 
            else { 
                left = mid + 1;    // Guess was too low
            }
        }
        
        return -1; // Should never reach here
    }
};