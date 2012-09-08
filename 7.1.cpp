#ifdef P_7_1
#include <iostream>
using namespace std;

class Call
{
public:
	int		ID;

	Call(int nID) { ID = nID; };
};


class CallCenter
{
public:
	int DispatchCall(Call);
};


int CallCenter::DispatchCall(Call oCall)
{
	cout << oCall.ID;

	return 0;
}
#endif
