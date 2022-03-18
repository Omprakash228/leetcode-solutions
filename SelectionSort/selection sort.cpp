#include<iostream>
#include<vector>

using namespace std;

void printElements(vector<int> elements)
{
    for(int i: elements)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> selectionSort(vector<int> elements)
{
    int n = elements.size();
    for(int i = 0 ; i < n - 1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(elements[i] > elements[j])
            {
                int temp = elements[j];
                elements[j] = elements[i];
                elements[i] = temp;
            }
        }
    }
    return elements;
}


int main()
{
    vector<int> elements {2, 4, 1, 5, 3, 10, 7, 9};
    vector<int> sorted = selectionSort(elements);
    printElements(sorted);
    return 0;
}