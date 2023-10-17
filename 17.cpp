#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    
    Node(int item) {
        value = item;
        left = nullptr;
        right = nullptr;
    }
};

Node *insertIntoBST(Node *rootNode, int item) {
    if (rootNode == nullptr) return new Node(item);
    if (item < rootNode -> value) rootNode -> left = insertIntoBST(rootNode -> left, item);
    else if (item >= rootNode -> value) rootNode -> right = insertIntoBST(rootNode -> right, item);
    return rootNode;
}

Node *search(Node *node, int item) {
    if (node == nullptr || node -> value == item) return node;
    if (item < node -> value) return search(node -> left, item);
    return search(node -> right, item);
}

int main() {
    int n; cin >> n;
    int items[n];
    for (int i = 0; i < n; i++) cin >> items[i];
    
    Node* rootNode = nullptr;
    for (int i = 0; i < n; i++) {
        rootNode = insertIntoBST(rootNode, items[i]);
    }
    
    int target; cin >> target;
    Node *result = search(rootNode, target);
    if (result != nullptr) cout <<  "This item is in BST\n";
    else cout <<  "This item isn't in BST\n";

    rootNode = insertIntoBST(rootNode, target);
    
    return 0;
}
