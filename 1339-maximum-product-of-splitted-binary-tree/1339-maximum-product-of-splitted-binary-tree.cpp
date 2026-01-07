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

private:
 int sum(TreeNode*root,map<TreeNode*,long>&mp){
    if(!root) return 0;
     long long left=sum(root->left,mp);
     long long right=sum(root->right,mp);
     long long sum=left+right+root->val;
     return mp[root]=sum;

 }

public:
    int maxProduct(TreeNode* root) {
        long long M=1e9+7;
        map<TreeNode*,long >mp;
        long long totalsum=sum(root, mp);
        long long mx=0;
        for(auto it:mp){
            if(it.second!=totalsum){
                mx=max(mx,((totalsum -it.second)%M*(it.second)%M)%M);
            }
        }

     return mx;;
        
    }
};