/***************************************************
Programmer: Morgan Baccus
Class: CptS 121 Spring 2019
****************************************************/

#include "questions.h"

int main(void) {
	//Problem 1
	char wsu[100] = "washington";
	my_str_n_cat(wsu, "state", 2);
	printf("washington + 2 characters of state = ");
	puts(wsu);

	// Problem 2
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	printf("Index of 7 in array: %d\n", binary_search(arr, 10, 7));
	printf("Index of 55 in array: %d (not found)\n", binary_search(arr, 10, 55));
	// Problem 3
	char w1[10] = "scout";
	char w2[10] = "morgan";
	char w3[10] = "lovee";
	char w4[10] = "austin";
	int * list[4] = { w1, w2, w3, w4 };

	// Prints list prior to sort
	printf("Unsorted List:\n");
	for (int i = 0; i < 4; i++) {
		puts(list[i]);
	}

	bubble_sort(list, 4);

	// Prints list after sort
	printf("Sorted List:\n");
	for (int i = 0; i < 4; i++) {
		puts(list[i]);
	}

	// Problem 4
	printf("Is 'ra ceca r' a palindrome: %s\n", is_palindrome("ra ceca r", 7, 0) ? "true" : "false");
	printf("Is 'orange' a palindrome: %s\n", is_palindrome("orange", 6, 0) ? "true" : "false");

	// Problem 5
	printf("Sum of primes from 2 to 10: %d\n", sum_primes(10));

	// Problem 6
	Occurrences array[10];
	int occurrences = 0;
	char ch = '\0';
	maximum_occurrences("test string", array, &occurrences, &ch);
	printf("%c has maximum occurrences in string 'test string', with %d occurrences.\n", ch, occurrences);
	maximum_occurrences("apples", array, &occurrences, &ch);
	printf("%c has maximum occurrences in string 'apples', with %d occurrences.\n", ch, occurrences);

	system("pause");
	return 0;
}