#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Player {
    string name;
    int health;
    int maxHealth;
    int mana;
    int maxMana;
    int coins;
    int herbs;        
    int crystals;     
    int runes;        
    int phoenixFeathers; 
    int dragonScales;
    int elixirCount; 
    bool hasBasicPotion; 
    Player() {
        name = "Alchemist";
        health = 100;
        maxHealth = 100;
        mana = 50;
        maxMana = 50;
        coins = 20;
        herbs = 0;
        crystals = 0;
        runes = 0;
        phoenixFeathers = 0;
        dragonScales = 0;
        elixirCount = 0;
        hasBasicPotion = false;
    }
};

void printTitleArt() {
    cout << R"(
    ____  _            _                      _     _           
   / ___|| | ___   ___| | _____  ___  _ __ __| |___| |__  _   _ 
   \___ \| |/ _ \ / __| |/ / __|/ _ \| '__/ _` / __| '_ \| | | |
    ___) | | (_) | (__|   <\__ \ (_) | | | (_| \__ \ | | | |_| |
   |____/|_|\___/ \___|_|\_\___/\___/|_|  \__,_|___/_| |_|\__, |
                                                           |___/ 
            The Alchemist's Journey - Brew the Philosopher's Elixir
    )" << '\n';
}

void printElixirArt() {
    cout << R"(
         ___________
        '._==_==_=_.'
        .-\:      /-.
       | (|:.     |) |
        '-|:.     |-'
          \::.    /
           '::. .'
             ) (
           _.' '._
          `"""""""`
    )" << '\n';
}

void showStatus(const Player &p) {
    cout << "\n--- STATUS ---\n";
    cout << "Name: " << p.name << "\n";
    cout << "Health: " << p.health << "/" << p.maxHealth << "   Mana: " << p.mana << "/" << p.maxMana << "\n";
    cout << "Coins: " << p.coins << "   Elixirs: " << p.elixirCount << "\n";
    cout << "Inventory: Herbs:" << p.herbs << "  Crystals:" << p.crystals << "  Runes:" << p.runes;
    cout << "  Feathers:" << p.phoenixFeathers << "  Scales:" << p.dragonScales << "\n";
    cout << "Basic Potion: " << (p.hasBasicPotion ? "Yes" : "No") << "\n";
    cout << "---------------\n\n";
}

void heal(Player &p, int amount) {
    p.health += amount;
    if (p.health > p.maxHealth) p.health = p.maxHealth;
    cout << "Healed " << amount << " HP.\n";
}

void restoreMana(Player &p, int amount) {
    p.mana += amount;
    if (p.mana > p.maxMana) p.mana = p.maxMana;
    cout << "Restored " << amount << " mana.\n";
}

void takeDamage(Player &p, int dmg) {
    p.health -= dmg;
    if (p.health < 0) p.health = 0;
    cout << "You took " << dmg << " damage.\n";
}

