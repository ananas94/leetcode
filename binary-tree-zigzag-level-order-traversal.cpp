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
        std::vector<vector<int>> ret;
        std::vector<TreeNode*> currentLayer;
        std::vector<TreeNode*> nextLayer;
        if (!root)
            return ret;
        
        currentLayer.push_back(root);        
        bool directOrder = true;
        while (!currentLayer.empty()) {
            vector<int> current;
            if (directOrder)
                std::for_each( currentLayer.begin(),currentLayer.end(),
                              [&current](auto elem) {current.push_back(elem->val);} );
            else
                std::for_each( currentLayer.rbegin(),currentLayer.rend(),
                              [&current](auto elem) {current.push_back(elem->val);} );
            
            
            std::for_each(currentLayer.begin(), currentLayer.end(), 
                [&nextLayer](auto elem) {
                    if (elem->left) nextLayer.push_back(elem->left);
                    if (elem->right) nextLayer.push_back(elem->right); 
                }
            );         
            
            ret.push_back(current);
            directOrder^=true;
            currentLayer = nextLayer;
            nextLayer={};
        }
       return ret;
    }
};