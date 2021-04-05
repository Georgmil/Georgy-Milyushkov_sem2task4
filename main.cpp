#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
    int id;
    struct Node *next;
    } list;

void push(list **head,int value);
void insert_end(list **head,int value);
void insertafter(list *head, int value, int after);
void insertbefore(list **head, int value, int before);
void pop(list **head);
void poplast(list **head);
void popmiddle(list **head, int position);
void printlink(list *nodeptr);
void individual(list *head1, list *head2);


int main()
{
    list *head=NULL;
    list *head1=NULL;
    head=NULL;

    int n = 1;
	while (n) {
		printf("\n");
		printf("This is a menu, you will now see the options:\n");
		printf("\n");
		printf("To add node in the begining(push) of L1 press 1\n");
        printf("To add node after a specific node in L1 press 2\n");
        printf("To add node before a specific node in L1 press 3\n");
        printf("To add node in the end of L1 press 4\n");
        printf("To print L1 press 5\n");
        printf("To delete (pop) first node in L1 press 6\n");
        printf("To delete n-th node in L1 press 7\n");
        printf("To delete the last node in L1 press 8\n");
		printf("\n");
		printf("To add node in the begining(push) of L2 press 10\n");
        printf("To add node after a specific node in L2 press 20\n");
        printf("To add node before a specific node in L2 press 30\n");
        printf("To add node in the end of L2 press 40\n");
        printf("To print L2 press 50\n");
        printf("To delete (pop) first node in L2 press 60\n");
        printf("To delete n-th node in L2 press 70\n");
        printf("To delete the last node in L2 press 80\n");
		printf("\n");
		printf("Individaul task(Linked list L with elements from L1 which are not in L2 press 100\n");
		scanf("%d", &n);
		printf("\n");
		switch (n) {
		case 1:
		    int a;
		    printf("Value of node you want to add:");
		    scanf("%d",&a);
		    push(&head,a);
		    printf("\nL1 is now:\n");
		    printlink(head);
            printf("\n\n"); break;

		case 2:
		    int b,c;
		    printf("\nEnter the value of the node you want to add:");
		    scanf("%d",&b);
		    printf("\nEnter value of the node previous node: ");
		    scanf("%d",&c);
		    insertafter(head,b,c);
		    printf("\nL1 is now:\n");
		    printlink(head);
            printf("\n\n"); break;
        case 3:
		    int d,e;
		    printf("\nEnter the value of the node you want to add:");
		    scanf("%d",&d);
		    printf("\nEnter value of the next node: ");
		    scanf("%d",&e);
		    insertbefore(&head,d,e);
		    printf("\nL1 is now:\n");
		    printlink(head);
            printf("\n\n");break;
        case 4:
		    int f;
		    printf("\nEnter the value of the node you want to add:");
		    scanf("%d",&f);
		    insert_end(&head,f);
		    printf("\nL1 is now:\n");
		    printlink(head);
            printf("\n\n"); break;
        case 5:
            printf("\nL1 linked list is:\n");
		    printlink(head);
            printf("\n\n"); break;
        case 6:
            pop(&head);
            printf("\nL1 after deleting first node is:\n");
		    printlink(head);
            printf("\n\n"); break;
        case 7:
            int g;
            printf("\nWhat is the position number of the node you want to delete:");
            scanf("%d",&g);
            popmiddle(&head,g);
            printf("L1 after deleting %d-th node is:\n",g);
		    printlink(head);
            printf("\n\n"); break;

        case 8:
            poplast(&head);
            printf("\nL1 after deleting last node is:\n");
		    printlink(head);
            printf("\n\n"); break;
		case 10:
		    int a1;
		    printf("Value of node you want to add:");
		    scanf("%d",&a1);
		    push(&head1,a1);
		    printf("\nL2 is now:\n");
		    printlink(head1);
            printf("\n\n"); break;
		case 20:
		    int b1,c1;
		    printf("\nEnter the value of the node you want to add:");
		    scanf("%d",&b1);
		    printf("\nEnter value of the node previous node: ");
		    scanf("%d",&c1);
		    insertafter(head1,b1,c1);
		    printf("\nL2 is now:\n");
		    printlink(head1);
            printf("\n\n"); break;
        case 30:
		    int d1,e1;
		    printf("\nEnter the value of the node you want to add:");
		    scanf("%d",&d1);
		    printf("\nEnter value of the next node: ");
		    scanf("%d",&e1);
		    insertbefore(&head1,d1,e1);
		    printf("\nL2 is now:\n");
		    printlink(head1);
            printf("\n\n"); break;
        case 40:
		    int f1;
		    printf("\nEnter the value of the node you want to add:");
		    scanf("%d",&f1);
		    insert_end(&head1,f1);
		    printf("\nL2 is now:\n");
		    printlink(head1);
            printf("\n\n"); break;
        case 50:
            printf("\nL2 linked list is:\n");
		    printlink(head1);
            printf("\n\n"); break;
        case 60:
            pop(&head1);
            printf("\nL2 after deleting first node is:\n");
		    printlink(head1);
            printf("\n\n"); break;
        case 70:
            int g1;
            printf("\nWhat is the position number of the node you want to delete:");
            scanf("%d",&g1);
            popmiddle(&head,g1);
            printf("L2 after deleting %d-th node is:\n",g1);
		    printlink(head1);
            printf("\n\n");break;

        case 80:
            poplast(&head1);
            printf("\nL2 after deleting last node is:\n");
		    printlink(head1);
            printf("\n\n"); break;

        case 100:
            printf("Linked list L1 is:\n");
            printlink(head);
            printf("\n");
            printf("Linked list L2 is \n");
            printlink(head1);
            printf("\n");
            individual(head,head1);
            printf("\n\n"); break;


		}
	}


    return 0;
}