void addCoins(Player &p, int c) {
    p.coins += c;
    cout << "You gained " << c << " coins.\n";
}
void hello(){
    cout<<"hi"<<endl;
}
void craft(Player &p) {
    cout << "\n=== Crafting Menu ===\n";
    cout << "1. Make Basic Potion (2 Herbs + 1 Crystal)\n";
    cout << "2. Make Greater Potion (3 Herbs + 2 Crystals + 1 Rune)\n";
    cout << "3. Make Phoenix Tincture (1 Feather + 2 Crystals)\n";
    cout << "4. Brew Philosopher's Elixir (FINAL) (5 Crystals + 3 Runes + 2 Feathers + 1 Scale)\n";
    cout << "5. Back\n";
    int choice; cin >> choice;
    if (choice == 1) {
        if (p.herbs >= 2 && p.crystals >= 1) {
            p.herbs -= 2; p.crystals -= 1;
            p.hasBasicPotion = true;
            cout << "You crafted a Basic Potion. Use it from menu.\n";
        } else cout << "Not enough ingredients.\n";
    } else if (choice == 2) {
        if (p.herbs >= 3 && p.crystals >= 2 && p.runes >= 1) {
            p.herbs -= 3; p.crystals -= 2; p.runes -= 1;
            heal(p, 60);
            cout << "You brewed a Greater Potion and healed 60 HP.\n";
        } else cout << "Not enough ingredients.\n";
    } else if (choice == 3) {
        if (p.phoenixFeathers >= 1 && p.crystals >= 2) {
            p.phoenixFeathers -= 1; p.crystals -= 2;
            heal(p, 120);
            cout << "The Phoenix Tincture heals 120 HP!\n";
            if (p.health > p.maxHealth) p.health = p.maxHealth;
        } else cout << "Not enough rare ingredients.\n";
    } else if (choice == 4) {
        if (p.crystals >= 5 && p.runes >= 3 && p.phoenixFeathers >= 2 && p.dragonScales >= 1) {
            p.crystals -= 5; p.runes -= 3; p.phoenixFeathers -= 2; p.dragonScales -= 1;
            p.elixirCount += 1;
            cout << "\nYou complete the sacred brew... The Philosopher's Elixir is ready!\n";
            printElixirArt();
            cout << "You win when you craft the Elixir and choose to use it.\n";
        } else cout << "Missing ingredients for the Elixir.\n";
    } else {
        cout << "Leaving crafting.\n";
    }
}

// Shop 
void shop(Player &p) {
    cout << "\n=== Alchemist's Market ===\n";
    cout << "Coins: " << p.coins << "\n";
    cout << "1. Buy Herb (10 coins)\n";
    cout << "2. Buy Crystal (20 coins)\n";
    cout << "3. Buy Rune (25 coins)\n";
    cout << "4. Buy Basic Potion (pre-made) (40 coins)\n";
    cout << "5. Sell Herbs (5 coins each)\n";
    cout << "6. Exit\n";
    int ch; cin >> ch;
    if (ch == 1) {
        if (p.coins >= 10) { p.coins -= 10; p.herbs += 1; cout << "Bought 1 Herb.\n"; }
        else cout << "Not enough coins.\n";
    } else if (ch == 2) {
        if (p.coins >= 20) { p.coins -= 20; p.crystals += 1; cout << "Bought 1 Crystal.\n"; }
        else cout << "Not enough coins.\n";
    } else if (ch == 3) {
        if (p.coins >= 25) { p.coins -= 25; p.runes += 1; cout << "Bought 1 Rune.\n"; }
        else cout << "Not enough coins.\n";
    } else if (ch == 4) {
        if (p.coins >= 40) { p.coins -= 40; p.hasBasicPotion = true; cout << "Bought a Basic Potion.\n"; }
        else cout << "Not enough coins.\n";
    } else if (ch == 5) {
        if (p.herbs > 0) {
            int sell = p.herbs * 5;
            p.coins += sell;
            cout << "Sold " << p.herbs << " herbs for " << sell << " coins.\n";
            p.herbs = 0;
        } else cout << "No herbs to sell.\n";
    } else cout << "Leaving market.\n";
}

