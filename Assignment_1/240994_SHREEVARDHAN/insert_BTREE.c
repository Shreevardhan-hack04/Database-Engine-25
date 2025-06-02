#include"B_TREE.h"
void sort(int *arr, char **names)
{
    int temp;
    char name_temp[MAX_LENGTH];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                strcpy(name_temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],name_temp);
            }
        }
    }
}
struct Node* createnode()
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));  
    for(int i=0;i<5;i++)
        newnode->child[i]=NULL;
    newnode->prev=NULL;
    newnode->count=0;
    return newnode;
}
struct Node* insert_first4(struct Node* head, int* arr, char** names)
{
    head=createnode();
    sort(arr,names);
    for(int i=0;i<4;i++)
    {
        head->keys[i]=arr[i];
        strcpy(head->names[i],names[i]);
    }
    head->count=4;
    return head;
}
struct Node* insert(struct Node* head,int value,char *name);
struct Node* split_child(struct Node* head, int split_ele,char *name, int *arr,char title[][MAX_LENGTH])
{
    if(head->prev==NULL)
    {
        struct Node **kid=head->child;
        kid[0]=createnode();
        kid[1]=createnode();

        kid[0]->keys[0]=arr[0];
        kid[0]->keys[1]=arr[1];
        kid[1]->keys[0]=arr[3];
        kid[1]->keys[1]=arr[4];

        kid[0]->prev=head;
        kid[1]->prev=head;

        strcpy(kid[0]->names[0],title[0]);
        strcpy(kid[0]->names[1],title[1]);
        strcpy(kid[1]->names[0],title[3]);
        strcpy(kid[1]->names[1],title[4]);
        for(int i=0;i<4;i++)
            head->keys[i]=0;

        head->keys[0]=arr[2];
        strcpy(head->names[0],title[2]);
        return head;
    }
    else
    {
        struct Node* new_head=head->prev;
        return insert(new_head,split_ele,name);
    }

}

struct Node* insert(struct Node* head,int value,char *name)
{
    int keyscount=head->count;
    int *keyval=head->keys;
    char (*name_ptr)[MAX_LENGTH]=head->names;
    struct Node** kid=head->child;
    if(keyscount==0)
    {
        keyval[0]=value;
        strcpy(name_ptr[0],name);
        (head->count)++;
        return head;
    }
    else if(keyscount>0 && keyscount<4)
    {
        for(int i=0;i<keyscount;i++)
        {
            if(i==0 && value<keyval[i])
            {
                if(kid[i]==NULL)
                {
                    for(int j=keyscount;j>i;j--)
                    {
                        keyval[j]=keyval[j-1];
                        strcpy(name_ptr[j],name_ptr[j-1]);
                    }
                    keyval[i]=value;
                    strcpy(name_ptr[i],name);
                    (head->count)++;
                    return head;
                }
                else
                    return insert(kid[i],value,name);
            }
            else if(i<keyscount-1 && value>keyval[i] && value<keyval[i+1])
            {
                if(kid[i+1]==NULL)
                {
                    for(int j=keyscount;j>i;j--)
                    {
                        keyval[j]=keyval[j-1];
                        strcpy(name_ptr[j],name_ptr[j-1]);
                    }
                    keyval[i]=value;
                    strcpy(name_ptr[i],name);
                    (head->count)++;
                    return head;
                }
                else
                    return insert(kid[i+1],value,name);
            }
        }
        if(value>keyval[keyscount-1]) 
        {
            if(kid[keyscount]==NULL)
            {
                keyval[keyscount]=value;
                strcpy(name_ptr[keyscount],name);
                (head->count)++;
                return head;
            }
            else
                return insert(kid[keyscount],value,name);
        }
    }
    else if(keyscount==4)
    {
        int a[5];
        char b[5][MAX_LENGTH];
        for(int i=0;i<keyscount;i++)
        {
            if(value>keyval[i])
            {
                a[i]=keyval[i];
                strcpy(b[i],name_ptr[i]);
            }
            else
            {
                a[i]=value;
                strcpy(b[i],name_ptr[i]);
                for(int j=i;j<keyscount;j++)
                {
                    a[j+1]=keyval[j];
                    strcpy(b[j+1],name_ptr[j]);
                }
                break;
            }
        }
        int split_ele=a[2];
        char split_name[MAX_LENGTH];
        strcpy(split_name,b[2]);
        return split_child(head,split_ele,split_name,a,b);
    }
}