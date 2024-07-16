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
    TreeNode* lca(TreeNode* root, int suru,int ses)
    {
        if(!root) return NULL;
        if(root->val == suru) return root;
        if(root->val == ses) return root;
        auto bam = lca(root->left,suru,ses);
        auto dan = lca(root->right,suru,ses);
        if(bam && dan) return root;
        if(!bam) return dan;
        return bam;
    }
    int path(TreeNode* root,int x,string &an1)
    {
        if(!root) return 0;
        if(root->val == x) return 1;
        an1 += 'L';
        auto an = path(root->left,x,an1);
        if(an) return 1;
        an1.pop_back();
        an1 += 'R';
        an = path(root->right,x,an1);
        if(an) return 1;
        an1.pop_back();
        return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root,startValue,destValue);
        string an1 = "",an2="";
        path(root, startValue,an1);
        path(root,destValue,an2);
        
       
        for(int i = 0;i < an1.size();i++) an1[i] = 'U';
        an1 += an2;
        return an1;
        
    }
};
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/submissions/
