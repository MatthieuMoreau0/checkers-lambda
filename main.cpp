#include "arbre.h"
#include <aws/lambda-runtime/runtime.h>
#include <string> 
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;
using namespace aws::lambda_runtime;

void to_json(json& j, const Move& m) {
        j = json{{"path", m.getPath()}, {"kills", m.getKills()}};
    }

void from_json(const json& j, Move& m) {
}

invocation_response my_handler(invocation_request const& request)
{
  Board B;
   map<int,vector<Move> > currentPlayableMove = B.playableMoves("white");
   json playableMovesJson(currentPlayableMove);
   return invocation_response::success(playableMovesJson.dump(), "application/json");
}

int main(){
    run_handler(my_handler);
   return 0;
}