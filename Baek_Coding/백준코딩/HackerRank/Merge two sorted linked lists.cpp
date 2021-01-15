SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedList* li = new SinglyLinkedList();
    while(head1 || head2){
        if(head1==nullptr){
            while(head2){
                li->insert_node(head2->data);
                head2 = head2->next;
            }
        }
        else if(head2==nullptr){
            while(head1){
                li->insert_node(head1->data);
                head1 = head1->next;
            }
        }
        else{
            int h1 = head1->data;
            int h2 = head2->data;
            if(h1<=h2){
                li->insert_node(h1);
                head1 = head1->next;
            }
            else{
                li->insert_node(h2);
                head2 = head2->next;
            }
        }
    }
    return li->head;
}