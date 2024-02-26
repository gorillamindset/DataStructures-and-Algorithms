Problem statement
You are given an expression 'exp' in the form of a string where operands will be : (TRUE or FALSE), and operators will be : (AND, OR or XOR).
Now you have to find the number of ways we can parenthesize the expression such that it will evaluate to TRUE.
As the answer can be very large, return the output modulo 1000000007.

Note :
‘T’ will represent the operand TRUE.
‘F’ will represent the operand FALSE.
‘|’ will represent the operator OR.
‘&’ will represent the operator AND.
‘^’ will represent the operator XOR.

Example :
Input: 'exp’ = "T|T & F".
Output: 1
Explanation:
There are total 2  ways to parenthesize this expression:
    (i) (T | T) & (F) = F
    (ii) (T) | (T & F) = T
Out of 2 ways, one will result in True, so we will return 1.
  
===================================================================================================================================================================================================================================================
MEMOIZATION
#define MOD 1000000007
#define MODULO(a) ((a) % MOD)
#define ll long long

pair<ll,ll> eval(int i,int j,string& exp,vector<vector<pair<ll,ll>>>& dp){
    if(i>=j){
        if(i==j){
            if(exp[i]=='T') return {1,0};
            else if(exp[i]=='F') return {0,1};
        }
        return {0,0};
    }
    if(dp[i][j].first!=-1 || dp[i][j].second!=-1) return dp[i][j];
    pair<ll,ll> count = {0,0};
    for(int k=i;k<=j;k++){

        if(exp[k]=='T' || exp[k]=='F') continue;

        pair<ll,ll> left = eval(i,k-1,exp,dp);
        pair<ll,ll> right = eval(k+1,j,exp,dp);
        if(exp[k]=='|'){
            count.first = MODULO(count.first + MODULO(MODULO(left.first*right.second) + MODULO(right.first*left.second) + MODULO(left.first*right.first)));
            count.second = MODULO(count.second + MODULO(left.second*right.second));
        }
        else if(exp[k]=='&'){
            count.first = MODULO(count.first + MODULO(left.first*right.first));
            count.second = MODULO(count.second + MODULO(MODULO(left.second*right.first) + MODULO(left.first*right.second) + MODULO(left.second*right.second)));
        }
        else{
            count.second = MODULO(count.second + MODULO(MODULO(left.second*right.second) + MODULO(left.first*right.first)));
            count.first = MODULO(count.first +  MODULO(MODULO(left.second*right.first + MODULO(left.first*right.second))));
        }
    
    }
    return dp[i][j] = count;
}


int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<pair<ll,ll>>> dp(n,vector<pair<ll,ll>>(n,{-1,-1}));
    return eval(0,exp.size()-1,exp,dp).first;
}
