#include <iostream>
#include <vector>
#include <string>

int main(void)
{
	int N;
	std::cin >> N;
	std::string S;
	std::cin >> S;

	const std::string ATCODER = "atcoder";
	const int MAX_N = 1000000;

	// dp[i][j] := Sのi文字目までで、atcoderのj文字目までを作れる通り数
	// i+1文字目を選ぶ場合、dp[i+1][j+1] += dp[i][j]
	// i+1文字目を選ばない場合、dp[i+1][j] = dp[i][j]
	std::vector<std::vector<int>> dp(MAX_N+1, std::vector<int>(ATCODER.size()+1));

	dp[0][0] = 1;

	const int mod = 1000000007;

	for(int i = 0; i < S.size(); i++)
	{
		for(int j = 0; j <= ATCODER.size(); j++)
		{
			dp[i+1][j] += dp[i][j];	// atcoderの各文字に対して、前周の結果を引き継ぐ
			// 今見ているS[i]に対して、atcoderのどの部分で使えるか記録する
			if(S[i] == 'a' && j == 0)
			{
				dp[i+1][j+1] += dp[i][j];	// S[i+1]を考えるとき、atcoderのj+1文字目を選べる <-> S[i]までにatcoderのj文字目まではできている
			}
			if(S[i] == 't' && j == 1)
			{
				dp[i+1][j+1] += dp[i][j];
			}
			if(S[i] == 'c' && j == 2)
			{
				dp[i+1][j+1] += dp[i][j];
			}
			if(S[i] == 'o' && j == 3)
			{
				dp[i+1][j+1] += dp[i][j];
			}
			if(S[i] == 'd' && j == 4)
			{
				dp[i+1][j+1] += dp[i][j];
			}
			if(S[i] == 'e' && j == 5)
			{
				dp[i+1][j+1] += dp[i][j];
			}
			if(S[i] == 'r' && j == 6)
			{
				dp[i+1][j+1] += dp[i][j];
			}
		}
		for(int j = 0; j <= ATCODER.size(); j++)
		{
			dp[i+1][j] %= mod;
		}
	}


	std::cout << dp[S.size()][7] << std::endl;

	return 0;
}
