#ifndef COURSE_INSTANCE_HEADER
#define COURSE_INSTANCE_HEADER

#include <map>

#include "pitem_instance.hpp"
#include "common/common_types.hpp"

typedef std::map<pupils_id , ushort> EquivPupilsNb;

struct CourseInstance {
    CourseInstance();
    ~CourseInstance();

    teacher_id getTeacher() const;
    const EquivPupilsNb& getPupils() const;
    sharedcourse_id getSharedId() const;

    void setTeacher(teacher_id teacher);
    void setPupils(const EquivPupilsNb& pupils);
    void setShared(sharedcourse_id shared);

    void addPupils(pupils_id pupils, ushort number);
    void remPupils(pupils_id pupils, ushort number);

    teacher_id teacher;
    EquivPupilsNb pupils;
    sharedcourse_id shared_i;
};

#endif
