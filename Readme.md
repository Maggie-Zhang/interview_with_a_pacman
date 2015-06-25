# Interview with a Pac Man

Hi Mr. Interviewee,

Your goal is to write a small Ascii version of PacMan using whatever programming language you are most comfortable with (javascript, C# or C++). We will evaluate your work based on how you structure your code and which algorithms and data structures you used. Basically, we want to evaluate your problem solving and coding skills!

When you are done, or when the time is up, we will review your work with and we will give you one last time to justify your choices! :)


##Game level description

A level, empty of moving character look like this:

	###################
	#........#........#
	#.#.####.#.####.#.#
	#.#......#......#.#
	#.#.####.#.####.#.#
	#...#.........#...#
	#.#.#.### ###.# #.#
 	.#...#     #...#. 
	#.#.#.#######.#.#.#
	#...#.........#...#
	#.#...#######...#.#
	#.##.....#.....##.#
	#.................#
	###################

A level, containing PacMan and the Ghosts look like this:

	###################
	#@.......#........#
	#.#.####.#.####.#.#
	#.#......#......#.#
	#.#.####.#.####.#.#
	#...#.........#...#
	#.#.#.### ###.# #.#
 	.#...#12 34#...#.     -> Warp zone!
	#.#.#.#######.#.#.#
	#...#.........#...#
	#.#...#######...#.#
	#.##.....#.....##.#
	#.................#
	###################

Where:

	‘#’: Wall
	‘ ‘ (espace):empty space in the labyrtinth. 
	‘.’: PacGum. Pacman loves to eat those.
	‘@’ : PacMan
	1’,’2’,’3’,’4’ : les fantômes (Sue is number 4)

A board example with Ghosts and Pac man moving and battling would be:

	###################
	#      @.#........#
	#.#.####.#.####.#.#
	#.#...2..#......#.#
	#.#.####.#.####.#.#
	#...#.........#...#
	#.#.#.### ###.# #.#
 	.#...# 1   #...#. 
	#.#.#.#######.#.#.#
	#...#.........#...#
	#.#...#######...#.#
	#.##.4...#..3..##.#
	#.................#
	###################


##Rules of the Game

- This is PacMan. Don't overthink it. But Respect it. The grand daddy of arcade game!
- When the game starts, Pac man is not moving.
- When the user hit an arrow (left, down, right, up) Pac-man starts moving in that direction.
- Each time PacMan pass over a PacGum, PacMan eats it. The space where the PacGum was is now empty. 
- PacMan scores is increased by one for each PacGum eaten. You should display PacMan score somewhere.
- Pac Man cannot pass a Wall. 
- If Pac Man (or a Ghosts) passes over one Warp zone, he should exits from the other Warp Zone.
- Ghosts Behavior:
	- All Ghosts starts in their Start up box.
	- When a Ghost arrives at an intersection:
		- Ghost 1 : 50% of the time goes toward PacMan. 50% another random direction
		- Ghost 2 : 100% goes toward a random direction.
		- Ghost 3: 75% goes to the Right if possible. 25%: goes anywhere else.
		- Ghost 4: 75% goes to the left if possible. 25%: goes anywhere else.
    - Ghosts can only change direction at an intersection.
    - Ghosts do not collide with each other (they can pass over each other)
    - Ghosts do not eat PacGum. They hate the taste.
    - If a Ghost ever collide with PacMan this is Game over!
- If PacMan eats all PacGum this is a glorious Victory (and the end of the game as well).



