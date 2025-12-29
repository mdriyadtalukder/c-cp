#include <iostream>
using namespace std;
main()
{
    int n;
    cout << "Number of student: ";
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " Student number: ";
        cin >> s[i];
    }
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + s[i];
    }
    float avrg = (float) total / n;

    cout << "Total number: " << total << endl;
    cout << "Average number: " << avrg << endl;

    int max = s[0];
    int min = s[0];
    for (int i = 0; i < n; i++)
    {
        if (max < s[i])
        {
            max = s[i];
        }
        if (min > s[i])
        {
            min = s[i];
        }
    }
    cout << "Max number: " << max << endl;
    cout << "Min number: " << min << endl;
}