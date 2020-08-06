#include<stdio.h>
void mergesort(int a[], int, int);                                                      // Function Declaration
void merge(int a[], int, int, int, int);
void display(int a[], int);

int main()
{
	int a[20], i, n;

	printf("Enter number of elements you want in array : "); //Input no. of array elements
	scanf("%d", &n);
	printf("\n");

	printf("Enter the values of elements in array\n");  //Input array elements
	for (i = 0;i<n;i++)
	{
		printf("The element %d is : ", i + 1);
		scanf("%d", &a[i]);
	}
	printf("\n");

	printf("The entered array is \n");                                                // Printing entered values in array
	display(a, n); //Display the array as entered by user

	mergesort(a, 0, n - 1);                                                               // Function Call for Dividing

	printf("Sorted array is \n");
	display(a, n);

	return 0;

}

void mergesort(int a[20], int i, int j)                                             // Function Definition For dividing
{
	int mid;

	if (i<j)
	{
		mid = (i + j) / 2;//Divide and conquer
		mergesort(a, i, mid);                                                             // Dividing left sub array  
		mergesort(a, mid + 1, j);                                                           // Dividing right sub array
		merge(a, i, mid, mid + 1, j);                                                         // Merging arrays
	}

}

void merge(int a[20], int i1, int j1, int i2, int j2)                               // Function for merging
{
	int t[20];
	int i, j, k;
	i = i1;
	j = i2;
	k = 0;

	while (i <= j1 && j <= j2)
	{
		if (a[i]<a[j])
			t[k++] = a[i++];

		else
			t[k++] = a[j++];

	}

	while (i <= j1)                                                             // Remaining elements in Left Sub array
		t[k++] = a[i++];

	while (j <= j2)                                                             // Remaining elements in Right sub array
		t[k++] = a[j++];

	for (i = i1, j = 0;i <= j2;i++, j++)
		a[i] = t[j];

}

void display(int a[20], int n)                                             // Display Function
{
	int i;
	for (i = 0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");

}

