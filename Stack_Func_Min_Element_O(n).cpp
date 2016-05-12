#include <iostream>
#include <limits>
#include <cstdlib>
#include <time.h>

int main() {

	/*
	 * Question: How would you design a stack which, in addition to push and pop, also has
	 * 			 a function min which returns the minimum element? Push, pop and min should
	 * 			 all operate in O(1) time.
	 *
	 * Solution: Uses two stacks to keep track of data and minimum value. Sacrifices some
	 * 			 space complexity to get O(1) times for all three operations.
	 *
	 * Caveat:   For simplicity, stack is implemented with fixed size arrays. Also, further
	 * 			 optimization can be done to reduce space complexity (ie. do not store
	 * 			 duplicate elements).
	 *
	 * Complexity: O(1) for all three operations.
	 *
	 * Adapted from Cracking The Coding Interview: Chapter 3, Question 2
	 *
	 */

}