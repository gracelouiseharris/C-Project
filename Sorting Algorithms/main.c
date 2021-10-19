
int main(void)
{
	int choice = 0;
	while (choice != 7)
	{
		int invalid = 0;
		printf("Press the number corresponding to the function you want to use.\n");
		printf("	1) String Copy\n");
		printf("	2) Binary Search\n");
		printf("	3) Bubble Sort\n");
		printf("	4) Palindrome Checker\n");
		printf("	5) Sum of Primes\n");
		printf("	6) Maximum Occurences\n");
		printf("	7) Exit\n");
		scanf("%d", &choice);
		system("cls");

		if (choice == 1)
			run_str_to_cat();
		else if (choice == 2)
			run_binary_search();
		else if (choice == 3)
			run_bubble_sort();
		else if (choice == 4)
			run_is_palindrome();
		else if (choice == 5)
			run_sum_primes();
		else if (choice == 6)
			run_max_occurrences();
		else if (choice == 7)
			return 0;
		else
			invalid = 1;

		while (invalid == 1)
		{
			printf("Please select a valid option.\n");
			scanf("%d", &choice);
			if (choice = 1)
				run_str_to_cat();
			else if (choice = 2)
				run_binary_search();
			else if (choice = 3)
				run_bubble_sort();
			else if (choice = 4)
				run_is_palindrome();
			else if (choice = 5)
				run_sum_primes();
			else if (choice = 6)
				run_max_occurrences();
			else
				invalid = 1;
		}
	}
}