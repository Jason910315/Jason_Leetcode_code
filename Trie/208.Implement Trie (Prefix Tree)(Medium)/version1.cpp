#include <iostream>
#include <string>
using namespace std;

class Trie{
private:
    // 建構TrieNode(Trie結構的節點)
    struct TrieNode{
        TrieNode* child[26]; // node的下個節點為何
        bool isEndOfWord;    // 判斷node是否為字串結尾
        // 建構TrieNode
        TrieNode():isEndOfWord(false){
            for(int i = 0;i < 26;i++){
                child[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;
public:
    // 建構Trie結構
    Trie(){
        root = new TrieNode();  // 設root為新的TrieNode
    }
    // insert
    void insert(string word){
        TrieNode* cur = root;
        for(char ch:word){
            int index = ch - 'a'; // index是ch的ASCII碼
            // 該字符不存在於Trie中，為其創造新節點
            if(cur->child[index] == nullptr){  
                cur->child[index] = new TrieNode();  
            }
            cur = cur->child[index];  // 前進到Trie中的下個字符
        }
        cur->isEndOfWord = true;  // 遍歷完畢，最後一個節點為結尾
    }
    
    // search
    bool search(string word){
        // 有可能某路徑上存在此字串，但其實字串並不在Trie中
        return find(word) && find(word)->isEndOfWord;
    }
    // startWith
    bool startsWith(string prefix){
        // 只需判斷存在即可，不需看其是否為結尾
        return find(prefix);
    }
private:
    // find輔助函式，判斷str是否存在
    TrieNode* find(string str){
        TrieNode* cur = root;
        for(char ch:str){
            int index = ch - 'a'; 
            if(cur->child[index] == nullptr){
                return nullptr; // 代表此字串不存在
            }
            cur = cur->child[index];
        }
        // cur會包含isEndOfWord資訊，可判斷其是否為結尾
        return cur;
    }
};

int main(){
    Trie t;
    t.insert("eat");
    t.insert("dig");
    t.insert("dog");
    cout<<"Is 'dig' in Trie: "<<t.search("dig")<<endl;
    cout<<"Is 'tea' in Trie: "<<t.search("tea")<<endl;
    cout<<"Is 'd' is the prefix in Trie: "<<t.startsWith("d");
}
