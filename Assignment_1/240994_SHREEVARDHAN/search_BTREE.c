#include"B_TREE.h"
struct Node* search(struct Node* head,int value)
{
    if(head==NULL)
        return head;
    int keyscount=head->count;
    int *keyval=head->keys;
    struct Node** kid=head->child;
    for(int i=0;i<keyscount;i++)
    {
        if(i==0 && value<keyval[i])
            return search(kid[i],value);
        else if(value==keyval[i])
            return head;
        else if(i<keyscount-1 && keyval[i]<value && value<keyval[i+1])
            return search(kid[i+1],value); 
        else if(i==3 && value>keyval[i])
            return search(kid[i+1],value);
    }
}
