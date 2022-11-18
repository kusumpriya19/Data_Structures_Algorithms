class Solution {
public:
    
    bool isUgly(int n) {
        set<int> se;
        if(n<=0){
           return false;
        }
        
        while(n%2 == 0){
            se.insert(2);
            n = n/2;
        }
        for(int i=3; i<=sqrt(n); i+=2){
            while(n%i==0){
                if(i>5){
                    return false;
                }
                se.insert(i);
                n = n/i;
            }
        }
        if(n>2){
            if(n>5)
                return false;
            
            
        }
        return true;
        
        
    }
};