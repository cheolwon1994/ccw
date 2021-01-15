SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedList* li = new SinglyLinkedList();
    stack<int> s;
    while(head){
        s.push(head->data);
        head = head->next;
    }
    while(!s.empty()){
        li->insert_node(s.top());
        s.pop();
    }   
    return li->head;
}