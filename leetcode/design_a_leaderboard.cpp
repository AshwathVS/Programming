class Leaderboard {
public:
    unordered_map<int, multiset<int>::iterator> scoreboard;
    multiset<int, greater<>> ms;

    Leaderboard() {

    }

    void addScore(int playerId, int score) {
        if(scoreboard.find(playerId) == scoreboard.end()) { 
            scoreboard[playerId] = ms.insert(score);
        } else {
            int total = *scoreboard[playerId] + score;
            ms.erase(scoreboard[playerId]);
            scoreboard[playerId] = ms.insert(total);
        }
    }

    int top(int K) {
        int sum = 0;
        int i=0;
        for(int score : ms) {
            sum+=score;
            i++;
            if(i == K) break;
        }
        return sum;
    }

    void reset(int playerId) {
        ms.erase(scoreboard[playerId]);
        scoreboard.erase(playerId);
    }
};