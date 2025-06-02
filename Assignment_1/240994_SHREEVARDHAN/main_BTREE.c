#include"B_TREE.h"
void freetree(struct Node* head)
{
    if(head==NULL)
        return;
    for(int i=0;i<=head->count;i++)
    {
        if(head->child[i]!=NULL)
            freetree(head->child[i]);
    }
    free(head);
}
int main()
{
    struct Node* head=NULL;
    int value;
    char name[MAX_LENGTH];
    int *a=(int*)malloc(4*sizeof(int));
    char **names=(char**)malloc(4*sizeof(char*));
    printf("Enter the first 4 elements:\n");
    for(int i=0;i<4;i++)
    {
        names[i]=(char*)malloc(MAX_LENGTH*sizeof(char));
        scanf("%d %s",&a[i],names[i]);  
        if(search(a[i],head)!=NULL)
        {
            free(names[i]);
            free(a[i]);
            i-=1;
        }   
    }
    head=insert_first4(head,a,names);
    int t;
    printf("Enter the elements:");
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s",&value,name);
        if(search(value,head)!=NULL)
        {
            t-=1;
            continue;
        }
        insert(head,value,name);
    }
    // int choice;
    // printf("Enter your choice:\nCase 1: Searching\nCase 2:Deletion");
    // scanf("%d",&choice);
    // struct Node* ptr;
    // if(choice==1)
    // {
    //     printf("Enter the key you want to search:");
    //     scanf("%d",&value);
    //     ptr=search(head,value);
    //     if(ptr!=NULL)
    //         printf("Element present");
    //     else
    //         printf("Element not found");
    // }
    // else if(choice==2)
    // {
    //     printf("Enter the key to be deleted:");
    //     scanf("%d",&value);
    //     ptr=search(head,value);
    //     if(ptr!=NULL)
    //     {
    //         delete(ptr,value);
    //         printf("Element is deleted");
    //     }
    //     else
    //         printf("Element not present only");
    // }
    // else
    //     printf("Invalid Choice");

    int h=height(head);
    int nodes=func(head);
    struct Node*** arr=(struct Node***)malloc(h*sizeof(struct Node**));
    for(int i=0;i<h;i++) 
        arr[i]=(struct Node**)malloc(nodes*sizeof(struct Node*));
    
    int* indices=(int*)calloc(h,sizeof(int));
    array_bfs(head,h,0,arr,indices);
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<indices[i];j++) 
        {
            for(int k=0;k<arr[i][j]->count;k++)
                printf("[%d: %s] ",arr[i][j]->keys[k],arr[i][j]->names[k]);

            printf("\n");
        }
    }

    free(indices);
    for (int i=0;i<h;i++) 
        free(arr[i]);
    free(arr);
    for (int i=0;i<4;i++) 
        free(names[i]);
    free(names);
    free(a);
}