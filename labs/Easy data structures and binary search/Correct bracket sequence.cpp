#include <bits/stdc++.h>
using namespace std;

struct Node {
    char key;
    Node *next = nullptr;
};

class List {
    private:
        Node* head = new Node();
    public:
        bool is_empty(){
           return (head->next == nullptr);
        }
        void push(char value) {
            Node *p = new Node();
            p->next = head->next;
            p->key = value;
            head->next = p;
        }
        bool del(char end) {
            bool ans = true;
            Node *p = new Node();
            p->key = head->next->key;
            if ((end == ')' and p->key != '(') or (end == ']' and p->key != '[')) {
                ans = false;
            }
            head->next = head->next->next;
            return ans;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    string s;
    while(cin>>s) {
        List l;
        bool r = true;
        bool ans = true;
        for (int i = 0;i < s.size(); i++) {
            if (s[i] == '(' or s[i] == '[') {
                l.push(s[i]);
            } else {
                if (l.is_empty()){
                    r = false;
                } else
                    r = l.del(s[i]);
            }
            if (r == false) {
                ans = false;
            }
        }
        if (ans == true and l.is_empty()) {
            cout<<"YES"<<'\n';
        } else {
            cout<<"NO"<<'\n';
        }
        //l.head->next = nullptr;
    }

    return 0;
}
