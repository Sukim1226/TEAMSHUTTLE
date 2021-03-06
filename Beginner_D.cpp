/*
	hingook
	beginner D
*/

#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int dp[501][501];

int max(int a, int b, int c){
	if(a > b)
		if(a > c)
			return a;
		else
			return c;
	else
		if(b > c)
			return b;
		else
			return c;
}

int main(){
	int n, m;
	int sum = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
			scanf("%d", &arr[i][j]);
	
	arr[0][1] = arr[1][0] = 500000;
	
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++)
			if(arr[i - 1][j] == 0 && arr[i][j - 1] == 0){
				arr[i][j] = 0;
			}
			
	arr[0][1] = arr[1][0] = 0;
	
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=m; j++){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
			if(i != 1 && j != 1)
				if(arr[i - 1][j] == 0 && arr[i][j - 1] == 0 && arr[i - 1][j - 1] == 0)
					dp[i][j] = 0;
		}
		
	/*
	printf("\n");
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	
	printf("\n");
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	*/

	printf("%d", dp[n][m]);
	return 0;
}
