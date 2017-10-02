#include "abstract_specimen.hpp"

AbstractSpecimen::AbstractSpecimen(const SharedData& _SD) : shareddata(_SD)
{

}

AbstractSpecimen& AbstractSpecimen::operator=(const AbstractSpecimen& AS)
{
    pitems = AS.getPItems();
    courses = AS.getCourses();
    mark = AS.getMark();
}

bool AbstractSpecimen::operator<=(AbstractSpecimen const &sp) const 
{
    return (mark < sp.getMark());
}

const SharedData& AbstractSpecimen::getSharedData() const { return shareddata; }
const PItemsInstancesType& AbstractSpecimen::getPItems() const { return pitems; }
const CourseInstancesType& AbstractSpecimen::getCourses() const { return courses; }
mark_t AbstractSpecimen::getMark() const { return mark; }
void AbstractSpecimen::setMark(mark_t _mark) { mark = _mark; }

int AbstractSpecimen::uniformDistrib(int min, int max) { 
    return floor( (max-min) * ((float) rand()/RAND_MAX) + min + 0.5); 
}

