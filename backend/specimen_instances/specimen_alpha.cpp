#include "specimen_alpha.hpp"
#include <cmath>

SpecimenAlpha(const SharedData& _SD) : AbstractSpecimen(_SD)
{

}

void evaluate()
{
    
}

uchar mutate(AbstractSpecimen *specimen, uchar min, uchar max)
{
    uchar nb_mut = 0,
          nb_mut_todo = floor( (max-min)*((float) rand()/RAND_MAX)+min ); 
    for (int i=0; i
}

void changeRoom()
{

}

void changeHour()
{

}

void changeTeacher()
{

}

void changePupils()
{

}

