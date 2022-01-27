//Calculate the minimum average waiting time of the customers ordering Pan 

/*Ramu owns a Pan shop and he manages it in his own way. While in a normal shop, a customer is served by following 
the first-come, first-served rule, Ramu simply minimizes the average waiting time of his customers. So he gets to 
decide who is served first, regardless of how sooner or later a person comes.

Different kinds of Pans take different amounts of time to cook. Also, once he starts cooking a Pan, 
he cannot cook another Pan until the first Pan is completely cooked. Let's say we have three customers who come 
at time t=0, t=1, & t=2 respectively, and the time needed to cook their Pans is 3, 9, & 6 respectively. 
If Ramu applies first-come, first-served rule, then the waiting time of three customers is 3, 11, & 16 respectively. 
The average waiting time in this case is (3 + 11 + 16) / 3 = 10. This is not an optimized solution. After serving the 
first customer at time t=3, Ramu can choose to serve the third customer. In that case, the waiting time will be 3, 7, & 17 respectively. 
Hence the average waiting time is (3 + 7 + 17) / 3 = 9.

Help Ramu achieve the minimum average waiting time. For the sake of simplicity, just find the integer part of the 
minimum average waiting time.
*********************************************************************************/

#include<bits/stdc++.h>
using namespace std;

//Function to calculate the minimum average waiting time of the customers
int minAvgWaitTime(vector<pair<int,int>> &orders)
{
    long long minTime = 0, currTime = 0;

    //priority queue is used to push the orders according to less cooking time needed
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    int i = 1;
    minHeap.push(make_pair(orders[0].second,orders[0].first));
    currTime = orders[0].first;

    //To add until the heal gets empty or the loop reaches the last order received
    while(!minHeap.empty() || i<orders.size())
    {
        while(i<orders.size() && orders[i].first<=currTime)
        {
            minHeap.push(make_pair(orders[i].second,orders[i].first));
            i++;
        }

        //If min heap formed is already empty and the loop is not yet out of bound(size), then new pair is 
        //pushed into heap and currTime is updated
        if(minHeap.empty() && i<orders.size())
        {
            currTime = orders[i].first;
            minHeap.push(make_pair(orders[i].second,orders[i].first));
            i++;
        }

        pair<int,int> p = minHeap.top();
        minHeap.pop();

        //Calculate the current time by adding in every loop
        currTime += (long long) p.first;

        //Calculate the minimum time by adding the new current time and subtracting the time of the order placed for that particular order
        minTime += (long long)(currTime) - (long long)(p.second);
    }

    return minTime/orders.size();
}

int main()
{
    int n; //n is the number of customers
    cout << endl;
    cout << "Enter the total number of customers ordering Pan : ";
    cin >> n;
    cout << endl;

    //Vector of pair is the vector containing the pair of ordered time and cooking time for each customer's order
    vector<pair<int,int>> arrivalAndCookTime(n);
    cout << "Enter arrival and cook time for all the customers : ";
    for(int i=0;i<n;i++)
    {
        cin >> arrivalAndCookTime[i].first >> arrivalAndCookTime[i].second;
    }
    cout << endl;

    //sort the input pair according to the time of arrival 
    sort(arrivalAndCookTime.begin(),arrivalAndCookTime.end());

    cout << "Minimum Average Waiting Time is : " << minAvgWaitTime(arrivalAndCookTime) << endl;
    cout << endl;
    return 0;
}