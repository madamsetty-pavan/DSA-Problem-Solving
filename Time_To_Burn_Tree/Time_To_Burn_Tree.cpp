/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void dfs(BinaryTreeNode<int>* &root1, int &ans, int level,  BinaryTreeNode<int>* &prev) {
    if(!root1) return;
    ans = max(ans, level);
    if(root1->left != prev) dfs(root1->left, ans, level+1, root1);
    if(root1->right != prev) dfs(root1->right, ans, level+1, root1);
}

void dfsOnParent(BinaryTreeNode<int>* &root1, vector<BinaryTreeNode<int>*> &ansVc,int& ans) {
    int n = ansVc.size();
    if(n>0) {
        dfs(ansVc[n-1], ans, 1, root1);
    }
    
    for(int i = n-2;i>=0;i--) {
        dfs(ansVc[i], ans, n-i, ansVc[i+1]);
    }
}

void findTheNode(BinaryTreeNode<int>*root, int start, vector<BinaryTreeNode<int>*>&temp, vector<BinaryTreeNode<int>*>&ansVc, BinaryTreeNode<int>*&root1){
    if(!root) return ;
    if(root->data == start) {
        ansVc = temp;
        root1 = root;
        return;
    }
    temp.push_back(root);
    findTheNode(root->left, start, temp, ansVc, root1);
    findTheNode(root->right, start, temp, ansVc, root1);
    temp.pop_back();
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    vector<BinaryTreeNode<int>*> temp, ansVc;
    BinaryTreeNode<int>* root1;
    findTheNode(root, start, temp, ansVc, root1);
    int ans = 0;
    dfs(root1,ans, 0, root1);
    dfsOnParent(root1,ansVc, ans);
    return ans;
}
