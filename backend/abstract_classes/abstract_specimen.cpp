#include "abstract_specimen.hpp"

AbstractSpecimen::AbstractSpecimen(const SharedData& _SD) : SD(_SD)
{

}

bool AbstractSpecimen::operator<=(AbstractSpecimen const &sp) const 
{
    return (mark < sp.getMark());
}

mark_t AbstractSpecimen::getMark() const { return mark; }

