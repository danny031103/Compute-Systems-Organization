//packages
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

//constants
#define SIZE 100

//strlen(char *s):  This returns the length of the string s, not including the terminating 0
//strcmp(char *s1, char *s2):  This compares s1 and s2 using alphabetical order (like in a dictionary). 

//global variable hashtable
struct HASHCELL *hashtable[SIZE]={NULL};

//HASHCELL structure
struct HASHCELL{
    char *word;
    struct HASHCELL *next;
};

//hash_string function
int hash_string(char *word){
    unsigned int hash=1;
    for(int c=0;c<strlen(word);c++){
        hash=(hash*7)+word[c];
    }
    return hash%SIZE;
}

//insert_hash_cell functiom
void insert_hash_cell(char *word) {
    int hashind=hash_string(word);
    struct HASHCELL *new_cell=(struct HASHCELL *)malloc(sizeof(struct HASHCELL));
    if (!new_cell){
        printf("Malloc failed\n");
        return;
    }
    new_cell->word=(char *)malloc(strlen(word)+1);
    if (!new_cell->word){
        printf("Malloc failed\n");
        return;
    }
    //strcpy(char *s1, char *s2): This copies the contents of s2 into s1, including the terminating 0
    strcpy(new_cell->word,word);
    new_cell->next=NULL;

    //not empty
    if (hashtable[hashind]!=NULL){
        struct HASHCELL *curr=hashtable[hashind];
        while (curr->next!=NULL){
            if (strcmp(curr->word,word)==0) {
                return;
            }
            curr=curr->next;
        }
        if (strcmp(curr->word,word)==0){
            return;
        }
        curr->next=new_cell;
    }
    //empty
    else{
        hashtable[hashind]=new_cell;
    }

}

//print_hash_table function
void print_hash_table(struct HASHCELL *hashtable[]){
    for(int i=0;i<SIZE;i++){
        printf("%d:",i);
        struct HASHCELL *curr=hashtable[i];
        while(curr!=NULL){
            printf("%s ",curr->word);
            curr=curr->next;
        }
        printf("\n");
    }
}

//main func
int main(){
    char str[100];
    while(scanf("%s",str)!=EOF){
        insert_hash_cell(str);
    }
    //print_hash_table(hashtable);
    for (int i=0;i<SIZE;i++){
        struct HASHCELL *curr=hashtable[i];
        while(curr!=NULL){
            insert_node(curr->word);
            curr=curr->next;
        }
    }
    //print
    print_tree(root);
    return 0;
}
