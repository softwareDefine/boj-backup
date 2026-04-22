/*
  Croatia 2005 / Final Exam #1
  Problem ZMAJ

  Zadatak rjesavamo koristeci aparat linearne algebre. Potrebno je primjetiti da
  vrijednosti varijabla mozemo pretstaviti kao vektor, a operacije pridruzivanja
  kao linearne operatore (matrice) nad tim vektorom.

  Npr. neka neki program ima 4 operacije pridruzivanja. Nazovimo njihove
  ogovarajuce matrice A, B, C i D. Neka se A i B, te C i D nalaze u petljama
  velicine 3 i 4, te neka je vektor stanja varijabli x.
  Tada ce nakon izvrsavanja svih naredbi vrijednosti varijabli iznositi
    A*B*A*B*A*B*C*D*C*D*C*D*C*D*x
  sto mozemo jos zapisati kao
    (A*B)^3 * (C*D)^4 * x

  A, B, C i D su kvadratne matrice, a x je vektor. Stoga je rezultat ovog
  mnozenja takodjer vektor.

  Dakle, sve petlje mozemo zapisati u obliku potencija, te mozemo primjeniti
  brzo (logaritamsko) potenciranje matrica sto nas vodi do rjesenja s ukupnom
  vremenskom slozenosti
    O( broj_linija_koda * broj_print_naredbi * broj_varijabli^3 * log2(100000) )

  Za implementacijske detalje vidi donji kod.
*/

#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
//0v
#define MOD 10000
//0
inline int mod( int x ) { return (x%MOD+MOD)%MOD; }

struct matrica {
   vector<int> polje;
   int n, m;
   int & operator () ( int r, int s ) { return polje[r*m+s]; }
   matrica( int N, int M ) {
      n=N; m=M;
      polje.resize( n*m );
      for( int i = 0; i < n; ++i )
         for( int j = 0; j < m; ++j )
            polje[i*m+j] = 0;
   }
   //곱하기
    friend matrica operator * ( matrica A, matrica B ) {
      matrica C( A.n, B.m );
      for( int i = 0; i < C.n; ++i )
         for( int j = 0; j < C.m; ++j ) {
            C(i,j) = 0;
            for( int k = 0; k < A.m; ++k ) {
               C(i,j) += A(i,k) * B(k,j);
               C(i,j) %= MOD;
            }
         }
      return C;
   }
   //제곱
   friend matrica operator ^ ( matrica A, int k ) {
      if( k == 1 ) return A;
      if( k%2 == 1 ) return A * (A ^ (k-1));
      matrica ret = A ^ (k/2);
      return ret * ret;
   }
};

vector<string> program;
int line;

pair<matrica, int> rec( matrica stanje ) {
   matrica trans( 27, 27 );
   for( int i = 0; i < 27; ++i ) trans(i,i) = 1;
   int print = 0;

   for( ;; ) {
      istringstream iss( program[line++] );
      string s;
      iss >> s;
      //0
      if( s == "STOP" ) break;
      else if( s == "REPEAT" ) {
         int koliko;
         iss >> koliko;

         int pamti = line;
         pair<matrica, int> t = rec( trans*stanje );
         print |= t.second;

         if( t.second == 1 ) {
            trans = t.first * trans;
            for( int i = 1; i < koliko; ++i ) {
               line = pamti;
               trans = rec( trans*stanje ).first * trans;
            }
         } else {
            trans = (t.first ^ koliko) * trans;
         }
      } else if( s == "PRINT" ) {
         print = 1;
         string var;
         iss >> var;
         cout << var << " = " << mod( (trans*stanje)(var[0]-'a',0) ) << endl;
      } else {
         matrica izraz( 27, 27 );
         for( int i = 0; i < 27; ++i ) izraz(i,i) = 1;
         izraz(s[0]-'a',s[0]-'a') = 0;

         string op, var;
         while( iss >> op >> var ) {
            int k = 1;
            int v = 26;
            if( isalpha( var[var.size()-1] ) ) v = var[var.size()-1]-'a';
            if( var[0] == '-' || isdigit( var[0] ) ) sscanf( var.c_str(), "%d", &k );
            if( op == "-" ) k *= -1;
            izraz( s[0]-'a', v ) += k;
         }
         trans = izraz * trans;
      }
   }
   return make_pair( trans, print );
}

int main( void ) {
   matrica stanje( 27, 1 );
   stanje(26,0) = 1;

   //0
   for( string s; getline( cin, s ); program.push_back( s ) );

   //0
   line = 1;
   rec( stanje );

   return 0;
}
