
#  The Alchemist’s Journey

**The Alchemist’s Journey** is a text-based C++ adventure game where you play as an ambitious alchemist on a quest to craft the *Philosopher’s Elixir* — the legendary potion of immortality.

Explore magical lands, gather ingredients, fight guardians, and brew powerful potions as you uncover the secrets of alchemy.

---


##  How to Play
1. Run the program.
2. Read the story and choose your actions (e.g., mix, explore, rest, etc.).
3. Manage health, coins, and inventory wisely.
4. Brew the **final Elixir** to complete your journey!

> 💡 Tip: Each decision may affect your fate — not all potions are safe!

---

###  Build and Run
```bash
g++ main.cpp -o alchemist
./alchemist
```

##  Features

-  **Potion Crafting System** — Collect ingredients, combine them, and brew elixirs with unique effects.  
-  **Coin Economy** — Earn coins through exploration and use them to buy rare items.  
-  **Mystical Encounters** — Meet sages, spirits, and magical creatures who may help (or curse) you.  
-  **Health & Mana Mechanics** — Manage your vitality and energy carefully.  
-  **Simple Console Gameplay** — Playable entirely in the terminal, no extra libraries required.

---
##  Main Functions Overview

| Function | Description |
|-----------|-------------|
| `printTitleArt()` | Displays the magical title screen ASCII art. |
| `printElixirArt()` | Prints the glowing elixir art when a potion is successfully brewed. |
| `heal(Player &p, int h)` | Restores player health by `h` points. |
| `damage(Player &p, int d)` | Reduces player health by `d` points. |
| `addCoins(Player &p, int c)` | Adds coins to the player's inventory. |
| `usePotion(Player &p)` | Consumes a potion to regain health. |
| `treasureRoom(Player &p)` | Allows the player to find coins or special items. |
| `fightRoom(Player &p)` | Initiates combat with a magical creature or rogue alchemist. |
| `bossRoom(Player &p)` | The final alchemical duel; win to complete the game. |
| `printMenu()` | Shows available in-game actions. |
| `main()` | Entry point; controls the full gameplay loop. |

---

## Video
https://github.com/prashantgarg8/Alchemists-Journey/releases/tag/v1

