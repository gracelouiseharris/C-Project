#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sum_primes(int n);
void run_sum_primes(void);
void run_str_to_cat(void);
void str_to_cat(char *source, char *final);
void print_final(char *final);
void run_is_palindrome(void);
int is_palindrome(char *string, int len);
void run_binary_search(void);
void binary_search(int list[], int size, int value,
	int *found, int *index);
void sort_list(int list[]);
void run_bubble_sort();
void bubblesort(int list[], int length);
void print(int list[], int length);
char maximum_occurrences(char string[], struct occurrences alphanumerics[63], int *maxptr, char *character, int length);
void run_max_occurrences(void);
