
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(p == NULL && q == NULL) return true;

        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false;
 
        bool leftAns = isSameTree(p->left, q->left);
        if(!leftAns) return false;

        bool rightAns = isSameTree(p->right, q->right);
        if(!rightAns) return false;

        return true;

        

        
    }
};