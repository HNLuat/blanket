#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define pii pair<int,int>
#define ff first
#define ss second
//-------------------------------------------------------------------//
using namespace std;
float a[maxn];
int n;

void fast_io(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("inp.inp","r",stdin);
    return ;
}
//---------------------------------------------------------------------//
int random(int l,int r){
    return rand()%(r-l+1)+l;
}
float part(float arr[],int low,int high)
{
  //choose the pivot

  float pivot=arr[random(low,high)];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  ll i=(low-1);

  for(ll j=low;j<=high;j++)
  {
    //If current element is smaller than the pivot
    if(arr[j]<pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}

// The Quicksort function Implement

void quickSort(float arr[],int low,int high)
{
  // when low is less than high
  if(low<high)
  {
    // pi is the partition return index of pivot

    float pi=part(arr,low,high);

    //Recursion Call
    //smaller element than pivot goes left and
    //higher element goes right
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}
//-------------------------------------------------------------------//
void heapify(float arr[], int N, int i)
{

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

// Main function to do heap sort
void heapSort(float arr[], int N)
{

    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
//--------------------------------------------------------------------//
void merg(float arr[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new float[subArrayOne],
         *rightArray = new float[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(float arr[], int const begi, int const en)
{
    if (begi >= en)
        return;

    int mid = begi + (en - begi) / 2;
    mergeSort(arr, begi, mid);
    mergeSort(arr, mid + 1, en);
    merg(arr, begi, mid, en);
}
//-----------------------------------------------------------------------//
void enter(){
    fast_io();
    n=maxn-5;
    for(int i=0;i<n;i++) cin>>a[i];
    srand(time(NULL));
    clock_t b = clock();
    quickSort(a,0,n-1);
    //sort(&a[0],&a[n]);
    //heapSort(a,n);
    //mergeSort(a, 0, n - 1);
    clock_t e = clock();
    cout<<(float)(e-b)/CLOCKS_PER_SEC;
    //for(int i=1;i<=n;i++) cout<<a[1][i];
}
int main()
{
    enter();
    return 0;
}
