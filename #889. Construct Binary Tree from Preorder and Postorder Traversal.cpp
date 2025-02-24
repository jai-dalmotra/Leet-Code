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
    unordered_map<int, int> postIndexMap; // Stores indices of postorder elements
    int preIndex = 0; // Tracks current position in preorder

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int left, int right) {
        if (preIndex >= preorder.size() || left > right)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIndex++]); // Create root node

        if (preIndex < preorder.size() && left <= right) {
            int leftSubtreeRootIndex = postIndexMap[preorder[preIndex]]; // Find left subtree root in postorder
            if (leftSubtreeRootIndex <= right) {
                root->left = constructFromPrePost(preorder, postorder, left, leftSubtreeRootIndex);
                root->right = constructFromPrePost(preorder, postorder, leftSubtreeRootIndex + 1, right - 1);
            }
        }

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++)
            postIndexMap[postorder[i]] = i; // Store index of postorder elements

        return constructFromPrePost(preorder, postorder, 0, postorder.size() - 1);
    }
};

// Helper function to print Inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
