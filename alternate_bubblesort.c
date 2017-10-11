void bubble_sort() {
  Node *first_sorted = NULL;
 
  while (first_sorted != first->next) {
    Node *prev = first;
    Node *tmp  = first->next;
   
    while (first_sorted != tmp->next) {
      if (tmp->value > tmp->next->value) {
        prev->next = tmp->next;
        tmp->next = prev->next->next;
        prev->next->next = tmp;
        prev = prev->next;
      } else {
        prev = tmp;
        tmp = tmp->next;
      }
    }
   
    first_sorted = tmp;
  }
}
