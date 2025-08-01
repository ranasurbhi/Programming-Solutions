class Solution {
    void collectLeaves(TreeNode* node, unordered_set<int>& leaves) {
        if (!node) return;
        if (!node->left && !node->right) {
            leaves.insert(node->val);
        } else {
            collectLeaves(node->left, leaves);
            collectLeaves(node->right, leaves);
        }
    }

    bool isValidBST(TreeNode* node, long minVal, long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return isValidBST(node->left, minVal, node->val) &&
               isValidBST(node->right, node->val, maxVal);
    }

    void merge(TreeNode* root, unordered_map<int, TreeNode*>& mp, unordered_set<int>& used) {
        if (!root) return;

        if (root->left && mp.count(root->left->val) && !used.count(root->left->val)) {
            root->left = mp[root->left->val];
            used.insert(root->left->val);
            merge(root->left, mp, used);
        } else {
            merge(root->left, mp, used);
        }

        if (root->right && mp.count(root->right->val) && !used.count(root->right->val)) {
            root->right = mp[root->right->val];
            used.insert(root->right->val);
            merge(root->right, mp, used);
        } else {
            merge(root->right, mp, used);
        }
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp; 
        unordered_set<int> leaves;

        for (auto tree : trees) {
            mp[tree->val] = tree;
        }

        for (auto tree : trees) {
            if (tree->left) leaves.insert(tree->left->val);
            if (tree->right) leaves.insert(tree->right->val);
        }

        TreeNode* root = nullptr;
        for (auto tree : trees) {
            if (!leaves.count(tree->val)) {
                if (root) return nullptr; 
                root = tree;
            }
        }

        if (!root) return nullptr;

        unordered_set<int> used;
        merge(root, mp, used);

        if (used.size() + 1 != trees.size()) return nullptr;

        if (!isValidBST(root, LONG_MIN, LONG_MAX)) return nullptr;

        return root;
    }
};
