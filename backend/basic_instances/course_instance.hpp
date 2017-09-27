#ifndef COURSE_INSTANCE_HEADER
#define COURSE_INSTANCE_HEADER

#include <map>

#include "pitem_instance.hpp"
#include "common/common_types.hpp"

typedef std::map<eqpupils_id , nbpupils_t> EqPupilsNbType;

class CourseInstance {
public:
    CourseInstance()=default;
    ~CourseInstance()=default;

    teacher_id getTeacher() const;
    const EqPupilsNbType& getEqPupilsNb() const;
    nbpupils_t getNumber() const;
    sharedcourse_id getSharedId() const;

    void setTeacher(teacher_id teacher);
    void setEqPupilsNb(const EqPupilsNbType& eqpupilsnb);
    void setShared(sharedcourse_id shared);

    void addEqPupils(eqpupils_id pupils, ushort number);
    void remEqPupils(eqpupils_id pupils, ushort number);

private :
    teacher_id teacher;
    EqPupilsNbType eqpupilsnb;
    uchar number;
    sharedcourse_id shared_id;
};

#endif
