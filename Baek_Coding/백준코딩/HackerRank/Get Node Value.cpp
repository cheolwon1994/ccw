int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    SinglyLinkedListNode* node = head;
    int cnt=0;
    while(head){
        cnt++;
        head = head->next;
    }
    cnt = (cnt-1)-positionFromTail;
    int val;
    while(node){
        if(cnt==0){ 
            val = node->data;
            break;
        }
        cnt--;
        node = node->next;
    }
    return val;
}