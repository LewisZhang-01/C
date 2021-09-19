//
//  s10q1.c
//
//  Student name: Zhi Zhang
//  Student number: 18210054
//
#include <stdio.h>
#include <stdlib.h>
/* Define a Node structure */
struct Node
{
    int data; /* "data" is the member which will hold the integer */
    struct Node *nextNode; /* pointer hold the next address */
};

/* Declare the function */
void copy_to_linkedlist(int n,int *a);

void copy_to_linkedlist(int n,int *a)
{
    int i;
    struct Node *head ,*current,*p;
    head = current = NULL; /* Initialize with an Null address */
    for (i = 0 ;i< n;i++)
    {/* Dynamically allocate memory useing malloc */
        p = (struct Node *)malloc(sizeof(struct Node));
        /* Copies the values in the array into the structure */
        p->data = a[i];
        if (head == NULL)
        {/* If it is the first time, assign p to both "head" and "current" */
            head = current = p;
        }
        else
        {/* Otherwise, update the current, make sure it hold the nextnode address */
            current = current->nextNode;
        }
        /* update the nextnode address */
        current->nextNode = p;
    }
    
    /* Assign head address to p again */
    p=head;
    /* while not the end of the list */
    while (p != NULL)
    {/* Display the content of each node */
        printf("%d -> ",p->data);
        /* Update the next pointer*/
        p=p->nextNode;
    }
    printf("NULL\n");
}

int main (void)
{
    int i,n,a[10];
    /* Ask user input the total number they want store in array */
    printf("How many elements do you want to store in an array: ");
    scanf("%d",&n);
    
    int num;
    for (i=0;i<n;i++)
    {/* Ask user input each elements one by one */
        printf("Please enter the NO.%d element:\n",i+1);
        scanf("%d",&num);
        /* store it into array */
        a[i]=num;
    }
    /* Display the user input */
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
    /* Call the function copied to linkedlist */
    copy_to_linkedlist(n,a);
    
    return 0;
}
