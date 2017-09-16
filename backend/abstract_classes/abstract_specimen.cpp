#include "abstract_specimen.hpp"


bool AbstractSpecimen::operator<=(AbstractSpecimen const &specimen1, AbstractSpecimen const &specimen2) {

    return specimen1.isBetterThan(specimen2);

}