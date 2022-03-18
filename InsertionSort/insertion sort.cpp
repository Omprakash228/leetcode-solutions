#include<iostream>
#include<vector>

using namespace std;

vector<int> insertionSort(vector<int> elements)
{
    for(int i = 1; i < elements.size(); i++)
    {
        int key = elements[i];
        int j = i - 1;
        
        while(j >= 0 && elements[j] > key)
        {
            elements[j+1] = elements[j];
            j = j - 1;
        }
        elements[j+1] = key;
    }
    return elements;
}

int main()
{
    vector<int> elements {2, 4, 1, 3, 5};
    vector<int> sorted = insertionSort(elements);
    for(int i:sorted)
    {
        cout << i << endl;
    }
    return 0;
}