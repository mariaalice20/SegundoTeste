#include <iostream>
# include "SensorIndustrial.h"

using namespace std;

cout<<"Ola mundo"<<endl;

// Instanciando um objeto da classe SesnorIndustrial
SesnorIndustrial si("S01V","L/s");

// Ponteiro do tipo SensorIndustrial
SensorIndustrial* sensores[] = {&si}