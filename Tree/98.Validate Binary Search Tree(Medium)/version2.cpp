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
    long long pre = LLONG_MIN;  // pre要設為全域變數才能在每個遞迴間同步
    // 用中序(左中右)，判斷目前節點是否大於上個節點pre
    bool isValidBST(TreeNode* root) {  
        if(root == nullptr){
            return true;
        }
        // step1: 判斷左子樹是否符合BST
        if(!isValidBST(root->left)){
            return false;
        }
        // step2: 判斷目前節點是否>上個子點
        if(root->val <= pre){
            return false;
        }
        pre = root->val;  // 將pre更新為目前節點以便下個遞迴比較
        // 返回右子樹是否也為BST
        return isValidBST(root->right);
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