bool battleGuardian(Player &p, int guardianLevel) {
    
    int guardHP = 30 + guardianLevel * 15;
    int guardAtk = 8 + guardianLevel * 5;
    cout << "\nA Guardian of the " << (guardianLevel==1? "Forest": guardianLevel==2? "Cavern" : guardianLevel==3? "Desert":"Volcano")
         << " appears! HP: " << guardHP << "  Attack: " << guardAtk << "\n";
    while (guardHP > 0 && p.health > 0) {
        cout << "1. Cast Spell (cost 10 mana)   2. Strike (low damage)   3. Use Basic Potion   4. Flee\n";
        int c; cin >> c;
        if (c == 3) {
            if (p.hasBasicPotion) {
                p.hasBasicPotion = false;
                heal(p, 40);
                continue;
            } else cout << "No basic potion.\n";
        } else if (c == 4) {
            if (rand()%2 == 0) { cout << "You escaped!\n"; return true; }
            else { cout << "Failed to escape!\n"; }
        } else if (c == 1) {
            if (p.mana >= 10) {
                p.mana -= 10;
                int spellDmg = 18 + rand()%8;
                cout << "You cast a spell for " << spellDmg << " damage.\n";
                guardHP -= spellDmg;
            } else cout << "Not enough mana.\n";
        } else {
            int strike = 6 + rand()%6;
            cout << "You strike for " << strike << " damage.\n";
            guardHP -= strike;
        }
        if (guardHP > 0) {
            takeDamage(p, guardAtk + rand()%6);
        }
    }
    if (p.health > 0) {
        cout << "Guardian defeated!\n";
        int rewardCoins = 15 + rand()%21;
        addCoins(p, rewardCoins);
        // reward an ingredient
        int loot = rand()%4;
        if (loot == 0) { p.herbs += 2; cout << "Found 2 Herbs!\n"; }
        else if (loot == 1) { p.crystals += 1; cout << "Found 1 Crystal!\n"; }
        else if (loot == 2) { p.runes += 1; cout << "Found 1 Rune!\n"; }
        else { p.coins += 5; cout << "Found some extra coins.\n"; }
        return true;
    } else {
        cout << "You were defeated by the guardian...\n";
        return false;
    }
}

void exploreRegion(Player &p) {
    cout << "\nChoose a region to explore:\n";
    cout << "1. Enchanted Forest (low risk)\n";
    cout << "2. Crystal Cavern (medium)\n";
    cout << "3. Sun-scorched Desert (risky)\n";
    cout << "4. Smoldering Volcano (dangerous, rare loot)\n";
    cout << "5. Back\n";
    int r; cin >> r;
    if (r == 5) return;
    int event = rand()%6;

    if (r == 1) { // Forest
        if (event == 0) { cout << "You find a patch of herbs.\n"; p.herbs += 2; }
        else if (event == 1) { cout << "A friendly grove spirit gives you a crystal.\n"; p.crystals += 1; }
        else if (event == 2) { battleGuardian(p, 1); }
        else if (event == 3) { cout << "You find a small chest with coins.\n"; addCoins(p, 10 + rand()%11); }
        else if (event == 4) { cout << "A wandering trader offers a Phoenix Feather for 80 coins.\n"; if (p.coins >= 80) { p.coins -= 80; p.phoenixFeathers++; cout << "You bought a Phoenix Feather.\n"; } else cout << "You can't afford it.\n"; }
        else { cout << "A calming fountain restores some mana.\n"; restoreMana(p, 15); }
    } else if (r == 2) { // Cavern
        if (event == 0) { cout << "Crystal veins glitter; you mine one crystal.\n"; p.crystals += 1; }
        else if (event == 1) { cout << "You discover a rune etched in stone.\n"; p.runes += 1; }
        else if (event == 2) { battleGuardian(p, 2); }
        else if (event == 3) { cout << "You trigger a rockfall and lose some health.\n"; takeDamage(p, 12 + rand()%10); }
        else if (event == 4) { cout << "You find a small pouch of coins.\n"; addCoins(p, 20 + rand()%21); }
        else { cout << "A hidden alcove contains an old alchemical notebook. You gain a clue for crafting.\n"; p.coins += 5; }
    } else if (r == 3) { // Desert
        if (event == 0) { cout << "You find rare desert herbs.\n"; p.herbs += 3; }
        else if (event == 1) { cout << "A sand spirit offers a dragon scale for a heavy price (sell expensive goods?)\n"; if (p.coins >= 120) { p.coins -= 120; p.dragonScales += 1; cout << "You acquired a Dragon Scale.\n"; } else cout << "Not enough coins.\n"; }
        else if (event == 2) { battleGuardian(p, 2); }
        else if (event == 3) { cout << "A heatwave deals damage.\n"; takeDamage(p, 18 + rand()%12); }
        else if (event == 4) { cout << "You stumble on a ruined caravan and salvage some crystals.\n"; p.crystals += 2; }
        else { cout << "A trader sells you a phoenix feather for 60 coins.\n"; if (p.coins >= 60) { p.coins -= 60; p.phoenixFeathers += 1; cout << "Bought a Phoenix Feather.\n"; } else cout << "Can't afford.\n"; }
    } else if (r == 4) { // Volcano
        if (event == 0) { cout << "You brave the heat and recover rare crystals.\n"; p.crystals += 3; }
        else if (event == 1) { cout << "A lava wight attacks!\n"; battleGuardian(p, 3); }
        else if (event == 2) { cout << "Molten rock injures you.\n"; takeDamage(p, 25 + rand()%15); }
        else if (event == 3) { cout << "You find a fragment of dragon scale!\n"; p.dragonScales += 1; }
        else if (event == 4) { cout << "A mysterious altar restores health a little.\n"; heal(p, 40); }
        else { cout << "You find a rare ingredient for sale: Phoenix Feather for 40 coins.\n"; if (p.coins >= 40) { p.coins -= 40; p.phoenixFeathers += 1; cout << "Bought Feather.\n"; } else cout << "Too poor.\n"; }
    }
}

