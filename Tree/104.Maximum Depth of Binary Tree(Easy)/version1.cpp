#include <iostream>
#include <queue> // 層序遍歷需要的隊列
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int hL = maxDepth(root->left);
        int hR = maxDepth(root->right);
        return max(hL,hR) + 1;
    }
};

int main() {
    BinaryTree tree;

    // 新增節點到二元樹
    tree.addNode(1);
    tree.addNode(2);
    tree.addNode(3);
    tree.addNode(4);
    tree.addNode(5);
    tree.addNode(6);
    tree.addNode(7);

    cout << "original:";
    tree.printLevelOrder();

    // 反轉二元樹
    Solution s;
    int height = s.maxDepth(tree.root);
    cout << height;
    return 0;
}
