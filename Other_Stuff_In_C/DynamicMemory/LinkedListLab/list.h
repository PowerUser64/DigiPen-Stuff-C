struct Node
{
    int number;        /* data portion    */
    struct Node *next; /* pointer portion */
};

void add_front(struct Node **list, int value);   /* Given a list, add a new node to the front of the list that contains value */
void free_list(struct Node *list);               /* Given a list, free all of the nodes on the list */
void print_list(const struct Node *list);        /* Given a list, print the value of each node. The format specifier for the printf function is "%3i" */
int size_list(const struct Node *list);          /* Given a list, count the number of nodes in the list and return that value */
int sum_list(const struct Node *list);           /* Given a list, add up all of the values in the nodes and return that value */
void add_back(struct Node **list, int value);    /* Given a list, add a new node to the back of the list that contains value */
void remove_item(struct Node **list, int value); /* Given a list, remove the node that contains value. If there are multiple nodes that contain the same value, you will only remove the first one that you encounter */

/*
 * void add_front(struct Node **list, int value);      Given a list, add a new node to the front of the list that contains value.
 * 
 * void add_back(struct Node **list, int value);       Given a list, add a new node to the back of the list that contains value.
 * 
 * void free_list(struct Node *list);	               Given a list, free all of the nodes on the list.
 * 
 * void print_list(const struct Node *list);           Given a list, print the value of each node. The format specifier for the printf function is "%3i".
 * 
 * void remove_item(struct Node **list, int value);    Given a list, remove the node that contains value. If there are multiple nodes that contain the same value, you will only remove the first one that you encounter.
 * 
 * int size_list(const struct Node *list);             Given a list, count the number of nodes in the list and return that value.
 * 
 * int sum_list(const struct Node *list);              Given a list, add up all of the values in the nodes and return that value.
 */