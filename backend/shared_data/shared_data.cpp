#include "shared_data.hpp"

#include "string.h"


int SharedData::establishConn(char *filepath) {
    return sqlite3_open_v2(filepath, &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr);
}

int SharedData::reIndexTeachers() {
    std::vector<int> idTeachers = buildReIndexVector("SELECT id FROM Teachers ORDER BY id ASC");



}

std::vector<int> SharedData::buildReIndexVector(const char *sql_request) {
    /*
     * Build a vector of ids, the index of the vector will be used as new id
     *
     * */
    sqlite3_stmt *request;
    std::vector<int> idVector;

    int err = sqlite3_prepare_v2(db, sql_request, strlen(sql_request), &request, 0);

    if (!err) {
        while (err == SQLITE_OK || err == SQLITE_ROW) {
            err = sqlite3_step(request);

            if (err == SQLITE_OK || err == SQLITE_ROW) {
                int id = sqlite3_column_int(request, 0);
                idVector.push_back(id);
            }
        }

        sqlite3_finalize(request);


    }

    return idVector;

}

int SharedData::execRequest(const char *sql_request) {
    sqlite3_stmt *request;

    int err = sqlite3_prepare_v2(db, sql_request, strlen(sql_request), &request, 0);

    if (!err) {
        while (err == SQLITE_OK || err == SQLITE_ROW) {
            err = sqlite3_step(request);
        }

        sqlite3_finalize(request);

    }

    return err;
}

const TeachersType &SharedData::getTeachers() const {
    return Teachers;
}

const RoomsType &SharedData::getRooms() const {
    return Rooms;
}

const PupilssType &SharedData::getPupilss() const {
    return Pupilss;
}

const SharedPItemsType &SharedData::getSharedPItems() const {
    return SharedPItems;
}

const SharedCoursesType &SharedData::getSharedCourses() const {
    return SharedCourses;
}

const hour_t SharedData::getNbHoursPerWeek() const {
    return nb_hours_per_week;
}

const room_id SharedData::getNbRooms() const {
    return nb_rooms;
}
