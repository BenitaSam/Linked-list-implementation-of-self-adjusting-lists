#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

/* push at front */
Node* push_front(Node* head, int v) {
    Node* n = new Node();
    n->val = v;
    n->next = head;
    return n;
}

/* find node with value v, move it to front if found; return new head */
Node* find_move_to_front(Node* head, int v) {
    if (!head) return head;
    if (head->val == v) return head; // already front
    Node* prev = head;
    Node* cur = head->next;
    while (cur) {
        if (cur->val == v) {
            prev->next = cur->next; // unlink
            cur->next = head;      // move to front
            head = cur;
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    return head; // not found
}

/* free whole list */
void free_list(Node* head) {
    while (head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
}


int main() {
    Node* head = nullptr;
    head = push_front(head, 1); // 1
    head = push_front(head, 2); // 2,1
    head = push_front(head, 3); // 3,2,1
    head = find_move_to_front(head, 2); // 2,3,1
    for (Node* p = head; p; p = p->next) cout << p->val << ' ';
    cout << '\n';
    free_list(head);
    return 0;
}