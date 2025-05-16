#include<iostream>
#include<string>
#include<cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
int idk = 0;
int hehe = 0;
class item {
	friend class player;
protected:
	string name = " ";
	int points;
	int x;
	int y;
public:
	virtual ~item() {}
	string getName() {
		return name;
	}
	int getPoints() {
		return points;
	}
};
class sword :public item {
private:
	int usage = 2;
public:
	sword() {
		name = "Sword";
		points = 40;
	}
	bool useSword() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
};
class shield :public item {
private:
	int usage = 1;
public:
	shield() {
		name = "Shield";
		points = 30;
	}
	bool useShield() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
};
class water :public item {
private:
	int usage = 1;
public:
	water() {
		name = "Water";
		points = 50;
	}
	bool useWater() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
};
class key :public item {
private:
	int usage = 1;
public:
	key() {
		name = "Key";
		points = 70;
	}
	bool useKey() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
};
class fire :public item {
private:
	int usage = 2;
public:
	fire() {
		name = "Fire";
		points = 50;
	}
	bool useFire() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
class snake :public item {
private:
	int usage = 3;
public:
	snake() {
		name = "Snake";
		points = 30;
	}
	bool useSnake() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}

};
class ghost :public item {
private:
	int usage = 1;
public:
	ghost() {
		name = "Ghost";
		points = 20;
	}
	bool useGhost() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}

};
class lion :public item {
private:
	int usage = 4;
public:
	lion() {
		name = "Lion";
		points = 50;
	}
	bool useLion() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}

};
class lock :public item {
	friend class player;
private:
	int exist = 1;
public:
	lock() {
		name = "Lock";
		points = 60;
	}
	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void useLock() {
		exist = 0;
	}
};

class goldCoin :public item {
private:
	int usage = 8;
public:
	goldCoin(int usage) {
		name = "Gold Coin";
		points = 10;
		this->usage = usage;
	}
	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool useGoldCoin() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
};
class silverCoin :public item {
private:
	int usage = 7;
public:
	silverCoin(int usage) {
		name = "Silver Coin";
		points = 5;
		this->usage = usage;
	}
	void setPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool useSilverCoin() {
		if (usage > 0) {
			--usage;
			return 1;
		}
		else {
			return 0;
		}
	}
};
class player {
	friend int main();
private:
	int x;int y;
	static item*** grid;
	int size;
	int gc = 0; int sc = 0;
	int points = 0;
	item** inventory;
	int inventorySize = 0;
public:
	void display(player& p2, int playernum) {

		cout << "Gold Coins : " << gc << "  " << "Silver Coins : " << sc << "  " << "Points : " << points << "  " << "Inventory : ";
		if (inventorySize == 0)cout << "No Item In Inventory" << endl;
		else {
			for (int i = 0; i < inventorySize; i++) {
				cout << (*(inventory + i))->getName() << "  ";
			}
			cout << endl;
		}
		displayGrid(p2, playernum);
	}
	void placeItemsOnGrid() {
		int index = 0;
		cout << "inventory: " << endl;
		for (int i = 0; i < inventorySize; i++)
		{
			cout << (*(inventory + i))->getName() << endl;
		}
		cout << "Enter the index of the item you want to use : " << endl;
		cin >> index;
		int xin, yin;
		cout << "x : ";
		cin >> xin;
		cout << "y : ";
		cin >> yin;
		if (index >= 0 && index < inventorySize) {
			grid[xin][yin] = inventory[index];
			useItem(inventory[index]->name);
			cout << "placed item on index: " << index << endl;
		}
	}
	const string RESET = "\033[0m";
	const string BOLD = "\033[1m";

	// Pastel backgrounds
	const string LIGHT_PINK_BG = "\033[48;5;218m";  // Soft pink
	const string LIGHT_BLUE_BG = "\033[48;5;153m";  // Baby blue
	const string FINISH_GOLD = "\033[48;5;229m";  // Bright pastel gold

	// Foregrounds
	const string TEXT_BLACK = "\033[38;5;16m";
	const string TEXT_GOLD = "\033[38;5;220m";
	const string TEXT_RED = "\033[38;5;196m";  // Add this with other color constants

