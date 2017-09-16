#ifndef COURSE_INSTANCE_HEADER
#define COURSE_INSTANCE_HEADER

#include <map>

typedef std::map<unsigned char, unsigned short> EquivPupilsNb;

#include "pitem_instance.hpp"
#include "common/id_types.hpp"

class CourseInstance {
public:
    CourseInstance();
    ~CourseInstance();

    teacher_id getTeacher() const;
    const EquivPupilsNb& getPupils() const;
    sharedcourse_id getShared() const;

    void setTeacher(teacher_id teacher);
    void setPupils(const EquivPupilsNb& pupils);
    void setShared(sharedcourse_id shared);

private:
    teacher_id teacher;
    EquivPupilsNb pupils;
    sharedcourse_id shared;
};

#endif
