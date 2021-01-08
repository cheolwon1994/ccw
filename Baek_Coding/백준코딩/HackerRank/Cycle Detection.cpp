/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool has_cycle(SinglyLinkedListNode* head) {
    int i=0;
    while(head){
        head=head->next;
        i++;
        if(i>1000) return true;
    }   
    return false;
}