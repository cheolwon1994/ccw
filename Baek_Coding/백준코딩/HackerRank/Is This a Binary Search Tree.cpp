bool isBST(Node* root, int low, int high){
        if(root->data <= low || root->data >= high) return false;
        bool result = true;
        if(root->left!=nullptr){
            result &= isBST(root->left,low,root->data);
        }
        if(root->right!=nullptr)
            result &= isBST(root->right,root->data,high);
        return result;
    }