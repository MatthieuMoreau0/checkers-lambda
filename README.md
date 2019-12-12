# checkers-lambda

This is the code for the C++ AWS lambda of an online version of the checkers game I'm currently working on.

The frontend will send to the lambda the state of the board and the lambda will either send back all the possible moves (for the player to chose its move) or the best move if it is the turn of the AI to play.
