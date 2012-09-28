#ifdef _ARRAY_SERIALIZE_

/*
Problem

Solution

*/

#include "Header.h"

auto SerializeArray(vector< string > vArr) -> pair<vector< int >, string>
{
	vector< int > vStringIdx;
	int nStringStartIdx = 0;
	string strResult;

	int i = 0;
	for (; i < vArr.size(); ++i)
	{
		strResult.append(vArr[i]);
		vStringIdx.push_back(nStringStartIdx);
		nStringStartIdx += vArr[i].size();
	}

	vStringIdx.push_back(nStringStartIdx);

	return make_pair(vStringIdx, strResult);
}

auto DeSerializeArray(vector< int > vStringIdx, string strOriginal) -> vector< string >
{
	vector< string > vResult;

	for (int i = 0; i < vStringIdx.size() - 1; ++i)
		vResult.push_back(string(strOriginal.begin() + vStringIdx[i], strOriginal.begin() + vStringIdx[i + 1]));
		//cout << string(strOriginal.begin() + vStringIdx[i], strOriginal.begin() + vStringIdx[i + 1]) << endl;

	return vResult;
}

void main()
{
	vector< string > vArr;
	vArr.push_back( "AAAAA" );
	vArr.push_back( "BBBBBBBBBB" );

	auto Result = SerializeArray(vArr);

	copy(Result.first.begin(), Result.first.end(), ostream_iterator< int >(cout, " "));
	cout << Result.second << endl;

	auto Result2 = DeSerializeArray(Result.first, Result.second);
	copy(Result2.begin(), Result2.end(), ostream_iterator< string >(cout, " "));
}

#endif
