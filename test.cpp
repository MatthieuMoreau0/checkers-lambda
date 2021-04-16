#include "arbre.h"
#include <string>
#include "nlohmann/json.hpp"

// for convenience
using json = nlohmann::json;

void to_json(json &j, const Move &m)
{
    j = json{{"path", m.getPath()}, {"kills", m.getKills()}};
}

void from_json(const json &j, Move &m)
{
}

int main(int argc, char *argv[])
{
    std::cout << argc << std::endl;
    std::cout << argv[1] << std::endl;
    json positions;
    try
    {
        positions = json::parse(argv[1]);
    }
    catch (json::exception &e)
    {
        std::cout << "Error while parsing input json : " << e.what() << '\n';
    }

    Board B(positions);
    map<int, vector<Move>> currentPlayableMove = B.playableMoves("black");
    json playableMovesJson(currentPlayableMove);

    std::cout << playableMovesJson.dump(4) << std::endl;
    return 0;
}
