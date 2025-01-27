# include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct LinkedList {
    ListNode* head;    // 頭節點指標

    // 初始化鏈結串列，頭節點設為 nullptr
    LinkedList() : head(nullptr) {}

    // 新增節點到鏈結串列末尾
    void addNode(int val) {
        ListNode* newNode = new ListNode(val);  // 動態分配新節點
        if (!head) {                    // 如果是空的鏈結串列
            head = newNode;             // 將新節點設為頭節點
        } else {
            ListNode* temp = head;          // 從頭節點開始遍歷
            while (temp->next) {        // 找到最後一個節點
                temp = temp->next;
            }
            temp->next = newNode;       // 新節點加到尾部
        }
    }
     // 顯示鏈結串列內容
    void display() const {
        ListNode* temp = head;              // 從頭節點開始
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);  // 此dummy node的next指向head;
        ListNode* left = &dummy;  // left為dummy 位址
        ListNode* right = head;   // right設為head位址
        // 先將right移動n步
        while(n > 0){
            right = right->next;
            n--;
        }
        // 再將right、left同步移動值到right為null
        while(right != nullptr){
            right = right->next;
            left = left->next;
        }
        // 此時left位址即為要移除的node的前一個node
        ListNode* deleteNode = left->next;
        left->next = left->next->next;
        delete deleteNode;
        return dummy.next;
    }
};

int main(){
    LinkedList list1;
    list1.addNode(1);
    list1.addNode(2);
    list1.addNode(3);
    list1.addNode(4);
    list1.addNode(5);
 
    cout<<"original: ";
    list1.display();

    Solution s;
    LinkedList ans;
    ans.head = s.removeNthFromEnd(list1.head,3);
    cout<<"Remove: ";
    ans.display();

}
