// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
void build(){

}
#define N 101010
int n , m , u[ N ] , v[ N ] , ans[ N ] , vl , sum[ N ];
int mr[ N ];
void init(){
  vl = 1;
  for( int i = 1 ; i <= n ; i ++ )
    sum[ i ] = 0;
  for( int i = 0 ; i < m ; i ++ ){
    u[ i ] = getint();
    v[ i ] = getint();
    if( u[ i ] != 1 && v[ i ] != 1 ){
      ans[ i ] = vl;
      sum[ u[ i ] ] += vl;
      sum[ v[ i ] ] += vl;
      vl ++;
    }
  }
}
void solve(){
  vector< PII > vv;
  for( int i = 2 ; i <= n ; i ++ )
    vv.PB( { sum[ i ] , i } );
  sort( ALL( vv ) );
  for( size_t i = 0 ; i < vv.size() ; i ++ )
    mr[ vv[ i ].SE ] = vl ++;
  puts( "Yes" );
  for( int i = 0 ; i < m ; i ++ ){
    if( u[ i ] == 1 || v[ i ] == 1 )
      ans[ i ] = mr[ max( u[ i ] , v[ i ] ) ];
    printf( "%d%c" , ans[ i ] , " \n"[ i + 1 == m ] );
  }
}
int main(){
  build();
  freopen( "flights.in" , "r" , stdin );
  freopen( "flights.out" , "w" , stdout );
  //__ = getint();
  // while( __ -- ){
  while( scanf( "%d%d" , &n , &m ) == 2 ){
    if( n == 0 && m == 0 ) break;
    init();
    solve();
  }
}
