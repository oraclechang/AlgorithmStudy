#ifdef P_4_3

/*
Problem
	Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height

Solution
	We will try to create a binary tree such that for each node, 
	the number of nodes in the left subtree and the right subtree are equal, if possible 
	Algorithm:
	1   Insert into the tree the middle element of the array
	2   Insert (into the left subtree) the left subarray elements
	3   Insert (into the right subtree) the right subarray elements
	4   Recurse

	public static TreeNode addToTree(int arr[], int start, int end){
		if (end < start) {
			return null;
		}
		int mid = (start + end) / 2;
		TreeNode n = new TreeNode(arr[mid]);
		n.left = addToTree(arr, start, mid - 1);
		n.right = addToTree(arr, mid + 1, end);
		return n;
	}

	public static TreeNode createMinimalBST(int array[]) {
		return addToTree(array, 0, array.length - 1);
	}
*/

#include "Header.h"

void main()
{
}

#endif
