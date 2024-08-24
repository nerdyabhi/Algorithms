# [Sliding windows By Striver](https://www.youtube.com/watch?v=9kdHxplyl5I&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL)

## Patterns : 
We do have 6 patterns in Sliding window Pattern !

1. Constant Window
2. Longest Subarray /substring where < condition>
3. No. of Subarrays where < condition>.
4. Finding The shortest / minimum window  < condition >


### Template for most of the Questions.

```cpp
l = 0, r= 0 , sum = 0 , ans =0;

while(l <r){
	sum+=arr[r];
	if(valid){
		// update answer accordingly
	}

	while(Ans Is Not valid){
		// Make it valid , by moving pointers 
		// or with any of your logic.
	}
}
```


