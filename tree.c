#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE *root;

//insert node recurse
void rec_insert_node(struct NODE *n,struct NODE *r){
    if (strcmp(n->word,r->word)>0){
        if (r->left==NULL){
            r->left=n;
        }
        else{
            rec_insert_node(n,r->left);
        }
    }
    else if (strcmp(n->word,r->word)<0){
        if (r->right==NULL){
            r->right=n;
        }
        else{
            rec_insert_node(n,r->right);
        }
    }
    else{
        return;
    }
}

//insert_node
void insert_node(char *string){
    struct NODE *newnode=(struct NODE *)malloc(sizeof(struct NODE));
    newnode->word=string;
    if (root!=NULL){
        rec_insert_node(newnode,root);
    }
    else{
        root=newnode;
    }
}

//print tree
void print_tree(struct NODE *r){
    if (r==NULL){
        return;
    }
    //print trees recurs
    else{
        print_tree(r->right);
        printf("%s\n",r->word);
        print_tree(r->left);
    }
}