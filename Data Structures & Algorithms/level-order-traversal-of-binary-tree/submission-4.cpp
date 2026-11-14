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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans;
        q.push({root,0});

        while(!q.empty()){
            int a = q.front().second;
            vector<int> v;
            while(!q.empty() && q.front().second == a){
                TreeNode* r = q.front().first;q.pop();
                v.push_back(r -> val);
                if(r -> left){
                    q.push({r -> left,a + 1});
                }
                if(r -> right){
                    q.push({r -> right,a + 1});
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
