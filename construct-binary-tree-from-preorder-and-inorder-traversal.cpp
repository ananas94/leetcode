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
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       if (preorder.empty())
            return nullptr;
        int root =preorder[0];
        preorder.erase(preorder.begin());
        
        vector<int> iLeft(inorder.begin(),std::find(inorder.begin(),inorder.end(),root )),
                    iRight(std::find(inorder.begin(),inorder.end(),root),inorder.end());
        
	    if (!iRight.empty()) iRight.erase(iRight.begin());
        
        set<int> right(iRight.begin(),iRight.end());
        
        vector<int> pLeft(preorder.begin(),
                          std::find_if(preorder.begin(), preorder.end(),
                                       [right](auto elem) {return right.find(elem)!=right.end();}  ) ),
                    pRight(std::find_if(preorder.begin(), preorder.end(),
                                       [right](auto elem) {return right.find(elem)!=right.end();}),
                            preorder.end()  ) ;
        return new TreeNode(root, buildTree(pLeft,iLeft), buildTree(pRight,iRight));
    }
};