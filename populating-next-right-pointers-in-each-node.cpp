/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    std::array<Node*,4097> arr;
    int size;
    void fillArr(Node *n,int current){
        if (!n) return;
        arr[current]=n;
        size=current;
        fillArr(n->left, current*2);
        fillArr(n->right, current*2+1);
    }
public:
    Node* connect(Node* root) {
        fillArr(root,1);
        for (int i=1;i<size;i<<=1){
            for (int j=i;j<i*2-1;j++)
                arr[j]->next=arr[j+1];
            arr[i*2-1]=NULL;
        }
        return root;
    }
};