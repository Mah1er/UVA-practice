#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void count_sort(int * arr,int len,int exp,int times)
{

    int *output=(int *)malloc(sizeof(int)*len);
    int buckets[10]={0};

    for(int i=0;i<len;i++)
        buckets[(arr[i]/exp)%10]++;
    
    for(int i=1;i<10;i++)
        buckets[i]+=buckets[i-1];
    
    for(int i=len-1;i>=0;i--)
    {
        output[buckets[(arr[i]/exp)%10]-1]=arr[i];
        buckets[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<len;i++)
        arr[i]=output[i];

    if(times==1)
    {
        for(int i=0;i<len;i++)
            printf("%d,",output[i]);
        printf("\n");
    }
    free(output);
}


void RadixSort(int *arr,int len,int times)
{
    int max=arr[0];
    for(int i=0;i<len;i++)
        if(max<arr[i]) max=arr[i];

    for(int exp=1;max/exp>0 && times>0 ;exp*=10,times--)
        count_sort(arr,len,exp,times);
}

int main()
{
    int arr[21];
    int count=0;
    char str[100];
    fgets(str,100,stdin);
    int x=0,y;

    for(int i=0;i<strlen(str)-2 && str[i]!='\n';i++)
    {
        if(str[i]!=',')
        {
            y=str[i]-'0';
            x=x*10+y;
        }
        else
        {
            arr[count++]=x;
            x=0;
        }
    }
    arr[count++]=x;

    
    int times;
    scanf("%d",&times);

    RadixSort(arr,count,times);

    return 0;
}