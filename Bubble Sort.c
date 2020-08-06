#include<stdio.h>
void main()
{
	int n,i,j,a[20],temp;
	printf("Enter the size of array less than 20\n"); //Input Array Size
	scanf("%d",&n);
	printf("Enter the array elements\n"); //Input Array elements
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<(n-i);i++) // Actual bubble sort operation
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}

		}
	}
	printf("the sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d, ",a[i]);
	}
}

