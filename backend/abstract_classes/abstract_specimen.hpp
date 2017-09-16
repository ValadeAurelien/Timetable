#ifndef ABSTRACT_SPECIMEN_HEADER
#define ABSTRACT_SPECIMEN_HEADER

#include <map>
#include <vector>
#include "../basic_instances/pitem_instance.hpp"
#include "../basic_instances/course_instance.hpp"

typedef std::vector<PItemInstance> PItemsInstances;

class CourseInstance {
public:
    CourseInstance();
    ~CourseInstance();

    const Teacher* getTeacher() const;
    const EquivPupilsNb_t& getPupils() const;
    const CourseTemplate* getTempl() const;

    void setTeacher(const Teacher* teacher);
    void setPupils(const EquivPupilsNb& pupils);
    void setTempl(const CourseTemplate* templ);

private:
    const Teacher* teacher;
    EquivPupilsNb pupils;
    const CourseTemplate* templ;

};

typedef std::vector<CourseInstance> CourseInstances;

class AbstractSpecimen {

public:
    AbstractSpecimen();
    ~AbstractSpecimen();

    virtual float mark() = 0;

    virtual float mutate(AbstractSpecimen *specimen, uchar min = 0, uchar max = 10) = 0;

    virtual bool isBetterThan(AbstractSpecimen const &specimen) const = 0;

    bool operator<=(AbstractSpecimen const &specimen2) const;

    float getMark() const;  

protected:
    PItemsInstances pitems;
    CourseInstances courses;
    float mark = 0;

private:

};


#endif
