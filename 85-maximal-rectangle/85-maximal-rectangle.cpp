class Solution {
public:
    
    int largestRectangleArea(vector<int> &heights){
        int n = heights.size();
        vector<int> left(n), right(n);
        
        stack<int> mystack;
        for(int i=0; i<n; i++){
            if(mystack.empty()){
                left[i] = 0;
                mystack.push(i);
            }
            else{
                while(!mystack.empty() && heights[mystack.top()] >= heights[i])
                    mystack.pop();
                left[i] = mystack.empty() ? 0 : mystack.top()+1;
                mystack.push(i);
            }
            
        }
        while(!mystack.empty())
            mystack.pop();
        
        for(int i=n-1; i>=0; i--){
            if(mystack.empty()){
                right[i]=n-1;
                mystack.push(i);
            }
            else{
                while(!mystack.empty() && heights[mystack.top()] >= heights[i])
                    mystack.pop();
                
                right[i] = mystack.empty() ? n-1 : mystack.top()-1;
                mystack.push(i);
            }
        }
        int max_area = 0;
        for(int i=0; i<n; i++){
            max_area = max(max_area, heights[i]*(right[i]-left[i]+1));
        }
        return max_area;
            
          
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> v(col, 0);
        int res = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '0')
                    v[j]=0;
                else
                    v[j]++;
            }
            res = max(res, largestRectangleArea(v));
        }
        return res;
        
    }
};