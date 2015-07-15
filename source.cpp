#include<iostream> 
using namespace std;  
int Max(int a, int b);
const int MAXSIZE = 101;
int  data[MAXSIZE][MAXSIZE];
int  result[MAXSIZE][MAXSIZE];
int  path[MAXSIZE][MAXSIZE];
int main()
{
	int n,i,j;
	cin >> n;
	while (n < 2 || n>100)
		cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
		{
			cin >> data[i][j];
			while (data[i][j]<0||data[i][j]>100)
				cin >> data[i][j];
		}
			
	for (i = 1; i <= n; i++)
		result[n][i] = data[n][i];
	for (i = n - 1; i > 0; i--)
		for (j = 1; j <= n; j++)
			result[i][j] = Max(result[i + 1][j], result[i + 1][j + 1]) + data[i][j];
	cout << result[1][1] << endl;
	return 0;

}
int Max(int a, int b)
{
	return (a>b ? a : b);
}
