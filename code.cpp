#include <bits/stdc++.h>
// #include <windows.h>
#define loop(i, j) for (int i = 0; i < j; ++i)
using namespace std;
// #include<conio.h>

vector<int>
getArrayInput()
{
    int n, i;
    cout << "Enter the number of elements:- ";
    cin >> n;
    vector<int> v(n);
    for (i = 0; i < n; ++i)
    {
        cout << "Element " << i + 1 << ":- ";
        cin >> v[i];
    }
    return v;
}

void printSpaces(int n)
{
    loop(i, n)
            cout
        << " ";
}

void printBorder(vector<int> v, int index, string box)
{
    loop(i, v.size())
    {
        if (i == index)
        {
            cout << box << endl;
            break;
        }
        printSpaces(floor(log10(v[i]) + 1) + 3);
    }
}

void printBorders(vector<int> v, vector<int> index, vector<string> box)
{
    int j = 0;
    loop(i, v.size())
    {
        if (binary_search(index.begin(), index.end(), i))
        {
            cout << box[j];
            ++j;
            printSpaces(3);
        }
        else
            printSpaces(floor(log10(v[i]) + 1) + 3);
    }
    cout << endl;
}

void printArrays(vector<int> v, vector<int> index)
{
    vector<string> box(index.size(), "+");
    int cntdigits;
    loop(i, index.size())
    {
        cntdigits = floor(log10(v[index[i]]) + 1);
        loop(j, cntdigits + 2)
        {
            box[i] += "-";
        }
        box[i] += "+";
    }

    printBorders(v, index, box);
    loop(i, v.size())
    {
        if (binary_search(index.begin(), index.end(), i))
        {

            cout << "| " << v[i] << " |";
        }
        else
        {
            cout << v[i];
        }
        printSpaces(3);
    }
    cout << endl;
    printBorders(v, index, box);
}

void printArray(vector<int> v, int index)
{
    string box = "+";
    int cntdigits = floor(log10(v[index]) + 1);
    loop(i, cntdigits + 2)
    {
        box += "-";
    }
    box += "+";
    printBorder(v, index, box);
    loop(i, v.size())
    {
        if (i == index)
        {

            cout << "| " << v[i] << " |";
        }
        else
        {
            cout << v[i];
        }
        printSpaces(3);
    }
    cout << endl;
    printBorder(v, index, box);
}

void printMainMenu()
{
    cout << "1 -> Searching\n2 -> Sorting\n3 -> Exit\nEnter your choice :- ";
}

void linearSearch()
{
    int i, n, tmp, t, notFound = 0;
    string ip;
    vector<int> v = getArrayInput();
    cout << "Enter the element to search :- ";
    cin >> tmp;
    cout << "Enter the time delay in seconds:- ";
    cin >> t;
    cout << "\tImplementing Linear Searching\n";
    for (i = 0; i < v.size(); ++i)
    {
        //      Sleep(t*1000);
        printArray(v, i);
        if (v[i] == tmp)
        {
            cout << tmp << " is at index " << i << endl;
            ++notFound;
            break;
        }
    }
    if (!notFound)
    {
        cout << tmp << "not found in the given list!!" << endl;
    }
    system("PAUSE");
}

void printArrayBinary(vector<int> v, int index, int l, int r)
{
    string box = "+";
    int cntdigits = floor(log10(v[index]) + 1);
    loop(i, cntdigits + 2)
    {
        box += "-";
    }
    box += "+";
    printBorder(v, index - l, box);
    for (int i = l; i <= r; ++i)
    {
        if (i == index)
        {

            cout << "| " << v[i] << " |";
        }
        else
        {
            cout << v[i];
        }
        printSpaces(3);
    }
    cout << endl;
    printBorder(v, index - l, box);
}

