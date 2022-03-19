#include<bits/stdc++.h>
using namespace std;
 
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
 
#define lol long long int
#define ulol unsigned long long
#define pf cout
#define nl "\n"
#define elif else if
#define mod 1000000007
#define vi vector<int>
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define vpii vector<pii>
#define pb push_back
#define pob pop_back
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define mp            make_pair
#define PI            3.141592653589793238
#define E           2.7182818284590452353602874713527
#define deb(x)    cout<<endl<<#x<<"="<<x<<endl
#define deb2(x,y)    cout<<endl<<#x<<"="<<x<<" and "<<#y<<"="<<y<<endl
#define fp(x,n,y) for(int i=x; i<n; i+=y)
#define fn(a,c,b) for(int i=a; i>c; i-=b)
#define arrin(a,n) for(int i=0; i<n; i++){ cin>>a[i];}
#define arr2in(a,b,n) for(int i=0; i<n; i++){ cin>>a[i]; b[i]=a[i];}
 
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
bool prime(lol n)
{
    // Corner case
 
    if (n <= 1)
        return false;
 
    // Check from 2 to square root of n
    for (lol i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------BIT MASKING FUNCTIONS---------------------------------------------------------------------*/
lol SetBitCount(lol n)
{
    lol count=0;
    while(n){
      count++;
      n=n&(n-1);
    }
    return count;
}
 
int GetIthBit(lol n, lol i){
  return (n & (1<<i))? 1:0;
}
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
 
void solve(){
/*--------------------------------------------------------------------------------------------------*/
  int x;
  cin >> x ;
  char arr[x][x];
  for(int i = 0 ; i <x; i++){
    for(int j = 0 ; j < x; j++){
      cin>>arr[i][j];
    }
  }
  if(arr[x-1][x-1] == '*'){
    cout<<0;
    return;
  }
  int a[x][x], e = x-1;
  memset(a,0,sizeof(a));
  a[e][e] = 1;
 
  for(int i = e-1; i>=0; i--){
    a[i][e] = a[i+1][e];
    if(arr[i][e] == '*'){
      a[i][e] = 0;
    }
  }
  for(int i = e-1; i>=0; i--){
    a[e][i] = a[e][i+1];
    if(arr[e][i] == '*'){
      a[e][i] = 0;
    }
  }
 
  for(int i = e-1; i>=0; i--){
    for(int j = e-1; j>=0; j--){
      a[i][j] = (a[i+1][j]%1000000007 + a[i][j+1]%1000000007)%1000000007;
      if(arr[i][j] == '*'){
        a[i][j] = 0;
      }
    }
  }
  cout<<a[0][0] ;
 
/*--------------------------------------------------------------------------------------------------*/
}
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------*/
 
int main(){
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ulol t=1;
    // cin>>t;
    // deb(t);
    while(t--){
        solve();
        cout<<'\n';
    }
}