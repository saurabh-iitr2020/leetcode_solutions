/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // inOrder for BST is sorted
    void inOrder(TreeNode* root, vector<int>& v) {
        if (!root) {
            return;
        }
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }

    // Use sorted nodes then pick root from mid and build left and right tree
    // with recusion
    TreeNode* buildTree(vector<int>& v, int start, int end) {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        // cout << mid << v[mid] << endl;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = buildTree(v, start, mid - 1);
        root->right = buildTree(v, mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inOrder(root, nodes);
        // it looks like inorder is already sorted as its BST
        // sort(nodes.begin(), nodes.end());
        // convert BST to Balanced BST
        TreeNode* newRoot = buildTree(nodes, 0, nodes.size() - 1);
        return newRoot;
    }
};