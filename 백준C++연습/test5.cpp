#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdbool>
#include <string>

using namespace std;
typedef long long unsigned ll;
#define MAX 16

ll DP[MAX]; //크키가 i인 직사각형 채우는 방법의 수
int n;

int solution(int n)
{
	DP[0] = 1;
	DP[1] = 3;
	if (n % 2 != 0) return 0;
	else n /= 2;
	for (int i = 2; i <= n; i++)
	{
		DP[i] += DP[i - 1] * 3;
		for (int j = 2; j <= i; j++)
			DP[i] += 2 * DP[i - j];
	}
	return DP[n];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cout << solution(n) << '\n';
	return 0;
}	//DP[n] = DP[n-2] * 3 + sum(DP[n-i]*2) + 2*3 + 2 점화식