#include<stdio.h>
#include<stdlib.h>

struct node {
    int num;
    struct node * next;
}*head;

void build(int n)
{
    int i, num;
    struct node *preptr, *newnode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of the list:\n");
        scanf("%d", &num);
        head->num = num;
        head->next = NULL;
        preptr = head;
        for(i=2; i<=n; i++) { 
            newnode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &num);
            newnode->num = num;
            newnode->next = NULL;	
            preptr->next = newnode;	
            preptr = newnode;   		
        }
        preptr->next = head; 
    }
}

void display(struct node *head)
{
    struct node *tmp;
    int n = 1;
    
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        tmp = head;
        
        
        do {
            printf("%d ",tmp->num);
            tmp = tmp->next;
            n++;
        }while(tmp != head);
    }
}
int count(struct node *head)
{
    int cnt = 0;
    struct node *cur = head;

    
    do 
    {
        cur = cur->next;
        cnt++;
    } while (cur != head);

    return cnt;
}

int main(void)
{
    int n;
    struct node *head1 = NULL; 
    struct node *head2 = NULL;
    head = NULL;
    printf("Enter the size of circular linked list: ");
    scanf("%d ", &n);
    build(n); 
    printf("\nCircular linked list data:\n");
    display(head);
    printf("\nTotal number of nodes are: %d",count(head));
}