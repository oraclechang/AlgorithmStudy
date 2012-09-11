#ifdef _MAXSUM

/*
Problem
	배열에서 연속적인 부분의 합중 최대값 구하기

Solution
	생각하는 프로그래밍 컬럼 8
*/

#include "Header.h"

template< typename T >
T MaxSum1(vector< T > vArr)
{
	T nMaxSum = 0;

	for (int i = 0; i < vArr.size(); i++)
	{
		for (int j = i; j < vArr.size(); ++j)
		{
			T nSum = 0;
			for (int k = i; k <= j; ++k)
				nSum += vArr[k];

			nMaxSum = max(nMaxSum, nSum);
		}
	}

	return nMaxSum;
}

template< typename T >
T MaxSum2(vector< T > vArr)
{
	vector< T > vSoFarSum;

	vSoFarSum.push_back(vArr[0]);
	for (int i = 1; i < vArr.size(); ++i)
	{
		vSoFarSum.push_back(vArr[i] + vSoFarSum[i - 1]);
	}

	/*
	cout << "vSoFarSum: ";
	copy(vSoFarSum.begin(), vSoFarSum.end(), ostream_iterator< double >(cout, " "));
	*/
	
	T nMaxSum = 0;

	for (int i = 0; i < vArr.size(); i++)
	{
		T nSum = 0;

		for (int j = i; j < vArr.size(); ++j)
		{
			if (0 == i)
				nSum = vSoFarSum[j];
			else
				nSum = vSoFarSum[j] - vSoFarSum[i - 1];

			nMaxSum = max(nMaxSum, nSum);
		}
	}

	return nMaxSum;
}

template< typename T >
T MaxSum3(vector< T > vArr)
{

}

template< typename T >
T MaxSum4(vector< T > vArr)
{
	T nMaxSum = 0;
	T nMaxEndingHere = 0;

	for (int i = 0; i < vArr.size(); ++i)
	{
		nMaxEndingHere = max(nMaxEndingHere + vArr[i], (T)0);
		nMaxSum = max(nMaxSum, nMaxEndingHere);
	}

	return nMaxSum;
}

void main()
{
	vector< double > vArr;
	/*
	random_device rd;
    mt19937 gen(rd());
	normal_distribution<> NorDist(5, 3);

	for (int i = 0; i < 10; ++i) 
		vArr.push_back(NorDist(gen));
		//cout << NorDist(gen) << endl;
	*/

	vArr.push_back(1);
	vArr.push_back(2);
	vArr.push_back(-20);
	vArr.push_back(4);
	vArr.push_back(-5);
	vArr.push_back(5);
	vArr.push_back(6);
	vArr.push_back(-10);
	vArr.push_back(8);
	vArr.push_back(9);

	copy(vArr.begin(), vArr.end(), ostream_iterator< double >(cout, " "));

	cout << endl;

	cout << "MaxSum1 : " << MaxSum1(vArr) << endl;

	cout << "MaxSum2 : " << MaxSum2(vArr) << endl;

	cout << "MaxSum4 : " << MaxSum4(vArr) << endl;
}

#endif
