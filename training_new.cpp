#include <iostream>
#include <random>

using namespace std;

class Batter {
    
    private : 
        string name;
        int contact = 30;
        int power = 30;
        int eye = 30;
        int speed = 30;
        int focus = 30;
        int defend = 30;
    
    public :
            // 경험치 느낌의 point 선언. 능력치에 1씩 부여하는 과정 point만큼 반복
        void first(string name, int point) {
            this->name = name;
            
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<int> dis(0,5);
            
            for(int i = 0; i < point; ++i) {
                switch(dis(gen)) {
                    case 0:
                        contact += 1;
                        break;
                    case 1:
                        power += 1;
                        break;
                    case 2:
                        eye += 1;
                        break;
                    case 3:
                        speed += 1;
                        break;
                    case 4:
                        focus += 1;
                        break;
                    case 5:
                        defend += 1;
                        break;
                }
            }
        }
        
        void Contact() {
            this -> contact += 1;
            this -> eye += 1;
        
        }
        void Muscle() {
            this -> power += 2;
        }
        void Medit() {
            this -> focus += 2;
        }
        void Run() {
            this -> speed += 2;
        }
        void Fungo() {
            this -> defend += 2;
        }
        void Rating() {
            cout << "Name : " << name << endl;
            cout << "contact : " << contact << "  power  : " << power << endl;
            cout << "eye     : " << eye << "  speed  : " << speed << endl;
            cout << "focus   : " << focus << "  defend : " << defend << "\n\n" << endl;
        }
};

class PlayersList {
    
    private :
        Batter player[25];
        int player_list_size = 0;
        
        void addPlayer(string name, int first_point) {
            player[player_list_size].first(name, first_point);
            player_list_size += 1;
        }
    
    public :
        void setList() {
            addPlayer("Alex", 300);
            addPlayer("Bailey", 250);
        }
        
        void showStat() {
            for(int i = 0; i < player_list_size; ++i) {
                player[player_list_size].Rating();
            }
        }
    
};

void magicfunction() {
    
    PlayersList Movings;
    
    Movings.setList();
    Movings.showStat();
    
    /*BattingStat Alex;
    Alex.first(300);
    Alex.Rating();
    Alex.Fungo();
    Alex.Rating(); */
    
}


int main() {
    magicfunction();
    
    return 0;
}