#include <iostream>
#include <string>

using namespace std;

// Forward declaration of the Enemy class
class Enemy;

class Player {
public:
    string name;
    int health;

    Player(string playerName) {
        name = playerName;
        health = 100;
    }

    // Function to attack an Enemy
    void attack(Enemy& target);
};

class Enemy {
public:
    string name;
    int health;

    Enemy(string enemyName) {
        name = enemyName;
        health = 50;
    }

    // Function to attack a Player
    void attack(Player& target);
};

// Definition of the Player::attack function
void Player::attack(Enemy& target) {
    cout << name << " attacks " << target.name << "!" << endl;
    target.health -= 10;
    cout << target.name << " loses 10 health points." << endl;
}

// Definition of the Enemy::attack function
void Enemy::attack(Player& target) {
    cout << name << " attacks " << target.name << "!" << endl;
    target.health -= 10;
    cout << target.name << " loses 10 health points." << endl;
}

int main() {
    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;

    Player player(playerName);
    Enemy enemy("Monster"); // Ensure that the Enemy object is properly declared and initialized

    cout << "Welcome to the Battle Game!" << endl;
    cout << "Player vs Enemy" << endl;

    while (player.health > 0 && enemy.health > 0) {
        cout << endl << "=====================" << endl;
        cout << player.name << "'s Health: " << player.health << endl;
        cout << enemy.name << "'s Health: " << enemy.health << endl;
        cout << "=====================" << endl << endl;

        player.attack(enemy);
        if (enemy.health <= 0) {
            cout << enemy.name << " has been defeated!" << endl;
            break;
        }

        enemy.attack(player);
        if (player.health <= 0) {
            cout << player.name << " has been defeated!" << endl;
            break;
        }
    }

    return 0;
}
