void reversePrint(SinglyLinkedListNode* head) {
    stack<int> s;
    while(head){
        s.push(head->data);
        head = head->next;
    }
    while(!s.empty()){
        cout << s.top()<<'\n';
        s.pop();
    }
}