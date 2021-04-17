#include "arbre.h"
#include <string>
#include <fstream>
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
    json request_data;

    try
    {
        if (argc < 2)
        {
            // The setup of json args in vscode launch.json is a massive pain (because of automatic quote escaping), so I use this case to debug the program, replace example_args.json with wanted values
            std::ifstream i("example_args.json");
            i >> request_data;
        }
        else
        {
            request_data = json::parse(argv[1]);
        }
    }
    catch (json::exception &e)
    {
        std::cerr << "Error while parsing input json : " << e.what() << '\n';
    }

    Board B(request_data["positions"]);
    Move move(request_data["move"]["path"], request_data["move"]["kills"]);
    B.playMove(move, false);
    map<int, vector<Move>> currentPlayableMove = B.playableMoves(request_data["color"]);

    json response;
    response.emplace("playableMoves", currentPlayableMove);
    response.emplace("positions", B.getPositions());
    std::cout << response.dump() << std::endl;
    return 0;
}
