//Matt Brown 
//CSC114-404 
//12/4/2024 
//Final Exam
//I wrote the code
//This is very loosly based on my D&D group :) 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

const int NUM_PLAYERS = 4;
const int NUM_ENEMIES = 5;
const int MAX_HP = 100;
const int MAX_ENEMY_HP = 80;

struct Spell {
	string name;
	int damage;
};

struct Item {
	string name;
	string effectType;
	int effectValue;
	int quantity;
};

struct Character {
	string name;
	int hp;
	bool isAlive;
	Spell spells[3];
	Item inventory[4];
};

void initializeCharacters(Character players[], Character enemies[]);
void displayStatus(const Character players[], const Character enemies[]);
void playerTurn(Character players[], Character enemies[], bool& exitGame);
void enemyTurn(Character players[], Character enemies[]);
bool checkVictory(const Character characters[], int size);
void useItem(Character& player);
void rollForLoot();
int randomInRange(int min, int max);

int main() {
	srand(static_cast<unsigned int>(time(0))); // Seed RNG

	Character players[NUM_PLAYERS];
	Character enemies[NUM_ENEMIES];

	initializeCharacters(players, enemies);

	cout << "Welcome to the Gaggle of Idiots JRPG! Based on a true story... sorta." << endl;

	bool exitGame = false;

	while (true) {
		displayStatus(players, enemies);

		playerTurn(players, enemies, exitGame);
		if (exitGame) {
			cout << "\nDM Andy calls the game here. Bye!" << endl;
			break;
		}

		if (checkVictory(enemies, NUM_ENEMIES)) {
			cout << "\nQueue Pokemon battle win music... Congrats! You have foiled Andy, he should have fudged the numbers more." << endl;
			rollForLoot();
			break;
		}

		enemyTurn(players, enemies);
		if (checkVictory(players, NUM_PLAYERS)) {
			cout << "\nWow, I can't believe you actually lost. We'll create new characters next week!" << endl;
			break;
		}
	}

	return 0;
}

void initializeCharacters(Character players[], Character enemies[]) {
	string playerNames[NUM_PLAYERS] = {"Nim", "Bernard", "Henx", "Kintsugi"};
	Spell playerSpells[NUM_PLAYERS][3] = {
		{{"Slash", 20}, {"Backstab", 30}, {"Nimble Shank", 10}},
		{{"Fireball", 25}, {"Smaller Fireball", 20}, {"BIG ASS FIREBALL", 35}},
		{{"Blast 'em", 20}, {"Rapid Shot", 25}, {"Explosive Shot", 30}},
		{{"Mending", 20}, {"Spiritual Weapon", 15}, {"Spirit Guardians", 25}}
	};

	string enemyNames[NUM_ENEMIES] = {"Goblin", "Orc", "Bandit", "Troll", "Thief"};
	Spell scrollSpells[] = {{"Inferno", 40}, {"Blizzard", 35}, {"Thunder", 50}, {"Regeneration", -30}};

	for (int i = 0; i < NUM_PLAYERS; i++) {
		players[i].name = playerNames[i];
		players[i].hp = MAX_HP;
		players[i].isAlive = true;
		for (int j = 0; j < 3; j++) {
			players[i].spells[j] = playerSpells[i][j];
		}

		players[i].inventory[0] = {"Health Potion", "heal", 30, 2};
		int firstRandomSpell = rand() % 4;
		int secondRandomSpell = rand() % 4;
		while (secondRandomSpell == firstRandomSpell) {
			secondRandomSpell = rand() % 4;
		}
		players[i].inventory[1] = {"Spell Scroll", "damage", scrollSpells[firstRandomSpell].damage, 1};
		players[i].inventory[2] = {"Spell Scroll", "damage", scrollSpells[secondRandomSpell].damage, 1};
		players[i].inventory[3] = {"Empty Slot", "none", 0, 0};
	}

	for (int i = 0; i < NUM_ENEMIES; i++) {
		enemies[i].name = enemyNames[i];
		enemies[i].hp = MAX_ENEMY_HP;
		enemies[i].isAlive = true;
	}
}

void displayStatus(const Character players[], const Character enemies[]) {
	cout << "\nPlayer Status:" << endl;
	for (int i = 0; i < NUM_PLAYERS; i++) {
		cout << players[i].name << " (HP: " << players[i].hp
			<< (players[i].isAlive ? ")" : " - Dead as hell)") << endl;
	}

	cout << "\nEnemy Status:" << endl;
	for (int i = 0; i < NUM_ENEMIES; i++) {
		cout << enemies[i].name << " (HP: " << enemies[i].hp
			<< (enemies[i].isAlive ? ")" : " - Dead as hell)") << endl;
	}
}

