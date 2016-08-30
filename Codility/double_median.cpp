/*
*
* Tag: Data Structure
* Time: O(k*log(k + n + m))
* Space: O(log(n + m))
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

//sort equation for std::sort(), used in all median attempts
bool AnswerVectorComparison( int a , int b )
{
    return a < b;
}
int bisection_median_optimize ( const std::vector<int> &A,
								const std::vector<int> &B,
								int p,
								int q,
								int r,
								int s )
{
	int x = q-p+1,
		y = s-r+1;

	if ( x+y <= 5 )
	{
		//Get an array for all of our answers
		std::vector<int> answer_vector;

		//loop through the remaining values in A and B and add them to our vector
		for ( int i = p ; i <= q ; i++ )
		{
			answer_vector.push_back( A[i] );
		}
		for ( int i = r ; i <= s ; i++ )
		{
			answer_vector.push_back( B[i] );
		}

		//sort the vector and find the median
		std::sort( answer_vector.begin(), answer_vector.end(), AnswerVectorComparison );
		int median = answer_vector[ (x+y) / 2 ];
	
		//clear out all the extra data we made
		answer_vector.clear();

		return median;
	}
	else
	{
		int d = (x+y) / 4;

		if ( A[p+d] < B[s-d] )
		{
			return bisection_median_optimize( A, B, p+d, q, r, s-d );
		}
		else
		{
			return bisection_median_optimize( A, B, p, q-d, r+d, s );
		}
	}
}

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int median_optimize ( const std::vector<int> &A,
					  const std::vector<int> &B,
					  int p,
					  int q,
					  int r,
					  int s )
{
	//x = total number of values in segment A[p]->A[q]
	//y = total number of values in segment B[r]->B[s]
	//z = half the difference between x and y
	int x = q-p+1,
		y = s-r+1,
		z = abs(x-y) / 2 ; //x-y is odd 

	//if x has more values in its segment
	if ( x > y )
	{
		if ( A[p+z] >= B[s] )
		{
			return A[p+z];
		}
		else if ( A[q-z] <=B[r] )
		{
			return A[q-z];
		}
		else
		{
			return bisection_median_optimize( A, B, p+z, q-z, r, s );
		}
	}
	//if y has mroe values in its segment or the same as x
	else
	{
		if ( B[r+z] >= A[q] )
		{
			return B[r+z];
		}
		else if ( B[s-z] <= A[p] )
		{
			return B[s-z];
		}
		else
		{
			return bisection_median_optimize( A, B, p, q, r+z, s-z );
		}
	}
}

//Run time
//O(K*(log(K)+log(N)+log(M)))
int solution(vector<int> &A, vector<int> &B, vector<int> &P, vector<int> &Q, vector<int> &R, vector<int> &S )
{
	//A and B are assumed to be sorted
	//P-Q and R-S are continous segments, P[i]->Q[i] a segment of A and R[i]->S[i] a segment of B

	//Get the sizes of the arrays, P.size = Q.size = R.size = S.size
	//Size of A and B is irrelevant since the two segments are guaranteed to be within A and B's boundaries
	//k is the total number of segments
	int k = P.size();

	//Get an array for all of the medians of all the segments
	std::vector<int> answer_vector;

	//Iterate through all the values of P-Q and R-S and find the medians of those segments in A and B
	for ( int i = 0 ; i < k ; i++ )
	{
		answer_vector.push_back( median_optimize( A, B, P[i], Q[i], R[i], S[i] ) );
	}

	//Take the answer vector and return the median of it
    //Sort answer_vector and return the middle/median value
    std::sort( answer_vector.begin(), answer_vector.end(), AnswerVectorComparison );

	int median = answer_vector[ (k / 2) ];

	//Clear our temporary vector
	answer_vector.clear();

	return median;
}
