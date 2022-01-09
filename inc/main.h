//
// Created by dusan on 20-Dec-21.
//

#ifndef MONTECARLO_MAIN_H
#define MONTECARLO_MAIN_H

typedef struct
{
    int TOTAL_NUM_OF_PHOTONS;
    int NUM_OF_PARALLEL_PHOTONS;
}Arguments;

//void signalHandler(int signum);
Arguments parseArguments(int argc, char**argv);

#endif //MONTECARLO_MAIN_H
