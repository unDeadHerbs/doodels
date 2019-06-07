#include <iostream>

int s( int n , int d )
{
	return d == n ? 1 : n % d ? s( n , d + 1 ) : 0 ;
}

void a ( int n )
{
	if ( s( n , 2 ) )
	{
		std::cout << n << " " ;
	}
	a( n + 1 );
}

int main( )
{
	a(2);
	return 0;
}