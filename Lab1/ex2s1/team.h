#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <vector>
#include "player.h"

class Team {
public:
    std::string name;
    std::vector<Player> players;

    Team(std::string n) {
        name = n;
    }

    void addPlayer(Player player) {
        players.push_back(player);
    }

    std::vector<Player> showPlayers() {
        return players;
    }
};

#endif