#include "unity.h"
#include "sort.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE_ARRAY 5

static int* ARRAY1;
static int* ARRAY2;

// init two identical arrays
static void initArrays(void)
{
    for(int i=0;i<SIZE_ARRAY;i++){
      ARRAY1[i] = rand();
      ARRAY1[i] = rand()%2 == 0 ? ARRAY1[i] : ARRAY1[i]*-1;
      ARRAY2[i] = ARRAY1[i];
    }
}

// check if all elemets in ARRAY1 are in ARRAY2
static bool checkArraysElements(void)
{
  bool usedIndexes[SIZE_ARRAY];
  bool flag = true;
  for(int i=0; i<SIZE_ARRAY; i++)
    usedIndexes[i]=false;

  for(int i=0; i<SIZE_ARRAY; i++)
    for(int j=0; j<SIZE_ARRAY; j++)
      if(ARRAY1[i]==ARRAY2[j] && !usedIndexes[j]){
        usedIndexes[j]=true;
        break;
      }

  for(int i=0; i<SIZE_ARRAY; i++)
    if(!usedIndexes[i]){
      flag = false;
      break;
    }
  return flag;
}

void setUp(void)
{
  srand(time(NULL));
  ARRAY1 = malloc(sizeof(int)*SIZE_ARRAY);
  ARRAY2 = malloc(sizeof(int)*SIZE_ARRAY);
  initArrays();
}

void tearDown(void)
{
  free(ARRAY1);
  free(ARRAY2);
}

// test the checkArraysElements function
void testCompareArraysFunc(void)
{
  int aux = ARRAY2[0];
  ARRAY2[0] = ARRAY2[SIZE_ARRAY-1];
  ARRAY2[SIZE_ARRAY-1] = aux;
  TEST_ASSERT_MESSAGE(checkArraysElements(),"Error in compareArray function");
}

// check if the sort function changed any value of the array
void testCheckIfValuesWereChanged(void)
{
  sort(ARRAY1,SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(checkArraysElements(),"Sort functions changed the values");
}

// check if the restult array is in the correct order
void testCheckOrder(void){
  sort(ARRAY1,SIZE_ARRAY);
  for(int i=0; i<SIZE_ARRAY-1; i++)
    TEST_ASSERT_MESSAGE(ARRAY1[i]<=ARRAY1[i+1], "Array is not in order");
};
