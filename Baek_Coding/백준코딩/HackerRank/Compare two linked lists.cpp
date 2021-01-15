bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while(1){
        if(head1 == nullptr && head2 == nullptr) return true;
        else if((head1 == nullptr && head2 !=nullptr) || (head1 != nullptr && head2 ==nullptr)) return false;
        else{
            if(head1->data != head2->data) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
    }
}