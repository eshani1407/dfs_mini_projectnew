/* C program to implement Threaded binary tree */

#define infinity 9999

#define SIZE 20

typedef enum { thread,childlink} boolean;

typedef char tbt_element_type;

typedef struct data{
	int book_id;
	tbt_element_type  book_name [SIZE];
	tbt_element_type  book_author [SIZE];
}tbt_data;

typedef struct tbt_node
{
    struct tbt_node *left_ptr;
    boolean left;
    tbt_data info;
    boolean right;
    struct tbt_node *right_ptr;
}tbt_node;

tbt_node *head;

struct tbt_node *in_succ(struct tbt_node *p);
struct tbt_node *in_pred(struct tbt_node *p);


int insert_head();
int find(int item,tbt_node **par,tbt_node **loc);
tbt_node *insert(tbt_data details);
tbt_node *in_succ(tbt_node *ptr);
tbt_node *in_pred(tbt_node *ptr);
void inorder();

