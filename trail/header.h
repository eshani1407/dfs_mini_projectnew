/* C program to implement Threaded binary tree */

#define infinity 9999

typedef enum { thread,childlink} boolean;
struct tbt_node *in_succ(struct tbt_node *p);
struct tbt_node *in_pred(struct tbt_node *p);

typedef struct tbt_node
{
    struct tbt_node *left_ptr;
    boolean left;
    int info;
    boolean right;
    struct tbt_node *right_ptr;
}tbt_node;

tbt_node *head=NULL;


int insert_head();
int find(int item,tbt_node **par,tbt_node **loc);
int insert(int item);
tbt_node *in_succ(tbt_node *ptr);
tbt_node *in_pred(tbt_node *ptr);
void inorder();

