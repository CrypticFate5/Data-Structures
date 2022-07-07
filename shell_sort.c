#include <stdio.h>
void shellSort(int*arr,int n){
    int gap,i,j;
    for(gap=n/2;gap>0;gap/=2){
        for(i=gap;i<n;i++){
            int temp=arr[i];
            for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }

    }
}
int main(){
    int n=8;
    int arr[]={40,20,97,14,60,61,70,30};
    shellSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
