#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
class Score
{
    private:
    enum GameState
    {
        PLAYER_WIN,
        COMPUTER_WIN,
        PLAYING
    };


    public:
    //return the state of the game once the caller passed the gameBoard to score
    GameState getGameState(GameBoard &cGameBoard);
    bool winChecking(char sign,GameBoard &cGameBoard);

};


#endif // SCORE_H_INCLUDED
