#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    std::string name;
    int goals;

    Player(std::string playerName) {
        name = playerName;
        goals = 0;
    }

    void scoreGoal() {
        goals++;
    }
};

#endif