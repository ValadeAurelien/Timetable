#include "abstract_specimen.hpp"

bool AbstractSpecimen::operator<=(AbstractSpecimen const &sp) const 
{
    return (mark < sp.getMark());
}

mark_t AbstractSpecimen::getMark() const { return mark; }

AbstractSpecimen::AbstractSpecimen() = default;