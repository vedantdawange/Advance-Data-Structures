// #include <bits/stdc++.h>
#include <iostream>
#define TNO 2
#define MOD 6
using namespace std;
int cuckooTable[TNO][MOD];
int POSITION[TNO];
void fillTable()
{
    for (int j = 0; j < MOD; j++)
        for (int i = 0; i < TNO; i++)
            cuckooTable[i][j] = INT_MIN;
}
void printTable()
{
    cout << "Hash Tables are:\n"
         << endl;
    for (int i = 0; i < TNO; i++, printf("\n"))
    {
        int k = i + 1;
        cout << "Table: " << k << "-> ";
        for (int j = 0; j < MOD; j++)
        {
            if (cuckooTable[i][j] == INT_MIN)
                cout << " N ";
            else
                cout << " " << cuckooTable[i][j];
        }
    }
    cout << endl;
}
int getHashValue(int function, int key)
{
    switch (function)
    {
    case 1:
        return key % MOD;
    case 2:
        return (key / MOD) % MOD;
    }
}
void getArrange(int key, int id, int c, int n)
{
    if (c == n)
    {
        cout << key << " do not have a position\n"
             << endl;
        //cycle present rehash
        return;
    }
    for (int i = 0; i < TNO; i++)
    {
        POSITION[i] = getHashValue(i + 1, key);
        if (cuckooTable[i][POSITION[i]] == key)
            return;
    }
    if (cuckooTable[id][POSITION[id]] != INT_MIN)
    {
        int dis = cuckooTable[id][POSITION[id]];
        cuckooTable[id][POSITION[id]] = key;
        getArrange(dis, (id + 1) % TNO, c + 1, n);
    }
    else
        cuckooTable[id][POSITION[id]] = key;
}
void cuckooFunction(int keys[], int n)
{
    fillTable();
    for (int i = 0, c = 0; i < n; i++, c = 0)
        getArrange(keys[i], 0, c, n);
    printTable();
}
int main()
{
    int count;
    int keyTable1[10];
    cout << "Enter the Number of elements(Max 10): ";
    cin >> count;
    cout << endl;
    for (int i = 0; i < count; i++)
    {
        cout << "\nEnter the the Number : ";
        cin >> keyTable1[i];
    }
    cout << "\nPerforming Cuckoo Function:\n"
         << endl;
    cuckooFunction(keyTable1, count);

    return 0;
}
