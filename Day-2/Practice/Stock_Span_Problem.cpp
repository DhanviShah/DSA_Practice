//Stock Span Problem
//The stock span problem is a financial problem where we have a series of n daily price quotes 
//for a stock and we need to calculate span of stock’s price for all n days. 

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void CalculateStockSpan(int stockPrice[], int days, int S[])
{
    stack<int> stk;
    stk.push(0);

    //Span for the first day is always 1 as there are no previous days
    S[0] = 1;

    //Calculating span values for the rest of the elements
    for(int i=1;i<days;i++)
    {
        //While the stack is not empty and the price of the current day is higher than previous days, 
        //then pop out the previous days from the stack.
        while(!stk.empty() && stockPrice[i]>=stockPrice[stk.top()])
            stk.pop();

        //If stack is already empty by now, then update the value in stack by pushing the current day index
        if(stk.empty())
            S[i] = i+1;
        //Else if stack is not empty, then update the value in the stack by the difference of the days
        else
            S[i] = i - stk.top();

        stk.push(i);
    }
}

int main()
{
    int days;
    cout << "Enter the number of days for which you want to calculate span of stock's price : ";
    cin >> days;
    int stockPrice[days];
    int S[days];
    cout << "Enter the price for each of the " << days << " days : ";
    for(int i=0;i<days;i++)
    {
        cin >> stockPrice[i];
    }
    //cout << stockPrice[0] << endl;
    //int S[days];
    
    CalculateStockSpan(stockPrice,days,S);

    //To print the calculated span values
    cout << "Calculated Span values of the stock are : ";
    for(int i=0;i<days;i++)
    {
        cout << S[i] << " ";
    }
    cout << endl;
    return 0;
}