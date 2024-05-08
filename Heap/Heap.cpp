#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Enemy {
public:
    Enemy() {
        std::cout << "An enemy was created\n";
    }
    ~Enemy() {
        std::cout << "An enemy was destroyed\n";
    }
    std::string m_name;
};

Enemy createEnemy() {
    Enemy e;
    return e;
}

class Item {
public:
    Item(std::string item_name) : m_item_name(item_name) {
        std::cout << "Item " << m_item_name << " was created\n";
    }
    ~Item() {
        std::cout << "Item " << m_item_name << " was destroyed\n";
    }
    std::string getItemName() {
        return m_item_name;
    }

private:
    std::string m_item_name;
};

class Player {
public:
    Player(std::string player_name) : m_player_name(player_name) {
        std::cout << "Player " << m_player_name << " has joined\n";
    }
    void add_item(std::unique_ptr<Item> item) {
        std::cout << "Do you want to store this item? " << item->getItemName() << std::endl;
        std::cout << "YES or NO\n";
        std::string response;
        std::cin >> response;
        if (response == "YES") {
            m_inventory.push_back(std::move(item));

        }
    }
    void checkInventory() {
        std::cout << "Player " << m_player_name << " has the following inventory\n";
        for (const auto& item : m_inventory) {
            std::cout << item->getItemName() << std::endl;
        }
    }

private:
    std::string m_player_name;
    std::vector<std::unique_ptr<Item>> m_inventory;
};

std::unique_ptr<Item> generateItem() {
    std::string item_name;
    std::cout << "What should the item name be? \n";
    std::cin >> item_name;
    return std::make_unique<Item>(item_name);
}

int main() {
    std::cout << "Level 1, what is your player name? \n";
    std::string playerName;
    std::cin >> playerName;
    Player player(playerName);
    player.add_item(generateItem());
    player.checkInventory();

    // Testare pentru Enemy
    std::cout << "You encounter an enemy!\n";
    std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();
    // Lupta cu inamicul...
    std::cout << "You defeated the enemy!\n";

    return 0;
}
