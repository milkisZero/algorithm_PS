#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int n = 0, m = 0;
	int arr[100];
	int sum = 0;
	int value = 0, value2 = 0, value3 = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0;  i != j && j < n; j++)
		{
			for (int k = 0; k != j && k != i && k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] <= m)
				{
					value = arr[i];
					value2 = arr[j];
					value3 = arr[k];
				}
				if (sum < value + value2 + value3)
				{
					sum = value + value2 + value3;
				}
			}
		}
	}	

	printf("%d", sum);

	return 0;
}