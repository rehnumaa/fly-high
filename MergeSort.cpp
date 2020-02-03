#include <iostream>

using namespace std;

void MERGE(int A[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;

    int L[n1+1], R[n2+1];

    for (i = 1; i <=n1; i++)
         L[i] = A[p + i -1];
    for (j = 1; j <= n2; j++)
         R[j] = A[q + j];

    L[n1+1]=99999; //infinity
    R[n2+1]=99999; //infinity

    i = 1;
    j = 1;
    for(k = p ; k <= r ; k++)
    {
        if(L[i] <= R[j])
        {
        A[k] = L[i];
        i = i + 1;
        }
        else
        {
        A[k] = R[j];
        j = j + 1;
        }
    }
    return;
}
void MERGE_SORT(int A[], int p, int r)
{
   int q;
    if(p < r)
    {
        q = ((p + r)/2);
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
    return;
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<< A[i] <<endl;
}
int main()
{
    int A[] = {5,2,1,9,15,21,10,43,30,55};
    int size = sizeof(A)/sizeof(A[0]);

    cout << "Unsorted Array:" << endl;
    printArray(A, size);

    MERGE_SORT(A,0,8);

    cout << "Sorted Array:" << endl;
    printArray(A, size);
    return 0;
}
