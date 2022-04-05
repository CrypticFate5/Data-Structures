#include <stdio.h>
int n=0;
void insert(int a[],int p,int e){
    for(int i=n-1;i>=p;i--){
        a[i+1]=a[i];
    }
    a[p]=e;
    n+=1;
    printf("Element successfully inserted!\n");
}
void delete(int a[],int p){
    for(int i=p;i<n-1;i++){
        a[i]=a[i+1];
    }
    n-=1;
    printf("Element successfully deleted\n");
}
void search(int a[],int e){
    int flag=0,i;
    for(i=0;i<n;i++){
        if(a[i]==e){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("%d found at %d\n",e,i);
    }
    else{
        printf("Element not found\n");
    }
}
void display(int a[]){
    printf("The elements are:\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int a[100];
    int c;
    printf("WELCOME TO ARRAY IMPLEMENTATION MENU\n");
    do{
        printf("CHOOSE YOUR CHOICE\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d",&c);
        int p,e;
        switch(c){
            case 1:
            printf("Enter the position and the element to be inserted: \n");
            scanf("%d %d",&p,&e);
            insert(a,p,e);
            display(a);
            break;
            case 2:
            printf("Enter the position to be deleted: \n");
            scanf("%d",&p);
            delete(a,p);
            display(a);
            break;
            case 3:
            printf("Enter the element to be found: \n");
            scanf("%d",&e);
            search(a,e);
            break;
            case 4:
            display(a);
            break;
            case 5:
            break;
            default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    while(c<5);
    return 0;
}

