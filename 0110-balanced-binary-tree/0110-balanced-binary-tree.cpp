
class Solution {
public:

    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left,right);
    }


    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);



    }
};