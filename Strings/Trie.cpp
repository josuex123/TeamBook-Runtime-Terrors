struct Node
{
    Node *next[26];
    bool overNode;

    Node(){
        for(int i = 0; i < 26; i++){
            overNode = false;
            next[i] = NULL;
        }
    }

    void insertWord(string s){
        Node *cur = this;
        int size = s.length();
        for(int i = 0; i < size; i++){
            int imap = s[i] - 'a';
            if(!cur->next[imap]){
                cur->next[imap] = new Node();
            }
            cur = cur->next[imap];
        }
        cur->overNode = true;
    }


    bool searchWord(string s){
        Node *cur = this;
        int size = s.length();
        cout << size <<endl;
        bool founded = true;
        for(int i = 0; i < size; i++){
            int imap = s[i] - 'a';
            cout << imap << " " << s[i] << endl;
            if(!cur->next[imap]){
                founded = false;
                break;
            }
            cur = cur->next[imap]; // Update the pointer to the next node
        }
        return founded && cur->overNode;
    }
};
