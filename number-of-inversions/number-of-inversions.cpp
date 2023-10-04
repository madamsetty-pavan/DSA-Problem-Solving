void merge(vector<int>&arr, int start, int end, int mid ,int &count ) {
    vector<int> temp;

    int i = start, j = mid+1;
    while(i<=mid && j<=end) {
        if(arr[i] <= arr[j] ) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            count += mid - i +1;
        }
    }
    while(i<=mid) temp.push_back(arr[i++]);
    while(j<= end) temp.push_back(arr[j++]);

    for(int i = start;i<=end;i++) {
        arr[i] = temp[i-start]; 
    }
}

void mergeSort(vector<int>&a, int start, int end, int &count) {
    if(start==end) return;
    int mid = start + (end-start)/2;
    mergeSort(a,start,mid, count);
    mergeSort(a,mid+1,end, count);
    merge(a, start, end, mid ,count);
}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    int count = 0;
    mergeSort(a,0,n-1, count);
    return count;
}

