#include <iostream>
#include <queue> // 層序遍歷需要的隊列
#include <climits>
using namespace std;

// 定義 TreeNode 結構
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 定義二元樹類別
class BinaryTree {
public:
    TreeNode* root; // 樹的根節點

    // 初始化樹，根節點設為 nullptr
    BinaryTree() : root(nullptr) {}

    // 新增節點到二元樹（按層序插入）
    void addNode(int val) {
        TreeNode* newNode = new TreeNode(val); // 建立新節點
        if (!root) { // 如果樹是空的
            root = newNode;
            return;
        }

        // 使用隊列（queue）進行層序遍歷，找到第一個可插入的位置
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            // 插入到左子樹
            if (!current->left) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }

            // 插入到右子樹
            if (!current->right) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    // 層序遍歷並印出節點
    void printLevelOrder() const {
        if (!root) {
            cout << "樹是空的。" << endl;
            return;
        }

        queue<TreeNode*> q; // 用於層序遍歷的隊列
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            // 印出當前節點
            cout << current->val << " ";

            // 將左子節點加入隊列
            if (current->left) {
                q.push(current->left);
            }

            // 將右子節點加入隊列
            if (current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
};

class Solution {
public:
    // 用前序(中左右)遍歷方法檢查，先判斷再遞迴 
    bool isValidBST(TreeNode* root,long long left = LLONG_MIN,long long right = LLONG_MAX) {  // 新增左右界限參數
        if(root == nullptr){
            return true;
        }
        int x = root->val;
        // 判斷目前節點是否在左右開區間內
        if(left < root->val && root->val < right){
            // 若是則判斷其左子點與右子點是否也符合BST定義，並要更新界限
            return isValidBST(root->left,left,x) && isValidBST(root->right,x,right);
        }
        return false;
    }
};
int main() {
    BinaryTree p;
    p.addNode(10);
    p.addNode(5);
    p.addNode(15);
    p.addNode(3);
    p.addNode(8);
    p.addNode(12);
    p.addNode(17);
    Solution s;
    bool valid = s.isValidBST(p.root);
    cout<<valid;
}
