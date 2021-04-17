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

void to_json(json &j, const std::map<int, std::vector<Move>> &map)
{
    for (auto &[key, value] : map)
    {
        j.emplace(std::to_string(key), value);
    }
}
int main(int argc, char *argv[])
{
    json positions;
    try
    {
        positions = json::parse(argv[1]);
    }
    catch (json::exception &e)
    {
        std::cerr << "Error while parsing input json : " << e.what() << '\n';
    }

    Board B(positions);
    map<int, vector<Move>> currentPlayableMove = B.playableMoves("black");
    json playableMovesJson(currentPlayableMove);

    std::cout << playableMovesJson.dump() << std::endl;
    return 0;
}
