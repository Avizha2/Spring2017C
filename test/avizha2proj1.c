#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Copies the elements of the fromArray into the toArray
void arrayCopy (int fromArray[], int toArray[], int size)
{
	//Most logical approach to copy arrays is a simple for loop to run through all the values of both 
	//arrays to its max size
	int i; // iterating variable
	for(i = 0; i < size; i++)
	{
		toArray[i] = fromArray[i];
	}
	
	return;
}

void sort (int arr[], int size)
{
	//modified insertion sort
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap
   
   for (i = 1; i < size; ++i) 
   {
      j = i;
      // Insert arr[i] into sorted part
      // stopping once arr[i] in correct position
      while (j > 0 && arr[j] < arr[j - 1]) 
	  {
         
         // Swap arr[j] and arr[j - 1]
         temp = arr[j];
         arr[j] = arr[j - 1];
         arr[j - 1] = temp;
         --j;
      }
   }
   
   return;
}


int linSearch (int arr[], int size, int target, int* countComparisons)
{
   int i = 0;
   for (i = 0; i < size; ++i) 
   {
      if (arr[i] == target) 
	  {
		 *countComparisons = i; 
         return i;
      }
   }
   
   return -1; 
}

int binSearch (int arr[], int size, int target, int* countComparisons)
{
   int mid = 0;
   int low = 0;
   int high = 0;
   //tree variables that store mid, low, and high values for Bin search comparisons
   
   
   high = size - 1;
   
   while (high >= low) {
      *countComparisons+=1;
	  mid = (high + low) / 2;
      if (arr[mid] < target) {
         low = mid + 1;
      }
      else if (arr[mid] > target) {
         high = mid - 1;
      }
      else {
         return mid;
      }
   }
   
   return -1; // not found

}

int main()
{
	int val, position1, position2, countComparisons1 =0 , countComparisons2=0;
	int *arr1;
	int *arr2;
	int size = 10;
	int count=0, i;

	arr1 = (int *) malloc (size * sizeof(int) ); //allocate space for the array
	
	printf("Type in the values to be inputed into the array followed by -999\n");
	scanf ("%d", &val);//scan in from input
	arr1[0] = val;
	while(val != -999)
	{
		if(count >= size)
		{
			int *temp;
			temp = (int *) malloc ( size * 2 * sizeof(int) );
			
			for ( i = 0 ; i < size ;i++)
			{
				temp[i] = arr1[i];
			}
			free (arr1);
			arr1 = temp;
			size = size * 2;
		}
		
		arr1[count] = val;
		scanf ("%d", &val);
		count++;
		
	}
	//count = count;
	
	arr2 = (int *) malloc (size * sizeof(int) ); //allocate space for the array2
	arrayCopy(arr1, arr2, count);//copy array1 into array2
	
	sort(arr2,count);//sort array2 for binary search later
	
	printf("Type in the values to be searched through the previous array followed by -999\n\n");
	scanf ("%d", &val);
	/*printf("count:%d\n",count);
		printf("count:%d\n",count);
	//int i;
	for(i=0;i<size;i++)
	{
		printf("%d",arr1[i]);
	}*/// code for debugging
	while(val != -999)
	{

		position1 = linSearch(arr1, count, val, &countComparisons1);
		if(position1 != -1)
		{
			printf("%d was found in the array by linear search with %d comparisons in the %d index\n", val, countComparisons1, position1);
		}
		else
		{
			printf("**%d was NOT found in the array by linear search**\n",val);
		}
		position2 = binSearch(arr2, count-1, val, &countComparisons2);
		if(position2 != -1)
		{
			printf("%d was found in the array by binary search with %d comparisons in the %d index\n\n", val, countComparisons2, position2);
		}
		else
		{
			printf("**%d was NOT found in the array by binary search**\n\n",val);
		}
		scanf ("%d", &val);
	}

return 0;
}