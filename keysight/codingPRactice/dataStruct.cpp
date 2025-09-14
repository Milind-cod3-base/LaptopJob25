// Array

// Rotation of array - make a circular array with shifting each element towards right in circular way.

// Method: 1
// place the last value in a temp var
// shift all the values towards one right
// put the value of temp in first pos

// Time complexity: O(n) — the loop runs n-1 times doing constant work per iteration.

// Space complexity: O(1) — only a single extra variable (temp) is used.

#include <iostream>
#include <vector>

void rotation(std::vector<int> &arr)
{
	// noting the size of the arry
	int size = arr.size();
	
	//last element pickup
	int temp = arr[size-1];
	
	// switch all to the right
	for(int i = size-1 ; i >=1; i--)
	{
		arr[i] = arr[i-1];
	}

	arr[0] = temp;
}

int main () 
{
	std::vector<int> arr = {1,2,3,4,5,6};
	
	rotation(arr);
	
	for(int i=0; i<arr.size(); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

// Reverse the array
// last element must become first
// Input: arr[] = [1, 4, 3, 2, 6, 5]  
// Output:  [5, 6, 2, 3, 4, 1]

// Time complexity: O(n) — it performs ~n/2 swaps, so linear in the number of elements.

// Space complexity: O(1) (constant extra space) — swaps done in-place using a single temporary variable.

#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &arr)
{
	int midpt = arr.size() / 2;
	
	//cout << midpt << endl;
	
	for (int i=0; i < midpt ; i++)
	{
		if(arr[i] != arr[arr.size() - 1 - i])
		{
		
		int temp = arr[i];
		
		arr[i] = arr[arr.size() - 1 - i];
		arr[arr.size() - 1 - i] = temp;
		}
	}
		
}



int main()
{
	vector<int> arr =  {1, 4, 3, 2, 6, 5};
	
	for(int i=0; i<arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
	
	reverse(arr);
	
	cout << "========" << endl;
	
	for(int i=0; i<arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
}



// Two sum problem

#include <iostream>
#include <vector>
#include <unordered_map> // unordered_map is the library for hash.

using namespace std;


vector<int> twoSum(vector<int>& nums, int target)
{
	//iniate a hash
	unordered_map<int,int> hash;
	
	for(int i= 0; i < nums.size(); i++ )
	{
		int complement = target - nums[i];
		
		if(hash.find(complement) != hash.end()) // not "not found" state.
		{
			return {hash[complement], i};
		}
		
		hash[nums[i]] = i; // if not found , store the index as value, 
	}
	return {};
}
			


int main()
{
	vector<int> nums = {2,7,11,15};
	
	int target = 9;
	
	vector<int> result = twoSum(nums, target); // since i have to return two indices, vector is bes for that
	
	cout << "[" << result[0] << "," << result[1] << "]" << endl;
	
}
	