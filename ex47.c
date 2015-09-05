/*
Exercise #46
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
  int x;
  struct node *next;
};
void displayList(struct node *conductor, struct node *root);
void append(int num, struct node *root);
void prepend(int value, struct node **list);

int main()
{

    struct node *root;       
    struct node *conductor;  

    root = malloc( sizeof(struct node) );  
    root->next = 0;   
    root->x = 12;
    conductor = root; 
    if ( conductor != 0 ) {
        while ( conductor->next != 0)
        {
            conductor = conductor->next;
        }
    }
    conductor->next = malloc( sizeof(struct node) );  

    conductor = conductor->next; 

    if ( conductor == 0 )
    {
        printf( "Out of memory" );
        return 0;
    }

    conductor->next = 0;         
    conductor->x = 42;
	
    append(5,root);   
    prepend(1, &root);
    displayList(conductor, root);

    
    

    return 0;
}
void displayList(struct node *conductor, struct node *root){
	conductor = root;
	if ( conductor != 0 ) 
	{ /* Makes sure there is a place to start */
	    while ( conductor->next != 0 ) {
	        printf( "%d\n", conductor->x );
	        conductor = conductor->next;
	    }
	    printf( "%d\n", conductor->x );
	}
}

// append function.
void append(int num, struct node *root)
{
    struct node *temp,*right;
    temp= (struct node *)malloc(sizeof(struct node));
    temp->x=num;
    right=(struct node *)root;
    while(right->next != NULL)
    right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}
void prepend(int value, struct node **list){
    struct node *temp = (struct node*) malloc (sizeof (struct node));
    temp->x = value;
    temp->next = *list;
    *list = temp;
}
 
