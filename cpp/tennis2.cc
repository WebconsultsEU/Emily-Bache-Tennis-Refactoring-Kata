#include <string>
#include <iostream>

class TennisGame {
private:
    int player1Score;
    int player2Score;
    
    std::string scoreName(int score) const {
        switch (score) {
            case 0: return "Love";
            case 1: return "Fifteen";
            case 2: return "Thirty";
            case 3: return "Forty";
            default: return "";
        }
    }
    
public:
    TennisGame(int p1, int p2) : player1Score(p1), player2Score(p2) {}
    
    std::string getScore() const {
        if (player1Score == player2Score) {
            if (player1Score < 3)
                return scoreName(player1Score) + "-All";
            return "Deuce";
        }
        
        if (player1Score >= 4 || player2Score >= 4) {
            int scoreDifference = player1Score - player2Score;
            if (scoreDifference == 1) return "Advantage player1";
            if (scoreDifference == -1) return "Advantage player2";
            if (scoreDifference >= 2) return "Win for player1";
            return "Win for player2";
        }
        
        return scoreName(player1Score) + "-" + scoreName(player2Score);
    }
};

const std::string tennis_score(int p1Score, int p2Score) {
    TennisGame game(p1Score, p2Score);
    return game.getScore();
}

int main() {
    TennisGame game(3, 2); // Example usage
    std::cout << game.getScore() << std::endl;
    return 0;
}
