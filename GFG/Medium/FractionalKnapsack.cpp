// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, [&](Item &a, Item &b)
             {
            double va = (double)a.value / a.weight;
            double vb = (double)b.value / b.weight;
    
            return va > vb; });
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (W >= arr[i].weight)
            {
                ans += arr[i].value;
                W -= arr[i].weight;
                continue;
            }

            double vw = (double)arr[i].value / arr[i].weight;

            ans += vw * W;
            W = 0;
            break;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends