#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double type;
typedef pair<type,type> Pt;
typedef pair<Pt,Pt> Line;
typedef pair<Pt,type> Circle;
#define X first
#define Y second
#define O first
#define R second
Pt operator+( const Pt& p1 , const Pt& p2 ){
  return { p1.X + p2.X , p1.Y + p2.Y };
}
Pt operator-( const Pt& p1 , const Pt& p2 ){
  return { p1.X - p2.X , p1.Y - p2.Y };
}
Pt operator*( const Pt& tp , const type& tk ){
  return { tp.X * tk , tp.Y * tk };
}
Pt operator/( const Pt& tp , const type& tk ){
  return { tp.X / tk , tp.Y / tk };
}
type operator*( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.X + p1.Y * p2.Y;
}
type operator^( const Pt& p1 , const Pt& p2 ){
  return p1.X * p2.Y - p1.Y * p2.X;
}
type norm2( const Pt& tp ){
  return tp * tp;
}
double norm( const Pt& tp ){
  return sqrt( norm2( tp ) );
}
Pt perp( const Pt& tp ){
  return { tp.Y , -tp.X };
}
#define x1 filjjlkjx1
#define y1 filjjlkjy1
#define x2 filjjlkjx2
#define y2 filjjlkjy2
#define N 101010
#define K 514
const double eps = 1e-6;
int n , x[ N ] , y[ N ];
double rr[ N ];
double r[ K ][ K ];
bool gr[ K ][ K ];
void init(){
  for( int i = 0 ; i < n ; i ++ ){
    scanf( "%d%d%lf" , &x[ i ] , &y[ i ] , &rr[ i ] );
    r[ x[ i ] ][ y[ i ] ] = rr[ i ];
    gr[ x[ i ] ][ y[ i ] ] = true;
  }
}
int x1 , y1 , x2 , y2;
double dst( const Pt& o , const Line& l ){
  Pt tmp = o - l.X;
  double vl = ( tmp ) * ( l.Y - l.X ) / norm( l.Y - l.X ) 
                                      / norm( l.Y - l.X );
  if( vl < eps ) vl = 0.0;
  if( vl > 1. - eps ) vl = 1.0;
  Pt pos = l.X + ( l.Y - l.X ) * vl;
  return norm( o - pos );
}
void solve(){
  int q; scanf( "%d" , &q ); while( q -- ){
    scanf( "%d%d%d%d" , &x1 , &y1 , &x2 , &y2 );
    if( x1 > x2 ){
      swap( x1 , x2 );
      swap( y1 , y2 );
    }
    int ans = 0;
    if( x1 == x2 ){
      if( y1 > y2 ) swap( y1 , y2 );
      for( int yy = y1 ; yy <= y2 ; yy ++ )
        if( gr[ x1 ][ yy ] )
          ans ++;
    }else if( y1 == y2 ){
      for( int xx = x1 ; xx <= x2 ; xx ++ )
        if( gr[ xx ][ y1 ] )
          ans ++;
    }else{
      Line tl = { { x1 , y1 } , { x2 , y2 } };
      double dlt = (double)( y2 - y1 ) / (double)( x2 - x1 );
      double cury = y1;
      for( int xx = x1 ; xx <= x2 ; xx ++ ){
        int my = round( cury );
        for( int yy = max( 1 , my - 1 ) ;
                 yy <= my + 1 ;
                 yy ++ ){
          if( not gr[ xx ][ yy ] ) continue;
          if( dst( { xx , yy } , tl ) < r[ xx ][ yy ] )
            ans ++;
        }
        cury += dlt;
      }
    }
    printf( "%d\n" , ans );
  }
}
void reset(){
  for( int i = 0 ; i < n ; i ++ )
    gr[ x[ i ] ][ y[ i ] ] = false;
}
int main(){
  for( int i = 0 ; i < K ; i ++ )
    for( int j = 0 ; j < K ; j ++ )
      r[ i ][ j ] = -1;
  while( scanf( "%d" , &n ) == 1 ){
    init();
    solve();
    reset();
  }
}
