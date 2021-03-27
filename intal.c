// C file for the implementation.
// SUBMITTED BY:
// NAME : Nitish S
// SRN: PES2201800368

// Library "intal" - Integer of arbitray length

// intal is a nonnegative integer of arbitrary length (not more than 1000 decimal digits).

// The integer is stored as a null terminated string of ASCII characters.

// String of decimal digits ('0' thru '9') are stored in big endian style.

// That is, the most significant digit is at the head of the string.

// Eg: Integer 25 is stored in str as '2' at str[0], '5' at str[1], and null char at str[2].



// DO NOT modify this header file.

// Your deliverable is the implementation file.

// The implementation file has the definition of the functions decalred here.

// You can write some of your own helper functions, keep them "static".

// Use the sample test file (that has the main function) to test your implementation.



// To generate your own testcases, you can use https://www.omnicalculator.com/math



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int convert_to_int(char ch)
{  
	return (int)(ch - 48);
}

char convert_to_char(int in) 
{  
	return (char)(in + 48);
}

// Returns the sum of two intals.
char* intal_add(char* intal1, char* intal2) 
{  
	int x1 = strlen(intal1);  
	int x2 = strlen(intal2);  
	int x = (x1 > x2)? x1 + 1: x2 + 1;  
	int s = (x1 > x2)? x2: x1;    
	int i, d1, d2, rd, a = 0;  
	char* result = (char*)malloc((x + 1) * sizeof(char));  
	for(i = 0 ; i < s; ++i) 
	{    
		d1 = convert_to_int(intal1[x1 - 1 - i]);    
		d2 = convert_to_int(intal2[x2 - 1 - i]);    
		rd = d1 + d2 + a;    
		a = (rd > 9)? 1: 0;    
		rd = (rd > 9)? rd - 10: rd;    
		result[x - 1 - i] = convert_to_char(rd);  
	}  
	while(i < x - 1) 
	{    
		if(x1 > x2) 
		{      
			rd = convert_to_int(intal1[x1 - 1 - i]) + a;      
			a = (rd > 9)? 1: 0;      
			rd = (rd > 9)? rd - 10: rd;      
			result[x - 1 - i] = convert_to_char(rd);    
		} 
		else 
		{      
			rd = convert_to_int(intal2[x2 - 1 - i]) + a;      
			a = (rd > 9)? 1: 0;      
			rd = (rd > 9)? rd - 10: rd;      
			result[x - 1 - i] = convert_to_char(rd);    
		}    
		++i;  
	}  
	if(a != 0) 
	{    
		result[0] = convert_to_char(a);    
		result[x] = '\0';  
	} 
	else 
	{    
		for(i = 0; i < x - 1; ++i) 
		{      
			result[i] = result[i + 1];    
		}    
		result = (char*)realloc(result, x * sizeof(char));    
		result[x - 1] = '\0';  
	}  
	return result;
}

// Returns the comparison value of two intals.

// Returns 0 when both are equal.

// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(char* intal1, char* intal2) 
{  
	int x1 = strlen(intal1);  
	int x2 = strlen(intal2);  
	if(x1 > x2)    
		return 1;  
	else if(x2 > x1)    
		return -1;  
	for(int i = 0; i < x1; ++i) 
	{    
		if(intal1[i] > intal2[i])      
			return 1;    
		else if(intal2[i] > intal1[i])      
			return -1;  
	}    
	return 0;
}	

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(char* intal1, char* intal2) 
{  
	int cmp = intal_compare(intal1, intal2);  
	if(cmp == 0) 
	{    
		char* result = (char*)malloc(2 * sizeof(char));    
		result[0] = '0';    
		result[1] = '\0';    
		return result;  
	} 
	else if(cmp == -1) 
	{    
		char* tmp = intal1;    
		intal1 = intal2;    
		intal2 = tmp;  
	}  
	int x1 = strlen(intal1);  
	int x2 = strlen(intal2);  
	int x = (x1 > x2)? x1: x2;  
	int s = x1 + x2 - x;    
	int i, d1, d2, rd, a = 0;  
	char* result = (char*)malloc((x + 1) * sizeof(char));  
	for(i = 0 ; i < s; ++i) 
	{    
		d1 = convert_to_int(intal1[x1 - 1 - i]) - a;    
		d2 = convert_to_int(intal2[x2 - 1 - i]);    
		a = (d2 > d1)? 1: 0;    
		d1 = (d2 > d1)? d1 + 10: d1;    
		rd = d1 - d2;    
		result[x - 1 - i] = convert_to_char(rd);  
	}  
	while(i < x) 
	{    
		rd = convert_to_int(intal1[x1 - 1 - i]) - a;    
		a = (rd > -1)? 0: 1;    
		rd = (rd > -1)? rd: rd + 10;    
		result[x - 1 - i] = convert_to_char(rd);    
		++i;  
	}  
	for(i = 0; i < x; ++i) 
	{    
		if(result[i] != '0')      
			break;  
	}  
	result[x] = '\0';  
	int trim = i;  
	if(trim != 0) 
	{    
		for(i = 0; i <= x - trim; ++i)      
			result[i] = result[i + trim];    
		result = realloc(result, (x - trim + 1) * sizeof(char));  
	}  
	return result;
}

