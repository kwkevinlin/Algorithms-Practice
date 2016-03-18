#include <stdio.h>
#include <sys/time.h>
#include "etime.h"

struct timeval start_time ;
struct timeval finish_time ;
struct timeval current_time ;

void tic()
{
   gettimeofday( &start_time, NULL ) ;    
}

void toc()
{
   gettimeofday( &finish_time, NULL ) ;    
}


double etime( )
{
   
   long esec, eusec ;
   double r ;

   esec = finish_time.tv_sec - start_time.tv_sec ;
   eusec = finish_time.tv_usec - start_time.tv_usec ;

   r = ((double) esec) + ((double) eusec) / 1000000.0 ;
   return r ;
}
