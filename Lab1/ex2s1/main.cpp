#include <iostream>
#include "player.h"
#include "team.h"

int main() {
    Player messi("Messi");
    Player yamal("Yamal");
    Player pedri("Pedri");

    messi.scoreGoal();
    yamal.scoreGoal();
    yamal.scoreGoal();

    Team barcelona("Barcelona");
    barcelona.addPlayer(messi);
    barcelona.addPlayer(yamal);
    barcelona.addPlayer(pedri);

    std::cout << "Team: " << barcelona.name << std::endl;
    std::cout << "Players:" << std::endl;

    std::cout << barcelona.players[0].name << " (" << barcelona.players[0].goals << " goals)" << std::endl;
    std::cout << barcelona.players[1].name << " (" << barcelona.players[1].goals << " goals)" << std::endl;
    std::cout << barcelona.players[2].name << " (" << barcelona.players[2].goals << " goals)" << std::endl;

    return 0;
}