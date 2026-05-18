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
    unordered_map<int, int> mp;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int left, int right) {
        
        if (left > right)
            return NULL;

        // Last element in postorder is root
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find root position in inorder
        int index = mp[rootVal];

        // Build right subtree first
        root->right = build(inorder, postorder, index + 1, right);

        // Build left subtree
        root->left = build(inorder, postorder, left, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // Store inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        postIndex = postorder.size() - 1;

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};