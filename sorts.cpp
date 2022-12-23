//sortings by wohl
//parameter order: 1 for descending 0 for ascending
#ifndef SORTING_H
#define SORTING_H
namespace wohlsorts
{
int* insertsort(int* array,int length,bool order)
{
	int temp = *array;
	for(int n = 1; n<length; n++)
	{
		temp = *(array + n);
		for(int m = n - 1; m>=0; m--)
		{
			if(*(array + m) > temp && order)
			{
				*(array + m + 1) = *(array + m);
				*(array + m) = temp;
			}
			if(*(array + m) < temp && !order)
			{
				*(array + m + 1) = *(array + m);
				*(array + m) = temp;
			}
		}
	}
	return array;
}
int* bubblesort(int* array,int length,bool order)
{
	int temp = *array;
	int* ascend;
	for(int n = 0; n<length; n++)
	{
		for(int m = 0; m<length; m++)
		{
			if(*(array + m) < *(array + m + 1))
			{
				temp = *(array + m + 1);
				*(array + m + 1) = *(array + m);
				*(array + m) = temp;
			}
		}
	}
	if(order)
	ascend = array;
	if(!order)
	{
		ascend = new int[length];
		for(int n = 0; n<length; n++)
		{
			*(ascend + n) = *(array + (length - 1 - n));
		}
	}
	return ascend;
}
int* quicksort(int left, int right,int* array) 
{
	int i, j, alter, temp;
	if(left > right)
	return array;
    temp = *(array+left);
    i = left;
    j = right;
    while(i != j) 
	{
    	while(*(array + j) >= temp && i < j)
    	j--;
    	while(*(array + i) <= temp && i < j)
    	i++;       
    	if(i < j)
    	{
    		alter = *(array + i);
    		*(array + i) = *(array + j);
    		*(array + j) = alter;
    	}
    }
    *(array+left) = *(array + i);
    *(array + i) = temp;
    quicksort(left, i-1,array);
    quicksort(i+1, right,array);
}
int* quicksort(int* array,int length,bool order)
{
	int* ascend;
	if(!order)
	{
		ascend = new int[length];
		for(int n = 0; n<length; n++)
		{
			*(ascend + n) = *(quicksort(0,length-1,array) + (length - 1 - n));
		}
	}
	else
	{
		ascend = quicksort(0,length-1,array);
	}
	return ascend;
}
}
#endif
