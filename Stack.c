#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a, i, n, n1, c, pu, po, temp, x = 0;
	printf("Enter size\n"); //Input the no. of elements to be inserted
	scanf("%d", &n);
	n1 = n;
	a = (int*)calloc(n, sizeof(int));//create a  dynamic array of given size
	printf("Stack is created from %u to %u \n", &a[0], &a[n]);
	for (i = (n1 - 1);i >= 0;i--)
	{
		scanf("%d", &a[i]);
		printf("%d is stored at %u \n", a[i], &a[i]);
	}
	printf("Which operation do you want to perform?\n1.Push\n2.POP\n"); //Input the operation to be performed
	scanf("%d", &c);
	if (c == 1) //for PUSH operation
	{
		printf("Enter the number of elements you want to push\n");
		scanf("%d", &pu);
		for (i = n1 - 1;i >= 0;i--)
		{
			a[i + pu] = a[i];
		}
		i = 0;
		printf("Enter the elements\n");
		for (i = 0;i<pu;i++)
		{
			scanf("%d", &a[i]);

		}
		for (i = 0;i<(n1 + pu);i++)
		{
			printf("%d is stored at %u \n", a[i], &a[i]);
		}

	}
	else if (c == 2) //for POP operation
	{
		printf("Enter the element to be popped out \n");
		scanf("%d", &po);
		i = 0;
		while (a[i] != po)
		{
			a[i] = 0;
			i++;
		}
		a[i] = 0;
		for (i = 0;i<n1;i++)
		{
			printf("%d is stored at %u \n", a[i], &a[i]);
		}
	}
	return 0;
}

