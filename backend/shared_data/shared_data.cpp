#include "shared_data.hpp"

#include "string.h"


int SharedData::establishConn(char *filepath) {
    return sqlite3_open_v2(filepath, &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr);
}

int SharedData::reIndexTeachers() {
    std::vector<int> idTeachers = buildReIndexVector("SELECT id FROM Teachers ORDER BY id ASC");

    std::string updateReq;

    for (unsigned int i = 0; i < idTeachers.size(); i++) {
        //Update ID in Teachers Table
        updateReq += "UPDATE Teachers SET id =" + std::to_string(i) + "WHERE id=" + std::to_string(idTeachers.at(i));
        updateReq += "; \n";

        //Update Refs in other tables
        //TO DO
    }

    return execRequest(updateReq.c_str()); // Exécute la requête et retourne le code d'erreur SQLite


}

int SharedData::reIndexRooms() {
    std::vector<int> idRooms = buildReIndexVector("SELECT id FROM Teachers ORDER BY id ASC");

    std::string updateReq;

    for (unsigned int i = 0; i < idRooms.size(); i++) {
        //Update ID in Teachers Table
        updateReq += "UPDATE Rooms SET id =" + std::to_string(i) + "WHERE id=" + std::to_string(idRooms.at(i));
        updateReq += "; \n";

        //Update Refs in other tables
        //TO DO
    }

    return execRequest(updateReq.c_str()); // Exécute la requête et retourne le code d'erreur SQLite

}

int SharedData::reIndexPupilss() {
    std::vector<int> idPupils = buildReIndexVector("SELECT id FROM Teachers ORDER BY id ASC");

    std::string updateReq;

    for (unsigned int i = 0; i < idPupils.size(); i++) {
        //Update ID in Teachers Table
        updateReq += "UPDATE Teachers SET id =" + std::to_string(i) + "WHERE id=" + std::to_string(idPupils.at(i));
        updateReq += "; \n";

        //Update Refs in other tables
        //TO DO
    }

    return execRequest(updateReq.c_str()); // Exécute la requête et retourne le code d'erreur SQLite
}

int SharedData::reIndexSharedPItems() {
    std::vector<int> idSharedPItems = buildReIndexVector("SELECT id FROM Teachers ORDER BY id ASC");

    std::string updateReq;

    for (unsigned int i = 0; i < idSharedPItems.size(); i++) {
        //Update ID in Teachers Table
        updateReq +=
                "UPDATE SharedPItems SET id =" + std::to_string(i) + "WHERE id=" + std::to_string(idSharedPItems.at(i));
        updateReq += "; \n";

        //Update Refs in other tables
        //TO DO
    }

    return execRequest(updateReq.c_str()); // Exécute la requête et retourne le code d'erreur SQLite
}

int SharedData::reIndexSharedCourses() {
    std::vector<int> idSharedCourses = buildReIndexVector("SELECT id FROM Teachers ORDER BY id ASC");

    std::string updateReq;

    for (unsigned int i = 0; i < idSharedCourses.size(); i++) {
        //Update ID in Teachers Table
        updateReq += "UPDATE SharedCourses SET id =" + std::to_string(i) + "WHERE id=" +
                     std::to_string(idSharedCourses.at(i));
        updateReq += "; \n";

        //Update Refs in other tables
        //TO DO
    }

    return execRequest(updateReq.c_str()); // Exécute la requête et retourne le code d'erreur SQLite
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

    int err = sqlite3_prepare_v2(db, sql_request, strlen(sql_request), &request, nullptr);

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



