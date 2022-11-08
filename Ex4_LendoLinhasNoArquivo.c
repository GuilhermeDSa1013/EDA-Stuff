#include<stdio.h>
main( )
{
  FILE *fp;
  char s[80];
  fp = fopen ( "Poem.txt", "r" );
  if ( fp == NULL )

  {
    puts ( "Cannot open file" );
    system("pause");
    exit(0);
  }

  while ( fgets ( s, 79, fp ) != NULL )
    printf ( "%s" , s );
  fclose ( fp );
  system("pause");
}