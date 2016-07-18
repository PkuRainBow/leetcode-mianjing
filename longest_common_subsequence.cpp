// 返回2个字符串的最长的公共子序列的长度

int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}


// 返回2个字符串的最长的公共子序列
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
 
   // Following code is used to print LCS
   int index = L[m][n];
 
   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

//返回2个字符串的所有的最长公共子序列
/* Returns set containing all LCS for X[0..m-1], Y[0..n-1] */
set<string> findLCS(string X, string Y, int m, int n)
{
    // construct a set to store possible LCS
    set<string> s;
 
    // If we reaches end of either string, return
    // a empty set
    if (m == 0 || n == 0)
    {
        s.insert("");
        return s;
    }
 
    // If the last characters of X and Y are same
    if (X[m - 1] == Y[n - 1])
    {
        // recurse for X[0..m-2] and Y[0..n-2] in
        // the matrix
        set<string> tmp = findLCS(X, Y, m - 1, n - 1);
 
        // append current character to all possible LCS
        // of substring X[0..m-2] and Y[0..n-2].
        for (string str : tmp)
            s.insert(str + X[m - 1]);
    }
 
    // If the last characters of X and Y are not same
    else
    {
        // If LCS can be constructed from top side of
        // the matrix, recurse for X[0..m-2] and Y[0..n-1]
        if (L[m - 1][n] >= L[m][n - 1])
            s = findLCS(X, Y, m - 1, n);
 
        // If LCS can be constructed from left side of
        // the matrix, recurse for X[0..m-1] and Y[0..n-2]
        if (L[m][n - 1] >= L[m - 1][n])
        {
            set<string> tmp = findLCS(X, Y, m, n - 1);
 
            // merge two sets if L[m-1][n] == L[m][n-1]
            // Note s will be empty if L[m-1][n] != L[m][n-1]
            s.insert(tmp.begin(), tmp.end());
        }
    }
    return s;
}