void playerTurn(Character players[], Character enemies[], bool& exitGame) {
	for (int i = 0; i < NUM_PLAYERS; i++) {
		if (!players[i].isAlive) continue;

		cout << "\n" << players[i].name << "'s Turn!" << endl;
		cout << "1. Cast Spell\n2. Use Item\n3. Give Up and Run Away\n4. Exit Game" << endl;

	int action;
	do {
		cout << "Choose action (1-4): ";
		cin >> action;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			action = 0; // Invalid action to retry
		}
	} while (action < 1 || action > 4);

	if (action == 1) {
		cout << "Choose a spell:" << endl;
		for (int j = 0; j < 3; j++) {
			cout << j + 1 << ". " << players[i].spells[j].name << " (Damage: "
			<< players[i].spells[j].damage << ")" << endl;
		}

		int spellChoice, target;
		do {
			cout << "Spell number (1-3): ";
			cin >> spellChoice;
		} while (spellChoice < 1 || spellChoice > 3);

		cout << "Choose your target:" << endl;
		for (int j = 0; j < NUM_ENEMIES; j++) {
		if (enemies[j].isAlive) {
			cout << j + 1 << ". " << enemies[j].name << " (HP: " << enemies[j].hp << ")" << endl;
		}
		}

		do {
			cout << "Target number: ";
			cin >> target;
			target--;
		} while (target < 0 || target >= NUM_ENEMIES || !enemies[target].isAlive);

		int damage = players[i].spells[spellChoice - 1].damage;
		enemies[target].hp -= damage;

		cout << players[i].name << " casts " << players[i].spells[spellChoice - 1].name
		<< " on " << enemies[target].name << " for " << damage << " damage!" << endl;

		if (enemies[target].hp <= 0) {
			enemies[target].hp = 0;
			enemies[target].isAlive = false;
			cout << enemies[target].name << " is dead as hell!" << endl;
		}
	} else if (action == 2) {
		useItem(players[i]);
	} else if (action == 3) {
		cout << players[i].name << " ran away! You can deal with them later..." << endl;
		players[i].isAlive = false;
	} else if (action == 4) {
			exitGame = true;
			return;
		}

		if (exitGame) {
			break;
		}
	}
}

void useItem(Character& player) {
	cout << "Items available:" << endl;
	for (int i = 0; i < 4; i++) {
		if (player.inventory[i].quantity > 0) {
			cout << i + 1 << ". " << player.inventory[i].name << " (Effect: "
			<< player.inventory[i].effectValue << ", Quantity: " << player.inventory[i].quantity << ")" << endl;
		}
	}

	int itemChoice;
	do {
		cout << "Choose item number: ";
		cin >> itemChoice;
		itemChoice--;
	} while (itemChoice < 0 || itemChoice >= 4 || player.inventory[itemChoice].quantity <= 0);

	if (player.inventory[itemChoice].effectType == "heal") {
		player.hp += player.inventory[itemChoice].effectValue;
		if (player.hp > MAX_HP) player.hp = MAX_HP;
	}
	player.inventory[itemChoice].quantity--;

		cout << player.name << " used " << player.inventory[itemChoice].name
		<< " and restored " << player.inventory[itemChoice].effectValue << " HP!" << endl;
}

int randomInRange(int min, int max) {
	return rand() % (max - min + 1) + min;
}

bool checkVictory(const Character characters[], int size) {
	for (int i = 0; i < size; i++) {
		if (characters[i].isAlive) {
			return false;
		}
	}
	return true;
}

void rollForLoot() {
	cout << "\nRolling for loot!" << endl;
	int loot = rand() % 100;
	if (loot < 40) {
		cout << "You found a rare item!" << endl;
	} else {
		cout << "No loot found." << endl;
	}
}

void enemyTurn(Character players[], Character enemies[]) {
	for (int i = 0; i < NUM_ENEMIES; i++) {
		if (!enemies[i].isAlive) continue;

		int target = rand() % NUM_PLAYERS;
		while (!players[target].isAlive) {
			target = rand() % NUM_PLAYERS;
		}

		int damage = randomInRange(10, 20);
		players[target].hp -= damage;
		cout << enemies[i].name << " attacks " << players[target].name << " for " << damage << " damage!" << endl;

		if (players[target].hp <= 0) {
			players[target].hp = 0;
			players[target].isAlive = false;
			cout << players[target].name << " is dead as hell!" << endl;
		}
	}
}

