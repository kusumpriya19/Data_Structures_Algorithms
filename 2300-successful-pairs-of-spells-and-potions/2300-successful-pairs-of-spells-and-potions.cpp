class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> v(spells.size(), 0);
        sort(potions.begin(), potions.end());
        
        for(int i=0; i<spells.size(); i++){
            int high = potions.size()-1;
            int low=0, mid;
            while(low<=high){
                mid = low + (high-low)/2;
                if((long long int)spells[i]*(long long int)potions[mid] >= success)
                    high = mid-1;
                else
                    low = mid+1;
            }
            v[i] = potions.size()-1-high;
        }
        return v;
    }
};