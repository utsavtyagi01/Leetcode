struct Node{
    Node *links[26];
    bool flag=false;

    bool contains(char ch){
        if(links[ch-'a']!=NULL)
        return true;

        return false;
    }

    void putword(char ch){
        links[ch-'a']=new Node();
    }

    Node * next(char ch){
        return links[ch-'a'];
    }

    bool last(){
        return flag;
    }

    void setend(){
        flag = true;
    }
};


class Trie {
    Node* root;
public:
    Trie() {
        root= new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->contains(word[i])){
                node->putword(word[i]);
            }

            node=node->next(word[i]);
        }

        node->setend();
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(!node->contains(word[i]))
            return false;
            node=node->next(word[i]);
        }

        return node->last();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->contains(prefix[i]))
            return false;
            node=node->next(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
