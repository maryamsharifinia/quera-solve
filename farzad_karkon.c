#include<stdio.h> 
#include<string.h> 
int max(int arr[],int n) {
	int temp=arr[0];
	for (int i = 0; i < n; i++)
	{
		if ( arr[i]>temp)
		{
			temp = arr[i];
		}
	}
	return temp;
}



int main()
{
	const int x = 1000;
	int n,m;
	scanf("%d", &n);
	int arr[x];
	int arr_sum[x];
	int index[x];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		arr[i] = m;
	}

	if (max(arr,n) <= 0) {
		printf("%d", 0);
	}
	

	else {
		int h[x];
		h[0]= max(arr, n);
		int p = 1;
		for (int i = 2; i < n; i++) {
			for (int j = 0; j < (n - (i)) + 1; j++) {
				int sum=0;
				for (int k = j; k < j + i; k++) {
					sum += arr[k];
				}
				h[p] = sum;
				p++;
			}
		}

		printf("%d", max(h, p + 1));
	}
}
