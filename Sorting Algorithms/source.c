#include "header.h"

///// task 1
void run_str_to_cat(void)
{
	char source[1000] = { '\0' };
	char new[1000] = { '\0' };
	char dummy;

	printf("Enter the string you want to copy.\n");
	getchar(&dummy);
	fgets(source, 1000, stdin);
	
	char *ptr = &source[0];
	char *ptr1 = &source[0];
	str_to_cat(ptr1, ptr, new);

	system("pause");
	system("cls");

}

void str_to_cat(char *ptr1, char *ptr, char *new)
{
	printf("\nOriginal string\n");
	while (*ptr1 != '\0')
	{
		printf("% c", *ptr1);
		ptr1++;
	}
	int idx = 0;
	printf("\nCopied string\n");
	while (*ptr != '\0')
	{
		*new = *ptr++;
		printf("% c", *new);
		*new++;
	}
	printf("\n");
}

///// task 2
void run_binary_search(void)
{
	srand(time(NULL));

	int list[1000];
	int size = 1000;
	int value = 0;
	int found = 0;
	int index = 0;
	int *foundptr = &found;
	int *indexptr = &index;

	printf("Enter a number between 0 and 1000 to check if it is in randomly generated the list.\n");
	scanf("%d", &value);

	for (int i = 0; i < 1000; i++)
	{
		list[i] = rand() % 1000;
	}

	sort_list(list);

	binary_search(list, size, value, foundptr, indexptr);

	if (found == 0)
		printf("Sorry, that number is not in the list!\n");
	if (found == 1)
		printf("Value %d has been found in space %d\n", value, index);
	system("pause");
	system("cls");
}

void binary_search(int list[], int size, int value, int *found, int *index)
{
	int left = 0, right = size - 1, middle = 0;

	*found = 0;
	*index = -1;

	while (!(*found) && left <= right)
	{
		middle = (left + right) / 2;

		if (value == list[middle])
		{
			*found = 1;
			*index = middle;
		}
		else if (value < list[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
}


void sort_list(int list[])
{
	int i = 0, k = 0, n = 0;

	for (i = 0; i < 1000; ++i)
	{
		for (k = i + 1; k < 200; ++k)
		{
			if (list[i] > list[k])
			{
				n = list[k];
				list[i] = list[k];
				list[k] = n;
			}
		}
	}
}

///// task 3

void bubblesort(char words[][14], int many)
{
	for (int i = 0; i < many; i++)
	{
		int c = 1, u = many, d = 0;
		while (c < many)
		{
			int copy = strcmp(words[c], words[d]);
			if (copy <= 0)
			{
				char temp[30] = { '0' };
				for (int j = 0; j < 14; j++)
				{
					temp[j] = words[c][j];
					words[c][j] = words[d][j];
					words[d][j] = temp[j];
				}
			}
			c++;
			d++;
			u--;
		}
	}
}

void run_bubble_sort()
{
	char words[30][14] = { '0' };
	char temp[30];
	int many = 0;
	char space = '\0';

	printf("How many strings do you want to sort alphabetically?\n");
	scanf("%d", &many);
	printf("Please enter the words you would like to sort, separated by pressing enter.\n");
	getchar(&space);

	for (int i = 0; i < many; i++)
	{
		fgets(words[i], 30, stdin);
	}

	bubblesort(words, many);

	printf("Alphabetized List: \n");
	for (int i = 0; i < many; i++)
	{
		int j = 0;
		while (words[i][j] != NULL)
		{
			printf("%c", words[i][j]);
			j++;

		}
		printf("\n");
	}

	system("pause");
	system("cls");

}

///// task 4
void run_is_palindrome(void)
{
	char string[1000] = { '\0'};
	int is = 0;
	char c = 0;

	c = getchar();
	printf("Enter a string to check if it is a palindrome.\n\n");
	fgets(string, 1000, stdin);

	int length = strlen(string) - 2;
	is = is_palindrome(0, length, string);

	if (is == 0)
		printf("This string is not a palindrome\n");
	if (is == 1)
		printf("This string is a palindrome\n");

	system("pause");
	system("cls");

}

int is_palindrome(int start, int end, char *string)
{
	if (string[start] != string[end])
	{
		if (string[start] != ' ' && string[end] != ' ')
			return 0;
		else if (string[start] == ' ')
			return is_palindrome(++start, end, string);
		else if (string[end] == ' ');
		return is_palindrome(start, --end, string);
	}

	if (start == end || start + 1 == end || end + 1 == start)
		return 1;
	else
		return is_palindrome(++start, --end, string);

	return 0;

}

///// task 5
void run_sum_primes(void)
{
	int sum = 2;
	int n = 0;
	int i = 2;

	printf("Enter a number to sum the prime numbers leading up to it.\n");
	scanf("%d", &n);
	sum = sum_primes(n, sum, i) - 2;
	printf("The sum of all prime numbers up to and including %d is %d.\n", n, sum);

	system("pause");
	system("cls");

}

int sum_primes(int n, int sum, int i)
{
	int isprime = 0;

	for (int j = 2; j < i; j++)
	{
		if (i % j == 0.0)
		{
			isprime = 1;
		}
		
	}
	if (isprime == 0)
	{
		sum += i;
	}
		if (i >= n)
			return sum;
		else
		{
			i++;
			sum_primes(n, sum, i);
		}
}

///// task 5
typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} occurrences;

void run_max_occurrences(void)
{
	struct occurrences alphanumerics[63] = { 0, 0.0 };
	int max = 0;
	int *maxptr = &max;
	char character = '\0';
	char *characterptr = &character;
	char string[30] = { '\0' };
	int length = 0;
	char dummy;

	printf("Enter a string see which characters appear most often.\n\n");
	dummy = getchar();
	fgets(string, 30, stdin);

	length = strlen(string);
	character = maximum_occurrences(string, alphanumerics, maxptr, character, length);

	for (int i = 0; i < 63; i++)
	{
		if (alphanumerics[i].num_occurrences > max)
		{
			max = alphanumerics[i].num_occurrences;
		}
	}

	printf("The character that appeared the most was %c, which occurred %d times.\n", character, max);

	system("pause");
	system("cls");
}
char maximum_occurrences(char string[], struct occurrences alphanumerics[63], int *maxptr, char *character, int length)
{

	char symbols[63] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
						'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
						'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ' };
	char character3 = '\0';

	for (int i = 0; i < 63; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (symbols[i] == string[j])
			{
				alphanumerics[i].num_occurrences += 1;
			}
		}
	}
	int max = 0;

	for (int i = 0; i < 63; i++)
	{
		if (alphanumerics[i].num_occurrences > max)
		{
			max = alphanumerics[i].num_occurrences;
			character3 = symbols[i];
		}
	}


	return character3;
}