// Recursive solution

int recurse(vector<int>&arr, int target, int index) {
	if(index==0)  {
    if(sum==0 && arr[index]==0) return 2;
		if(arr[index] == target || sum==0) return 1;
		else return 0;
	}
	if(index<0) return 0;
	int notTake = recurse(arr,target,index-1);
	int take = 0;
	if(target>=arr[index]) {
		take = recurse(arr,target-arr[index],index-1);
	}
	return (take + notTake);
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	return recurse(arr,k,arr.size()-1);
}

