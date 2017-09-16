#ifndef COURSE_INSTANCE_HEADER
#define COURSE_INSTANCE_HEADER

#include <map>
#include "pitem_instance.hpp"

typedef std::map<unsigned char, unsigned short> EquivPupilsNb;

class CourseInstance {
public:
    CourseInstance();
    ~CourseInstance();

    const Teacher* getTeacher() const;
    const EquivPupilsNb& getPupils() const;
    const CourseTemplate* getTempl() const;

    void setTeacher(const Teacher* teacher);
    void setPupils(const EquivPupilsNb& pupils);
    void setTempl(const CourseTemplate* templ);

private:
    const Teacher* teacher;
    EquivPupilsNb pupils;
    const CourseTemplate* templ;

};

#endif
