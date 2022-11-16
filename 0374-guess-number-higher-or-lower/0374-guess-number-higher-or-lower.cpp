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
    int guessNumber(int n) {
        int maxi = n; int mini = 1;
        while(true){
        int midi = mini + (maxi-mini)/2;
        int res = guess(midi);
            if(res == 0){
                return midi;
            }
            else if(res == 1){
                mini = midi+1;
            }
            else{
                maxi = midi-1;
            }
            
        }
        return -1;
        
    }
};