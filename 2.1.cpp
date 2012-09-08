#ifdef P_2_1
/*
Problem
	Write code to remove duplicates from an unsorted linked list
	FOLLOW UP
	How would you solve this problem if a temporary buffer is not allowed?

Solution
	If we can use a buffer, we can keep track of elements in a hashtable and remove any dups:
	public static void deleteDups(LinkedListNode n) {
		Hashtable table = new Hashtable();
		LinkedListNode previous = null;
		while (n != null) {
			if (table.containsKey(n.data)) previous.next = n.next;
			else {
				table.put(n.data, true);
				previous = n;
			}
			n = n.next;
		}
	}
*/
/*
Solution 2
	Without a buffer, we can iterate with two pointers: ¡°current¡± does a normal iteration, 
	while ¡°runner¡± iterates through all prior nodes to check for dups 
	Runner will only see one dup per node, 
	because if there were multiple duplicates they would have been removed already

	public static void deleteDups2(LinkedListNode head) {
		if (head == null) return;
		LinkedListNode previous = head;
		LinkedListNode current = previous.next;
		while (current != null) {
			LinkedListNode runner = head;
			while (runner != current) { // Check for earlier dups
				if (runner.data == current.data) {
					LinkedListNode tmp = current.next; // remove current
					previous.next = tmp; 
					current = tmp; // update current to next node
					break; // all other dups have already been removed
				}
				runner = runner.next;
			}
			if (runner == current) { // current not updated - update now
				previous = current;
				current = current.next;
			}
		}
	}

*/

#include "header.h"
#include "LinkedList.h"

void RemoveDup(list< int >& lList)
{
	cout << "Before : ";
	copy(lList.cbegin(), lList.cend(), ostream_iterator< int >(cout, " "));

	set< int > sSet;
	for (list< int >::iterator it = lList.begin(); it != lList.end();)
	{
		auto rtn = sSet.insert(*it);	
		if (false == rtn.second)
		{
			lList.erase(it++);
		}
		else
			++it;
	}

	cout << endl << "After : ";
	copy(lList.cbegin(), lList.cend(), ostream_iterator< int >(cout, " "));
}


int main()
{
	/*
	list< int > lList;
	lList.push_back(5);
	lList.push_back(2);
	lList.push_back(1);
	lList.push_back(3);
	lList.push_back(4);
	lList.push_back(4);
	lList.push_back(4);
	lList.push_back(1);

	RemoveDup(lList);
	*/

	LinkedList< int >* pList = new LinkedList< int >();
	pList->Insert(5);
	pList->Insert(4);
	pList->Insert(1);
	pList->Insert(2);
	pList->Insert(4);
	pList->Insert(3);
	pList->Insert(1);

	cout << "Before : ";
	pList->PrintAll();

	//pList->deleteDups();
	pList->deleteDups2();

	cout << endl << "After : ";
	pList->PrintAll();

	return 0;
}
#endif
