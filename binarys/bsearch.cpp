#include <stdio.h>
#include <stdlib.h>

int my_bsearch( int data_array[], int len, int data)
{
    if (0 == len) return -1;
        
    int start = 0;
    int end = len -1 ;
    int mid = (start + end ) / 2;
    int count = 0;
    while (start <= end)
    {
        count++;
        if (data_array[mid] == data) 
        {
                printf ("found in %d loop at index %d \n", count, mid);
                return mid;
        }
        
        if (data_array[mid] < data )
        {
            start = mid + 1;
        }
        else
        {
            end = mid -1;              
        }
       
        mid = (start + end) / 2;
    }
}


int main()
{
    int * data;
    
    data = (int *) malloc(1024*1024*sizeof(int));
    
    for (int i =0; i < 1024*1024; i++)
    {
        data[i] = i*2;
    }
    
    
    int result = my_bsearch(data, 1024*1024, 1024);
    
    return result;
    
}

