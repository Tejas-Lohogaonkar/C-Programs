#include<stdio.h>
#include<stdlib.h>
struct node                      //Declare Structure NODE
{
	int data;
	struct node* next;
};
typedef struct node node;
node* create_node(node*);        //Declare the functions to be used

node* prepend(node*);
node* append(node*);
void print_list(node*);
node* insert_before(node*,int);
node* insert_after(node*,int);
node* delete_front(node*);
node* delete_last(node*);
node* delete_mid(node*,int);
int main()
{
       node* head=(node*)malloc(sizeof(node));//Create the very first node
	   head->next=NULL;
	   printf("Enter data of first node:\n");//Input data in first node
	   scanf("%d",&head->data);
	   printf("1st node is created at location %u \n", head);
	   int prev,after,nd;
	   
	      int n,m=0;
	      do
	      {
			printf("\n");
	         printf("1) Prepend Node\n");
	         printf("2) Append Node\n");
	         printf("3) Print List\n");
			 printf("4) Insert Before\n");
			 printf("5) Insert after\n");
			 printf("6) Delete Front Node\n");
			 printf("7) Delete Last Node\n");
			 printf("8) Delete Intermediate Node\n");
		     printf("choose[1-8]\n");
	         scanf("%d",&n);

         switch(n)
		 {
		 case 1:head=prepend(head);
			 printf("Now the address of head node is %u \n", head);
			 break;
		 case 2:append(head);
			 printf("Now the address of head node is %u \n", head);
			 break;
		 case 3:printf("\nThe current list is:\n"); print_list(head);
			 break;
		 case 4: printf("Enter data of node before which a new node is to be created:\n");
			 scanf("%d",&after);
			   insert_before(head,after);
			   break;

		 case 5:printf("Enter data of node after which a new node is to be created:\n");
			 scanf("%d",&prev);			    
			    insert_after(head,prev);
				break;
		 case 6:head=delete_front(head);break;
		 case 7:delete_last(head);break;
		 case 8:printf("Enter data of intermediate node to be deleted:\n");scanf("%d",&nd);			    
			     delete_mid(head,nd);break;
		 default:printf("Invalid Input!\n ");break;
		 }

	   printf("\nPress 1 to continue:\n");scanf("%d",&m);
	 
	   }
     while(m==1);
	   
	
	return 0;
}
node* create_node(node* next)                         
{
	node* new_node=(node*)malloc(sizeof(node));
	if(new_node==NULL)               
	{	
	  printf("Memory is full!\n ");
	  exit(0);
	}
	else
	{
	  int n;
	  printf("Input Data\n");
	  scanf("%d",&n);
	  new_node->data=n;
	  new_node->next=next;
	
	return new_node;
	  	  
    }
}

node* prepend(node* head)
{
	node* new_node=create_node(head);

	head=new_node;
	return head;
}
node* append(node *head)
{
	node* cursor=head;
	while(cursor->next!=NULL)
	{
		cursor=cursor->next;
	}
	node* new_node=create_node(NULL);
	cursor->next=new_node;
	return head;
}
void print_list(node* head)
{
	node* cursor=head;
	while(cursor!=NULL)
	{
		printf("%d \t",cursor->data);
		cursor=cursor->next;
	} 
   printf("\n");
}

node* insert_before(node* head,int after)
{
	node* cursor=head;
	node* back=NULL;           
	
	while(cursor->data!=after)
	{
	    back=cursor;
	    cursor=cursor->next; 
	}
	node* new_node=create_node(back->next);
	back->next=new_node;
	return head;
}
node* insert_after(node* head,int prev)
{
	node* cursor=head;
	while(cursor->data!=prev)
	{
	   cursor=cursor->next;
	}
	if(cursor!=NULL)
	{
	   node* new_node=create_node(cursor->next);
	   cursor->next=new_node;
	}
	return head;
}	
node* delete_front(node* head)
{
	node* temp=head;
	head=head->next;
	temp->next=NULL;
	free(temp);
	return head;
}
node* delete_last(node* head)
{
      node* cursor=head;
      if(head==NULL)              
	 return NULL;
      node* back=NULL;
      while(cursor->next!=NULL)
      {
	          
          back=cursor;
          cursor=cursor->next;
      }
       if(back!=NULL)
           back->next=NULL;
     free(cursor);
     return head;
}
node* delete_mid(node* head,int nd)
{
    
      if(nd==head->data)               
      { 
         head=delete_front(head);
         return head;

      }
	 

      node* cursor=head;
      node* back=NULL;                        
      while(cursor->data!=nd)
      { 
	 back=cursor;
         cursor=cursor->next;
      }
      if(cursor!=NULL)
       {
	  node* temp=back->next;
	  back->next=temp->next;
          temp->next=NULL;
	  free(temp);
	}
	return head;
}

