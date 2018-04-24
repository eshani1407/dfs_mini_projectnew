/*
*Author         : Eshani Shet Kurtarkar(1726)
                  Sameer Gaounkar
*Program        : Implementation of Storing records of a book using threaded binary tree (ADT Specifications).
*Modified Date  : 24th April 2018 
*/
 
#include<stdlib.h>
#include<stdio.h>
#include"header.h"

int main()
{
	int choice,opt;
	boolean flag;
	data_type info,temp;
	char response;
	tbt_type  tree=NULL;
	
	printIntro("Implementation of storing records of a book using threaded binary tree");
	tree=createTree();
	
	printf("\n Tree is created\n");	
        insert_tree();

	do
	{
		printf("\nWhat would you like to do?\n");
		printf("\t1: Insert New book record\n");
		printf("\t2: Search a Book\n");
		printf("\t3: Print all books\n");
		printf("\t4: Exit\n");	

	
		printf("\n\t\tEnter Your Choice:");
		scanf("%d",&choice);
	
		switch(choice)
		{
		      case 1:printf("\nDetails of a book\n");
		               printf("  Book-id :");
		               scanf("%d",&info.book_id);
		               
		               printf("\n  Name of the book: ");
			       getchar();
			       scanf("%c",&info.book_name);
			       
			       printf("\n  Authore of the book: ");
			       getchar();
			       scanf("%c",&info.book_author);
			       
			       printf("\n  Type of the book: ");
			       getchar();
			       scanf("%c",&info.book_type);
			       
			       tree=insertData(tree,info);	       
			       break;                   
                        case 3: inorder();
                        case 4: exit(-1);	
			default:printf("\nWrong choice, Please enter the correct option.");
		}
		
		printf("\nWant to continue? (Y/N)");
		response=getValidResponse();
        }
        while(response=='Y');

    return 0;
}
