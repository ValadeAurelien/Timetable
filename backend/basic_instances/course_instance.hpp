#ifndef COURSE_INSTANCE_HEADER
#define COURSE_INSTANCE_HEADER

#include <map>

#include "pitem_instance.hpp"
#include "common/common_types.hpp"

typedef std::map<pupils_id , ushort> EqPupilsNbType;

class CourseInstance {
public:
    CourseInstance()=default;
    ~CourseInstance()=default;

    teacher_id getTeacher() const;
    const EqPupilsNbType& getEqPupilsNb() const;
    sharedcourse_id getSharedId() const;

    void setTeacher(teacher_id teacher);
    void setPupils(const EqPupilsNbType& eqpupilsnb);
    void setShared(sharedcourse_id shared);

    void addEqPupils(pupils_id pupils, ushort number);
    void remEqPupils(pupils_id pupils, ushort number);

private :
    teacher_id teacher;
    EqPupilsNbType eqpupilsnb;
    sharedcourse_id shared_id;
};

#endif
