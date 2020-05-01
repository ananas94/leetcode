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
        
TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
    if (preorder.size() == 0)
        return NULL;
	stack<TreeNode*> pnStck;
	int pIndex=0, iIndex=0;
	TreeNode* current = new TreeNode(preorder[pIndex]), *root = current;
	pnStck.push(current);
	pIndex++;
	while (!pnStck.empty()) {
		while (pnStck.top()->val != inorder[iIndex]) {
			//going down on  left
			pnStck.top()->left = new TreeNode(preorder[pIndex]);
			pnStck.push(pnStck.top()->left);
			pIndex++;
		}
		while (!pnStck.empty() && pnStck.top()->val == inorder[iIndex]) {
		//look where right begin
			current = pnStck.top(); pnStck.pop();
			iIndex++;
		}
		if (pIndex<preorder.size()) {
			current->right = new TreeNode(preorder[pIndex]);
			current = current->right;
			pIndex++;
			pnStck.push(current);
		}
	}


    return root;
}
};