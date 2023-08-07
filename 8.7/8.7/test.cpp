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
        //��û�н���ǽ���������û�н�㣬
      //ǰ��ֱ�Ӵ������
        TreeNode* newnode = new TreeNode(preorder[pi]);

        //���������ҵ������ָ����������
        int pos = inbegin;
        while (preorder[pi] != inorder[pos])
        {
            ++pos;
        }
        //�����������������ָ����
        //[inbegin   pos-1]  pos [pos+1    inend]
        //�ָ������������Ϳ������õݹ鴴�����
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