SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode* newList = new SinglyLinkedListNode(data);
    newList->next = llist;
    return newList;
}