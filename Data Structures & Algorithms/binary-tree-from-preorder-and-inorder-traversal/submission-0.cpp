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
    unordered_map<int,int> mp;
    TreeNode* Solve(vector<int>& preorder,int preStart,int preEnd,int inStart,int inEnd){
        if(preStart > preEnd){
            return NULL;
        }
        
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int mid = mp[rootVal];
        int leftSize = mid - inStart;

        root -> left = Solve(preorder,preStart + 1,preStart + leftSize,inStart,mid - 1);
        root -> right = Solve(preorder,preStart + leftSize + 1,preEnd,mid + 1,inEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0;i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        return Solve(preorder,0,n - 1,0,n - 1);
    }
};
