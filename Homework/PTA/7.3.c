#include <stdio.h>
#define Cutoff 3

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void InsertionSort(int arr[], int len,int left)
{
    int i, j;
    int tmp;

    for (i = 1; i < len; i++)
    {
        tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp;
    }
    
    printf("insert(%d,%d):",left,len);
    for(int k=0;k<10;k++)
        printf("%d,",arr[k-left]);
    printf("\n");
}

int Median3(int arr[], int Left, int Right)
{
    int Center = (Left + Right) / 2;

    if (arr[Left] > arr[Center])
        swap(&arr[Left], &arr[Center]);
    if (arr[Left] > arr[Right])
        swap(&arr[Left], &arr[Right]);
    if (arr[Center] > arr[Right])
        swap(&arr[Center], &arr[Right]);

    swap(&arr[Center], &arr[Right - 1]);

    // for (int q = Left; q <= Right; q++)
    //     printf("%d,", arr[q]);
    // printf("\n");
    return arr[Right - 1];
}

void Qsort(int arr[], int Left, int Right)
{
    int i, j;
    int pivot;

    if (Left + Cutoff <= Right)
    {
        pivot = Median3(arr, Left, Right);
        i = Left;
        j = Right - 1;
        for (;;)
        {
            while (arr[++i] < pivot)
            {
                // for(int q=Left;q<=Right;q++)
                //     printf("%d,",arr[q]);
                // printf("\n");
            }
            while (arr[--j] > pivot)
            {
                // for(int q=Left;q<=Right;q++)
                //     printf("%d,",arr[q]);
                // printf("\n");
            }
            if (i < j)
            {
                swap(&arr[i], &arr[j]);
                // for(int q=Left;q<=Right;q++)
                //     printf("%d,",arr[q]);
                // printf("\n");
            }
            else
                break;
        }
        swap(&arr[i], &arr[Right - 1]);
        // for(int q=Left;q<=Right;q++)
        //     printf("%d,",arr[q]);
        // printf("\n");
        printf("Qsort(%d,%d):",Left,Right);
        for(int k=0;k<10;k++)
            printf("%d,",arr[k]);
    printf("\n");


        Qsort(arr, Left, i - 1);
        Qsort(arr, i + 1, Right);
    }
    else
        InsertionSort(arr + Left, Right - Left + 1,Left);
}

void Quicksort(int arr[], int len)
{
    Qsort(arr, 0, len - 1);
}

int main()
{
    int arr[10] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
    int index;
    scanf("%d", &index);

    int pivot = arr[index];
    swap(&arr[index], &arr[9]);

    int i = -1, j = 9;
    for (;;)
    {
        while (arr[++i] < pivot)
        {
            // for(int q=Left;q<=Right;q++)
            //     printf("%d,",arr[q]);
            // printf("\n");
        }
        while (arr[--j] > pivot)
        {
            // for(int q=Left;q<=Right;q++)
            //     printf("%d,",arr[q]);
            // printf("\n");
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
            // for(int q=Left;q<=Right;q++)
            //     printf("%d,",arr[q]);
            // printf("\n");
        }
        else
            break;
    }
    swap(&arr[i], &arr[9]);
    printf("Qsort(0,9):");
    for(int k=0;k<10;k++)
        printf("%d,",arr[k]);
    printf("\n");

    Qsort(arr,0,i-1);
    Qsort(arr,i+1,9);
    

    return 0;
}
