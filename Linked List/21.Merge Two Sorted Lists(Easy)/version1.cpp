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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 若list1為空，則返回list2這裡可行是因為若list2也為空也會返回null，符合題意
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        if(list1->val <= list2->val){
            // 若list1值較小，則list1會先取出並且next指向下一步[list1->next,list2]比較後的結果
            list1->next =  mergeTwoLists(list1->next,list2);
            // 若list1的值較小，會返回list1接在後面
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1,list2->next);
            // 若list2的值較小，會返回list2接在後面
            return list2;
        }
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
