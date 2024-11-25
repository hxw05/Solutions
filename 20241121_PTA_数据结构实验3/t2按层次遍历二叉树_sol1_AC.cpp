#include "iostream"
#include "queue"
#include "string"

using namespace std;

typedef struct Node {
    Node *lchild = nullptr;
    Node *rchild = nullptr;
    char value;
} Tree;

Tree *preOrderTraverse(Tree *t) {
    char ch;
    cin >> ch;
    if (ch == '#') {
        return nullptr;
    } else {
        if (t == nullptr) t = new Tree;
        t->value = ch;
        t->lchild = preOrderTraverse(t->lchild);
        t->rchild = preOrderTraverse(t->rchild);
        return t;
    }
}

int main() {
    Tree *tree = new Tree;
    tree = preOrderTraverse(tree);

    queue<Tree *> q;

    q.push(tree);
    while (!q.empty()) {
        Tree *current = q.front();
        q.pop();
        cout << current->value;
        if (current->lchild != nullptr) q.push(current->lchild);
        if (current->rchild != nullptr) q.push(current->rchild);
    }

    delete tree;
}