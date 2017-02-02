#include <stdio.h>
#include <stdlib.h>

void grow1 ( int*, int* );
void grow2 ( int**, int* );
int* grow3 ( int*, int* );

int main (int argc, char** argv)
{
 int* arr1;
 int size1 = 10;
 int max = 0;
 int i;

 /* allocate an array of "size1" values */
 arr1 = (int *) malloc (sizeof(int) * size1);


 /* add some new values into the array */
 for (i = 0 ; i < 30  ; i++)
  {
   /* allocate mote space if array is filled */
   if ( max >= size1 )
   {
     /* allocate new space for the larger array */
     int *temp;
     temp = (int *) malloc ( size1 * 2 * sizeof(int) );
 
     /* copy the existing values from the original array to the larger array */
     for ( i = 0 ; i < size1 ; i++)
       temp[i] = arr1[i];

     /* return the allocated memory from the original array back to the OS */
     free (arr1);

     /* have the variable arr1 refer to the location in memory of the larger array */
     arr1 = temp;

     /* update the size1 variable to properly reflect the current size of the array */ 
     size1 = size1 * 2;
   }

   /* store value in array */
   arr1[max] = 1000 + i;
   max++;
  }

 /* print out the values just stored into the array */
 printf ("\nThe original values in the array:\n");
 for (i = 0 ; i < max; i++)
  {
   printf ("%d ", arr1[i]);
   if ((i+1)%10 == 0)
     printf ("\n");
  }
 printf ("\n");

 /* add some new values into the array */
 for (i = 0 ; i < 30  ; i++)
  {
   /* allocate mote space if array is filled */
   if ( max >= size1 )
   {
     /* grow1 ( arr1, &size1); */     /* Warning does not work */

     /* comment out one of the two statements */
     grow2 ( &arr1, &size1); 
     /* arr1 = grow3 ( arr1, &size1);  */
   }

   /* store value in array */
   arr1[max] = 2000 + i;
   max++;
  }

 /* print out the values just stored into the array */
 printf ("\nThe original values in the array:\n");
 for (i = 0 ; i < max; i++)
  {
   printf ("%d ", arr1[i]);
   if ((i+1)%10 == 0)
     printf ("\n");
  }
 printf ("\n");



 /* print out the values for ALL positions in the array */
 printf ("\nThe current values for ALL positions in the array:\n");
 for (i = 0 ; i < size1; i++)
  {
   printf ("%d ", arr1[i]);
   if ((i+1)%10 == 0)
     printf ("\n");
  }
 printf ("\n");


 return 1;
}

/*  this code does NOT work */
/* array parameter is pass-by-value */ 
void grow1 (int* arr, int *sz)
{
 /* allocate new space for the larger array */
 int *temp;
 temp = (int *) malloc ( *sz * 2 * sizeof(int) );
 
 /* copy the existing values from the original array to the larger array */
 int i;
 for ( i = 0 ; i < *sz ; i++)
   temp[i] = arr[i];

 /* return the allocated memory from the original array back to the OS */
 free (arr);

 /* have the variable arr1 refer to the location in memory of the larger array */
 arr = temp;

 /* update the sz variable to properly reflect the current size of the array */ 
 *sz = *sz * 2;
}

/* array parameter is  not really pass-by-reference */ 
/* array parameter is pass-by-address  */ 
void grow2 (int** arr1, int *sz)
{
 /* create a deferenced access to the array */
 int*  tarr = *arr1;

 /* allocate new space for the larger array */
 int *temp;
 temp = (int *) malloc ( *sz * 2 * sizeof(int) );
 
 /* copy the existing values from the original array to the larger array */
 int i;
 for ( i = 0 ; i < *sz ; i++)
   /* temp[i] = (*arr1)[i]; */
   temp[i] = tarr[i];

 /* return the allocated memory from the original array back to the OS */
 free (*arr1);

 /* have the variable arr1 refer to the location in memory of the larger array */
 *arr1 = temp;

 /* update the sz variable to properly reflect the current size of the array */
 *sz = *sz * 2;
}

/* array parameter is pass-by-reference */ 
int* grow3 (int* arr1, int *sz)
{
 /* allocate new space for the larger array */
 int *temp;
 temp = (int *) malloc ( *sz * 2 * sizeof(int) );
 
 /* copy the existing values from the original array to the larger array */
 int i;
 for ( i = 0 ; i < *sz ; i++)
   temp[i] = arr1[i];

 /* return the allocated memory from the original array back to the OS */
 free (arr1);

 /* have the variable arr1 refer to the location in memory of the larger array */
 arr1 = temp;

 /* update the sz variable to properly reflect the current size of the array */ 
 *sz = *sz * 2;

 /* return the updated array address back to the calling code */
 return arr1;
}