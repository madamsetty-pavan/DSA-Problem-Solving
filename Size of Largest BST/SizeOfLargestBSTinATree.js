/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

class ReturnValue {
    public: 
    int maxi;
    int mini;
    bool isBST;
    int size;
    // ReturnValue(maxEle, minEle, IsBST, sizeEle){
    //     maxi = maxEle;
    //     mini = minEle;
    //     isBST = IsBST;
    //     size = sizeEle;
    // }
};

ReturnValue helper(TreeNode* root, int &ans) {
    if(!root) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    ReturnValue left = helper(root->left, ans);
    ReturnValue right = helper(root->right, ans);

    ReturnValue curr;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);
    curr.size = left.size + right.size + 1;

    if(left.isBST && right.isBST && left.maxi < root->data && root->data <right.mini ) {
        curr.isBST = true;
        ans = max(ans, curr.size);
    } else 
        curr.isBST = false;

    return curr;
}


int largestBST(TreeNode * root){
    int ans = 0;
    helper(root, ans);
    return ans;
}