void push(list **head,int value){

        list* newnode=(list*)malloc(sizeof(list));

        newnode->id=value;

        newnode->next=*head;

        *head=newnode;

}

void insert_end(list **head,int value){

    list *ptr=NULL, *temp=NULL;


    temp=(list*)malloc(sizeof(list));

    temp->id=value;
    temp ->next=NULL;
    if(*head==NULL){
        *head=temp;
        return;
    }

    ptr=*head;
    while(ptr->next!=NULL){
        ptr=ptr->next;}
    ptr->next=temp;
}
void insertafter(list *head, int value, int after){

    list *newnode=NULL;
    list *tmp=head;

    while(tmp){

        if(tmp->id==after){
            newnode=(list*)malloc(sizeof(list));

            newnode->id=value;
            newnode->next=tmp->next;
            tmp->next=newnode;
            return;
        }
        tmp=tmp->next;

    }

}
void insertbefore(list **head, int value, int before){

    list *newnode=NULL;
    list *tmp=*head;

    newnode=(list*)malloc(sizeof(list));


    newnode->id=value;

    if((*head)->id==value){
        newnode->next=*head;
        *head=newnode;
        return;
    }

    while(tmp && tmp->next){

        if(tmp->next->id==before){
            newnode->next=tmp->next;
            tmp->next=newnode;
            return;
        }
        tmp=tmp->next;
    }


}
void pop(list **head){
    list *tmp;

    tmp=*head;
    *head=(*head)->next;
    free(tmp);
}
void poplast(list **head){

    list *prev=NULL, *current=NULL;

    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
    }

    prev=*head;
    current=prev->next;

    while(current->next){
        prev=prev->next;
        current=current->next;
    }
    prev->next=NULL;
    free(current);
}
void popmiddle(list **head, int position){
    list *current=*head;
    list *previous=*head;

    if(*head==NULL)
        printf("List is already empty");
    else if(position==1){
        *head=current->next;
        free(current);
        current=NULL;
    }
    else{
        while(position!=1){
            previous=current;
            current=current->next;
            position--;
            }
        previous->next=current->next;
        free(current);
        current=NULL;
    }

}
void printlink(list *nodeptr){
    while(nodeptr!=NULL){

        printf("%d",nodeptr->id);
        nodeptr=nodeptr->next;
        if(nodeptr!=NULL)
            printf("-->");
    }
        }

void individual(list *head1, list *head2){
    list *head3=NULL;
    list *ptr1=head1;
    list *ptr2=head2;
    bool test;

    while(ptr1!=NULL){
            ptr2=head2;
        while(ptr2!=NULL){
            if(ptr1->id==ptr2->id){
                test=false;
                ptr2=ptr2->next;
                break;}
            else{
                ptr2=ptr2->next;
                test=true;}
        }
        if(test){
            insert_end(&head3,ptr1->id);
            ptr1=ptr1->next;}
        else
            ptr1=ptr1->next;

     }
     printf("Linked list L is:\n");
     printlink(head3);

}



