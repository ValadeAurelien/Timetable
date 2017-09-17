#ifndef ABSTRACT_SPECIMEN_HEADER
#define ABSTRACT_SPECIMEN_HEADER

#include <map>
#include <vector>
#include "basic_instances/pitem_instance.hpp"
#include "basic_instances/course_instance.hpp"

typedef std::vector<PItemInstance> PItemsInstancesType;
typedef std::vector<CourseInstance> CourseInstancesType;

typedef float mark_t;

class AbstractSpecimen {

public:
    AbstractSpecimen();

    ~AbstractSpecimen();

    virtual void evaluate() = 0;

    virtual float mutate(AbstractSpecimen *specimen, uchar min = 0,
                         uchar max = 10) = 0; // Apparemment on peut pas mettre des arguments par default sur une virtuelle

    bool operator<=(AbstractSpecimen const &specimen2) const;

    mark_t getMark() const;

protected:
    PItemsInstancesType pitems;
    CourseInstancesType courses;
    mark_t mark;

private:

};


#endif
