//counting sort [ stable ] [ support:+/- intergers ]
/**
   support : positive / negative arrays
   the last travese the array X : 
         FORWARD->not stable  
		 BACKWARD->stable
**/
/* counting sort  Time O(N)  Space O(N+range) */
/* 
   support : positive / negative arrays
   the last travese the array X : 
         FORWARD->not stable  
		 BACKWARD->stable
*/

void countingSort(vector<int>& X){
	int len = X.size();
	int start = INT_MAX, end = INT_MIN;
	for (int i = 0; i < len; i++){
		start = min(start, X[i]);
		end = max(end, X[i]);
	}
	int range = end - start + 1;

	vector<int> count(range, 0);
	vector<int> result(len, 0);
	for (int i = 0; i < len; i++){
		count[X[i]-start]++;
	}
	for (int i = 1; i < range; i++){
		count[i]=count[i-1]+count[i];
	}
	//for-ward traverse is not stable sorting  ??
	//for (int i = 0; i < len; i++)
	//back-ward traverse is stable sorting
	for (int i = len-1; i >= 0; i--){
		//as we know that the count array recorded element should '-1' to get the index
		result[count[X[i] - start]-1] = X[i];
		count[X[i] - start]--;
	}
	for (int i = 0; i < len; i++){
		X[i] = result[i];
	}
}

//Radix sort  Time O(log(base,MAX)*(N+base))  Space O(constant)  default:base=10
/* 
   support : only positive interger 
   can only deal with positive integers or change the float number 
   of the specified precision to intergers by multiplying 10^n 
*/


