#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& pi, int inbegin, int inend)
    {

        if (inbegin > inend)
            return NULL;
        //当没有结点是结束，左右没有结点，
      //前序直接创建结点
        TreeNode* newnode = new TreeNode(preorder[pi]);

        //在中序中找到根，分割出左右子树
        int pos = inbegin;
        while (preorder[pi] != inorder[pos])
        {
            ++pos;
        }
        //中序中左右子树被分割出来
        //[inbegin   pos-1]  pos [pos+1    inend]
        //分割出左右子树后就可以利用递归创建结点
        pi++;
        newnode->left = _buildTree(preorder, inorder, pi, inbegin, pos - 1);
        newnode->right = _buildTree(preorder, inorder, pi, pos + 1, inend);

        return newnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return  _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
    }
};