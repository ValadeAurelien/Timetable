#ifndef COURSE_INSTANCE_HEADER
#define COURSE_INSTANCE_HEADER

#include <map>

#include "pitem_instance.hpp"
#include "common/common_types.hpp"

typedef std::map<pupils_id , unsigned short> EquivPupilsNb;

class CourseInstance {
public:
    CourseInstance();
    ~CourseInstance();

    teacher_id getTeacher() const;
    const EquivPupilsNb& getPupils() const;
    sharedcourse_id getSharedId() const;

    void setTeacher(teacher_id teacher);
    void setPupils(const EquivPupilsNb& pupils);
    void setShared(sharedcourse_id shared);

    void addPupils(pupils_id pupils, unsigned short number);
    void remPupils(pupils_id pupils, unsigned short number);

private:
    teacher_id teacher;
    EquivPupilsNb pupils;
    sharedcourse_id shared_id;
};

#endif
