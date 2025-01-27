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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        // step1.將linkedlist分為一半
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow目前所指即為前半的串列終點
        // step2.將後半串列做reverse
        ListNode* second = slow->next; // second為後半串列的起點
        slow->next = nullptr;          // 先將前半串列的終點slow指向null
        ListNode *pre = nullptr;
        while(second){
            ListNode* temp = second->next;
            second->next = pre;
            pre = second;
            second = temp;
        }
        // pre即為後半串列reverse的起點

        ListNode* first = head;  // first為前半串列起點
        second = pre;  // second為後半串列起點

        // step3.合併前後兩串列
        while(second){;
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }
    }
};

int main(){
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);
    list.addNode(5);
    list.addNode(6);
    list.addNode(7);
    list.addNode(8);

    cout<<"original: ";
    list.display();

    Solution s;
    s.reorderList(list.head);
    list.display();

}
