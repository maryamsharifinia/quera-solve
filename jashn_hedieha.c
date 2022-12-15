#include <stdio.h>

int chek_true_name(int index_name[], char names[], char name[], int size)
{/*
	int size_name = 0;
	for (int k = 0; k < 25; k++) {
		if (name[k] == '\0')
		{
			size_name = k;
			break;
		}

	}*/
	int pointer_name = 0;
	int check_name = 0;
	while (pointer_name != -1)
	{

		if (names[index_name[pointer_name]] == name[0])
		{
			int n = index_name[pointer_name + 1] - index_name[pointer_name];
			for (int i = 1; i < n; i++)
			{
				if (name[i] != '\0') {
					if (name[i] == names[index_name[pointer_name] + i]) {
						if (i == n - 2)
						{
							return pointer_name;
						}
						continue;
					}
					else
					{
						pointer_name++;
						break;
					}
				}
				else
				{
					if (n == 2) {
						return pointer_name;
					}
					pointer_name++;
					break;
				}
			}
		}
		else {
			pointer_name++;
		}
		if (pointer_name > size) {
			pointer_name = -1;
		}

	}
	return -1;
}
int main()
{
	int n;
	const int t = 10;
	scanf("%d", &n);
	char names[t * 100];
	int index_name[t];
	int mony[t];
	int list_sarmaye[t];
	for (int i = 0; i < t; i++) {
		mony[i] = 0;
		list_sarmaye[i] = 0;
		index_name[i] = 0;
	}

	char name[t * 5];
	char ch = 'n';
	int j = 0;
	int pointer_index = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name);
		for (int k = 0; k < t * 10; k++) {
			if (name[k] == '\0')
			{
				names[j] = '#';
				j++;
				index_name[pointer_index] = j;
				pointer_index++;
				break;
			}
			else
			{
				names[j] = name[k];
				j++;
			}

		}

	}
	for (int i = 0; i < n; i++)
	{
		int sarmayeh, tedad;
		scanf("%s", name);
		int index = chek_true_name(index_name, names, name, n);

		scanf("%d%d", &sarmayeh, &tedad);

		int mo = 0;
		if (tedad != 0) {
			int pool_a = sarmayeh % tedad;
			int nahaee = sarmayeh - pool_a;
			mony[index] += -(nahaee);
			mo = sarmayeh / tedad;
		}
		else {
			mony[index] += sarmayeh;
		}

		list_sarmaye[index] = sarmayeh;
		for (int j = 0; j < tedad; j++)
		{
			scanf("%s", name);
			int index = chek_true_name(index_name, names, name, n);
			if (index != -1)
			{
				mony[index] += mo;
			}
		}
		/*
		if (sarmayeh - tedad * mo != 0)
		{
			mony[i] += sarmayeh - tedad * mo;
		}
		*/
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < index_name[i + 1] - index_name[i] - 1; k++)
		{
			int x = index_name[i];
			printf("%c", names[x + k]);
			x++;
		}
		printf("%c", ' ');
		printf("%d ", mony[i]);
		printf("%c", '\n');
	}
}
