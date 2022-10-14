#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(struct node *p, int n){
    int i=0;
   
    for(i=0; i<n; i++){
        struct node *q= (struct node*)malloc(sizeof(struct node));
        printf("enter a value for node-%d: ", i+2);
        scanf("%d", &q->data);
        p->next=q;
        q->next=NULL;
        p=q;
       
    }
    return p;
}struct node *print(struct node *p){
    while(p!=NULL){
        printf("%d->", p->data);
        p=p->next;
    }printf("\n");
}struct node *insert_begin(struct node *head){
    struct node *q= (struct node*)malloc(sizeof(struct node));
    printf("enter a value for the new node: ");
    scanf("%d", &q->data);
    q->next=head;
    head=q;
    return head;
}struct node *insert_end(struct node *p){
    struct node *q= (struct node*)malloc(sizeof(struct node));
    printf("enter a value for the new node: ");
    scanf("%d", &q->data);
    while(p->next!=NULL){
        p=p->next;
    }p->next=q;
    q->next=NULL;
   
}struct node *insert_middle(struct node *p){
    int i;
    printf("enter the datat after which you want to add the new node: ");
    scanf("%d", &i);
    struct node *q= (struct node*)malloc(sizeof(struct node));
    printf("enter a value for the new node: ");
    scanf("%d", &q->data);
    while(p!=NULL){
        if(p->data == i){
            goto add;
        }
        p=p->next;
    }add:
    q->next=p->next;
    p->next=q;
   
}struct node *del_begin(struct node *head){
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp=head->next;
    head=temp;
    print(head);
    return head;
}struct node *del_end(struct node *p){
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    while(p->next->next!=NULL){
        p=p->next;
    }
    temp=p->next;
    p->next=NULL;
    free(temp);
}struct node *del_middle(struct node *p){
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    int i;
    printf("enter the value of the node which needs to be deleted: ");
    scanf("%d", &i);
    while(p!=NULL){
        if(p->next->data == i){
            goto del;
        }
        p=p->next;
    }del:
    temp=p->next;
    p->next=temp->next;
    free(temp);
}struct node *search(struct node *head){
    struct node *p=head;
    int i;
    printf("enter a value to check for existence: ");
    scanf("%d", &i);
    while(p!=NULL){
        if(p->data == i){
            goto found;
        }
        p=p->next;
    }printf("value not found!\n");
    return p;
    found:
    printf("value found!\n");
}
int main() {
    struct node *head= (struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    printf("enter a value for the first node: ");
    scanf("%d", &head->data);
    int n;
    printf("enter the number of nodes you want to add: ");
    scanf("%d", &n);
    create(head,n);
    print(head);
    while (1){
		printf("\n1.Display\n2.Insert at beginning\n3.Insert in middle\n4.Insert at end\n5.Delete from beginning\n6.Delete from middle\n7.Delete from end\n8.Search an element\n9.Exit\n\nEnter your choice: ");
		int ch;
		scanf("%d",&ch);
		if (ch == 1){
			print(head);
		}
		
		else if (ch == 2) {
			insert_begin(head);
			print(head);
		}
		
		else if (ch == 3) {
			insert_middle(head);
			print(head);
		}
		
		else if (ch == 4) {
			insert_end(head);
			print(head);
		}
		
		else if (ch == 5) {
			del_begin(head);
			print(head);
		}
		
		else if (ch == 6) {
			del_middle(head);
			print(head);
		}
		
		else if (ch == 7) {
			del_end(head);
			print(head);
		}
		
		else if (ch == 8) {
			search(head);
			print(head);
		}
		
		else if (ch == 9){
			break;
		}
	}
    return 0;
}
