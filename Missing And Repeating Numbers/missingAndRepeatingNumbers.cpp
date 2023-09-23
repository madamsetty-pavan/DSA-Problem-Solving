vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    long long n = a.size(), computedSum = 0, computedSquareSum = 0;
    long long totalSquareSum = (n * (n+1) * (2*n +1))/6, totalSum = (n * (n+1))/2 ;
    for(int i=0;i<n;i++) {
        computedSum += a[i];
        computedSquareSum += (long long) a[i] * (long) (long) a[i];
    }
    long long sub = computedSum - totalSum, sum = (computedSquareSum - totalSquareSum)/sub;

    return {(sum+sub)/2, (sum-sub)/2};
}

