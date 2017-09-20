#ifndef SHARED_DATA_HEADER
#define SHARED_DATA_HEADER
#include "common/common_types.hpp"
#include "shared_data/shared_instances.hpp"

#include <vector>
#include "sqlite3.h"

typedef std::vector<Teacher> TeachersType;
typedef std::vector<Room> RoomsType;
typedef std::vector<Pupils> PupilssType;
typedef std::vector<SharedPItem> SharedPItemsType;
typedef std::vector<SharedCourse> SharedCoursesType;

class SharedData
{
  public:
    SharedData();
    ~SharedData();

    int establishConn(char *filepath);

    int loadTeachers();
    int loadRooms();
    int loadPupilss();
    int loadSharedPItems();
    int loadSharedCourses();

    int reIndexTeachers();
    int reIndexRooms();
    int reIndexPupilss();
    int reIndexSharedPItems();
    int reIndexSharedCourses();

    std::vector<int> buildReIndexVector(const char *sql_request);
    int execRequest(const char *sql_request); // Exec a request wich do not expect any return

    const TeachersType& getTeachers() const;
    const RoomsType& getRooms() const;
    const PupilssType& getPupilss() const;
    const SharedPItemsType& getSharedPItems() const;
    const SharedCoursesType& getSharedCourses() const;
    const hour_t getNbHoursPerWeek() const;
    const room_id getNbRooms() const;

  private:

    sqlite3 *db = 0;
    char *err = 0;

    TeachersType Teachers;
    RoomsType Rooms;
    PupilssType Pupilss;
    SharedPItemsType SharedPItems;
    SharedCoursesType SharedCourses;
    hour_t nb_hours_per_week;
    room_id nb_rooms;
};


#endif
