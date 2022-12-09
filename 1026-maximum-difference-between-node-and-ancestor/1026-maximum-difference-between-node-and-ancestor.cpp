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
    
    void helper(TreeNode *root,vector<int> &arr,vector<vector<int>> &ans){
        if(!root){
            return;
        }
        arr.push_back(root->val);
        if(!root->left and !root->right){
            ans.push_back(arr);
        }
        helper(root->left,arr,ans);
        helper(root->right,arr,ans);
        arr.pop_back();
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        vector<vector<int>> ans;
        vector<int> arr;
        helper(root,arr,ans);
        int maxi=INT_MIN;
        for(auto it:ans){
            // for(auto i:it){
            //     cout<<i<<" ";
            // }cout<<endl;
            int n1=*min_element(it.begin(),it.end());
            int n2=*max_element(it.begin(),it.end());
            maxi=max(maxi,n2-n1);
        }
        return maxi;
        
    }
};