// constructing lists
#include <iostream>
#include <list>
using namespace std; 

int findInSortRotateList(int array[], int start, int end, int number)
{
    int len = end - start;
    
    int pivot = -1;
    int mid = (start+end) / 2;
    
    if (len == 0) return -1;
    
    if (array[start] < array[end])
    {
        //return findInSortedArray(array, len, number);
        printf ("no pivot");
    }
    
    while (end >= start)
    {
        if ((mid+1 < end) && (array[mid+1] > array[end]))
        {
            start = mid+1;
            
        }
        
        else if ((mid-1 > start) && (array[mid-1] < array[start]))
        {
            //pivot is inside here
            end = mid-1;
          
        }
        else
        {
            pivot = mid;
            break;
        }
        
        mid = (start+end) / 2;
    }

    printf ("%d \n", array[mid]);
    
    return 0;
    
}
int main ()
{
  // constructors used in the same order as described above:
  list<int> first;                                // empty list of ints
  list<int> second (4,100);                       // four ints with value 100
  list<int> third (second.begin(),second.end());  // iterating through second
  list<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  cout << "The contents of fifth are: ";
  for (list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
    cout << *it << ' ';

  cout << '\n';
  
  int array[] = {45};
  findInSortRotateList(array,0, sizeof(array)/sizeof(array[0])-1,100);
  

  return 0;
}