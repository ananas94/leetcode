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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    stack<pair<TreeNode*, int>> st;
    TreeNode* root = new TreeNode(preorder[0]);
    st.emplace(root, numeric_limits<int>::max());
    auto current = st.top();
    for (int i = 1; i < preorder.size(); i++) {
        while (current.second < preorder[i]) { st.pop(); current = st.top(); }

      //  cout << "current: " << current.first->val;
        if (current.first->val > preorder[i]) {
         //   cout << " left: " << preorder[i] << std::endl;
            auto newNode = new TreeNode(preorder[i]);
            current.first->left = newNode;
            st.emplace(newNode, current.first->val);
        }
        else {
            //cout << " right " << preorder[i] << std::endl;
            auto newNode = new TreeNode(preorder[i]);
            current.first->right = newNode;
            st.emplace(newNode, current.second);
        }
        current = st.top();
    }
    return root;
}
};