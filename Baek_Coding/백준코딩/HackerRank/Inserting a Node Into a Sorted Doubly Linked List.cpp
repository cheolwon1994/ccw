DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    int cur;
    while (head) {
        cur = head->data;
        if (data <= cur) {
            DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
            node->prev = head->prev;
            node->next = head;
            if(head->prev!=nullptr)
                head->prev->next = node;
            else
                head->prev = node;
            break;
        }
        else {
            if (head->next != nullptr) {
                head = head->next;
            }
            else {
                DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
                node->prev = head;
                node->next = head->next;
                head->next = node;
                break;
            }
        }
    }
    while (head->prev != nullptr) {
        head = head->prev;
    }
    return head;
}