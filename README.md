## Medieval dynasty (Rock, Paper, Scissor Edition)
**Rock, Paper, Scissor**
- The game is similar to the normal Rock, Paper, Scissor but instead 
of 3 options we got 5 options to choose from:
  - Sword
  - Shield
  - Human
  - Gun
  - Grenade
- Each options consist of 2 wins and 2 loss:
  - `Sword` ***beats*** `Grenade` and `Shield`, but ***lose*** to `Gun` and `Human`
  - `Shield` ***beats*** `Gun` and `Human`, but ***lose*** to `Sword` and `Grenade`
  - `Human` ***beats*** `Gun` and `Sword`, but ***lose*** to `Shield` and `Grenade`
  - `Gun` ***beats*** `Grenade` and `Sword`, but ***lose*** to `Shield` and `Human`
  - `Grenade` ***beats*** `Human` and `Shield`, but ***lose*** to `Sword` and `Gun`

## HOW TO PLAY (FIRST TO WIN 3 GAMES)
![Funkit](C:\Users\GGPC\OneDrive\Desktop\Funkit.jpg)
1.  Using your terminal create a folder using `"git clone https://eng-git.canterbury.ac.nz/ence260-2020/group-205.git"`. (Folder can be created anywhere) Enter your UC id and password.
2.  Double click on the folder and open terminal.
3.  Both players will type `"Make"` into the terminal to compile the game and `"Make program"` after the compile has finish to play the game.
4.  LED Screen and Blue LED should light up on both boards and the LED screen should display `"WELCOME TO MEDIEVAL DYNASTY, MOVE NAVSWITCH TO START"`.
5.  Both players can move the nav switch in any direction to start the game. 
6.  Using the nav switch, moving it left and right will let the player select their choice.
7.  After you have decided what they want to choose, push up on the nav switch to lock in what you have selected, LED screen will turn off so your opponent can't see what you chose.
8.  Then place the board next to each other and both player press on Button B next to the LED screen at the same time to send signal between the boards and the LED screen will display either `'W'`, `'L'` or `'S'`:
    - `'W'` = Winner
    - `'L'` = Loser
    - `'S'` = Same/Tie
9.  After the board have displayed the outcome of that round. The player will have to press on the nav switch to go to the next round.
10. Repeat this process till one of the players wins 3 games. (At the end of each round a sound will start to play on one of the player's speaker when they lost the round)
11. After one of the players have won 3 game. A `"YOU LOSS!"` text will display on the board of the player who lost the game plus the speaker will turn on signifying that you lost the game and `"YOU WON!"` text on the board of the player who won the game.
12. To restart the game both players will press on Button A then and quickly press Button B on their board, this will return to the starting screen and the player can move the nav switch to play again.

