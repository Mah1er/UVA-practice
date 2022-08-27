void InsertionSort(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        int tmp;
        for(int j=i;j>0;j--)
        {
            if(arr[j-1]>arr[j])
            {
                tmp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=tmp;
            }
        }
    }
}
