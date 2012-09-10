#ifdef _HEAPSORT

#include "Header.h"

const int PQ_SIZE = 100;

struct pq
{
	int q[PQ_SIZE + 1];
	int n;
};

int pq_parent(int n)
{
	if (1 == n)
		return -1;
	else
		return (int) n / 2;
}

int pq_young_child(int n)
{
	return 2 * n;
}

void bubble_up(pq* q, int p)
{
	if (-1 == pq_parent(p))
		return;
	
	if (q->q[pq_parent(p)] > q->q[p])
	{
		pq_swap(q, p, pq_parent(p));
		bubble_up(q, pq_parent(p));
	}
}

void pq_insert(pq* q, int x)
{
	if (q->n >= PQ_SIZE)
		cout << "Overflow" << endl;
	else
	{
		q->n = (q->n) +1;
		q->q[q->n] = x;
		bubble_up(q, q->n);
	}
}


int main()
{
	return 0;
}

#endif