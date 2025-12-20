Knapsack 문제.
목표 금액이 아니라 동전을 주인공으로 생각해야 된다. 그렇게 해야 순서가 뒤섞이지 않는다.

dp[j] = dp[j] + dp[j-coin]

test케이스 여러개니깐 dp항상 초기화.
memset(dp, 0, sizeof(dp));로하면 됨.

for(int i=1; i<=N; i++)으로 동전을 주인공으로 한다. 그리고, 그 안에서 목표 금액까지 훑으면 된다. for(int j=coin; j<=M; j++)
