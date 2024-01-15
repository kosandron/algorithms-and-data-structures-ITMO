#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *next = nullptr;
};

class List {
    private:
        Node* head = new Node();
    public:
        void push(int value) {
            Node *p = new Node();
            p->next = head->next;
            p->key = value;
            head->next = p;
        }
        void del() {
            Node *p = new Node();
            p->key = head->next->key;
            cout<<p->key<<'\n';
            head->next = head->next->next;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    List l;
    for (int i = 0; i < n; i++) {
        char oper;
        cin>>oper;
        if (oper == '+') {
            int value;
            cin >> value;
            l.push(value);
        } else {
            l.del();
        }
    }

    return 0;
}
