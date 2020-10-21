#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>


# define derivative(x,h) (sin(x+h)-sin(x-h))/(2*h)
int main(int argc, char** argv) {
    
    
    

	
	int n, i, source, j,k;
	float my_1, my_range, pi = 3.14, range, tag, dest,F[25];


	MPI_Init(&argc, &argv);
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
	double  h;
	int N = 100;
	float my_result[25], results[100],send_var;
	
	double x = world_rank*pi/4;
	h = pi/(N-1);
	n = N / world_size;
	
	for (j = 0;j < 25;j++) {
        F[j]=sin(world_rank*pi/4+j*pi/99);
	}
	
	
	
	if (world_rank==0){
	        my_result[0]=(F[1]-F[0])/h;
	} else if (world_rank !=0){
	    F[0]=send_var;
	}
	
		for (j = 1;j < 25;j++) {
			
			my_result[j] = (F[j+1]-F[j-1]) / (2 * h);
			
		}
		if (world_rank>0){
		send_var=(world_rank-1)*pi/4;
		}
     if(world_rank<3){
        MPI_Send(&send_var,1,MPI_FLOAT,world_rank+1,0, MPI_COMM_WORLD);
       
    }
    
    if (0<world_rank<3){
        MPI_Recv(&send_var,1,MPI_FLOAT,world_rank-1,0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
    }
    
	
	
	MPI_Gather(my_result, 25, MPI_FLOAT, results, 25, MPI_FLOAT, 0 , MPI_COMM_WORLD);
	
	MPI_Finalize();
	
	
	for (i = 0;i < 25;i++) {
	    
		printf(" %f \n", my_result[i]);
		
	}
} 