	void displayGrid(player& p2, int playerNum) {
		int gridSize = this->size;
		int centerX = gridSize / 2;
		int centerY = gridSize / 2;

		const int cellWidth = 15;

		// Print top border
		cout << "+";
		for (int i = 0; i < gridSize; ++i) {
			cout << string(cellWidth, '-');
			cout << "+";
		}
		cout << endl;

		for (int x = 0; x < gridSize; ++x) {
			// Print content row
			cout << "|";
			for (int y = 0; y < gridSize; ++y) {
				// Determine background color
				string bgCode;
				if (x < centerX || (x == centerX && y < centerY))
					bgCode = LIGHT_PINK_BG;
				else
					bgCode = LIGHT_BLUE_BG;

				if (x == centerX && y == centerY)
					bgCode = FINISH_GOLD;

				string content;
				string fgCode = TEXT_BLACK;

				// Player markers
				if (x == this->x && y == this->y) {
					content = "P" + to_string(playerNum);
					fgCode = BOLD + TEXT_RED;
				}
				else if (x == p2.x && y == p2.y) {
					int otherPlayerNum = (playerNum == 1) ? 2 : 1;
					content = "P" + to_string(otherPlayerNum);
					fgCode = BOLD + TEXT_RED;
				}
				else if (x == centerX && y == centerY) {

					content = "FINISH";
					fgCode = BOLD + TEXT_RED;
				}
				else if (grid[x][y] != nullptr) {
					content = grid[x][y]->getName();
					fgCode = TEXT_BLACK;
				}
				else {
					content = "・";
				}

				// Padding
				int visibleLength = content.length();
				int padLeft = (cellWidth - visibleLength) / 2;
				int padRight = cellWidth - visibleLength - padLeft;

				cout << bgCode
					<< string(padLeft, ' ')
					<< fgCode << content << RESET << bgCode
					<< string(padRight, ' ')
					<< RESET;

				cout << "|";
			}
			cout << endl;

			// Print horizontal line between rows
			cout << "+";
			for (int i = 0; i < gridSize; ++i) {
				cout << string(cellWidth, '-');
				cout << "+";
			}
			cout << endl;
		}
	}



