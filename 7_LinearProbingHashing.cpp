#include <iostream>

using namespace std;

class hashtable
{
public:
    int table[50];
    int chain[50];
    int table_size;
    int counter;
    int prev_hashash_value;

    hashtable(int n)
    {
        table_size = n;
        counter = 0;
        for (int i = 0; i < table_size; i++)
        {
            table[i] = -1;
            chain[i] = -1;
        }
    }
    void chain_no_rep(int data);
    void chain_with_rep(int data);
    void display();
    int calculate(int data);
};

void hashtable::chain_with_rep(int data)
{
    int hash_value = calculate(data);
    if (table[hash_value] == -1)
    {
        table[hash_value] = data;
        counter++;
    }
    else
    {
        int temphashash_value = calculate(table[hash_value]);
        if (temphashash_value == hash_value)
        {
            while (chain[hash_value] != -1)
            {
                hash_value = chain[hash_value];
            }
            prev_hashash_value = hash_value;
        }
        while (1)
        {
            hash_value = (hash_value + 1) % table_size;
            if (counter == table_size)
            {
                cout << "\nThe hash table has no empty places to insert.";
                break;
            }
            else if (table[hash_value] == -1)
            {
                table[hash_value] == data;
                counter++;
                chain[prev_hashash_value] = hash_value;
                break;
            }
        }
        int tempdata = table[hash_value];
        int temphash_value = hash_value;
        table[hash_value] = data;
        counter++;
        while (chain[hash_value] != -1)
        {
            hash_value = chain[hash_value];
        }
        while (1)
        {
            hash_value = (hash_value + 1) % table_size;
            if (counter == table_size)
            {
                cout << "\nHash table has no empty place to store data.";
                break;
            }
            else if (table[hash_value] == -1)
            {
                table[hash_value] = tempdata;
                chain[temphash_value] = hash_value;
                break;
            }
        }
    }
    display();
}

void hashtable::chain_no_rep(int data)
{
    int hash_value = calculate(data);
    if (table[hash_value] == -1)
    {
        table[hash_value] = data;
        counter++;
    }
    else
    {
        while (chain[hash_value] != -1)
        {
            hash_value = chain[hash_value];
        }
        int prevhashash_value = hash_value;
        while (1)
        {
            hash_value = (hash_value + 1) % table_size;
            if (counter == table_size)
            {
                cout << "\nNo empty space in the hash table.";
                break;
            }
            else if (table[hash_value] == -1)
            {
                table[hash_value] = data;
                counter++;
                chain[prevhashash_value] = hash_value;
                break;
            }
        }
    }
    display();
}

int hashtable::calculate(int data)
{
    return data % table_size;
}

void hashtable::display()
{
    cout << "\nHash Table has: " << counter << " elements" << endl;
    cout << "\nKey :\tValue :\tChain" << endl;
    for (int i = 0; i < table_size; i++)
    {
        cout << " " << i << " \t" << table[i] << " \t" << chain[i] << endl;
    }
}

int main()
{
    hashtable h(10);
    int cont, data, ch1;

    cout << "\n--------Linear Probing Implimentation--------" << endl;
    cout << "1. Linear Probing with Chaining without Replacement.\n2. Linear Probing with chaining with replacement.\n0. Exit";
    cout << "\nEnter your choice: ";
    cin >> ch1;

    switch (ch1)
    {
    case 0:
        exit(0);
        break;

    case 1:
        while (1)
        {
            cout << "\nEnter the value you want to enter: ";
            cin >> data;
            h.chain_no_rep(data);
            cout << "\nDo you want to enter another value (1:Yes / 0:No ): ";
            cin >> cont;
            if (cont == 0)
                break;
        }
        break;

    case 2:
        while (1)
        {
            cout << "\nEnter the value you want to insert: ";
            cin >> data;
            h.chain_with_rep(data);
            cout << "\nDo you want to enter another value (1:Yes / 0:No ): ";
            cin >> cont;
            if (cont == 0)
                break;
        }
        break;

    default:
        cout << "\nWrong Choice! Try Again! ";
    }
    return 0;
}