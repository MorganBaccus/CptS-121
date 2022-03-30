/***************************************************
Programmer: Morgan Baccus
Class: CptS 121 Spring 2019
****************************************************/

#include "questions.h"

// Uses pointer arithmetic to add one string to another for n number of characters
char * my_str_n_cat(char *dest, const char *src, int n) {
	while (*dest != '\0') {
		dest++;
	}
	for (int i = 0; i < n; i++) {
		if (*src == '\0') {
			break;
		}
		else {
			*dest = *src;
			dest++;
			src++;
		}
	}
	return dest;
}

// If the target value is found, returns the index in the array. Else, returns -1
int binary_search(int list[], int size, int target) {
	int left = 1, right = size, targetIndex = -1, mid = 0;
	int found = 0;
	while (!found && left <= right) {
		mid = (left + right) / 2;
		if (list[mid] == target) {
			found = 1;
			targetIndex = mid;
		}
		else if (target < list[mid]) {
			right = mid - 1;
		}
		else if (target > list[mid]) {
			left = mid + 1;
		}
	}
	return targetIndex;
}

//Takes an array of strings and swaps addresses of strings based on ASCII values
void bubble_sort(char * arr[], int numStrings) {
	int markerU = numStrings, markerC = 1, i = 0;
	for (i = 0; i < markerU; i++);
	while (i > 1) {
		markerC = 1;
		while (markerC < markerU) {
			if (*arr[markerC] < *arr[markerC - 1]) {
				char * temp = arr[markerC - 1];
				arr[markerC - 1] = arr[markerC];
				arr[markerC] = temp;
			}
			markerC++;
		}
		markerU--;
		for (i = 0; i < markerU; i++);
	}
}

//Removes spaces from string, then uses pointer arithmetic to compare the converging value of str[0] and the end of the string. Returns 1 if string is a palindrome, 0 if no
int is_palindrome(char strOrg[], int length, int hasRemovedSpaces) {
	char str[100];
	int count = 0, i = 0;
	while (count < length && !hasRemovedSpaces) {
		if (strOrg[i] != ' ') {
			str[count] = strOrg[i];
			count++;
		}
		i++;
		if (count == length) {
			str[count] = '\0';
		}
	}

	if (!hasRemovedSpaces) { // first time running through, use str
		if (str[0] == '\0') {
			return 1;
		}

		if (str[0] != str[length - 1]) {
			return 0;
		}

		return is_palindrome(str + 1, length -= 2, 1);
	}
	else { // use strOrg
		if (strOrg[0] == '\0') {
			return 1;
		}

		if (strOrg[0] != strOrg[length - 1]) {
			return 0;
		}
		return is_palindrome(strOrg + 1, length -= 2, 1);
	}
}

// Checks if n is prime. If yes, adds it to the recursive call that converges downwards from n to 2. Eventually the sum of the prime numbers
int sum_primes(unsigned int n) {
	int sum = 0;
	if (n == 2) {
		return n;
	}
	if (isPrime(n)) {
		sum = n;
	}

	return sum_primes(n - 1) + sum;
}

//Returns 1 if n is prime, 0 if no. Basically divides odd n by every odd number between 3 and n and checks if it is evenly divisible or not. If so it is not prime, so it returns 0.
int isPrime(unsigned int n) {
	if (n % 2 == 0 && n > 2) {
		return 0;
	}
	for (int i = 3; i < n / 2; i += 2) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

//Reads in a string. Counts all occurrences of each character in the string, and then determines the maximum of those occurrences.
//Returns value through pointers to a integer and a character, where each corresponding value is kept track of in a parallel array.
//Frequencies are calculated based on the number of occurrences of each character divided by the total number of characters
void maximum_occurrences(char *str, Occurrences occurArr[], int *max_occurrences, char *ch) {
	int count[26] = { 0 };
	char temp[26] = { '\0' };
	
	int next = 0, nextInt = 0, c = 0, hold = 0, total = 0;
	while (*str != '\0') {
		c = 0;
		for (int i = 0; i < 100; i++) {
			if (*str == temp[i]) {
				hold = i;
				c++;
			}
		}
		if (c == 0) {
			temp[next++] = *str;
		}
		else {
			count[hold] += c;
		}
		total++;
		str++;
	}

	// calculate frequencies
	for (int i = 0; i < sizeof(occurArr) / sizeof(Occurrences); i++) {
		if (count[i] != 0) {
			occurArr[i].num_occurences = count[i] + 1;
			occurArr[i].frequency = (double)(count[i] + 1) / total;
		}
		else {
			occurArr[i].num_occurences = 1;
			occurArr[i].frequency = 1.0 / total;
		}
	}

	// return
	int max = 0, maxIndex = 0;
	for (int i = 0; i < 26; i++) {
		if (count[i] > max) {
			max = count[i];
			maxIndex = i;
		}
	}

	*max_occurrences = max + 1;
	*ch = temp[maxIndex];
}