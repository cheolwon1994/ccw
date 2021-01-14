SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* node = head;
    int cnt=1;
    while(head){
        if(cnt==position){
            SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
            newNode->next = head->next;
            head->next = newNode;
            head = head->next;
        }
        cnt++;
        head = head->next;
    }
    return node;
}