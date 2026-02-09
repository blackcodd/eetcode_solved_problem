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
 void inorder(TreeNode*root,vector<int>&v){
    if(root==nullptr) return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
 }
  TreeNode* distribution(vector<int>&v,int start,int end){
    if(start>end) return nullptr ;
    int mid=(start+end)/2;
    TreeNode* root =new TreeNode(v[mid]);
    root->left= distribution(v,start,mid-1);
    root->right=distribution(v,mid+1,end);
    return root;

  }
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        for(auto it:v){
            cout<<it<<" ";

        }
        int s=0,l=v.size()-1;
       
         return  distribution(v,s,l);
        



        
    }
};