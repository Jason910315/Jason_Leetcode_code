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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr){
            if(fast->next == nullptr){
                return false;
            }
            fast = fast->next->next;
            // 若fast、slow相遇到代表linked list有cycle
            if(fast == slow){
                return true;  
            }
            slow = slow->next;    
        }
        return false;
    }
};

int main(){
    LinkedList list1;
    list1.addNode(1);
    list1.addNode(1);
    list1.addNode(3);

}
