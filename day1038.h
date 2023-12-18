#pragma once
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
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
class day1038
{
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> num;
        CreateNum(root, num);
        PreOrder(root, num);
        return root;
    }
    void CreateNum(TreeNode* T,vector<int>& num) {
        if (T != nullptr) {
            num.push_back(T->val);
            CreateNum(T->left, num);
            CreateNum(T->right, num);
        }  
    }
    void PreOrder(TreeNode* T, vector<int>& num) {
        if (T != nullptr) {
            int sum = 0;
            int val = T->val;
            for (int i = 0; i < num.size(); i++) {
                if (num[i] >= val) {
                    sum = sum + num[i];
                }
            }
            T->val = sum;
            PreOrder(T->left,num);
            PreOrder(T->right,num);
        }
    }
};

