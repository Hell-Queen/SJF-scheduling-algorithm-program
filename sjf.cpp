// non-preemptive
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;

    cout << "enter the no. of process: ";
    cin >> n;
    int BT[n], AT[n], TAT[n];
    for (int i = 0; i < n; i++)
    {
        AT[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "enter the burst time of process " << (i + 1) << ": ";
        cin >> BT[i];
    }
    float WT = 0;
    float awt = 0;

    int min = 0;
    int t = 0;

    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (BT[j] < BT[min])
                {
                    min = j;

                }
            }
        }
       // cout << min << " ";

        t += BT[min];

        TAT[i] = t;
        WT += TAT[i] - BT[min];
        BT[min] = INT_MAX;
    }

    awt = WT / n;
    float tat = 0;

    float att = 0;
    for (int i = 0; i < n; i++)
    {
        tat += TAT[i];
    }
    att = tat / n;
    cout << "average turn around time: " << att << " ms" << endl;
    cout << "average waiting time: " << awt << " ms";
    return 0;
}
