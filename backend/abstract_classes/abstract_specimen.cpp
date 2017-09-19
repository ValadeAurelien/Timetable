#include "abstract_specimen.hpp"

AbstractSpecimen::AbstractSpecimen(const SharedData& _SD) : shareddata(_SD)
{

}

bool AbstractSpecimen::operator<=(AbstractSpecimen const &sp) const 
{
    return (mark < sp.getMark());
}

mark_t AbstractSpecimen::getMark() const { return mark; }

int AbstractSpecimen::uniformDistrib(int min, int max) { 
    return floor( (max-min) * ((float) rand()/RAND_MAX) + min + 0.5); 
}

