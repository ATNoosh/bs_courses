#include <iostream.h>
#include <conio.h>


long double cal ( ) {
 static bool first = true ;
 static long double v;
if (first == true) { v = v + 0.5; first = false; return v;}return 1;}
int main( ) {
 long double x = cal ( );
 long double y = cal ( );
 cout << x <<endl<< y;
 getch();
 return 0;
 }

