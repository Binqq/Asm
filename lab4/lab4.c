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
double SIMD_sub(int a)
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
                      "subps %%xmm0, %%xmm1\n"
                      "movups %%xmm1, %0\n"

                    :"=r"(vecA)
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
double SIMD_mult(int a)
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
                      "mulps %%xmm0, %%xmm1\n"
                      "movups %%xmm1, %0\n"

                    :"=r"(vecA)
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
double SIMD_div(int a)
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
                      "divps %%xmm0, %%xmm1\n"
                      "movups %%xmm1, %0\n"

                    :"=r"(vecA)
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
double SISD_add(int amount){

    double average_time = 0;
	clock_t begin;
	clock_t end;
	double time;

        for(int i=0; i < 10; i++){
				int j = 0;
                       int x = randomNumber();
                       int y = randomNumber();
		       int z=0;			
                begin = clock();
                for(; j < amount; j++){

                //begin = clock();
				asm(
                                        "movl %1, %%eax\n"
                                        "movl %2, %%ebx\n"
                                        "addl %%ebx, %%eax\n"
                                        "movl %%ebx, %0\n"
                                        :"=g"(z)
                                        :"g"(x),"g"(y)
                                );
                }

			end = clock();
			time = (double)(end - begin)/CLOCKS_PER_SEC;
			average_time = average_time + time;
        }

        average_time = average_time/10;
        return average_time;
}
