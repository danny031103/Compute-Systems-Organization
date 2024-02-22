struct NODE{
    char *word;
    struct NODE *left;
    struct NODE *right;
};
struct NODE *root;
void insert_node(char *string);
void print_tree(struct NODE *r);