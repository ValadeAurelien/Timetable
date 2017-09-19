#include "shared_data.hpp"

const TeachersType& SharedData::getSharedTeachers() const
{
    return SharedTeachers;
}

const RoomsType& SharedData::getSharedRooms() const
{
    return Rooms;
}

const PupilssType& SharedData::getSharedPupilss() const
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
