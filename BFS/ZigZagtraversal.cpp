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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
        {
            return v;
        }
        int h=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int i=q.size();
            vector<int>level;
            while(i!=0)
            {
                level.push_back(q.front()->val);
                if(q.front()->left!=NULL)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL)
                {
                    q.push(q.front()->right);
                }
                i--;
                q.pop();
            }
        if(h%2!=0)
        {
            reverse(level.begin(),level.end());
        }
            
            v.push_back(level);
           level.clear();
            h++;
        }
        return v;
        
    }
};
