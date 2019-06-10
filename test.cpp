#include "arbre.h"
#include <string> 
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;

void to_json(json& j, const Move& m) {
        j = json{{"path", m.path}, {"kills", m.kills}};
    }

void from_json(const json& j, Move& m) {
    j.at("path").get_to(m.path);
    j.at("kills").get_to(m.kills);
}

int main(){
    Board B;
   map<int,vector<Move> > currentPlayableMove = B.playableMoves("white");
   json playableMovesJson(currentPlayableMove);
   std::cout<<playableMovesJson.dump(4);
//    map<int,vector<Move> >::iterator it = currentPlayableMove.begin();
//    int arrival=(*it).second[0].getArrival();
//    std::string s = std::to_string(arrival);
//    std::cout<<s;
   return 0;
}