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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        if (!root)
            return vector<vector<int>>();

        vector<vector<int>> left_paths;
        vector<vector<int>> right_paths;
        if (root->left || root->right)
        {
            left_paths = pathSum(root->left, targetSum - root->val);
            right_paths = pathSum(root->right, targetSum - root->val);

            for (auto& path : right_paths)
                left_paths.push_back(path);
            for (auto& path : left_paths)
                path.insert(path.begin(), root->val);
            return left_paths;
        }
        if (targetSum - root->val == 0)
            return {{root->val}};
        return vector<vector<int>>();
    }
};

void print(vector<vector<int>> shit)
{
    for (auto& path : shit)
    {
        for (auto el : path)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}

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

    print(solution.pathSum(&n0_mid, 10));
}