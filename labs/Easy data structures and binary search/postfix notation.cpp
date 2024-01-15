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
    int del() {
        Node *p = new Node();
        p->key = head->next->key;
        int d = p->key;
        head->next = head->next->next;
        return d;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    List l;
    int x;
    cin>>x;
    l.push(x);
    cin>>x;
    l.push(x);
    string oper;
    while (cin>>oper) {
        //cin>>oper;
        if (isdigit(oper[0])) {
            int value = atoi(oper.c_str());;
            l.push(value);
        } else {
            int b = l.del();
            int a = l.del();
            int res = 0;
            if (oper == "+"){
                res = a + b;
            } else if (oper == "-") {
                res = a - b;
            } else if (oper == "*") {
                res = a * b;
            } else if (oper == "/") {
                res = a / b;
            }
            l.push(res);
        }
    }
    x = l.del();
    cout << x;

    return 0;
}
