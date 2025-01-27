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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 若兩個binary tree都是空，則返回相等
        if(!p && !q){
            return true;
        }
        // 若兩個都不為空且root值相等，再去比較其左右子樹
        if(p && q && p->val == q->val){
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        return false;  // 代表可能p、q有一為空或p、q值不相等
    }
};

int main() {
    BinaryTree p;
    BinaryTree q;

    // 新增節點到二元樹
    p.addNode(1);
    p.addNode(2);
    p.addNode(3);
    q.addNode(1);
    q.addNode(2);
    q.addNode(3);
    Solution s;
    bool ans = s.isSameTree(p.root,q.root);
    cout<<ans;
    return 0;
}
