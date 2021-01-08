/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedList* revlist = new DoublyLinkedList();
    while(1){
        if(head->next)
            head = head->next;
        else break;
    }
    while(head){
        revlist->insert_node(head->data);
        head = head->prev;
    }
    return revlist->head;
}