#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> res;

        if (root != nullptr)
        {
            auto temp = inorderTraversal(root->left);
            res.insert(res.end(), temp.begin(), temp.end());

            res.push_back(root->val);

            temp = inorderTraversal(root->right);
            res.insert(res.end(), temp.begin(), temp.end());
        }

        return res;
    }
};

std::string vecToStr(const std::vector<int>& vec)
{
    std::ostringstream oss;
    for (auto el : vec)
        oss << el << ", ";
    return oss.str();
}

int main()
{
    TreeNode last_node(3);
    TreeNode mid_node(2, nullptr, &last_node);
    TreeNode root_node(1, &mid_node, nullptr);
    Solution solution;
    std::cout << vecToStr(solution.inorderTraversal(&root_node)) << std::endl;
}