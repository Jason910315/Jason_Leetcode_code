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
    // 此法使用一個額外的節點來串接list1、list2合併後的串列
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);  // 先創造一個假節點dummy，其值為0
        ListNode* node = &dummy;  // 創造一個ListNode指標node指向dummy的位址
        // 當兩個串列都不為空
        while(list1 && list2){
            if(list1->val <= list2->val){
                node->next = list1;   // 將node指向list1(因list1值較小)
                list1 = list1->next;  // list1改為下個節點
            }
            else{
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;  // 比較完一次後node也要改為下個節點
            // 若list1已經沒有節點了
            if(list1 == nullptr){  
                node->next = list2;
            }
            else if(list2 == nullptr){
                node->next = list1;
            }
        }
        return dummy.next;  // 因為dummy的位址不變動始終指向最初答案鏈結開始的地方，所以返回dummy.next
    }
};

int main(){
    LinkedList list1;
    list1.addNode(1);
    list1.addNode(1);
    list1.addNode(3);

    LinkedList list2;
    list2.addNode(2);
    list2.addNode(4);
    list2.addNode(8);
 
    cout<<"original:"<<endl;
    list1.display();
    list2.display();

    Solution s;
    LinkedList ans;
    ans.head = s.mergeTwoLists(list1.head,list2.head);
    cout<<"Merge: ";
    ans.display();

}