	void operator=(player& obj) {
		this->points = obj.points;
		this->size = obj.size + 2;
		grid = new item * *[size];
		for (int i = 0; i < size; i++) {
			*(grid + i) = new item * [size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				grid[i][j] = nullptr;
			}
		}
	}
	player() {

	}
	player(int s) {
		srand(time(NULL));
		size = s;
		grid = new item * *[size];
		for (int i = 0; i < size; i++) {
			*(grid + i) = new item * [size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (rand() % 7 == 1 || rand() % 7 == 2 || rand() % 7 == 3) {
					grid[i][j] = new goldCoin((rand() % 5) + 5);
				}
				else if (rand() % 7 == 0 || rand() % 7 == 5) {
					grid[i][j] = new silverCoin((rand() % 5) + 5);
				}
				else {
					grid[i][j] = nullptr;
				}
			}
		}
	}
	void setPlayer(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool canMove(int playerNum) {
		int exist;
		int temp;
		int index = -1;
		string solution;
		string name;
		if (grid[x][y] != nullptr) {
			if (grid[x][y]->getName() == "Fire" || grid[x][y]->getName() == "Snake" || grid[x][y]->getName() == "Ghost" || grid[x][y]->getName() == "Lion" || grid[x][y]->getName() == "Lock") {
				name = grid[x][y]->getName();
				if (name == "Fire") {
					fire* f = dynamic_cast<fire*>(grid[x][y]);
					if (f) {
						if (!f->useFire()) {
							grid[x][y] = nullptr;
							exist = 0;
						}
						else exist = 1;
					}
					solution = "Water";
				}

				else if (name == "Lock") {
					lock* f = dynamic_cast<lock*>(grid[x][y]);
					if (f) {
						if (!(f->exist)) {
							grid[x][y] = nullptr;
							exist = 0;
						}
						else exist = 1;
						solution = "Key";

					}
				}
				else if (name == "Snake") {
					snake* f = dynamic_cast<snake*>(grid[x][y]);
					if (f) {
						if (!f->useSnake()) {
							grid[x][y] = nullptr;
							exist = 0;
						}
						else exist = 1;
						solution = "Sword";
					}
				}
				else if (name == "Lion") {
					lion* f = dynamic_cast<lion*>(grid[x][y]);
					if (f) {
						if (!f->useLion()) {
							grid[x][y] = nullptr;
							exist = 0;
						}
						else exist = 1;
						solution = "Sword";
					}
				}
				else if (name == "Ghost") {
					ghost* f = dynamic_cast<ghost*>(grid[x][y]);
					if (f) {
						if (!f->useGhost()) {
							grid[x][y] = nullptr;
							exist = 0;
						}
						else exist = 1;
						solution = "Shield";
					}
				}
				if (exist == 1) {
					for (int i = 0; i < inventorySize; i++)
					{
						if (inventory[i]->getName() == solution) {
							index = i;
						}
					}
					if (index == -1) {
						if (purchase()) {
							if ((*(inventory + inventorySize - 1))->getName() == solution) {
								cout << "You have Used " << solution << " so You Can Move!" << endl;
								if (solution == "Key") {
									lock* f = dynamic_cast<lock*>(grid[x][y]);
									if (f) {
										if (f->exist) {
											return 0;
										}
										else {
											return 1;
										}
									}
								}
								grid[x][y] = nullptr;
								useItem(solution);
								return 1;
							}
							else {
								if (playerNum == 2) {
									if (name == "Snake") {
										if (idk == 0) {
											if ((x - 1) < 0) {
												if ((y += 3) >= size) {
													y = size - 1;
												}
											}
											else {
												if ((y += 3) >= size) {
													--x;
													if (idk)idk = 0;
													else idk = 1;
													temp = y - size + 1;
													y = size - temp;

												}
											}

										}
										else {
											if ((y -= 3) < 0) {
												--x;
												temp = abs(y);
												y = temp - 1;
												if (idk)idk = 0;
												else idk = 1;
											}
										}
									}
								}
								else {
									if (name == "Snake") {
										if (hehe == 0) {
											if ((y -= 3) < 0) {
												if ((x + 1) >= size) {
													y = 0;
												}
												else {
													++x;
													if (hehe)hehe = 0;
													else hehe = 1;
													y += 3;
													temp = y + 1;
													y = 3 - temp;
												}

											}
										}
										else {
											if ((y += 3) >= size) {
												++x;
												if (hehe)hehe = 0;
												else hehe = 1;
												temp = y - (size);
												y = size - 1;
												y -= temp;
											}
										}
									}
								}
								return 0;
							}
						}
						else {
							if (playerNum == 2) {
								if (name == "Snake") {
									if (idk == 0) {
										if ((x - 1) < 0) {
											if ((y += 3) >= size) {
												y = size - 1;
											}
										}
										else {
											if ((y += 3) >= size) {
												--x;
												if (idk)idk = 0;
												else idk = 1;
												temp = y - size + 1;
												y = size - temp;

											}
										}

									}
									else {
										if ((y -= 3) < 0) {
											--x;
											temp = abs(y);
											y = temp - 1;
											if (idk)idk = 0;
											else idk = 1;
										}
									}
								}
							}
							else {
								if (name == "Snake") {
									if (hehe == 0) {
										if ((y -= 3) < 0) {
											if ((x + 1) >= size) {
												y = 0;
											}
											else {
												++x;
												if (hehe)hehe = 0;
												else hehe = 1;
												y += 3;
												temp = y + 1;
												y = 3 - temp;
											}

										}
									}
									else {
										if ((y += 3) >= size) {
											++x;
											if (hehe)hehe = 0;
											else hehe = 1;
											temp = y - (size);
											y = size - 1;
											y -= temp;
										}
									}
								}
							}
							return 0;
						}
					}
					else {
						useItem(solution);
						cout << "you have used : " << solution << " ! " << "so you can move!" << endl;
						grid[x][y] = nullptr;
						return 1;
					}
				}
				else {
					return 1;
				}
			}
		}

	}
	void move(int playerNum) {

		int response;
		int success = 0;
		if (grid[x][y] != nullptr) {
			if (grid[x][y]->getName() == "Gold Coin") {
				goldCoin* f = dynamic_cast<goldCoin*>(grid[x][y]);
				if (f) {
					\
						while ((f->useGoldCoin())) {
							gc++;
							points += 10;
							grid[x][y] = nullptr;
						}
				}
			}
			else if (grid[x][y]->getName() == "Silver Coin") {
				silverCoin* f = dynamic_cast<silverCoin*>(grid[x][y]);
				while ((f->useSilverCoin())) {
					sc++;
					points += 5;
					grid[x][y] = nullptr;
				}
			}
		}
		if (canMove(playerNum)) {
			if (!checkSuccess()) {
				if (playerNum == 2) {
					if (idk == 1) {
						if (++y >= size) {
							--y;
							++x;
							idk = 0;

						}
					}
					else {
						if (--y < 0) {
							++y;
							++x;
							idk = 1;

						}
					}
				}
				else {
					if (hehe == 0) {
						if (++y >= size) {
							--y;
							--x;
							hehe = 1;
						}
					}
					else {
						if (--y < 0) {
							++y;
							--x;
							hehe = 0;
						}
					}
				}
			}
			else {
				cout << "Player" << playerNum << " : Wins" << endl;
			}
		}
	}
	bool checkSuccess() {
		if (x == size / 2 && y == size / 2) {
			return 1;
		}
		else return 0;
	}
	bool purchase() {
		int response = 1;
		cout << "Do you want to purchase any item? ";
		cin >> response;
		if (response) {
			cout << "1. Sword" << endl << "2. Shield" << endl << "3. Water" << endl << "4. Key" << endl << "5. Fire" << endl << "6. Snake" << endl << "7. Ghost" << endl << "8. Lion" << endl << "9. Lock" << endl;
			cin >> response;

			if (response >= 1 && response <= 9) {
				item** temp = new item * [inventorySize + 1];
				for (int i = 0; i < inventorySize; i++) {
					*(temp + i) = *(inventory + i);
				}
				++inventorySize;
				//delete inventory here!!!
				inventory = temp;
				temp = nullptr;
			}
			switch (response) {
			case 1:
				if (points - 40 < 0) {
					cout << "sorry cannot purchase a sword!" << endl;
					return 0;
				}
				else {
					*(inventory + inventorySize - 1) = new sword();
					points -= 40;
					return 1;
				}
				break;
			case 2:
				if (points - 30 < 0) {
					cout << "sorry cannot purchase a shield!" << endl;
					return 0;
				}
				else {
					*(inventory + inventorySize - 1) = new shield();
					points -= 30;
					return 1;
				}
				break;
			case 3:
				if (points - 50 < 0) {
					cout << "sorry cannot purchase water!" << endl;
					return 0;
				}
				else {
					*(inventory + inventorySize - 1) = new water();
					points -= 50;
					return 1;
				}
				break;
			case 4:
				if (points - 70 < 0) {
					cout << "sorry cannot purchase a key!" << endl;
					return 0;
				}
				else {
					*(inventory + inventorySize - 1) = new key();
					points -= 70;
					return 1;
				}
				break;
			case 5:
				if (points - 50 < 0) {
					cout << "sorry cannot purchase fire!" << endl;
					return 0;
				}
				else {
					*(inventory + inventorySize - 1) = new fire();
					points -= 50;
					return 1;
				}

				break;
			case 6:
				if (points - 30 < 0) {
					cout << "sorry cannot purchase a snake!" << endl;
					return 0;
				}
				else {
					*(inventory + inventorySize - 1) = new snake();
					points -= 30;
				}
				break;
			case 7:
				if (points - 20 < 0) {
					cout << "sorry cannot purchase a ghost!" << endl;
					return 0;
				}
				else {
					*(inventory + inventorySize - 1) = new ghost();
					points -= 20;
					return 1;
				}
				break;
			case 8:
				if (points - 50 < 0 && gc < 5) {
					cout << "sorry cannot purchase a lion!" << endl;
					return 0;
				}
				else if (points - 50 >= 0 && gc >= 5) {
					*(inventory + inventorySize - 1) = new lion();
					points -= 50;
					return 1;
				}
				break;
			case 9:
				if (points - 60 < 0) {
					cout << "sorry cannot purchase a lock!" << endl;
					return 0;
				}
				else {
					*(inventory + inventorySize - 1) = new lock();
					points -= 60;
					return 1;
				}
				break;
			}
		}
		else {
			return 0;
		}
	}
	void useItem(string name) {
		int remove = 0;
		item** temp = new item * [inventorySize - 1];
		for (int i = 0; i < inventorySize; i++) {
			if ((*(inventory + i))->getName() != name) {
				*(temp + i) = *(inventory + i);
			}
			else if ((*(inventory + i))->getName() == name && remove > 0) {
				*(temp + i) = *(inventory + i);
			}
			else {
				++remove;
			}
		}
		delete[]inventory;
		inventory = temp;
		temp = nullptr;
		--inventorySize;
	}
};
item*** player::grid;
int main() {
	int purchase;
	int response;
	int size = 5;
	player p1(size);
	player p2(size);
	player p3;
	player p4;
	player p5;
	player p6;
	player p7;
	player p8;
	p1.setPlayer(size - 1, 0);
	p2.setPlayer(0, size - 1);
	p1.points = 100;
	p2.points = 100;
	cout << "------------------------------------------GAME STARTS---------------------------------------" << endl;
	p1.displayGrid(p2, 1);;
	while (!(p1.checkSuccess() || p2.checkSuccess())) {
		cout << "Player 1 Turn : " << endl;
		p1.move(1);
		p1.display(p2, 1);
		p1.purchase();
		if (p1.checkSuccess()) {
			cout << "Player 1 Wins!" << endl;
			break;
		}
		cout << "do you want to place any item on the opponents block?" << endl;
		cin >> purchase;
		if (purchase) {
			p1.placeItemsOnGrid();
		}
		cout << "Player 2 turn: " << endl;
		p2.move(2);
		p2.display(p1, 2);
		p2.purchase();
		if (p2.checkSuccess()) {
			cout << "Player 2 Wins!" << endl;
			break;
		}
		cout << "do you want to place any item on the opponents block?" << endl;
		cin >> purchase;
		if (purchase) {
			p2.placeItemsOnGrid();
		}
		system("cls");
	}




	cout << "Do you want to go into the 7 x 7 grid?" << endl;
	cin >> response;
	if (response) {
		size = 7;
		p3 = p1;
		p4 = p2;
		p3.setPlayer(size - 1, 0);
		p4.setPlayer(0, size - 1);
		p3.grid[3][0] = new lock();
		p4.grid[1][3] = new lock();

		while (!(p3.checkSuccess() || p4.checkSuccess())) {
			cout << "Player 1 Turn : " << endl;
			p3.display(p4, 1);
			cout << "Do you want to purchase any Item: ";
			p3.purchase();
			p3.move(1);
			if (p3.checkSuccess()) {
				cout << "Player 1 Wins!" << endl;
				break;
			}
			cout << "do you want to place any item on the opponents block?" << endl;
			cin >> purchase;
			if (purchase) {
				p3.placeItemsOnGrid();
			}
			cout << "Player 2 turn: " << endl;
			p4.display(p3, 2);
			cout << "Do you want to purchase any Item: ";
			cin >> purchase;
			if (purchase) {
				p2.purchase();
			}
			p4.move(2);
			if (p4.checkSuccess()) {
				cout << "Player 2 Wins!" << endl;
				break;
			}
			cout << "do you want to place any item on the opponents block?" << endl;
			cin >> purchase;
			if (purchase) {
				p4.placeItemsOnGrid();
			}
		}
	}

	cout << "Do you want to go into the 9 x 9 grid?" << endl;
	cin >> response;
	if (response) {
		size = 9;
		p5 = p3;
		p6 = p4;
		p5.setPlayer(size - 1, 0);
		p6.setPlayer(0, size - 1);
		p5.grid[0][2] = new snake();
		p6.grid[4][2] = new snake();

		while (!(p5.checkSuccess() || p6.checkSuccess())) {
			cout << "Player 1 Turn : " << endl;
			p5.display(p6, 1);
			cout << "Do you want to purchase any Item: ";
			cin >> purchase;
			p5.purchase();
			p5.move(1);
			if (p5.checkSuccess()) {
				cout << "Player 1 Wins!" << endl;
				break;
			}
			cout << "do you want to place any item on the opponents block?" << endl;
			cin >> purchase;
			if (purchase) {
				p5.placeItemsOnGrid();
			}
			cout << "Player 2 turn: " << endl;
			p6.display(p5, 2);
			cout << "Do you want to purchase any Item: ";
			cin >> purchase;
			if (purchase) {
				p6.purchase();
			}
			p6.move(2);
			if (p6.checkSuccess()) {
				cout << "Player 2 Wins!" << endl;
				break;
			}
			cout << "do you want to place any item on the opponents block?" << endl;
			cin >> purchase;
			if (purchase) {
				p6.placeItemsOnGrid();
			}
		}
	}

	cout << "Do you want to go into the 11 x 11 grid?" << endl;
	cin >> response;
	if (response) {
		size = 11;
		p7 = p5;
		p8 = p6;
		p7.setPlayer(size - 1, 0);
		p8.setPlayer(0, size - 1);
		p7.grid[3][0] = new lock();
		p8.grid[1][3] = new lock();

		while (!(p7.checkSuccess() || p8.checkSuccess())) {
			cout << "Player 1 Turn : " << endl;
			p7.display(p8, 1);
			cout << "Do you want to purchase any Item: ";
			p7.purchase();
			p7.move(1);
			if (p7.checkSuccess()) {
				cout << "Player 1 Wins!" << endl;
				break;
			}
			cout << "do you want to place any item on the opponents block?" << endl;
			cin >> purchase;
			if (purchase) {
				p7.placeItemsOnGrid();
			}
			cout << "Player 2 turn: " << endl;
			p8.display(p5, 2);
			p8.purchase();
			p8.move(2);
			if (p8.checkSuccess()) {
				cout << "Player 2 Wins!" << endl;
				break;
			}
			cout << "do you want to place any item on the opponents block?" << endl;
			cin >> purchase;
			if (purchase) {
				p8.placeItemsOnGrid();
			}
		}
	}
	return 0;
}
