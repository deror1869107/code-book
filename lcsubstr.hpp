int longest_common_substr(string a, string b)
{
  //set initial values
  for (int i=0; i<=a.length(); i++) dp[i][b.length()] = 0;
  for (int i=0; i<=b.length(); i++) dp[a.length()][i] = 0;

  int best = 0;
  for (int i=a.length()-1; i>=0; i--)
  for (int j=b.length()-1; j>=0; j--)
  if(a[i] == b[j]) //if its a match, you can extend both prefixes by one
  {
  dp[i][j] = 1 + dp[i+1][j+1];
  if (best < dp[i][j]) //remember best so far
  best = dp[i][j];
  }
  else dp[i][j] = 0; //else you have to start over
  return best;
}
