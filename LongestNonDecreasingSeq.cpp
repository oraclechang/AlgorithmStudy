#ifdef _LONGEST_NONDECREASING_SEQ

/*
Problem
	From TopCoder http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=dynProg
	Given a sequence of N numbers - A[1] , A[2] , ..., A[N] . Find the length of the longest non-decreasing sequence. 

	As described above we must first find how to define a "state" which represents a sub-problem and 
	thus we have to find a solution for it. 
	Note that in most cases the states rely on lower states and are independent from greater states. 

	Let's define a state i as being the longest non-decreasing sequence which has its last number A[i] . 
	This state carries only data about the length of this sequence. 
	Note that for i<j the state i is independent from j, i.e. doesn't change when we calculate state j. 
	Let's see now how these states are connected to each other. 
	Having found the solutions for all states lower than i, we may now look for state i. 
	At first we initialize it with a solution of 1, which consists only of the i-th number itself. 
	Now for each j<i let's see if it's possible to pass from it to state i. 
	This is possible only when A[j]¡ÂA[i] , thus keeping (assuring) the sequence non-decreasing. 
	So if S[j] (the solution found for state j) + 1 (number A[i] added to this sequence which ends with number A[j] ) is better than a solution found for i (ie. S[j]+1>S[i] ), we make S[i]=S[j]+1. 
	This way we consecutively find the best solutions for each i, until last state N. 

	Let's see what happens for a randomly generated sequence: 5, 3, 4, 8, 6, 7: 
Solution

*/

#include "Header.h"

void main()
{
}

#endif
