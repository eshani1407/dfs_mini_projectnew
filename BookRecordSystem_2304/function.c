/*
*Author         : Eshani Shet Kurtarkar(1726)
                  Sameer Gaounkar
*Program        : Implementation of Storing records of a book using threaded binary tree (ADT Specifications).
*Modified Date  : 23rd April 2018 
*/
 



#define SIZE 100
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"header.h"



/**********************************************************************************************************************************************/

//to get the valid response from the user
char getValidResponse()
{
	char t;
	do{
		getchar();
		scanf("%c",&t);
		t=toupper(t);
		if(t=='Y' || t=='N')
		 {
			 break;
		 }
		else
		 {
		  	printf("invalid respose enter Y or N\n");
		 }
	}
	while(1);
	return t;
}



/**********************************************************************************************************************************************/

// to display the program qts.
void printIntro(char *intro)
{
	printf("\n-------------------------------------------------------\n");	
	printf("\n%s\n",intro);
	printf("\n--------------------------------------------------------\n");
}


/*****************************************************************************************************************************/

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

tbt_type createTree()
{
        tree=NULL;
	return tree;
}

/*****************************************************************************************************************************/

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
tbt_type insertData(tbt_type tree,data_type newdata)
{

        tbtNodeType *newnode;
	int item;
	
	item=newdata.book_id;
	
        find(item,&parent,&location);

        if(location!=NULL)
        {
                printf("\nBook is already added in record\n");
                return tree;
        }
        
        newnode=(tbtNodeType *)malloc(sizeof(tbtNodeType));
        if(newnode==NULL)
        {
                printf("\nERROR\n");
                exit(-1);
        }
                
        newnode->info=newdata;
        newnode->left=thread;
        newnode->right=thread;

        if(parent==tree) /*tree is empty*/
        {
                tree->left=link;
                tree->left_ptr=newnode;
                newnode->left_ptr=tree;
                newnode->right_ptr=tree;
        }
        
        else if( item < parent->info.book_id )
        {
                newnode->left_ptr=parent->left_ptr;
                newnode->right_ptr=parent;
                parent->left=link;
                parent->left_ptr=newnode;
        }
        else
        {
                newnode->left_ptr=parent;
                newnode->right_ptr=parent->right_ptr;
                parent->right=link;
                parent->right_ptr=newnode;
        }
        
        printf("record\n");
        return tree;
}/*End of insert()*/


 /*****************************************************************************************************************************/
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

int find(int item,tbtNodeType **par,tbtNodeType **loc)
{
    tbtNodeType *ptr,*ptrsave;
    
    if(tree->left_ptr==tree)  /* If tree is empty*/
    {
        *loc=NULL;
        *par=tree;
        return 1;
    }
    
    if(item==tree->left_ptr->info.book_id) /* item is at tree->left_ptr */
    {
        *loc=tree->left_ptr;
        *par=tree;
        return 1;
    }
    
    ptr=tree->left_ptr;
    
    while(ptr!=tree)
    {
        ptrsave=ptr;
        if( item < ptr->info.book_id)           /*left sub travel*/
        {       
            if(ptr->left==link)
            {
                ptr=ptr->left_ptr;
            }
            else
            {
                break;
            }
        }
        
        else if(item > ptr->info.book_id)
        {
            if(ptr->right==link)
            {
                ptr=ptr->right_ptr;
            }
            else
            {
                break;
            }
        }
        
        
        if(item==ptr->info.book_id)
        {
            *loc=ptr;
            *par=ptrsave;
            return 0;
        }
                
    }/*End of while*/
    
    *loc=NULL;   /*item not found*/
    *par=ptrsave;
}/*End of find()*/

/*****************************************************************************************************************************/

/*DUMMY root node*/

tbt_type insert_tree()
{
        struct tbtNodeType *tmp;
        tree=(tbtNodeType *)malloc(sizeof(tbtNodeType));
        tree->info.book_id= 9999;                //  tree->info= infinity;
        tree->left=thread;
        tree->left_ptr=tree;
        tree->right=link;
        tree->right_ptr=tree;
}/*End of insert_tree()*/


/*****************************************************************************************************************************/


/* Finding succeeder */

tbtNodeType *in_succ(tbtNodeType *ptr)
{
    tbtNodeType *succ;
    if(ptr->right==thread)
        succ=ptr->right_ptr;
    else
    {
        ptr=ptr->right_ptr;
        while(ptr->left==link)
            ptr=ptr->left_ptr;
        succ=ptr;
    }
    return succ;
}/*End of in_succ()*/


/*****************************************************************************************************************************/

/* Finding predecessor */

tbtNodeType *in_pred(tbtNodeType *ptr)
{
    tbtNodeType *pred;
    if(ptr->left==thread)
        pred=ptr->left_ptr;
    else
    {
        ptr=ptr->left_ptr;
        while(ptr->right==link)
            ptr=ptr->right_ptr;
        pred=ptr;
    }
    return pred;
}/*End of in_pred()*/



/*****************************************************************************************************************************/

/* Displaying all nodes */

int inorder()
{
    tbtNodeType *ptr;
    if(tree->left_ptr==tree)
    {
        printf("Tree is empty");
        return 0;
    }

    ptr=tree->left_ptr;

    /*Find the leftmost node and traverse it */

    while(ptr->left==link)
        ptr=ptr->left_ptr;
    printf("%d ",ptr->info);

    while( 1 )
    {
        ptr=in_succ(ptr);
        if(ptr==tree)     /*If last node reached */
            break;
        printf("%d  ",ptr->info);
    } /*End of while*/
}/*End of inorder()*/

