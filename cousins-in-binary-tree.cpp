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
    bool isCousins(TreeNode* root, int x, int y) {
        int xdepth=0, ydepth=0;
        
        std::queue<std::pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));
        
        while (!q.empty() && (xdepth==0 || ydepth==0)) {
            auto node = q.front(); q.pop();
            if (node.first->val == x ) xdepth = node.second;
            if (node.first->val == y ) ydepth = node.second;
            
           
            
            if (node.first->left)
                q.push(make_pair(node.first->left, node.second+1));
            
            if (node.first->right)
                q.push(make_pair(node.first->right, node.second+1)); 
             if (node.first->left && node.first->right && 
                    (node.first->left->val == x &&  node.first->right->val==y ||
                     node.first->left->val == y && node.first->right->val == x  )
                )
                return false;
        }         
        return xdepth == ydepth;   
    }
};