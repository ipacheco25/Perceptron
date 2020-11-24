/*Isaac Pacheco[id: 1042890], Luis Duran[id: 1036942], Daniel Carig [id: 1029924]
ip1042890@swccd.edu,luis_edward340@live.com,dc1029924@swccd.edu*/
#include <stdio.h>
#include <stdlib.h>
double dotProduct();
int main()
{

    double net = 0;
    double out;
    int iterationCounter = 0;
    double iterationError;
    double threshold = 0.5;
    double learningRate = 0.1;
    double desired[4];
    double weights[3] = {0, 0, 0};
    double trainingData[4][4] = { {1,0,0,1}, {1,0,1,1}, {1,1,0,1}, {1,1,1,0},};
    double change[3] = {0,0,0};
    int row;
    int col;
    int i;
    for(col = 0; col < 4; col++)
    {
        desired[col] = trainingData[col][4];
    }
    while(iterationError > 0)
    {
        iterationError = 0;
        printf("Iteration: %d\n", iterationCounter);
        for(row = 0; row <4; row++)
            {
                net = dotProduct(trainingData, row, weights);
                out = net > threshold? 1:0;
                if(out != desired[row]) //check if output = desired
                {
                    iterationError += 0.25;
                    //calculate change
                    for(i = 0; i <3 ; i++)
                    {
                        change[i] = ((desired[row] - out) * learningRate * trainingData[row][i]);
                    }
                    adjustWeights(weights, change);

                }
                else
                    {
                        for(i = 0; i < 3; i++)
                        {
                            change[i] = 0;//make no changes
                        }
                        adjustWeights(weights, change);
                    }
            }
            iterationCounter++;
    }
}
double dotProduct(double array1 [4][4] , int row, double array2[3] )
    {
        double value = 0;
        int i;
        for(i = 0; i < 3; i++)
        {
            value += (array1[row][i] * array2[i]);
        }
        return value;
    }
void adjustWeights(double weight[3], double array[3], double error)
    {
        int i;
        double errorr;
        for(i = 0; i < 3; i++)
        {
            weight[i] += array[i];//adjust weight according to change
            //print adjusted weight
            printf("%.2f    ", weight[i]);
        }
        printf("\n");
    }


