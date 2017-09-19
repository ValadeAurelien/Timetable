#include "shared_data.hpp"

const TeachersType& SharedData::getTeachers() const
{
    return Teachers;
}

const RoomsType& SharedData::getRooms() const
{
    return Rooms;
}

const PupilssType& SharedData::getPupilss() const
{
    return Pupilss;
}

const SharedPItemsType& SharedData::getSharedPItems() const
{
    return SharedPItems;
}

const SharedCoursesType& SharedData::getSharedCourses() const
{
    return SharedCourses;
}

const hour_t SharedData::getNbHoursPerWeek() const
{
    return nb_hours_per_week;
}

const room_id SharedData::getNbRooms() const
{
    return nb_rooms;
}
