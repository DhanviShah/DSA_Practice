/*Reverse An Array*/

/*An array is a data structure that keeps items of the same kind in a single memory block. Each memory position in an array, P, of size Q, has a unique index, I (where 0=i=Q), which may be referred as P[i] or Pi. Reverse an integer array.

Example 
P=[4,5,6]
Return [6,5,4]

Reverse an integer array. Description of the Function

complete the reverseArray function in any programming language or your choice or you may write sudo code for the same

The parameter(s) for reverseArray are:
int P [q]: the array to reverse  

Returns
Int[q]: the reversed array

Input format
The first line includes an integer, Q, which represents the number of integers in P.
P is made up of Q space-separated numbers on the second line.

Constraints
1<=Q<=103
1<=p[i]<=104 where p[i]  is the ith integer in P

****************************************************************/


#include<bits/stdc++.h>
using namespace std;

//Reverse Array Function
int* reverseArray(int size, int arr[])
{
    //Iterating the loop only till half the size of an array because it replaces the first element with the last element
    for(int i=0;i<size/2;i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
    return arr;
}

int main()
{
    int q;
    cout << "Enter the size of an array : ";
    cin >> q;

    int p[q];
    cout << "Enter the elements of an array : ";
    for(int i=0;i<q;i++)
    {
        cin >> p[i];
    }

    //Calling the reverseArray function to reverse the input Array
    int* revp = reverseArray(q,p);

    cout <<  "Reversed array is : ";
    for(int i=0;i<q;i++)
    {
        cout << revp[i] << " ";
    }
    return 0;
}
