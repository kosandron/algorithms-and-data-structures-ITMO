#include <bits/stdc++.h>
using namespace std;

struct Node {
    std::string key = "";
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    struct Node *parent = nullptr;
    int first = 0;
    int second = 0;
    int third = 0;
};

Node* null = new Node();

class Tree {
public:
    int tsize = 0;
    Node* root = nullptr;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;

    void insert(string z) {
        tsize++;
        Node* curr = root;
        if (curr == nullptr) {
            curr->key = z;
            root = curr;
        } else {
            while (true) {
                if (z < curr->key) {
                    if (curr->left == nullptr) {
                        Node* new_node = new Node();
                        new_node->key = z;
                        curr->left = new_node;
                        new_node->parent = curr;
                        break;
                    } else {
                        curr = curr->left;
                    }
                } else {
                    if (curr->right == nullptr) {
                        Node* new_node = new Node();
                        new_node->key = z;
                        curr->right = new_node;
                        new_node->parent = curr;
                        break;
                    } else {
                        curr = curr->right;
                    }
                }
            }
        }
        /*Node new_v;
        new_v.key = z;
        if (z < place->key) {
            if (place->left == nullptr) {
                new_v.parent = place;
                place->left = &new_v;
            } else {
                insert(z, place->left);
            }
        } else {
            if (place->right == nullptr) {
                new_v.parent = place;
                place->right = &new_v;
            } else {
                insert(z, place->right);
            }
        }*/
    }

    Node* search(string value) {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->key == value) return curr;
            else if (curr->key > value) curr = curr->left;
            else if (curr->key < value) curr = curr->right;
        }
        return curr;
    }
/*
    Node* minimum (Node* place) {
        Node* curr = place;
        if (curr->left == nullptr) {
            return curr;
        }

        return minimum(curr->left);
    }

    Node* maximum(Node* place) {
        Node* curr = place;
        if (curr->right == nullptr) {
            return curr;
        }

        return maximum(curr->right);
    }

    Node* prev(int x) {
        Node* curr = root;
        Node* ans = new Node();
        while (curr != nullptr) {
            if (curr->key >= x) {
                curr = curr->left;
            } else {
                ans = curr;
                curr = curr->right;
            }
        }
        return ans;
    }

    Node* next(int x) {
        Node* curr = root;
        Node* ans = new Node();
        while (curr != nullptr) {
            if (curr->key > x) {
                ans = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return ans;
    }

    void delet(Node* x) {
        tsize--;
        Node* p = x->parent;
        if (x->left == nullptr and x->right == nullptr) {
            if (p->left == x) {
                p->left = nullptr;
            }
            if (p->right == x) {
                p->right = nullptr;
            }
        } else if (x->left == nullptr or x->right == nullptr) {
            if (x->left == nullptr) {
                if (p->left == x) {
                    p->left = x->right;
                } else {
                    p->right = x->right;
                }
                    x->right->parent = p;
            } else {
                if (p->left == x)
                    p->left = x->left;
                else
                    p->right = x->left;
                x->left->parent = p;
            }
        } else {
            Node* successor = next(x->key);
            x->key = successor->key;
            if (successor->parent->left == successor) {
                successor->parent->left = successor->right;
                if (successor->right != nullptr) {
                    successor->right->parent = successor->parent;
                }
            } else {
                successor->parent->right = successor->right;
                if (successor->right != nullptr) {
                    successor->right->parent = successor->parent;
                }
            }
        }
    }
*/
    void go(Node* x) {
        Node* curr = x;
        if (curr->left != nullptr) {
            go(curr->left);
        }
        if (curr->right != nullptr) {
            go(curr->right);
        }
        int ball = 0;
        if (curr->first + curr->second + curr->third == 2) {
            ball = 1;
        } else if (curr->first + curr->second + curr->third == 1) {
            ball = 3;
        }

        if (curr->first == 1) {
            p1 += ball;
        }
        if (curr->second == 1) {
            p2 += ball;
        }
        if (curr->third == 1) {
            p3 += ball;
        }
    }
};

int main() {
    //null -> key = INT_MAX;
    int n;
    cin>>n;
    string s;
    Tree t;
    vector <std::string> b(n);
    vector <std::string> c(n);
    vector <std::string> d(n);
    for (int i = 0; i <  n; i++) {
        cin >> s;
        b[i] = s;
        Node* a = t.search(s);
         if (a == nullptr) {
             if (t.root == nullptr) {
                Node* new_v = new Node();
                new_v->key = s;
                t.root = new_v;
            } else {
                t.insert(s);
            }
        }
    }
    for (int i = 0; i <  n; i++) {
        cin >> s;
        c[i] = s;
        Node* a = t.search(s);
         if (a == nullptr) {
             if (t.root == nullptr) {
                Node* new_v = new Node();
                new_v->key = s;
                t.root = new_v;
            } else {
                t.insert(s);
            }
        }
    }
    for (int i = 0; i <  n; i++) {
        cin >> s;
        d[i] = s;
        Node* a = t.search(s);
         if (a == nullptr) {
             if (t.root == nullptr) {
                Node* new_v = new Node();
                new_v->key = s;
                t.root = new_v;
            } else {
                t.insert(s);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        Node* a = t.search(b[i]);
        a->first++;
    }
    for (int i = 0; i < n; i++) {
        Node* a = t.search(c[i]);
        a->second++;
    }
    for (int i = 0; i < n; i++) {
        Node* a = t.search(d[i]);
        a->third++;
    }
    t.go(t.root);
    cout << t.p1 <<" " << t.p2 << " " << t.p3;

    return 0;
}
