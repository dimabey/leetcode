#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root)
            return false;
        if (root->left || root->right)
            return hasPathSum(root->left, targetSum - root->val) ||
                   hasPathSum(root->right, targetSum - root->val);
        return targetSum - root->val == 0;
    }
};

int main()
{
    Solution solution;
    TreeNode n3_r(4);
    TreeNode n2_r(3, nullptr, &n3_r);
    TreeNode n1_r(2, nullptr, &n2_r);
    TreeNode n3_l(4);
    TreeNode n2_l(3, &n3_l, nullptr);
    TreeNode n1_l(2, &n2_l, nullptr);
    TreeNode n0_mid(1, &n1_l, &n1_r);

    cout << solution.hasPathSum(&n0_mid, 10) << endl;
}