/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        
        queue<TreeNode*>nodesQueue;
        nodesQueue.push(root);
        int leftToRight = 0;
        
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row;
            for(int i=0; i<size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                row.push_back(node->val);
                if(node->left)
                    nodesQueue.push(node->left);
                if(node->right)
                    nodesQueue.push(node->right);
                
                
            }
            if(leftToRight%2 != 0)
                reverse(row.begin(), row.end());
            
            result.push_back(row);
            leftToRight++;
            
            
        }
        return result;
        
        
        
        
    }
};