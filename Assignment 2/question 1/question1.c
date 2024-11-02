
#include <stdio.h>

int main() {
int arr[5], smallest, second_smallest, i;
int n=5;
printf("Enter %d elements:\n", n);
for(i=0; i<n; i++){
    printf("elements -%d: ", i);
    scanf("%d", &arr[i]);
    
}
smallest=9999;
second_smallest=9999;
for(i=0; i<n; i++){
    if(arr[i]<smallest){
        smallest=arr[i];
    }
}
for(i=0; i<n; i++){
    if(arr[i]>smallest && arr[i]<second_smallest){
        second_smallest=arr[i];
    }
}
if(second_smallest==9999){
    printf("No second smallest element found");
}
else{
    printf("second smallest element is:%d\n", second_smallest);
}

    
return 0;
}