int binarySearch(vector<int> arr, int x)
{
    int t, l = 0;
    int r = arr.size() - 1;
    vector<int> tmp = arr;
    sort(arr.begin(), arr.end());
    if (arr != tmp)
        cout << "\nSince the array is not sorted, so we sort the array first\n";
    cout << "Enter the time Delay in Seconds:- ";
    cin >> t;
    //    Sleep(t*1000);
    cout << "\n\t\tImplementing Binary Search....\n";
    while (l <= r)
    {
        int m = (l + r) / 2;
        // Sleep(t*1000);
        printArrayBinary(arr, m, l, r);
        // Sleep(t*1000);
        cout << "\nThe middle element is " << arr[m] << "\n";

        // Check if x is present at mid
        if (arr[m] == x)
        {
            //  Sleep(t*1000);
            return m;
        }
        // If x greater, ignore left half
        if (arr[m] < x)
        {
            l = m + 1;
            // Sleep(t*1000);
            cout << "\n"
                 << arr[m] << " is less than " << x << endl;
            // Sleep(t*1000);
            cout << "\nNew Searching Array:-\n\n";
            // Sleep(t*1000);
            for (int i = l; i <= r; ++i)
            {
                cout << arr[i] << " ";
                //  Sleep(0.7*1000);
            }
            cout << endl;
        }
        // If x is smaller, ignore right half
        else
        {
            r = m - 1;
            // Sleep(t*1000);
            cout << "\n"
                 << arr[m] << " is greater than " << x << endl;
            //  Sleep(t*1000);
            cout << "\nNew Searching Array:-\n\n";
            //    Sleep(t*1000);
            for (int i = l; i <= r; ++i)
            {
                cout << arr[i] << " ";
                // Sleep(0.7*1000);
            }
            cout << endl;
        }
    }
    return -1;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort()
{
    int i, j, t;
    vector<int> arr = getArrayInput();
    int n = arr.size();
    vector<int> index(2);
    cout << "\nEnter time delay in seconds:- ";
    cin >> t;
    cout << "\n\t\t Implementing Bubble Sort\n";
    for (i = 0; i < n - 1; i++)
    {
        cout << "\n Iteration No. - " << i + 1 << "\n";
        for (j = 0; j < n - i - 1; j++)
        {
            index[0] = j;
            index[1] = j + 1;
            // Sleep(t*1000);
            sort(index.begin(), index.end());
            printArrays(arr, index);
            if (arr[j] > arr[j + 1])
            {
                //      Sleep(t*1000);
                cout << "\n"
                     << arr[j] << " is greater than " << arr[j + 1] << " we will swap.\n";
                swap(&arr[j], &arr[j + 1]);
                //        Sleep(t*1000);
                cout << "\nNew Array:-\n";
                //          Sleep(t*1000);
                cout << endl;
                for (int k = 0; k < n; ++k)
                    cout << arr[k] << " ";
                cout << endl;
            }
            else
            {
                //          Sleep(t*1000);
                cout << "\n"
                     << arr[j] << " is less than " << arr[j + 1] << " No swapping.\n";
            }
        }
    }
    //  Sleep(t*1000);
    cout << "\nFinal Sorted Array:- \n";
    //    Sleep(t*1000);
    for (int k = 0; k < n; ++k)
        cout << arr[k] << " ";
    cout << endl;
    system("PAUSE");
}

void selectionSort()
{
    int i, t, j, min_idx;
    vector<int> arr = getArrayInput();
    int n = arr.size();
    vector<int> index(2);
    cout << "\nEnter time delay in seconds:- ";
    cin >> t;
    for (i = 0; i < n - 1; i++)
    {
        // Sleep(t*1000);
        cout << "\n Iteration No. - " << i + 1 << "\n";
        min_idx = i;
        // Sleep(t*1000);
        cout << "The minimum element in the unsorted array is " << arr[i] << "\n";
        for (j = i + 1; j < n; j++)
        {
            index[0] = j;
            index[1] = min_idx;
            sort(index.begin(), index.end());
            // Sleep(t*1000);
            printArrays(arr, index);
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
                // Sleep(t*1000);
                cout << "\nSince the minimum element in unsorted array is greater than ";
                cout << arr[j] << " so new minimum element is " << arr[j] << "\n";
            }
            else
            {
                // Sleep(t*1000);
                cout << "\n"
                     << arr[min_idx] << " is less than";
                cout << arr[j] << " so minimum element remains same\n";
            }
        }

        // Sleep(t*1000);
        cout << "\nFinally we swap the minimum element with first element in unsorted array\n";
        swap(&arr[min_idx], &arr[i]);
        index[0] = min_idx;
        index[1] = i;
        sort(index.begin(), index.end());
        // Sleep(t*1000);
        printArrays(arr, index);
    }
    cout << "\n The final Sorted Array\n";
    loop(i, arr.size())
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    int choice, choice2;
    string name;
    cout << "Please Enter Your Name :- ";
    getline(cin, name);
    cout << "\nWelcome to S&S Simplified!!! " << name << "\n\n";

    while (1)
    {
        printMainMenu();
        cin >> choice;
        if (choice == 1)
        {
            cout << "1 -> Linear Search\n2 -> Binary Search\n";
            cout << "Select one to go ahead :- ";
            cin >> choice2;
            if (choice2 == 1)
            {
                linearSearch();
            }
            else if (choice2 == 2)
            {
                int x;
                vector<int> v = getArrayInput();
                cout << "Enter element to search for:- ";
                cin >> x;
                int tempo = binarySearch(v, x);
                if (tempo == -1)
                    cout << "\n The element is not present in the list\n";
                else
                    cout << "\n"
                         << x << " present at index " << tempo << "\n";
                system("PAUSE");
            }
            else
            {
                cout << "\n Invalid Entry!! Try Again...\n";
            }
        }
        else if (choice == 2)
        {
            cout << "\n1 -> Bubble Sort\n2 -> Selection Sort\n";
            cout << "\nSelect one to go ahead :- \n";
            cin >> choice2;
            if (choice2 == 1)
            {
                bubbleSort();
            }
            else if (choice2 == 2)
            {
                selectionSort();
            }
            else
            {
                cout << "\n Invalid Entry!! Try Again...\n";
            }
        }
        else if (choice == 3)
        {
            exit(0);
        }
        else
            cout << "\nInvalid choice!! Try Again...\n";
    }
    return 0;
}
