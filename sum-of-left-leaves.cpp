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
    enum class NODE_TYPE
    {
      LEFT,
      RIGHT,
      ROOT
    };
    int sumOfLeftLeaves(TreeNode* root) {
        return leafChecker(root,NODE_TYPE::ROOT);
    }
    int leafChecker(TreeNode* node, NODE_TYPE type)
    {
        if (!node) return 0;
        if (!node->left && !node->right)
        {
            if (type == NODE_TYPE::LEFT)
                return node->val;
            else
                return 0;
        }
        else
        {
            return leafChecker(node->left,NODE_TYPE::LEFT)+leafChecker(node->right,NODE_TYPE::RIGHT);
        }
    }
};