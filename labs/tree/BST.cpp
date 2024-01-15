#include <iostream>
using namespace std;

struct Node {
    int key = INT_MIN;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    struct Node *parent = nullptr;
};

Node* null = new Node();

class Tree {
public:
    Node* root = nullptr;
    void insert(int z) {
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

    Node* search(int value) {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->key == value) return curr;
            else if (curr->key > value) curr = curr->left;
            else if (curr->key < value) curr = curr->right;
        }
        return curr;
    }

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
        Node* ans = nullptr;
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
        Node* ans = nullptr;
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

    void delet(Node* d) {
        Node* x = d;
        if (x->parent == nullptr) {
            if (x->left == nullptr and x->right == nullptr) {
                root = nullptr;
            } else if (x->left == nullptr and x->right != nullptr) {
                root = x->right;
                x->right->parent = nullptr;
            } else if (x->left != nullptr and x->right == nullptr) {
                root = x->left;
                x->left->parent = nullptr;
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
        } else {
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
}
};

int main() {
    null -> key = INT_MAX;
    string s;
    int z;
    Tree t;
    while (cin>>s) {
        cin >> z;
        if (s == "insert") {
            if (t.root == nullptr) {
                Node* new_v = new Node();
                new_v->key = z;
                t.root = new_v;
            } else if (t.search(z) == nullptr){
                t.insert(z);
            }
        } else if (s == "delete") {
            if (!(t.root == nullptr || t.search(z) == nullptr)) {
                t.delet(t.search(z));
            }
        } else if (s == "exists") {
            if (t.search(z) != nullptr) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        } else if (s == "next") {
            if (t.root == nullptr) {
                cout << "none\n";
            } else {
                Node* b = t.next( z);
                if (b == nullptr || b->key <= z) {
                    cout << "none\n";
                } else
                    cout << b->key << '\n';
            }
        } else if (s == "prev") {
            if (t.root == nullptr) {
                cout << "none\n";
            } else {
                Node* b = t.prev( z);
                if (b == nullptr || b->key >= z) {
                    cout << "none\n";
                } else
                    cout << b->key << '\n';
            }
        }
    }
    return 0;
}