void useBasicPotion(Player &p) {
    if (p.hasBasicPotion) {
        p.hasBasicPotion = false;
        heal(p, 40);
        cout << "You used a Basic Potion.\n";
    } else cout << "No basic potion available.\n";
}

void printMenu() {
    cout << "\n=== Main Menu ===\n";
    cout << "1. Explore (collect ingredients & fight)\n";
    cout << "2. Craft\n";
    cout << "3. Visit Market\n";
    cout << "4. Use Basic Potion\n";
    cout << "5. Show Status\n";
    cout << "6. End Game / Exit\n";
    cout << "Choose: ";
}

int main() {
    srand((unsigned)time(0));
    Player p;
    printTitleArt();
    cout << "Enter your name, Alchemist: ";
    getline(cin, p.name);
    cout << "\nWelcome, " << p.name << "! Begin your journey to brew the Philosopher's Elixir.\n";
    int choice;
    while (true) {
        if (p.health <= 0) {
            cout << "\nYou have perished on your journey... Game Over.\n";
            break;
        }
        if (p.elixirCount > 0) {
            cout << "\nYou have brewed the Philosopher's Elixir! Do you wish to use it now? (y/n): ";
            char useEl; cin >> useEl;
            if (useEl == 'y' || useEl == 'Y') {
                cout << "\nYou drink the Elixir... Your mind and body transcend. Victory!\n";
                printElixirArt();
                cout << "\n=== Congratulations, " << p.name << "! You completed The Alchemist's Journey ===\n";
                showStatus(p);
                break;
            } else {
                cout << "You keep the Elixir for now.\n";
            }
        }
        printMenu();
        cin >> choice;
        if (choice == 1) {
            exploreRegion(p);
        } else if (choice == 2) {
            craft(p);
   
   
   
        } else if (choice == 3) {
            shop(p);
        } else if (choice == 4) {
            useBasicPotion(p);
        } else if (choice == 5) {
            showStatus(p);
        } else if (choice == 6) {
            cout << "Ending the journey. Goodbye!\n";
            break;
        } else {
            cout << "Invalid option.\n";
        }

        if (p.mana < p.maxMana) {
            p.mana += 3;
            if (p.mana > p.maxMana) p.mana = p.maxMana;
        }
    }
    cout << "\n--- Thanks for playing The Alchemist's Journey ---\n";
    return 0;
}

