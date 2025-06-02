#include"B_TREE.h"
int height(struct Node* head)
{
    if(head==NULL)
        return 0;
    int maxheight=0;
    for(int i=0;i<=head->count;i++)
    {
        if(head->child[i]!=NULL)
        {
            int childheight=height(head->child[i]);
            if(childheight>maxheight)
                maxheight=childheight;
        }
    }
    return maxheight+1;
}

int func(struct Node* head)
{
    if(head==NULL)
        return 0;
    int total=1;
    for(int i=0;i<=head->count;i++)
    {
        if(head->child[i]!=NULL)
            total=total+func(head->child[i]);
    }
    return total;
}

void array_bfs(struct Node* head, int max_height, int c, struct Node*** arr, int* indices)
{
    if(head==NULL)
        return;

    arr[c][indices[c]++]=head;
    for (int i=0;i<=head->count;i++) 
    {
        if (head->child[i]!=NULL)
            array_bfs(head->child[i],max_height,c+1,arr,indices);
    }
}