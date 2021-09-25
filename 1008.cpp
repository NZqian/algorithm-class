#include <iostream>
#include <memory.h>
using namespace std;
bool isprime(int a)
{
    for (int i = 2; i <= a / 2; i++)
        if (a % i == 0)
            return false;
    return true;
}
bool search(int arr[], bool used[], int depth)
{
    if (depth == 21)
        return true;
    for (int i = 1; i <= 20; i++)
    {
        if (used[i] || !isprime(arr[depth - 1] + i))
            continue;
        arr[depth] = i;
        used[i] = true;
        if (depth == 20 && isprime(arr[depth] + arr[1]))
        {
            return true;
        }
        if (depth != 20 && search(arr, used, depth + 1))
            return true;
        used[i] = false;
    }
    return false;
}
void show(int arr[])
{
    for (int i = 1; i < 20; i++)
        cout << arr[i] << ' ';
    cout << arr[20] << endl;
}
int main()
{
    int arr[21];
    bool used[21];
    memset(used, false, sizeof(used));
    for (int i = 1; i <= 20; i++)
    {
        arr[1] = i;
        used[i] = true;
        if (search(arr, used, 2))
        {
            show(arr);
            break;
        }
        used[i] = false;
    }
}