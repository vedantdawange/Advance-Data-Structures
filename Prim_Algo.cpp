// Prim's Algorithm Implementation

#include <cstring>
#include <iostream>
using namespace std;

#define INF 9999999

#define Max_V 10

int A[Max_V][Max_V]; // Matrix For edge weight values

int main()
{
    int edges = 0;
    int total_cost = 0;

    int selected[Max_V];

    memset(selected, false, sizeof(selected));

    int i, j;
    cout << " Enter value of the total number of vertices : ";
    int verts;
    cin >> verts;
    cout << " Enter the adj.matrix for cost: ";

    for (i = 0; i < verts; i++)
    {
        for (j = 0; j < verts; j++)
        {
            cin >> A[i][j];
        }
    }

    selected[0] = true;

    int r; //  row number
    int c; //  column number

    cout << "Edges : Weight" << endl;

    while (edges < verts - 1)
    {

        int min = INF;
        r = 0;
        c = 0;

        for (int i = 0; i < verts; i++)
        {
            if (selected[i])
            {

                for (int j = 0; j < verts; j++)
                {
                    if (!(selected[j]) && A[i][j])
                    {
                        if (min > A[i][j])
                        {
                            min = A[i][j];
                            r = i;
                            c = j;
                        }
                    }
                }
            }
        }
        cout << r << " -> " << c << " :  " << A[r][c];
        cout << endl;
        total_cost = total_cost + A[r][c];
        selected[c] = true;
        edges++;
    }
    cout << " Minimum cost of path : " << total_cost;
    return 0;
}
