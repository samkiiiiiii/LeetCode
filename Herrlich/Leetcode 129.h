#pragma once

#include "_include.h"
#include "_TreeNode.h"

class Solution {
public:
        int res = 0;
        int sumNumbers(TreeNode* root) {
                dfs(root, 0);
                return res;
        }

        void dfs(TreeNode* node, int pre) {
                if (!node) return;
                if (!node->left && !node->right) {
                        res += pre * 10 + node->val;
                        return;
                }
                dfs(node->left, 10 * pre + node->val);
                dfs(node->right, 10 * pre + node->val);
        }
};