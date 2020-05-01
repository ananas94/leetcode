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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        std::stack<TreeNode*> st;
        auto node = root;
        while (node ||  !st.empty() ) {
            if (node) {
                st.push(node);
                node = node->left;
            }else {
                node=st.top();
                st.pop();
                count++;
                if (count == k) return node->val;
                node = node->right;
            }
        }
        return 0;
    }
};