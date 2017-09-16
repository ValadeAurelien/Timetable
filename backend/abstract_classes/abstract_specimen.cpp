#include "abstract_specimen.hpp"
#include "mark.hpp"

virtual bool AbstractSpecimen::operator<=(AbstractSpecimen const &sp) const 
{
    return (mark < sp.getMark());
}

Mark AbstractSpecimen::getMark() const { return mark; };
