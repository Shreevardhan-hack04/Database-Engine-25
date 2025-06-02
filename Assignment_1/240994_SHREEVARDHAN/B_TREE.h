#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 10

struct Node{
    int keys[4];
    int count;
    struct Node* child[5];
    struct Node* prev;
    char names[4][MAX_LENGTH];

};
