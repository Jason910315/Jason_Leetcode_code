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
    int kthSmallest(TreeNode* root, int& k) { // 注意k改成引用，透過k的位址直接修改k
        if(root == nullptr){
            return -1;  // 代表第k小未找到
        }
        // 先在左子樹找答案
        int left_res = kthSmallest(root->left,k); 
        if(left_res != -1){  // 不等於-1代表答案存在於左子樹
            return left_res; 
        }
        k--;
        // k為0代表root節點即為第k小
        if(k == 0){
            return root->val;
        }
        return kthSmallest(root->right,k); // 若上述都未找到代表答案存在右子樹 
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
    int k = 4;
    int ans = s.kthSmallest(p.root,k);
    cout<<ans;
}
