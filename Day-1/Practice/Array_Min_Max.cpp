//Find the maximum and minimum element in an array
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of an array : ";
    cin >> size;
    int arr[size];
    cout << "Enter the values of an array : ";
    for(int i=0;i<size;i++)
    {
        cin >> arr[i];
    }

    int max_ele = INT_MIN, min_ele = INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(min_ele>arr[i])
            min_ele = arr[i];
        
        if(max_ele<arr[i])
            max_ele = arr[i];
    }

    cout << "Max element of an array is : " << max_ele << endl;
    cout << "Min element of an array is : " << min_ele << endl;
    cout << endl;
    return 0;
}