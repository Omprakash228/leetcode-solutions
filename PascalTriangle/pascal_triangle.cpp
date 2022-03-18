#include <iostream>
#include <vector>

using namespace std;

void printTriangle(vector<vector<int>> triangle)
{
    for(int i = 0; i < triangle.size(); i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    if(numRows >= 1)
    {
        triangle.push_back({1});
    }
    if(numRows >= 2)
    {
        triangle.push_back({1,1});
    }
    
    for(int i = 2; i < numRows; i++)
    {
        vector<int> inner{1};
        for(int j = 1; j < i ; j++)
        {
            inner.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
        }
        inner.push_back(1);
        triangle.push_back(inner);
    }
    return triangle;
}

int main() {
    int numRows = 10;
    vector<vector<int>> triangle = generate(numRows);
    printTriangle(triangle);
    return 0;
}
