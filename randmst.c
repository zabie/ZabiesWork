#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX_NODES 100000
#define MAX_DIMENSION 10
#define double_MAX 500;

double prims(int nodes, int dimension);
double problem1Dist(int a, int b, int d);
double euclideanDist(int a, int b, int d);

double generateRand();

double nodes[MAX_NODES][MAX_DIMENSION];

void populate_nodes(int n, int dimension) {
    for (int i = 0; i< n; ++i)
    {
        for (int d = 0; d < dimension; ++d)
        {
            //printf("%f\n", (double) rand() / (double) RAND_MAX);
            nodes[i][d] =  generateRand();//(double) rand() / (double) RAND_MAX;
            printf("NODE IS %i and VAL of %i IS:%f\n",i, d,  nodes[i][d]);


        }
    }
}

int main(int argc, char *argv[]){
     if(argc != 5) {
        printf("Please enter correct number of command line arguments\n");
     }
     else{
        int numpoints = atoi(argv[2]);
        int numtrials = atoi(argv[3]);
        int dimension = atoi(argv[4]);
        srand((unsigned int)time(NULL));
        generateRand();
        double final;
        for (int c=0;c<numtrials;c++){
            populate_nodes(numpoints, dimension);
            // if (dimension == 0){
            //     final += prims(numpoints, problem1Dist, dimension);
            // }
            
            //else{
                final += prims(numpoints, dimension);
            //}
            
         }
        printf("Prims is %f\n", final/numtrials);

    }

    return 0;
}

// generate random number
double generateRand(){
    return ((double) (rand()))/((double) RAND_MAX);
}

double problem1Dist(int a, int b, int d){
    return generateRand();
}


double euclideanDist(int x, int y, int dimension){
    double total;
    // if(dimension == 0)
    // {
    //     total = (double) rand() / (double) RAND_MAX;
    //     return total;
    // }
    // if(dimension >= 2)
    // {
    //     total += pow(nodes[x][i] - nodes[y][i],2)
    // }
    // if(dimension >= 3)
    // {
    //     total += pow(nodes[x][i] - nodes[y][i],2)
    // }
    // if(dimension == 4)
    // {
    //     total += pow(nodes[x][i] - nodes[y][i],2)
    // }

    for (int i=0;i<dimension;i++){
        // printf("x i IS: %f\n", nodes[x][i]);
        // printf("y i IS: %f\n", nodes[y][i]);
        // printf("DIFF IS : %f\n", nodes[x][i] - nodes[y][i]);


        total += pow(nodes[x][i] - nodes[y][i],2);
    }
    //printf("%f\n",total);
    // printf("%f\n",sqrt(total));
    // printf("%i %i\n",x,y);
    return sqrt(total);
}



double prims(int nodes, int dimension){

    printf("NUM OF NODES: %i\n", nodes);
    double distance[nodes];
    for (int i=0;i<nodes;i++)
    {
        distance[i]= double_MAX;
    }
    
    int in_mst[nodes];

    for (int i=0;i<nodes;i++)
    {
        in_mst[i] = 0;
    }   

    in_mst[0] = 1;
    distance[0]=0.0;

    //     double mstweight = 0.;
    double min;
    min = double_MAX;
    int minindex = 0;
    double mstweight = 0;

    // Trying to reach x
    for (int x=1; x<nodes-1; x++)
    {
        //min = double_MAX;

        for (int i=0; i<nodes; i++)
        {
            if (in_mst[i] == 0 && min<distance[i])
            {
                min=distance[i];
                minindex=i;
            }
        }

        in_mst[minindex]=1;

        for (int j=0; j<nodes; j++)
        {
            if (in_mst[j] == 0)
            {
                double temp= euclideanDist(minindex, j, dimension);
                //printf("%f\n", temp);
                if (temp < distance[j]){
                    printf("%f\n", temp);
                    distance[j]=temp;
                }
            }
        }
    }

    for (int i=0;i<nodes;i++)
    {
        //printf("%f\n", distance[i]);
        mstweight += distance[i];
    }

    return mstweight;
        // // Checking if i is a good idea
        // for (int i=0; i<nodes; i++){
        //     if (in_mst[i] == 0 && min<dist[i]) {
        //         double temp= distanceFn(x, i, dimension);
        //         if (temp < distance[i]){
        //             distance[i]=temp;
        //             printf("distance is %f, %i, %I",distance[i]);
        //         }
        //     }
        // }
//         double min = double_MAX;
//         int minindex = -1;
//         for (int i = 0; i < nodes; i++) {
//             if (in_mst[i] == 0 && distance[i] < min) {
//                 min = distance[i];
//                 minindex = i;
//                 printf("HELLO\n");
//                 printf("%i",minindex);
//             }
//         }

//         in_mst[minindex]=1;
//         mstweight += min;
//         printf("mstweight is %f\n",mstweight);
//     } 

//     return mstweight;  
 }

