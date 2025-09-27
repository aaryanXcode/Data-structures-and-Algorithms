//selection sort
//find the minimum in rest of the element and swap it to the front
#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}


//merge sort
void merge(vector<int> &v, int low, int mid, int high,vector<int> &a){
    
    int i = low;
    int j = mid+1;
    int k = low;
    while(i<=mid && j<=high ){
        if(v[i]<=v[j]){
            a[k]=v[i];
            i++;
        }
        else{
            a[k]=v[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        while(j<=high){
            a[k]=v[j];
            j++;
            k++;
        }
    }else{
        while(i<=mid){
            a[k]=v[i];
            i++;
            k++;
        }
    }
    for (int x = low; x <= high; x++) {
        v[x] = a[x];
    }
}
void mergeSort(vector<int> &v,int low,int high, vector<int> &a){

    if(low<high){
        int mid = low+(high-low)/2;
        mergeSort(v,low,mid,a);
        mergeSort(v,mid+1,high,a);
        merge(v,low,mid,high,a);
    }
}

//quick sort
int partition(vector<int> &v,int low,int high){
    int pivot = v[low];
    int start=low;
    int end = high;
    while(start<end){
        while(v[start]<=pivot){
            start++;
        }
        while(v[end]>pivot){
            end--;
        }
        if(start<end){
            swap(v[start],v[end]);
        }
    }
    swap(pivot,v[end]);
    return end;
}
void quickSort(vector<int> &v, int low, int high){
    if(low<high){
        int pivotIdx = partition(v,low,high);
        quickSort(v,low,pivotIdx-1);
        quickSort(v,pivotIdx+1,high);
    }
}


//insertion sort
void insertionSort(vector<int> &v,int n){
    for(int i=1;i<n;i++){
        int temp = v[i];
        int j=i-1;
        while(j>=0 && v[j]>temp){
            v[j+1]=v[j];
            j--;
        }
        cout<<j<<endl;
        v[j+1]=temp;
    }
}

void insertionSortRecursize(vector<int> &v,int n){
    for(int i=1;i<n;i++){
        int temp = v[i];
        int j=i-1;
        while(j>=0 && v[j]>temp){
            v[j+1]=v[j];
            j--;
        }
        cout<<j<<endl;
        v[j+1]=temp;
    }
}




//bubble sort
//it works by placing maximum to the end place 
//and inner loop will loop till kth place which is except the last element placed
//suppose if x is placed at last then inner loop will loop till n-i-1
void bubbleSort(vector<int> &v,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            //cout<<"i:"<<i<<", j:"<<j<<endl;
            if(v[j]>v[j+1])
            {
                swap(v[j],v[j+1]);
                //cout<<"v[j]:"<<v[j]<<", v[j+1]:"<<v[j+1]<<endl;
            }
        }
    }
}

void bubbleSortRecursive(vector<int> &arr, int n, int depth = 1) {
    // Base case
    if (n == 1) {
        cout << "Base case reached. Final array: ";
        printArray(arr);
        return;
    }

    cout << "Pass " << depth << ": Starting bubble pass for n = " << n << endl;

    // One pass of bubble sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "  Swapping " << arr[i] << " and " << arr[i + 1] << endl;
            swap(arr[i], arr[i + 1]);
        }
    }

    cout << "After pass " << depth << ": ";
    printArray(arr);

    // Recursive call
    bubbleSortRecursive(arr, n - 1, depth + 1);
}

//selection sort
void selection(vector<int> &v,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(v[i]>v[j]){
                swap(v[i],v[j]);
            }
        }
    }
}
int findMin(vector<int> &v, int idx, int n) {
    int min = INT_MAX;
    int minIdx = -1;
    for (int i = idx; i < n; i++) {
        if (v[i] < min) {
            min = v[i];      // FIXED
            minIdx = i;
        }
    }
    return minIdx;
}

void selectionSort(vector<int> &v, int n) {
    for (int i = 0; i < n; i++) {
        int minIdx = findMin(v, i, n);
        int min = v[minIdx];  // value
        if (minIdx != i) {    // FIXED
            v[minIdx] = v[i];
            v[i] = min;
        }
    }
}

int main(){
    vector<int> v = {99,2,9,11,3,13};
    int n = v.size();
    //selectionSort(v,n);
    //insertionSort(v,n);
    //bubbleSort(v,n);
    //quickSort(v,0,n-1);
    //vector<int> a(n+1);
    //mergeSort(v,0,n-1,a);
    bubbleSortRecursive(v,n);
    printArray(v,n);
}