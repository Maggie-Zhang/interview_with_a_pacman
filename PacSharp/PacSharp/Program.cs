using System;

namespace PacSharp
{
    class Game
    {
        public Random RandomGenerator { get; set; }
        public int Timeoutc { get; set; }  // Validity of user input
        public ConsoleKey CharInput { get; set; } // User input
        public long Time { get; set; }      // Game time
        public int Pos { get; set; }      // Monster position
        public int OldPos { get; set; }   // Old monster position
        public long MonsterNextUpdate { get; set; } // Monster next update time

        public Game()
        {
            Console.CursorVisible = false;

            CharInput = ConsoleKey.Spacebar;
            Pos = 0;
            Time = GetTime();
            RandomGenerator = new Random();
        }

        public static long GetTime()
        {
            long milliseconds = DateTime.Now.Ticks / TimeSpan.TicksPerMillisecond;
            return milliseconds;
        }

        // To position the console cursor position
        public void GotoXY( int x, int y ) 
        { 
            Console.SetCursorPosition(x, y);
        }

        public Int32 PickANumberAnyNumber()
        {
            return RandomGenerator.Next();
        }

        // To read the console input in a non-blocking way
        public void GetUserInput()
        {
            if (Console.KeyAvailable)
            {
                CharInput = Console.ReadKey(true).Key;
            }
        }

        // Perform all the non-user updates
        public void PerformAI()
        {
            // Time to update AI !
            if (Time > MonsterNextUpdate)
            {
                OldPos = Pos;
                Pos = (Pos + 1) % 10;
                MonsterNextUpdate = Time + 1000;
            }
        }

        // Refresh the game output
        public void DrawGame()
        {
            // Draw something
            GotoXY(5, 5);
            Console.Write("Char: {0} at {1} ms", CharInput.ToString(), Time);

            // Draw Pac man!
            if (OldPos != Pos)
            {
                GotoXY(OldPos, 10);
                Console.Write(" ");
                GotoXY(Pos, 10);
                Console.Write("*");
            }
        }

        // Determine if the game end condition
        public bool IsGameFinished()
        {
            return CharInput == ConsoleKey.Q;
        }

        // Display the game results
        public void DisplayResults()
        {
            Console.Clear();
            Console.Write("** Whatever wins! ** \n\n");
            Console.Write("<press a key to continue>\n");
            Console.ReadKey();
        }

        // Un-init the game
        public void TerminateGame()
        {

        }
    };

    class Program
    {
        static void Main(string[] args)
        {

            var game = new Game();
            while (!game.IsGameFinished())
            {
                game.Time = Game.GetTime();
                game.GetUserInput();
                game.PerformAI();
                game.DrawGame();
            }

            game.DisplayResults();

            game.TerminateGame();
        }
    }
}
