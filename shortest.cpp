#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of connections: ";
    cin >> m;

    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
        cost[i][i] = 0;

    cout << "\nEnter connections (A B cost):\n";

    for (int i = 0; i < m; i++)
    {
        char u, v;
        int c;

        cin >> u >> v >> c;

        int a = u - 'A';
        int b = v - 'A';

        cost[a][b] = c;
        cost[b][a] = c;
    }

    vector<int> d(n, INT_MAX);
    vector<bool> visited(n, false);

    d[0] = 0;  // Source node A

    for (int i = 0; i < n; i++)
    {
        int u = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] &&
                (u == -1 || d[j] < d[u]))
            {
                u = j;
            }
        }

        if (u == -1 || d[u] == INT_MAX)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                cost[u][v] != INT_MAX &&
                d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
            }
        }
    }

    cout << "\nShortest Distance Table\n";
    cout << "------------------------------------------------\n";

    cout << left << setw(15) << "Source Node"
         << setw(15) << "Node"
         << "Shortest Distance\n";

    cout << "------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(15) << 'A'
             << setw(15) << char('A' + i);

        if (d[i] == INT_MAX)
            cout << "Infinity";
        else
            cout << d[i];

        cout << endl;
    }

    return 0;
}
