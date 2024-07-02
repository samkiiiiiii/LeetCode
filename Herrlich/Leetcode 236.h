class Solution {
public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
                return dfs(root, p, q);
        };

        TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
                if (!node)return nullptr;
                if (node == p || node == q) return node;

                // 左右递归
                TreeNode* left = dfs(node->left, p, q);
                TreeNode* right = dfs(node->right, p, q);
                if (left && right) return node;

		// 判断位置
                if (left) return left;
                else return right;
        }
};