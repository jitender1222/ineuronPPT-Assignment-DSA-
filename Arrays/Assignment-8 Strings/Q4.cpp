
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *str2tree(string s)
{
    if (s.empty())
        return NULL;

    stack<TreeNode *> stk;
    int i = 0;

    while (i < s.length())
    {
        if (isdigit(s[i]) || s[i] == '-')
        {
            int start = i;

            while (i + 1 < s.length() && isdigit(s[i + 1]))
                i++;

            int val = stoi(s.substr(start, i - start + 1));
            TreeNode *node = new TreeNode(val);

            if (!stk.empty())
            {
                TreeNode *parent = stk.top();

                if (parent->left)
                    parent->right = node;
                else
                    parent->left = node;
            }

            stk.push(node);
        }
        else if (s[i] == ')')
        {
            stk.pop();
        }

        i++;
    }

    return stk.top();
}

void inorderTraversal(TreeNode *root, vector<int> &result)
{
    if (!root)
        return;

    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main()
{
    string s = "4(2(3)(1))(6(5))";
    TreeNode *root = str2tree(s);

    vector<int> result;
    inorderTraversal(root, result);

    cout << "Inorder Traversal: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
