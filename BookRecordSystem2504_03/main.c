/* C program to implement Threaded binary tree */

# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <malloc.h>
#include"header.h"

int main()
{
    int choice,num;
    
    head=NULL;
    tbt_data details;
    insert_head();
    while(1)
    {
        printf("\n");
        printf("1.Insert\n");
        printf("2.Inorder Traversal\n");
        printf("3.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
         case 1:printf("Enter the number to be inserted : ");
                printf("\n  Book-id :");
                scanf("%d",&details.book_id);
                printf("\n  Name of the book: ");
                getchar();
                scanf("%[^\n]s",&details.book_name);
                printf("\n  Authore of the book: ");
                getchar();
                scanf("%[^\n]s",&details.book_author);   
            
                head=insert(details);
            break;
         case 2:
            inorder();
            break;
         case 3:
            exit(-1);
         default:
            printf("Wrong choice\n");
        }/*End of switch */
    }/*End of while */
}/*End of main()*/


/* Output of Threaded Binary Search Tree Program */

