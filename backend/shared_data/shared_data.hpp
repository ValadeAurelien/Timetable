#ifndef SHARED_DATA_HEADER
#define SHARED_DATA_HEADER

#include <string>
#include <map>
#include <unordered_set>

class Classroom{
private:
    std::string name;
    unsigned int id;
    unsigned int capacity;
    bool projector;
    bool lab_inge;
    bool lab_bio;
    bool lab_phy;
    bool lab_chemi;
    bool c_inge;
    bool c_bio;
    bool c_phy;
    bool c_chemi;
    bool lab;
    bool w_board;
    bool b_board;


};

class PItem{
private:
    unsigned int duration;

};

class Teacher{

    int isHappyToWork(int hour) const;
    bool wantThisCourse(std::string course) const;


private:
    std::map<unsigned int, int> wishes;
    std::unordered_set<std::string> domain;


};

class Pupils{
    /* Faudra voir comment on definit les eleves....
    je propose éventuellement avec des string par type comme ça c'est dynamique avec la db plutôt qu'avec des defines
    qui emppècheraient la dynamicité des matières avec la db
     */

};
#endif
