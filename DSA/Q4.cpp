#include <bits/stdc++.h>
using namespace std;

int findRunway(int arr[], int dep[], int n)
{
    int runway_needed = 1, result = 1;

    for (int i = 0; i < n; i++) {
        runway_needed = 1;
        for (int j = 0; j < n; j++) {
            if (i != j)
                if (arr[i] >= arr[j] && dep[j] >= arr[i])
                    runway_needed++;
        }
        result = max(runway_needed, result);
    }
    return result;
}

int main()
{
    int arr[] = { 100, 300, 500 };
    int dep[] = { 900, 400, 600 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<findRunway(arr, dep, n);
    return 0;
}