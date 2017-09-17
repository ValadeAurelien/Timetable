#ifndef PITEM_INSTANCE_HEADER
#define PITEM_INSTANCE_HEADER

#include "course_instance.hpp"
#include "common/common_types.hpp"

class PItemInstance {
public:
    PItemInstance();
    ~PItemInstance();

    room_id getRoom() const;
    hour_t getHour() const;
    sharedpitem_id getShared() const;
    courseinstance_id getCourse() const;

    void setRoom(room_id Room);
    void setHour(hour_t hour);
    void setShared(sharedpitem_id _shared_pitem);
    void setCourse(courseinstance_id _course);

private:
    room_id Room;
    hour_t hour;
    sharedpitem_id shared_pitem;
    courseinstance_id course;
};

#endif
