class Solution {
public:
    
    bool check(vector<int> &piles, int h, int mid){
        int ans = 0;
        for(int i=0; i<piles.size(); i++){
            ans += (piles[i]+mid-1)/mid;
        }
        if(ans>h)
            return false;
        return true;
    }
        
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low<high){
            int mid = low + (high-low)/2;
            if(check(piles,h,mid)){
                
                high = mid;
            }
            else
                low = mid+1;
        }
        return low;
    }
};