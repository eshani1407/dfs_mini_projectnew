/*
*Author         : Eshani Shet Kurtarkar(1726)
                  Sameer Gaounkar
*Program        : Implementation of Storing records of a book using threaded binary tree (ADT Specifications).
*Modified Date  : 24th April 2018 
*/
 

#define SIZE 100

//typedef short int boolean;

typedef enum { thread,link} boolean;

typedef struct data{
	int book_id;
	char book_name[SIZE], book_type[SIZE], book_author[SIZE];	
}data_type;

typedef struct tbt_node{
	struct tbt_node *left_ptr;
	boolean left;
	data_type info;
	boolean right;
	struct tbt_node *right_ptr;
}tbtNodeType;


tbtNodeType *parent,*location, *tree;


tbtNodeType *in_succ(tbtNodeType *p);
tbtNodeType *in_pred(tbtNodeType *p);


typedef tbtNodeType *tbt_type;

//tbt_type  *tree=NULL;


/*********************************************************************************************/


char getValidResponse();
void printIntro(char *intro);



/*********************************************************************************************/
tbt_type createTree();
/*
**
**ADT Specification: createTree() 
**
**		Function	:Initializes tree to an empty state.
**		Preconditions   : None
**		Input           : None
**		Output          : tree(tbt_type)
**		Postconditions	: tree exists and is empty.
**
*/



/*********************************************************************************************/
tbt_type insertData(tbt_type tree,data_type newdata);
tbt_type insert_tree();
/*
**
**ADT Specification: insertData() 
**
**		Function        : Adds new book record to the existing records
**		Preconditions   : tree is existing
**		Input           : tree(tbt_type)
			          newdata(data_type)
**		Output          : tree(tbt_type)
**		Postconditions	: tree=(existing tree)+(newdata).
**
*/


/*********************************************************************************************/
int find(int item,tbtNodeType **par,tbtNodeType **loc);
/*
**
**ADT Specification: find() 
**
**		Function	:Search the book based on book_id.
**		Preconditions   : tree is existing
**		Input           : item(int)
                                  **par(tbtNodeType)
                                  **loc(tbtNodeType)
**		Output          : true(1) or false(0)
**		Postconditions	: none		//no modifications done to the tree
**
*/


/*********************************************************************************************/
//data_type searchBook(tbt_type tree, int search_book_id, data_type *temp);
/*
**
**ADT Specification: searchBook() 
**
**		Function	:Search the book based on book_id.
**		Preconditions   : tree is existing
**		Input           : tree(tbt_type)
				  search_book_id(int)
				  *temp(data_type)
**		Output          : temp(data_type)
**		Postconditions	: none		//no modifications done to the tree
**
*/


/*********************************************************************************************/
//void printInorder(tbt_type tree);
tbtNodeType *in_pred(tbtNodeType *ptr);
tbtNodeType *in_succ(tbtNodeType *ptr);
tbt_type inorder();

/*
**
**ADT Specification: printInorder() 
**
**		Function	: prints all the book records in in-order fashion
				  (i.e. left->root->right)
**		Preconditions   : tree is existing
**		Input           : tree(tbt_type)
**		Output          : lists all the records
**		Postconditions	: none 		//no modifications done to the tree
**
*/
