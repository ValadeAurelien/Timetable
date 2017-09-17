#ifndef ABSTRACT_SPECIMEN_HEADER
#define ABSTRACT_SPECIMEN_HEADER

#include <map>
#include <vector>
#include "basic_instances/pitem_instance.hpp"
#include "basic_instances/course_instance.hpp"
#include "shared_data/shared_data.hpp"

typedef std::vector<PItemInstance> PItemsInstancesType;
typedef std::vector<CourseInstance> CourseInstancesType;

typedef float mark_t;

class AbstractSpecimen {

public:
    AbstractSpecimen(const SharedData& _SD);
    ~AbstractSpecimen();

    virtual void evaluate() = 0;
    virtual uchar mutate(AbstractSpecimen *specimen, uchar min, uchar max) = 0; 
    bool operator<=(AbstractSpecimen const &specimen2) const;
    mark_t getMark() const;

protected:
    PItemsInstancesType pitems;
    CourseInstancesType courses;
    mark_t mark;
    const SharedData& shareddata;
private:

};


#endif
