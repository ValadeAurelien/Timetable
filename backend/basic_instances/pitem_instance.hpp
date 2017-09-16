#ifndef PITEM_INSTANCE_HEADER
#define PITEM_INSTANCE_HEADER

typedef unsigned char uchar;
typedef unsigned char hour_t;

#include "course_instance.hpp"

class PItemInstance {
public:
    PItemInstance();
    ~PItemInstance();

    Classroom* getClassroom() const;
    hour_t getHour() const;
    const PItem* getTempl() const;
    const CourseInstance* getCourse() const;

    void setClassroom(const Classroom& classroom);
    void setHour(hour_t hour);
    void setTempl(const PItem* templ);
    void setCourse(const CourseInstance* course);

private:
    const Classroom* classroom;
    hour_t hour;
    const PItem* templ;
    const CourseInstance* course;
};

#endif
