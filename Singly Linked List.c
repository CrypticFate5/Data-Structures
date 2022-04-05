#include <stdio.h>
#include <stdlib.h>
struct node{
    int element;
    struct node*next;
};
typedef struct node node;

node * find(node*list,int x){
    node*position;
    position=list->next;
    while(position!=NULL && position->element!=x){
        position=position->next;
    }
    return position;
}
node * findPrev(node*list,int x){
    node*position;
    position=list->next;
    while(position!=NULL && position->next->element!=x){
        position=position->next;
    }
    return position;
}
node * findNext(node*list,int x){
    node*position;
    position=find(list,x);
    return position->next;
}
int isEmpty(node*list){
    if(list->next==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isLast(node*position){
    if(position->next==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void traverse(node*list){
    node*position;
    position=list->next;
    if(!isEmpty(list)){
        while(position!=NULL){
            printf("%d ",position->element);
            position=position->next;
        }
        printf("\n");
    }
    else{
        printf("List is Empty!\n");
    }
}
// INSERTION

// Insertion at Beginning:
void insBeg(node*list,int x){
    node *newnode;
    newnode=malloc(sizeof(node));
    newnode->element=x;
    if(!isEmpty(list)){
        newnode->next=list->next;
        list->next=newnode;
    }
    else{
        list->next=newnode;
        newnode->next=NULL;
    }
}

// Insertion at Middle(next to the given position(the integer)):
void insMid(node*list,int p,int x){
    node *newnode;
    node*position;
    newnode=malloc(sizeof(node));
    newnode->element=x;
    if(!isEmpty(list)){
        position=find(list,p);
        newnode->next=position->next;
        position->next=newnode;
    }
    else{
        position=list;
        position->next=newnode;
        newnode->next=NULL;
    }
}

// Insertion at Last:
void insLast(node*list,int x){
    node*position;
    node*newnode;
    newnode=malloc(sizeof(node));
    newnode->element=x;
    newnode->next=NULL;
    position=list;
    if(!isEmpty(list)){
        while(position->next!=NULL){
            position=position->next;
        }
        position->next=newnode;
    }
    else{
        position->next=newnode;
    }
}

// DELETION

// Deletion at the Beginning:
void delBeg(node*list){
    if(!isEmpty(list)){
        node*tempnode;
        node*position;
        position=list->next;
        tempnode=position;
        list->next=tempnode->next;
        printf("The deleted element is %d\n",tempnode->element);
        free(tempnode);
    }
    else{
        printf("List is empty!!\n");
    }
}

// Deletion at Middle:
void delMid(node*list,int p){
    if(!isEmpty(list)){
        node*tempnode;
        node*position;
        position=findPrev(list,p);
        tempnode=position->next;
        position->next=tempnode->next;
        printf("The deleted element is %d\n",tempnode->element);
        free(tempnode);
    }
    else{
        printf("List is Empty!!\n");
    }
}

// Deletion at the End
void delEnd(node*list){
    if(!isEmpty(list)){
        node*tempnode;
        node*position;
        position=list->next;
        while(position->next->next!=NULL){
            position=position->next;
        }
        tempnode=position->next;
        position->next=NULL;
        printf("The element deleted is %d\n",tempnode->element);
        free(tempnode);
    }
    else{
        printf("The list is empty!!!\n");
    }
}
int main(){
    printf("WELCOME TO SINGELY LINKED LIST MENU\n");
    node*list=malloc(sizeof(node));
    list->next=NULL;
    node*position;
    int ch,p,x;
    do{
        printf("1. Insert at the Beginning\n2. Insert at the Middle\n3. Insert at the End\n4. Delete at the Beginning\n5. Delete at the Middle\n6. Delete at the End\n7. Find an element\n8. Traverse\n9. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d",&x);
            insBeg(list,x);
            printf("The list after the operation is: \n");
            traverse(list);
            break;
            case 2:
            printf("Enter the position element and the element to be inserted\n");
            scanf("%d %d",&p,&x);
            insMid(list,p,x);
            printf("The list after the operation is: \n");
            traverse(list);
            break;
            case 3:
            printf("Enter the element to be inserted\n");
            scanf("%d",&x);
            insLast(list,x);
            printf("The list after the operation is: \n");
            traverse(list);
            break;
            case 4:
            delBeg(list);
            printf("The list after the operation is: \n");
            traverse(list);
            break;
            case 5:
            printf("Enter the position element to be deleted\n");
            scanf("%d",&p);
            delMid(list,p);
            printf("The list after the operation is: \n");
            traverse(list);
            break;
            case 6:
            delEnd(list);
            printf("The list after the operation is: \n");
            traverse(list);
            break;
            case 7:
            printf("Enter the element to be found\n");
            scanf("%d",&x);
            if(find(list,x)!=NULL){
                printf("Element found!\n");
            }
            else{
                printf("Element not found!\n");
            }
            break;
            case 8:
            printf("The list is: \n");
            traverse(list);
            break;
            case 9:
            break;
            default:
            printf("Enter valid option!!...");
        }
    }
    while(ch<9);
    return 0;
}