// Returns the product of two intals.
char* intal_multiply(char* intal1, char* intal2) 
{  
	if(strcmp(intal1, "0") == 0 || strcmp(intal2, "0") == 0) 
	{    
		char* result = (char*)malloc(2 * sizeof(char));    
		result[0] = '0';    
		result[1] = '\0';    
		return result;  
	}  
	int i, j, rd, c = 0;  
	int l1 = strlen(intal1);  
	int l2 = strlen(intal2);  
	int l = l1 + l2;  
	char* result = (char*)malloc((l + 1) * sizeof(char));  
	for(i = 0; i < l; ++i)    
		result[i] = '0';  
	for(i = 0; i < l1; ++i) 
	{    
		c = 0;    
		for(j = 0; j < l2; ++j) 
		{      
			int d1 = convert_to_int(intal1[l1 - 1 - i]);      
			int d2 = convert_to_int(intal2[l2 - 1 - j]);      
			int d3 = convert_to_int(result[l - 1 - i - j]);      
			rd = (d1 * d2) + c + d3;      
			c = rd / 10;      
			rd = rd % 10;      
			result[l - 1 - i - j] = convert_to_char(rd);    
		}    
		for(j = l2 + i; j < l2 + l1; ++j) 
		{      
			int d3 = convert_to_int(result[l - 1 - j]);      
			rd = c + d3;      
			c = rd / 10;      
			rd = rd % 10;      
			result[l - 1 - j] = convert_to_char(rd);    
		}  
	}  
	result[l] = '\0';  
	if(result[0] == '0') 
	{    
		for(i = 0; i <= l; ++i)      
			result[i] = result[i + 1];    
		result = realloc(result, l * sizeof(char));  
	}  
	return result;
}

// Returns intal1 mod intal2

// The mod value should be in the range [0, intal2 - 1].

// intal2 > 1

// Implement a O(log intal1) time taking algorithm.

// O(intal1 / intal2) time taking algorithm may exceed time limit.

// O(intal1 / intal2) algorithm may repeatedly subtract intal2 from intal1.

// That will take intal1/intal2 iterations.

// You need to design a O(log intal1) time taking algorithm.

// Generate your own testcases at https://www.omnicalculator.com/math/modulo
char* intal_mod(char* intal1, char* intal2) 
{  
	int cmp = intal_compare(intal1, intal2);  
	if(cmp == -1) 
	{    
		char* result = (char*)malloc((strlen(intal1) + 1) * sizeof(char));    
		strcpy(result, intal1);    
		return result;  
	} 
	else if(cmp == 0) 
	{    
		char* result = (char*)malloc((2) * sizeof(char));    
		strcpy(result, "0");    
		return result;  
	}  
	int p = strlen(intal2);  
	int stop = strlen(intal1);  
	char* current = (char*)malloc((strlen(intal2) + 2) * sizeof(char));  
	for(int i = 0; i < p; ++i)    
		current[i] = intal1[i];  
	current[p] = '\0';  
	do 
	{    
		if(intal_compare(current, intal2) == -1 && p < stop) 
		{      
			int len = strlen(current);      
			if(strcmp(current, "0") == 0)        
				len = 0;      
			current[len] = intal1[p];      
			current[len + 1] = '\0';      
			++p;    
		}    
		if(intal_compare(current, intal2) != -1)
		{      
			char* result = intal_diff(current, intal2);      
			while(intal_compare(result, intal2) > -1) 
			{        
				char* tmp = result;        
				result = intal_diff(result, intal2);        
				free(tmp);      
			}            
			strcpy(current, result);      
			free(result);    
		}      
	} 
	while(p < stop);  
	current = realloc(current, (strlen(current) + 1) * sizeof(char));  
	current[strlen(current) + 1] = '\0';  
	return current;
}

