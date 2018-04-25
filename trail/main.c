/* C program to implement Threaded binary tree */

# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <malloc.h>
#define infinity 9999
#include"header.h"



int main()
{
    int choice,num;
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
         case 1:
            printf("Enter the number to be inserted : ");
            scanf("%d",&num);
            insert(num);
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

