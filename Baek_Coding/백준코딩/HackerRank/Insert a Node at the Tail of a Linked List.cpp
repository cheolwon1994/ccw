SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* rtnList = head;
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    while (head) {
        if (head->next == nullptr) break;
        head = head->next;
    }
    if (head == nullptr) return node;
    head->next = node;
    return rtnList;
}