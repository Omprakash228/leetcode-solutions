while(head != NULL && reversed_head != NULL) {
                if(head -> val != reversed_head -> val)
                    return false;
                head = head -> next;
                reversed_head = reversed_head -> next;
            }