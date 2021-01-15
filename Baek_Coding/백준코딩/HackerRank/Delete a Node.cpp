SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if(position==0) return head->next;
    SinglyLinkedListNode* node = head;
    int cnt=0;
    while(head){
        if(cnt+1==position){
            head->next = head->next->next;
            break;
        }
        head = head->next;
        cnt++;
    }
    return node;
}