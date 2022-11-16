#include<stdio.h>

void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void print(int *arr,int len)
{
    for(int i=0;i<len;i++)
        printf("%d,",arr[i]);
    printf("\n");
}

void Ssort_print(int* arr,int len)
{
    int min;
    for(int i=0;i<len-1;i++)
    {
        min=i;
        for(int j=i+1;j<len;j++)
            if(arr[j]<arr[min]) min=j;
        swap(&arr[min],&arr[i]);
        print(arr,len);
        
    }
}


int main()
{
    int arr[21];
    int n;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d,",&arr[i]);
    
    Ssort_print(arr,n);
    return 0;
}

