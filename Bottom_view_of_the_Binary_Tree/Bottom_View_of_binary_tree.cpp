#include<unordered_map>

void preorder(TreeNode<int> *root, unordered_map<int, pair<int,int>> &mp, int level, int xlevel, int &lowerLevel, int &higherLevel) {
    if(!root)return;
    lowerLevel = min(lowerLevel, level);
    higherLevel = max(higherLevel, level);
    preorder(root->left, mp, level-1, xlevel+1,lowerLevel, higherLevel );
    if(mp.find(level) == mp.end()) {
        mp[level] = {root->data, xlevel};
    } else{
        auto y = mp[level];
        if(y.second<=xlevel) mp[level] = {root->data, xlevel};
    }
    preorder(root->right, mp, level+1, xlevel+1, lowerLevel, higherLevel);
}


vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
    unordered_map<int, pair<int,int>> mp;
    int lowerLevel = 0, higherLevel = 0;
    preorder(root, mp, 0, 0, lowerLevel, higherLevel);

    vector<int> ans;
    for(int i=lowerLevel; i<=higherLevel;i++) {
        ans.push_back(mp[i].first);
    }
    return ans;
}
