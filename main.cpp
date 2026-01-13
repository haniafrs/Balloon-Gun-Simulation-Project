#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Balloon {
public:
    int x, y;
    bool isPopped;

    Balloon(int startX, int startY) {
        x = startX;
        y = startY;
        isPopped = false;
    }

    void fly() {
        if (!isPopped) {
            y--; 
            if (y <= 0) {
                isPopped = true; 
            }
        }
    }
};

class Player {
public:
    string name;
    int score;
    Player(string n) : name(n), score(0) {}
};

class GameEngine {
private:
    vector<Balloon> balloons;
    Player p1, p2;
    int turn;
    int width, height;

public:
    GameEngine(string n1, string n2) : p1(n1), p2(n2), turn(1), width(50), height(20) {
        srand(time(0));
        for (int i = 0; i < 20; i++) {
            int rx = rand() % (width - 4) + 2;
            int ry = (height - 2) - (rand() % 10); 
            balloons.push_back(Balloon(rx, ry));
        }
    }

    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    int countActive() {
        int count = 0;
        for (int i = 0; i < (int)balloons.size(); i++) {
            if (!balloons[i].isPopped && balloons[i].y > 0) {
                count++;
            }
        }
        return count;
    }

    void draw(Player& current) {
        clearScreen();
        cout << "Player: " << current.name << " | Score: " << current.score << endl;
        cout << "Balloons in Range: " << countActive() << " | Turn: " << turn << endl;
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                bool printed = false;
                if (i == 0 || i == height - 1) {
				cout << "-"; printed = true;
				}
                else if (j == 0 || j == width - 1) {
				cout << "|"; printed = true;
				}
                else {
                    for (int k = 0; k < (int)balloons.size(); k++) {
                        if (!balloons[k].isPopped && balloons[k].x == j && balloons[k].y == i && balloons[k].y > 0) {
                            cout << "O"; 
                            printed = true;
                            break;
                        }
                    }
                }
                if (!printed)
				cout << " ";
            }
            cout << endl;
        }
    }

    void play() {
        while (countActive() > 0) {
            Player& current = (turn % 2 != 0) ? p1 : p2;
            draw(current);

            cout << "\n" << current.name << ", Enter X-coordinate to shoot (1-" << width-2 << "): ";
            int shot;
            if (!(cin >> shot)) {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            bool hit = false;
            for (int k = 0; k < (int)balloons.size(); k++) {
                if (!balloons[k].isPopped && balloons[k].x == shot && balloons[k].y > 0) {
                    balloons[k].isPopped = true;
                    current.score += 10;
                    hit = true;
                }
            }

            if (hit) {
			cout << "BOOM! Target Hit!" << endl;
		}
            else {
			cout << "MISS!" << endl;
		}
            for (int k = 0; k < (int)balloons.size(); k++) {
                balloons[k].fly();
            }

            cout << "Press Enter for the next turn...";
            cin.ignore(1000, '\n');
            cin.get();
            turn++;
        }
        showResults();
    }

    void showResults() {
        clearScreen();
        cout << "-----------------------------" << endl;
        cout << "          GAME OVER          " << endl;
        cout << "-----------------------------" << endl;
        cout << p1.name << "'s Score: " << p1.score << endl;
        cout << p2.name << "'s Score: " << p2.score << endl;
        
        if (p1.score > p2.score) {
		cout << "The Winner is " << p1.name << "!" << endl;
	}
        else if(p2.score > p1.score) {
		cout << "The Winner is " << p2.name << "!" << endl;
	}
        else {
		cout << "It's a Draw!" << endl;
	}
    }
};

int main() {
    string n1, n2;
    cout << "Enter Player 1 Name: "; 
	cin >> n1;
    cout << "Enter Player 2 Name: ";
	cin >> n2;

    GameEngine game(n1, n2);
    game.play();

    return 0;
}
