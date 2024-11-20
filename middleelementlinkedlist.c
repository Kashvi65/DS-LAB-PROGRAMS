typedef struct ListNode* NODE;
struct ListNode* middleNode(struct ListNode* first) {
    int count = 0, mid;
    NODE curr = first;
    if (first == NULL) {
        return NULL;
    }
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    if (count % 2 == 0) {
        mid = count / 2 + 1;
    }
    else {
        mid = (count + 1) / 2;
    }

    curr = first;
    count = 1;
    while (curr != NULL && count < mid) {
        curr = curr->next;
        count++;
    }
    return curr;
}
