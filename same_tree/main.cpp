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
    bool isBalanced(TreeNode* root)
    {
        bool ans = true;
        checkBalance(root, ans);
        return ans;
    }

    int checkBalance(TreeNode* root, bool& check)
    {
        if (!root)
            return 0;
        if (!check)
            return 0;
        int depth_left = checkBalance(root->left, check);
        int depth_right = checkBalance(root->right, check);
        if (abs(depth_left - depth_right) > 1)
            check = false;
        return max(depth_left, depth_right) + 1;
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

    cout << solution.isBalanced(&n0_mid) << endl;
}