// Returns intal1 ^ intal2.

// Let 0 ^ n = 0, where n is an intal.

// Implement a O(log n) intal multiplications algorithm.

// 2^3000 has less than 1000 decimal digits. 3000 intal multiplications may exceed time limit.
char* intal_pow(char* intal1, unsigned int n) 
{  
	if(n == 0) 
	{    
		char* result = (char*)malloc(2 * sizeof(char));    
		result[0] = '1';    
		result[1] = '\0';    
		return result;  
	}  
	char* result = (char*)malloc((strlen(intal1) + 1) * sizeof(char));  
	strcpy(result, intal1);  
	for(int i = 1; i < n; ++i) 
	{    
		char* var = result;    
		result = intal_multiply(result, intal1);    
		free(var);  
	}  
	return result;
}

// Returns Greatest Common Devisor of intal1 and intal2.

// Let GCD be "0" if both intal1 and intal2 are "0" even though it is undefined, mathematically.

// Use Euclid's theorem to not exceed the time limit.
char* intal_gcd(char* intal1, char* intal2) 
{  	
	char* a = (char*)malloc((strlen(intal1) + 1) * sizeof(char));  
	strcpy(a, intal1);  
	char* b = (char*)malloc((strlen(intal2) + 1) * sizeof(char));  
	strcpy(b, intal2);  
	int flag = strcmp(a, "0");  
	while(flag != 0) 
	{    
		char* temp = b;    
		b = a;    
		a = intal_mod(temp, a);    
		free(temp);    
		flag = strcmp(a, "0");  
	}  
	free(a);  
	return b;
}

// Returns nth fibonacci number.

// intal_fibonacci(0) = intal "0".

// intal_fibonacci(1) = intal "1".
char* intal_fibonacci(unsigned int n) 
{  
	char* a = (char*)malloc(2 * sizeof(char));  
	a[0] = '0';  
	a[1] = '\0';  
	if(n == 0)    
		return a;  
	char* b = (char*)malloc(2 * sizeof(char));  
	b[0] = '1';  
	b[1] = '\0';  
	if(n == 1)    
		return b;  
	for(int i = 1; i < n; ++i) 
	{    
		char* c = intal_add(a, b);    
		free(a);    
		a = b;    
		b = c;  
	}  
	free(a);  
	return b;
}

// Returns the factorial of n.
char* intal_factorial(unsigned int n) 
{  
	char* start = (char*)malloc(2 * sizeof(char));  
	start[0] = '1';  
	start[1] = '\0';  
	if(n < 2)    
		return start;  
	char* result = (char*)malloc(2 * sizeof(char));  
	result[0] = '1';  
	result[1] = '\0';  
	char* step = (char*)malloc(2 * sizeof(char));  
	step[0] = '1';  
	step[1] = '\0';  
	for(int i = 1; i <n; ++i) 
	{    
		char* temp = start;    
		start = intal_add(start, step);    
		free(temp);    
		temp = result;    
		result = intal_multiply(start, result);    
		free(temp);  
	}  
	free(start);  
	free(step);    
	return result;
}

// Returns the Binomial Coefficient C(n,k).

// 0 <= k <= n

// C(n,k) < 10^1000 because the returning value is expected to be less than 10^1000.

// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)

// Make sure the intermediate intal values do not cross C(n,k).

// Use Dynamic Programming. Use extra space of not more than O(k) number of intals. Do not allocate the whole O(nk) DP table.

// Don't let C(1000,900) take more time than C(1000,500). Time limit may exceed otherwise.
char* intal_bincoeff(unsigned int n, unsigned int k) 
{  
	char** a = (char**)malloc((k+1) * sizeof(char*));  
	for(int i = 0; i < k + 1; ++i) 
	{    
		a[i] = (char*)malloc(2 * sizeof(char));    
		a[i][0] = '0';    
		a[i][1] = '\0';  
	}  
	a[0][0] = '1';  
	for(int i = 1; i < n + 1; ++i) 
	{    
		int j = (i > k)? k: i;    
		while(j > 0) 
		{      
			char* tmp = a[j];      
			a[j] = intal_add(a[j], a[j - 1]);      
			free(tmp);      
			--j;    
		}  
	}  
	char* result = (char*)malloc((strlen(a[k]) + 1) * sizeof(char));  
	strcpy(result, a[k]);    
	for(int i = 0; i < k + 1; ++i)
	{    
		free(a[i]);  
	}  
	free(a);  
	return result;
}

// Returns the offset of the largest intal in the array.

