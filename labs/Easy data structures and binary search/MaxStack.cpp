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
        p->next = hea#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int maxim;
    Node *next = nullptr;
};

class List {
private:
    Node* head = new Node();
public:
    int maxim_last;
    void push(int value) {
        Node *p = new Node();
        p->next = head->next;
        p->key = value;
        maxim_last = max(maxim_last, value);
        p->maxim = maxim_last;
        head->next = p;
    }
    void maximum() {
        Node *r = new Node();
        r->maxim = head->next->maxim;
        cout<<r->maxim<<'\n';
    }
    void del() {
        Node *p = new Node();
        //cout<<p->key<<'\n';
        head->next = head->next->next;
        p->key = head->next->key;
        maxim_last = p->key;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    List l;
    l.maxim_last = INT_MIN;
    for (int i = 0; i < n; i++) {
        string oper;
        cin>>oper;
        if (oper == "+") {
            int value;
            cin >> value;
            l.push(value);
        } else if (oper == "-"){
            l.del();
        } else {
            l.maximum();
        }
    }

    return 0;
}d->next;
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
