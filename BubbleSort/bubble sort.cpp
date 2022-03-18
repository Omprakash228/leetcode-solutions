#include<iostream>
#include<vector>

using namespace std;

vector<int> bubbleSort(vector<int> elements)
{
    int n = elements.size();
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(elements[j] > elements[j+1])
            {
                int temp = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = temp;
            }
        }
    }
    return elements;
}

int main() 
{
    vector<int> elements {2,4,1,5,3};
    vector<int> sorted = bubbleSort(elements);
    for(int i: sorted)
    {
        cout << i << endl;
    }
    return 0;
}