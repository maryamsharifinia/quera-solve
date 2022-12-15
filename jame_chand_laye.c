#include<stdio.h> 
#include<string.h> 
const int x = 100000;
int re_number(char arr[], int index) {
	int temp = ((int)arr[index] - 48);
	for (int i = index + 1; i < x; i++)
	{
		if (arr[i] == '{' || arr[i] == '}' || arr[i] == ','|| arr[i] == ' ')
		{
			break;
		}
		else
		{
			temp = temp * 10;
			temp += ((int)arr[i] - 48);
		}
	}

	return temp;
}
int re_index(char arr[], int index) {
	for (int i = index; i < x; i++)
	{
		if (arr[i] == '{' || arr[i] == '}' || arr[i] == ',')
		{
			break;
		}
		else
			index++;
	}
	return index-1;
}

int main()
{

	char ebarat[x];
	scanf("%[^\n]s", ebarat);
	int stack[x];
	for (int i = 0; i < x; i++) {
		stack[i] = -1;
	}
	int j = 0;
	for (int i = 0; i < x; i++)
	{
		if (ebarat[i] == ' ') {
			continue;
		}
		else if (ebarat[i] == '\0')
			break;
		else if (ebarat[i] == ',') {
			continue;
		}
		else if (ebarat[i] == '{') {
			stack[j] = -8;
			j++;
		}
		else if (ebarat[i] == '}')
		{
			int sum = 0;
			for (int k = j; i >= 0; k--)
			{
				if (stack[k] == -8) {
					for (int m = k; m < x; m++)
					{
						stack[m] = stack[m + 1];
						if (stack[m + 1]==-1)
						{
							break;
						}


					}
					//stack[k] = 0;
					printf("%d\n", sum);
					break;
				}
				else if(stack[k]!= -1)
				{
					sum += stack[k];
				}
			}
		}
		else
		{
			stack[j] = re_number(ebarat, i);
			j++;
			i = re_index(ebarat, i);
		}

	}


}
