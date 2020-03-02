/*
    cos.c
    Copyright (C) 2020  Bruce Hiram Ginori Rodriguez
                        bruginrod@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include "library.h"
#include <mpi.h>

int main(int nargs, char **argv){
    int miproc;
    int numproc;
    /* for(int i = 0; i<nargs; i++){
        printf("%i\n", i);
        printf("%s\n", argv[i]);
    }
    */
    
    float a = 0.0;
    float b = 0.0;
    float dx = 0.1;
    float x = 0.0;
    
    int n = 0;
    float dN = 0;
    float a0; 
    float b0;
    
    MPI_Init(&nargs, &argv); /* Inicializar MPI */
    
        MPI_Comm_rank(MPI_COMM_WORLD, &miproc); /* Determina el rango del rpoceso invocado */
        MPI_Comm_size(MPI_COMM_WORLD, &numproc); /* Determina el numero de procesos */
        // printf("\nProceso: %i Total: %i\n", miproc)
    
    MPI_Barrier (MPI_COMM_WORLD);
    
    if (miproc == 0){
        printf("I am 0 process.\n");
    }
    
    if (nargs != 4){
        printf("Wrong number of arguments. You need 2 arguments.\n");
        return 0;
    }
    
    sscanf(argv[1],"%f", &a);
    sscanf(argv[2],"%f", &b);
    sscanf(argv[3],"%f", &dx);
    dN = (b-a)/numproc;
    a0 = a+miproc*dN;
    b0 = a+(miproc+1)*dN;
    
    //printf("Range_%i %f %f \n", miproc, a0, b0);
    
    n = (b0-a0)/dx + 1;
    printf("n=%i\n", n);
    x = a0;
    
    for(int i=1; i<=n; i++){
        
        printf("%f\t%f\n",x, f(x));
        
        //x = x+dx
        x = a0 + i * dx;
    }
    
    MPI_Finalize();
    return 0;
}
