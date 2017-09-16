#ifndef ABSTRACT_SPECIMEN_HEADER
#define ABSTRACT_SPECIMEN_HEADER

#include <map>
#include <vector>

typedef std::vector<PItemInstance> PItemsInstances;
typedef std::vector<CourseInstance> CourseInstances;
typedef float mark_t;

class AbstractSpecimen {

public:
    AbstractSpecimen();
    ~AbstractSpecimen();

    virtual void evaluate() = 0;

    virtual float mutate(AbstractSpecimen *specimen, uchar min = 0, uchar max = 10) = 0;

    bool operator<=(AbstractSpecimen const &specimen2) const;

    mark_t getMark() const;  

protected:
    PItemsInstances pitems;
    CourseInstances courses;
    mark_t mark;

private:

};


#endif
