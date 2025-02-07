#include <iostream>
#include <string>
using namespace std;

class WordDictionary {
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
    
    // 若遇到'.'，則使用dfs函式遍歷所有字母，且從第j個開始到結尾
    bool dfs(string word,TrieNode* root,int j){
        TrieNode* cur = root;
        for(int i = j;i < word.length();i++){
            char ch = word[i];
            // 若字符不為'.'，則前進至下個node，如同Trie的search一樣
            if(ch != '.'){
                int index = ch - 'a';
                if(cur->child[index] == nullptr){  // 代表此字符不存在於路徑上
                    return false;
                }
                cur = cur->child[index];
            }
            // ch為'.'，將其當為所有字母節點遍歷一次
            else{  
                // 遍歷cur的所有child子節點(26個字母)
                for(TrieNode* node:cur->child){
                    // 遞迴呼叫dfs，且字串從i+1開始
                    if(node != nullptr && dfs(word,node,i+1)){
                        return true;
                    }
                }
                return false;
            }
        }
        // 字串都遍歷完畢，也有可能其不Trie裡的關鍵字，還要看最後一個node的isEndOfWord是否為true
        return cur->isEndOfWord;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char ch:word){
            int index = ch - 'a';
            if(cur->child[index] == nullptr){
                cur->child[index] = new TrieNode();
            }
            cur = cur->child[index];
        }
        cur->isEndOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word,root,0);
    }
};

int main(){
    WordDictionary w;
    w.addWord("bad");
    w.addWord("dad");
    w.addWord("mad");
    cout<<"Is 'pad' in Trie: "<<w.search("pad")<<endl; 
    cout<<"Is 'bad' in Trie: "<<w.search("bad")<<endl; 
    cout<<"Is '.ad' in Trie: "<<w.search(".ad")<<endl;  
    cout<<"Is 'b..' in Trie: "<<w.search("b..");
}
