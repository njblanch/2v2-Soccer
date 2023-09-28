# M1OEP-njblanch
### By Nathan Blanchard

## Summary
This program is a somewhat chess-style 2v2 soccer game. Each team consists of two players, and you are able to choose 
which player to control each turn. On offense, you can either move one player twice, pass, or shoot. The closer you are 
to the goal, the better chance you have of scoring. On defense, you are able to move one player just once as you try to 
block the offensive players from getting into a scoring position. Also, if the defense gets within 1 cardinal space (up, 
down, left, right) of the offensive player with the ball, they are able to steal it. To balance this, and make it so 
that games do not go on forever, the offense only has 8 turns to try to score for each possession.
Module 1 concepts used:
- **Classes:**
I used 3 different classes to make this game. The first class is the Player class. This holds attributes for each 
player, such as team and player number, field position, and information about ball possession, and has a function to 
generate the string representation of the player. Next is the Field class. This allows us to see where the players are 
in relation to each other, storing pointers to the Player objects in a 2d vector. This also has a function that lets us 
know if a space is occupied, meaning it is easy to tell if we can actually move a player to a specified space. Finally, 
we have the SoccerGame class. This class creates instances of the Player and Field objects and gets them to more or less 
behave well with each other. It provides functions like movePlayer, passBall, and switchActiveTeam (to name a few) that 
let us control the flow of the game from our main program.
- **Overloaded Operator:**
I used an overloaded operator in the Field class to allow for the field to be printed easily. I overloaded the << 
operator, creating a custom printout using some text-art to make a tiled playing field that makes it clear how far 
players are from each other, the edges of the field, and the goal.
- **Enumerated Type:**
I used an enum to represent the fixed set of text symbols that the players can be represented by. I had originally made 
it so that it just generated this string each time the function was called, but using an enumerated type to do this, 
since there are only a set number of possibilities for symbols, made more sense.

## Known Bugs
As of right now there are no game-breaking bugs that I know about, but there are some balancing changes that need to be made to make the game more enjoyable.

## Future Work
In the future I definitely want to add graphics to this game. The text-based approach, although easy to execute, makes 
the game feel very slow. Aside from this, though, I want to do some balancing changes, add some more functionality to 
the players, and maybe add some randomness components to the game. This could be done by something simple like allowing 
the characters to move diagonally or possibly something bigger like including powerups that you can pick up. I would 
also like to move some of the functionality included in main to the SoccerGame class, as I ended up putting a lot of 
things in main that probably should have been put in that class. In addition to this, there is definitely some more 
bugtesting that needs to be done as I'm sure there are some gameplay paths that I missed going down. Whatever happens 
though, there is definitely a lot of future work to be done on this game.

## Citations
- Kasera, J. (2022, April 12). ABS() in C++. Scaler Topics. https://www.scaler.com/topics/abs-in-cpp/#
- Thakur, N. (2019, July 30). How to map C++ enums to strings?. tutorialspoint. https://www.tutorialspoint.com/how-to-map-cplusplus-enums-to-strings

## Grade
- **Main program complexity and usability:** I believe that my program was sufficiently complex, it uses three of the 
four concepts from module 1, and it validates user input. One thing I could get points off for is I feel that my main 
program is a little disorganized, and some fo the logic could have been included in the SoccerGame class. Overall, I 
think that I deserve at least 35 points.
- **Concept: C++ class:** I included 3 C++ classes. I believe that each was designed well, implemented robustly, and 
used in the main program in a way that makes sense. Because of this I think that I should get 20 points for each.
- **Concepts: Overloaded Operator, enum, struct:** I used one overloaded operator and one enum, each of which I think is 
designed well, implemented robustly, and used in the main program in a way that makes sense. Because of this, I think 
that I should get 5 points for each.
- **Penalties:** None (hopefully)
- **Overall:** 35 + 60 + 10 -> 105