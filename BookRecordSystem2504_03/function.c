# include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
# include<malloc.h>
#include"header.h"

int insert_head()
{
    struct tbt_node *tmp;
    head=(tbt_node *)malloc(sizeof(tbt_node));
    head->info.book_id= infinity;
    head->left=thread;
    head->left_ptr=head;
    head->right=childlink       ;
    head->right_ptr=head;
}/*End of insert_head()*/

int find(int item,tbt_node **par,tbt_node **loc)
{
    tbt_node *ptr,*ptrsave;
    if(head->left_ptr==head)  /* If tree is empty*/
    {
        *loc=NULL;
        *par=head;
        return 0;
    }
    if(item==head->left_ptr->info.book_id) /* item is at head->left_ptr */
    {
        *loc=head->left_ptr;
        *par=head;
        return 0;
    }
    ptr=head->left_ptr;
    while(ptr!=head)
    {
        ptrsave=ptr;
        if( item < ptr->info.book_id )
        {
            if(ptr->left==childlink)
                ptr=ptr->left_ptr;
            else
                break;
        }
        else
             if(item > ptr->info.book_id)
             {
            if(ptr->right==childlink)
                ptr=ptr->right_ptr;
            else
                break;
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

/* Creating threaded binary search tree */

tbt_node *insert(tbt_data details)
{
    tbt_node *tmp,*parent,*location;
    int item=details.book_id;
    
    find(item,&parent,&location);

    if(location!=NULL)
    {
        printf("Item already present");
        return head;
    }

    tmp=(tbt_node *)malloc(sizeof(tbt_node));
    tmp->info=details;
    tmp->left=thread;
    tmp->right=thread;

    if(parent==head) /*tree is empty*/
    {
        head->left=childlink;
        head->left_ptr=tmp;
        tmp->left_ptr=head;
        tmp->right_ptr=head;
        
        return head;
    }
    else
        if( item < parent->info.book_id )
        {
            tmp->left_ptr=parent->left_ptr;
            tmp->right_ptr=parent;
            parent->left=childlink;
            parent->left_ptr=tmp;
        
                return head;
        }
        else
        {
            tmp->left_ptr=parent;
            tmp->right_ptr=parent->right_ptr;
            parent->right=childlink;
            parent->right_ptr=tmp;
        
        return head;
        }
        
}/*End of insert()*/

/* Finding succeeder */

tbt_node *in_succ(tbt_node *ptr)
{
    tbt_node *succ;
    if(ptr->right==thread)
        succ=ptr->right_ptr;
    else
    {
        ptr=ptr->right_ptr;
        while(ptr->left==childlink)
            ptr=ptr->left_ptr;
        succ=ptr;
    }
    return succ;
}/*End of in_succ()*/

/* Finding predecessor */

tbt_node *in_pred(tbt_node *ptr)
{
    tbt_node *pred;
    if(ptr->left==thread)
        pred=ptr->left_ptr;
    else
    {
        ptr=ptr->left_ptr;
        while(ptr->right==childlink)
            ptr=ptr->right_ptr;
        pred=ptr;
    }
    return pred;
}/*End of in_pred()*/

/* Displaying all nodes */

void inorder()
{
    tbt_node *ptr;
    if(head->left_ptr==head)
    {
        printf("Tree is empty");
        return;
    }

    ptr=head->left_ptr;

    /*Find the leftmost node and traverse it */

    while(ptr->left==childlink)
        ptr=ptr->left_ptr;
    printf("%d | %s | %s\n",ptr->info.book_id,ptr->info.book_name,ptr->info.book_author);

    while( 1 )
    {
        ptr=in_succ(ptr);
        if(ptr==head)     /*If last node reached */
            break;
        printf("%d | %s | %s\n",ptr->info.book_id,ptr->info.book_name,ptr->info.book_author);
    } /*End of while*/
}/*End of inorder()*/

