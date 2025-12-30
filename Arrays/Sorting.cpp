#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selection(int arr[], int n){
    for(int i = 0;i<=n-2;i++){
        int min = i;
        for(int j = i;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i]= arr[min];
        arr[min]=temp;
    }
    cout<<"Selection Sort : ";
    print(arr,n);
}
void bubble(int arr[], int n){
    for(int i = n-1; i>=1;i--){
        for(int j = 0;j<=i-1;j++){
            if(arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]= temp;
            }
        }
    }
    cout<<"Bubble Sort : ";
    print(arr,n);
}
void insertion(int arr[], int n){
    for(int i =0;i<n;i++){
        int j =i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1]= arr[j];
            arr[j]= temp;
        }
    }
    cout<<"Insertion Sort : ";
    print(arr,n);
}
void merge(int (&arr)[], int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.emplace_back(arr[left]);
            left++;
        }
        else{
            temp.emplace_back(arr[right]);
            right ++;
        }
    }
    while(left<=mid){
        temp.emplace_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.emplace_back(arr[right]);
        right++;
    }
    for(int i = low; i<=high; i++){
        arr[i]=temp[i-low];
    }
}
void mergeSort(int (&arr)[],int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(arr,0,mid);
    mergeSort(arr,mid+1,high);
    merge(arr, low, mid , high);
}
int getIndex(int (&arr)[], int low, int high){
    int pivot = low;
    int i = low;
    int j = high;
    while(i<j){
        while(arr[pivot]>arr[i] && i<=high-1){
            i++;
        }
        while(arr[pivot]<arr[j] && j>=low-1){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
        }
    }
    int temp = arr[j];
    arr[j]= arr[pivot];
    arr[pivot]= temp;
    return j;
}
void quickSort(int (&arr)[], int low, int high){
    if(low>=high) return;
    int p_index = getIndex(arr,low,high);
    quickSort(arr, low, p_index-1);
    quickSort(arr,p_index+1, high);
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    // selection(arr,n);
    // bubble(arr,n);
    // insertion(arr,n);
    // mergeSort(arr,0,n-1);
    // cout<<"Merge Sort : ";
    quickSort(arr,0,n-1);
    cout<<"Quick Sort : ";
    print(arr,n);
    return 0;
}
