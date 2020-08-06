int main()
	{
		int n, a[20], e, i,j = 0,temp;
		printf("Enter the array size less than 20\n");
		scanf("%d", &n); //Input array size from User
		printf("Enter the array\n");
		for (i = 0; i< n;i++) //Input array from User
		{
			scanf("%d", &a[i]);
		}
		for (i = 1;i < n;i++)
		{
			j = i;
			while (j>0 && a[j] > a[j-1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j-1] = temp;
				j--;
			}
		}
		printf("The sorted array is\n");
		while(n!=0)
		{
			printf("%d , ", a[n-1]);
			n--;
		}
		return 0;
	}