// Return the smallest offset if there are multiple occurrences.

// 1 <= n <= 1000
int intal_max(char **arr, int n) 
{  
	int x = 0;  
	for(int i = 1; i < n; ++i) 
	{    
		if(intal_compare(arr[i], arr[x]) == 1)      
			x = i;  
	}  
	return x;
}

// Returns the offset of the smallest intal in the array.

// Return the smallest offset if there are multiple occurrences.

// 1 <= n <= 1000
int intal_min(char **arr, int n) 
{  
	int x = 0;  
	for(int i = 1; i < n; ++i) 
	{    
		if(intal_compare(arr[x], arr[i]) > -1)      
			x = i;  
	}  
	return x;
}

// Returns the offset of the first occurrence of the key intal in the array.

// Returns -1 if the key is not found.

// 1 <= n <= 1000
int intal_search(char **arr, int n, const char* key) 
{  
	int x = -1;  
	for(int i = 0; i < n; ++i) 
	{    
		if(intal_compare(arr[i], (char*)key) == 0) 
		{     
			x = i;      
			break;    
		}  
	}  
	return x;
}

// Returns the offset of the first occurrence of the key intal in the SORTED array.

// Returns -1 if the key is not found.

// The array is sorted in nondecreasing order.

// 1 <= n <= 1000

// The implementation should be a O(log n) algorithm.
int intal_binsearch(char **arr, int n, const char* key) 
{  
	int start = 0;  
	int end = n - 1;  
	while(start <= end) 
	{    
		int mid = (start + end) / 2;    
		int cmp = intal_compare(arr[mid], (char*)key);    
		if(cmp == 0) 
		{      
			return mid;    
		} 
		else if(cmp > 0) 
		{      
			end = mid - 1;    
		} 
		else 
		{      
			start = mid + 1;    
		}  
	}  
	return -1;
}
int partition(char** arr, int l, int r) 
{
  
	int i = l - 1;
  
	char* var = arr[r];

  
	for(int j = l; j < r; ++j) 
	{
    
		if(intal_compare(arr[j], var) < 0) 
		{
      
			++i;
      
			char* temp = arr[i];
      
			arr[i] = arr[j];
      
			arr[j] = temp;
    
		}
  
	}

  
	char* temp = arr[i + 1];
  
	arr[i + 1] = arr[r];
  
	arr[r] = temp;

  
	return (i + 1);

}



void quicksort(char** arr, int l, int r) 
{
  
	if(l < r) 
	{
    
		int var = partition(arr, l, r);
    
		quicksort(arr, l, var - 1);
    
		quicksort(arr, var + 1, r);
  
	}

}


// Sorts the array of n intals.

// 1 <= n <= 1000

// The implementation should be a O(n log n) algorithm.

void intal_sort(char **arr, int n) 
{
  
	quicksort(arr, 0, n - 1);

}



// Coin-Row Problem - Dynamic Programming Solution

// There is a row of n coins whose values are some positive integers C[0..n-1].

// The goal is to pick up the maximum amount of money subject to the constraint that

// no two coins adjacent in the initial row can be picked up.

// 1 <= n <= 1000

// The implementation should be O(n) time and O(1) extra space even though the DP table may be of O(n) size.

// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25
char* coin_row_problem(char **arr, int n) 
{  
	char** f = (char**)malloc((n + 1) * sizeof(char*));  
	f[0] = (char*)malloc(2 * sizeof(char));  
	f[0][0] = '0';  
	f[0][1] = '\0';  
	for(int i = 0; i < n; ++i) 
	{    
		f[i + 1] = (char*)malloc((strlen(arr[i]) + 1) * sizeof(char));    
		strcpy(f[i + 1], arr[i]);  
	}  
	for(int i = 2; i < n + 1; ++i) 
	{    
		char* val = intal_add(arr[i -1], f[i - 2]);    
		if(intal_compare(val, f[i - 1]) > 0) 
		{      
			char* tmp = f[i];      
			f[i] = val;      
			free(tmp);    
		} 
		else 
		{      
			free(f[i]);      
			f[i] = (char*) malloc((strlen(f[i - 1]) + 1) * sizeof(char));      
			strcpy(f[i], f[i - 1]);      
			free(val);    
		}  
	}  
	char* result = (char*)malloc((strlen(f[n]) + 1) * sizeof(char));  
	strcpy(result, f[n]);  
	for(int i = 0; i < n + 1; ++i) 
	{    
		free(f[i]);  
	}  
	free(f);  
	return result;
}