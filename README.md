# Tribal Zork
This game has been created as a tribute to the original Zork using the same gameplay mechanics.


### Plot
The game takes place in 10.000 BC. After going hunting with his tribe, the main character falls down a cliff, loses all his equipment and remains unconscious for a few hours.

The player, introducing command lines, has to explore the world and find his way back home, fighting at the end against the Smilodon, a saber-toothed cat.


### Map
The map has 9 rooms to explore. In those rooms the player will have to pick up items and manipulate them to win the game.


### Items
- **Berry**: red, small and juicy fruit.
- **Bag**: Small leather bag. It may contain something...
- **Branch**: a long tree limb.
- **Flint**: a small piece of sharp flint.
- **Vine**: a long string, it could be used as a rope.
- **Spoiled meat**: some dead creature's meat. It looks rotten.
- **Spear**: a long sharp spear.  RECEIPE (1xBranch + 1xFlint + 1xVine)


### Gameplay
The player will use commands to interact with the world:

| 1 Word commands| Action |
| --- | --- |
|Look | Description of the close enviroment |
|Inventory | List of player's inventory |
|Quit | Quit the game |

| **2 Word commands**| | Action |
| --- | --- | --- |
|Look  |(entity)| Detailed description |
|Go |(direction)| Player movement towards that direction |
|Get/Pick/Take |(item)| Add item to player's inventory |
|Drop |(item)| Remove item from player's inventory and leave it on the floor |
|Craft |(receipe)| Remove receipe's items from inventory and add the crafted one |
|Eat |(item)| Remove item from player's inventory and enjoy the food |
|Open |(container)| Open the container and put its content in player's inventory |

| **4 Word commands**| | | | Action |
| --- | --- | --- | --- | --- |
|Put |(item)| in  |(container)| Remove item from player's inventory and store it inside the container |


### Ending
Depending on which items the player has on entering the final room (Smilodon's Lair) he will have one of the 4 different endings.
- **No spear and no meat**: The player dies facing the Smilodon.
- **Meat**: The player distracts the Smilodon for a while, but it ends up getting caught and killed.
- **Spear**: The player kills the Smilodon, but also dies wounded by the great creature.
- **Spear and meat**: The player distracts the creature with the spoiled meat and wins killing the creature from behind.


### Author
Sergi Ledesma Sánchez
<br> Contact: sergi.dev@gmail.com
<br> Check out the full project at https://github.com/SergiLedesma
<br> Project License: GNU GENERAL PUBLIC LICENSE 3.0
