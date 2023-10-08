# M2OEP-njblanch
### By Nathan Blanchard

## Summary
This program is a somewhat chess-style 2v2 soccer game. Each team consists of two players, and you are able to choose 
which player to control each turn. On offense, you can either move one player twice, pass, or shoot. The closer you are 
to the goal, the better chance you have of scoring. On defense, you are able to move one player just once as you try to 
block the offensive players from getting into a scoring position. Also, if the defense gets within 1 cardinal space (up, 
down, left, right) of the offensive player with the ball, they are able to steal it. There are two different types of
players for this game: fast players `𖨆` and striker players `𖠋`. Fast players can move twice per turn, while striker
players have a higher chance of scoring (+25% from anywhere on the field). To balance this, and make it so 
that games do not go on forever, the offense only has 8 turns to try to score for each possession.

## Module 2 concepts used:
- **Inheritance Class Relationship:**
My initial design for this game consisted of one generic type of player. This made it so that there were not many
options for moves, as usually only one or two moves made sense. To make it more interesting, and so that games had
less of a pre-determined outcome, I decided to add two new types of players that would inherit from and override
functions in the Player class. The first type of player, the FastPlayer, overrides the movement function from the Player
class. This makes it so that this type of player can move twice per turn. The second type of player, the StrikerPlayer,
overrides the shoot function from the Player class. This makes it so that this type of player has a higher chance of
scoring. This game then makes use of polymorphism to call these functions.
- **Component Class Relationship:**
My game makes use of multiple component class relationships. The first one is that a SoccerGame object has-a FastPlayer.
Similarly, a SoccerGame object has-a StrikerPlayer. These relationships are essential for the reusability of code since
there are multiple of these player objects needed for each game. The next component class relationship that my game
makes use of is that a SoccerGame object has-a Field. This relationship is great for allowing player objects to interact
with each other and get distances between player objects and between a player and the goal. One other relationship that
I had was that a Field object has a 2d vector of pointers to player objects. I am unsure if this counts as a component
class relationship, but it makes use of the inheritance relationships mentioned above to reference both FastPlayer and
StrikerPlayer objects which I thought was neat.

## Known Bugs
As of right now there are no game-breaking bugs that I know about, but there are some balancing changes that need to be made to make the game more enjoyable.

## Future Work
In the future I definitely want to add graphics to this game. The text-based approach, although easy to execute, makes 
the game feel very slow. Aside from this, though, I want to do some balancing changes, and maybe add some randomness 
components to the game. This could be done by something simple like allowing the characters to move diagonally or 
possibly something bigger like including powerups that you can pick up. Currently, it is still easy to determine the 
best move in any scenario, and this makes it so that most games have the same outcome. This is something that I improved 
in this version by making different types of player objects, so that you have more of a choice about where to move and 
when to shoot, but it would be interesting in the future to experiment more with how to improve this aspect of the 
gameplay. In addition to this, there is definitely some more bugtesting that needs to be done as I'm sure there are some 
gameplay paths that I missed going down. Whatever happens though, there is definitely a lot of future work to be done on 
this game.

## Citations
- Kasera, J. (2022, April 12). ABS() in C++. Scaler Topics. https://www.scaler.com/topics/abs-in-cpp/#
- Thakur, N. (2019, July 30). How to map C++ enums to strings?. tutorialspoint. https://www.tutorialspoint.com/how-to-map-cplusplus-enums-to-strings

## Grade
- **Main program complexity and usability:** I believe that my program was sufficiently complex, it uses two of the 
three concepts from module 1, and it validates user input. I spent a lot of time getting the inheritance class
relationships to work as intended, and this made it so that I had to rethink a lot of the functionality of the game and 
do some extensive bugtesting. One thing that I could get some points off for with this is that, although I wrote a fair
bit of new code and spent a lot of time reorganizing classes to work with inheritance, much of the functionality of the 
game remained unchanged. Because of this, I think that I should get 35 points for the main program complexity and
usability.
- **Testing program:** I unfortunately ran out of time to include a testing program. Therefore, I will be getting a 0
for this category.
- **Is-A or Has-A class relationship:** I made use of two inheritance class relationships, although both were fairly
similar. They did, however, override different functions. I believe that these should total 25 points. I also made
use of 4 has-a class relationships (SoccerGame has-a FastPlayer, a StrikerPlayer, and a Field, and Field has-a 2D vector
of pointers to player objects). I believe that the FastPlayer and StrikerPlayer should total 25 points. This is because
their implementation is very similar. Next, I believe that the SoccerGame has-a Field relationship should be 20 points.
I believe that this class relationship is designed well and used in a way that makes sense. Next, I believe that the 2D
vector of pointer to player objects should get 5 points, as I do not think it entirely qualifies as a has-a relationship,
though I still think it makes good use of the concepts we learned in module 2. Overall, I believe that I should get 75
points for this category.
- **Penalties:** None (hopefully)
- **Overall:** 35 + 75 -> 110