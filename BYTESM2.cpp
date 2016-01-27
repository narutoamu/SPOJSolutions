#include <iostream>

using namespace std;

int Memo[100][100];

void RefreshMemo()
{
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            Memo[i][j] = -1;
}

inline int Max(int a, int b, int c = -1)
{
    if( a > b && a > c)
        return a;
    else if( b > a && b > c)
        return b;
    return c;
}

int CollectMax(int Stones[100][100], int i, int j, int MaxRow, int MaxColumn)
{
    if (Memo[i][j] >= 0)
        return Memo[i][j];

    else
    {
        if (i == MaxRow)
            Memo[i][j] = Stones[i][j];
        else if (j == 0)
            Memo[i][j] = Stones[i][j] + Max( CollectMax(Stones, i+1, j, MaxRow, MaxColumn), CollectMax(Stones, i+1, j+1, MaxRow, MaxColumn) );
        else if (j == MaxColumn)
            Memo[i][j] = Stones[i][j] + Max( CollectMax(Stones, i+1, j, MaxRow, MaxColumn), CollectMax(Stones, i+1, j-1, MaxRow, MaxColumn) );  
        else
            Memo[i][j] = Stones[i][j] + Max( CollectMax(Stones, i+1, j, MaxRow, MaxColumn), CollectMax(Stones, i+1, j+1, MaxRow, MaxColumn), CollectMax(Stones, i+1, j-1, MaxRow, MaxColumn) );

        return Memo[i][j];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while ( t-- && t >= 0)
    {
        int Stones[100][100], h, w;
        int Answer = 0;
        cin>>h>>w;

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin>>Stones[i][j];
        RefreshMemo();  
        for (int i = 0; i < w; ++i)
        {
            int TryI = CollectMax(Stones, 0, i, h-1, w-1);
            if(Answer < TryI)
                Answer = TryI;
        }
        cout<<Answer<<endl;
    }
    return 0;
}