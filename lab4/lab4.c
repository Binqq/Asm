#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct vec
  {
	int a,b,c,d
  }vec;

vec vecA;
vec vecB;
vec vecC;
int randNumber()
{
   return rand()%200+1;
}

vec setValues(vec *v)
 {
    v->a=randNumber();
    v->b=randNumber();
    v->c=randNumber();
    v->d=randNumber();
  return *v;
 } 

double SIMD_add(int a)
{
   clock_t begin,end;
   double averge_t =0, time;

   for(int i=0;i<10;i++)
     {
         int j=0;
      
        for(;j < a/4; j++)
            {
 		setValues(&vecA);
                setValues(&vecB);
                begin = clock();
		asm(
		      "movups %1, %%xmm0\n"
		      "movups %2, %%xmm1\n"
    		      "addps %%xmm0, %%xmm1\n"
		      "movups %%xmm1, %0\n"

		    :"=r"(vecC)
		    :"r"(vecA), "r"(vecB)	
		   );		
	    }
       end=clock();
       time=(end-begin);
       averge_t=averge_t+time;

     }
    averge_t = averge_t/10;
   return averge_t;  

}

