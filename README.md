REPORT ON INTAL - ARBITRARY LENGTH POSITIVE INTEGERS IMPLEMENTATION.

PROBLEM STATEMENT:-  

Develop a C library for the integers of arbitrary length (intal).

INTRODUCTION:- 
Often times we need to deal with numbers that don't fit the data types available in the older languages.
INTAL is a library that builds logic to deal with arbitrary precision Integers by storing them in string.
An INTAL is a non - negative integer of arbitrary length. The integer is stored as a null-terminated string of ASCII characters. An intal is represented as a string of decimal digits ('0' through '9') that are stored in the Big - Endian style i.e. the most significant digit is at the head of the string. 
An integer 52, for example, is stored in a string 's' as '5' at s[0], '2' at s[1], and null char at s[2].
INTAL library is different from the other data types becuase:  Most of the times, the digits of precision of calculations performed on numbers is limited only by the memory allotted to those existing data types or memory available in the host system i.e. the fixed precision arithmetic. But INTAL integer library attempts to solve this problem by providing arbitrary precision integer math.
Although memory - wise , it is not an effective design, it will do the job.

APPLICATIONS OF INTAL LIBRARY INCLUDE:- 

1) Can be used in high precision mathematical computation
2) INTAL with Modification can be used to represented as BASE - 128 number
3) In public-key cryptography whose algorithms commonly employ arithmetic with integers having hundreds of digits.
4) In situations where artificial limits and overflows would be inappropriate.
5) For checking the results of fixed - precision calculations, and for determining optimal or near-optimal values for coefficients needed in formulae, for example the √⅓ that appears in Gaussian integration.
6) Arbitrary precision arithmetic is also used to compute fundamental mathematical constants such as 'π' to millions or more digits and to analyze the properties of the digit strings.
7) INTAL can be used in Scientific Computation as like the ones in CERN and LIGO

APPROACH USED IN IMPLEMENTATION:- 


Looking at the functions implemeted one by one:- 

1) intal_add:- It is carried out in the same way it is done on paper i.e it Adds two Intal digit-wise from right to left. If addition of two digits results in a value
 more than 10, then 1 is carried over to the next digit.

2) intal_compare:- Initially, the length is compared assuming there are no preceding zeros . If the length are same, 
then each digit is compared from left to right until there is a  mismatch. If there is no mis - match, then zero is returned , 
marking that the two Intal are equal.

3) intal_diff:- Subtracts two Intal digit - wise from right to left. If the subtracting digit is larger, the
 digit on top is added with 10 and 1 is subtracted from the next digit to be processed. The larger number 
is always placed on top using intal_compare. 

4) intal_multiply:- Follows naive multiplication with O(mn) complexity. Each digit from the second number is
 multiplied with the entire first number and the resulting products are added shifting each result by one 
place.

5) intal_mod:- This uses the long division method to compute, where the quotient isn't stored and the result 
remainder is the one that is cached from each computation.

6) intal_pow:- Follows a divide and conquer method for calculating the power in an iterative manner thereby avoiding large stack trace and effectively managing memory.

7) intal_gcd:- Uses the iterative algorithm:
 
ALGORITHM gcd(a,b):
    
	if a = 0:
      
	     return b
    
	gcd(b mod a, a);


8) 
intal_fibonacci:- The fibonacci algorithm using memoization where:

LOGIC:
  F(0) = Intal(0)
  
              F(1) = Intal(1)
 
              F(n) = F(n - 1) + F(n - 2);

9) intal_factorial: Iterative implementation of factorial with memoization where:

LOGIC:
  F(0) = Intal(1)
  
              F(1) = Intal(1)
  
              F(n) = Intal(n) + F(n - 2)

10) intal_bincoeff:- Binomial coefficient using bottoms up approach using memoization where:

LOGIC:
  C(n,k) = C(n-1,k) + C(n-1,k-1)
  
              C(n,0) = 1
  
              C(n,1) = n
  
We know that C(n,k) depends on C(n-1,k) and C(n-1,k-1)
.  We compute C(1,0), C(1,1) first then C(2,0), C(2,1) and C(2,2) using
  C(1,0), C(1,1). We build up this until C(n, k)
  Given C(n + 1, x) only depends on C(n, y), we need O(n) extra space.

11) intal_max:- Uses linear traversal and intal_compare to compare each number with the instantaneous 
highest value to find the absolute maximum.

12) intal_min:- Uses linear traversal and intal_compare to compare each number with the instantaneous 
lowest value to find the absolute minimum.

13) intal_search:- Compares the key with each element of array and uses intal_compare to find 
the position of the key in array.

14) intal_binsearch:- Compares the key with each element of array using divide and conquer
 and uses intal_compare to find the position of the key in array.

15) intal_sort:- Uses the method QuickSort to sort the array.

16) coin_row_problem:- Uses a O(n) DP table to implement coin row problem using:

LOGIC:
 
           CR(0) = 0

           CR(1) = Coin[1]
           
CR(n) = MAX(CR(n - 1), Coin[n] + CR(n - 2));


FUTURE IMPROVEMENTS:
-

1) INTAL library can be extended to negative numbers as well rather than restricting it only to positive numbers.
2) Increasing efficiency by usage of parallel algorithms.

3) To make it as a real - world like implementation, raw pointers and shift operations can be made use of.

4) Double numbers can be split into whole and floating point part and thereby implement operations separately for both parts and hence extending the library to floating point numbers
 as well.
5) Using GPU compute for faster computation.
