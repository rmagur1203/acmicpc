int arr[];

int bs(int l, int r, int k){
    while(l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid;
    }
}