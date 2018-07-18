#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

/*

functions used
- shuffle: shuffles cards
- isOp: checks that a correct operator is inputted
- math: does the math operation
- indexDrawn: checks if card is in deck and returns location
  - NOTE: if the card has the same value as the other card, the second
    index will be returned the second time
- draw4: draw four cards
- remove: removes 2 cards from a drawn pile
- readCard: reads card input

TYPE "quit" or "Q" or "q" TO QUIT THE GAME
TYPE "skip" or "S" or "s" TO SKIP THE ROUND

*/

/* ART SECTION */

void printWelcome(){ // prints "welcome to 24" in huge letters
  cout << "               _                            _          ___  _  _   _ " << endl;
  cout << "              | |                          | |        |__ \\| || | | |" << endl;
  cout << " __      _____| | ___ ___  _ __ ___   ___  | |_ ___      ) | || |_| |" << endl;
  cout << " \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\    / /|__   _| |" << endl;
  cout << "  \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |  / /_   | | |_|" << endl;
  cout << "   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |____|  |_| (_)" << endl << endl;

}

void printRules(){ // prints RULES in huge letters
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  cout << "  _____  _    _ _      ______  _____ " << endl;
  cout << " |  __ \\| |  | | |    |  ____|/ ____|" << endl;
  cout << " | |__) | |  | | |    | |__  | (___  " << endl;
  cout << " |  _  /| |  | | |    |  __|  \\___ \\ " << endl;
  cout << " | | \\ \\| |__| | |____| |____ ____) |" << endl;
  cout << " |_|  \\_\\_____/|______|______|_____/ " << endl;

  cout << endl << "24 is a famous arithmetic game that originated in ShangHai." << endl << endl;
  cout << "The objective of the game is to manipulate four numbers through arithmetic" << endl;
  cout << "operations to get the final result of 24. Every number must be used exactly" << endl;
  cout << "once. The only operations allowed are + - * /." << endl << endl;

  cout << "For example, if you are dealt the numbers \"1 7 7 10\", a possible solution" << endl;
  cout << "would be (10 - 7) * (1 + 7) = 24." << endl << endl;

  cout << "In our version of the game, you must select two cards at a time. Then, you" << endl;
  cout << "will be asked to choose an arithmetic operator. The numbers you are allowed" << endl;
  cout << "to use will be displayed on the screen." << endl << endl;

  cout << "To quit during the game, type QUIT (or q)." << endl;
  cout << "To skip a set of cards, type SKIP (or s). You will lose a point." << endl << endl;

  cout << "Type PLAY when you are ready to play: ";
}

void printStart(){ // prints GOOD LUCK in huge letters
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "   _____   ____    ____   _____    _      _    _   _____  _  __ _ " << endl;
  cout << "  / ____| / __ \\  / __ \\ |  __ \\  | |    | |  | | / ____|| |/ /| |" << endl;
  cout << " | |  __ | |  | || |  | || |  | | | |    | |  | || |     | ' / | |" << endl;
  cout << " | | |_ || |  | || |  | || |  | | | |    | |  | || |     |  <  | |" << endl;
  cout << " | |__| || |__| || |__| || |__| | | |____| |__| || |____ | . \\ |_|" << endl;
  cout << "  \\_____| \\____/  \\____/ |_____/  |______|\\____/  \\_____||_|\\_\\(_)" << endl << endl;

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl << endl << endl << endl;
}

void printDivider(){ // divider
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}

void printCongrats(){
  int a = rand()%3; // randomly generates one of three "CONGRATS" comments after you score a point
  if (a == 0){
    cout << "                                        _         _ " << endl;
    cout << "                                       | |       | |" << endl;
    cout << "   ___  ___   _ __    __ _  _ __  __ _ | |_  ___ | |" << endl;
    cout << "  / __|/ _ \\ | '_ \\  / _` || '__|/ _` || __|/ __|| |" << endl;
    cout << " | (__| (_) || | | || (_| || |  | (_| || |_ \\__ \\|_|" << endl;
    cout << "  \\___|\\___/ |_| |_| \\__, ||_|   \\__,_| \\__||___/(_)" << endl;
    cout << "                      __/ |                         " << endl;
    cout << "                     |___/                          " << endl;
  }

  if (a == 1){
    cout << "         _                 ____  " << endl;
    cout << "        (_)             _ |___ \\ " << endl;
    cout << "  _ __   _   ___  ___  (_)  __) |" << endl;
    cout << " | '_ \\ | | / __|/ _ \\     |__ < " << endl;
    cout << " | | | || || (__|  __/  _  ___) |" << endl;
    cout << " |_| |_||_| \\___|\\___| (_)|____/ " << endl;
  }

  if (a == 2){
    cout << "                           _     _         _             _____  " << endl;
    cout << "                          | |   (_)       | |           |  __ \\ " << endl;
    cout << "   __ _   ___    ___    __| |    _   ___  | |__   __  __| |  | |" << endl;
    cout << "  / _` | / _ \\  / _ \\  / _` |   | | / _ \\ | '_ \\  \\ \\/ /| |  | |" << endl;
    cout << " | (_| || (_) || (_) || (_| |   | || (_) || |_) |  >  < | |__| |" << endl;
    cout << "  \\__, | \\___/  \\___/  \\__,_|   | | \\___/ |_.__/  /_/\\_\\|_____/ " << endl;
    cout << "   __/ |                       _/ |                             " << endl;
    cout << "  |___/                       |__/                              " << endl;
  }
}

/* GAMEPLAY FUNCTION SECTION */

// shuffles cards in deck
// only 40 cards because we took out J, Q, and K
void shuffle(vector<float> &cards){
    for (int n = 0; n < 40; n++)
    {
        int k = rand() % 40; // chooses a random index
        int temp = cards[n]; // swaps two numbers and iterates 40 times
        cards[n] = cards[k];
        cards[k] = temp;
    }
}

// checks for a valid operator. could combine with math(a,b,op), but we found that just
//using math would sometimes crash our program, so we added isOp.
bool isOp(string a){
  if ((a == "+") || (a == "-") || (a == "*") || (a == "/"))
    return true;
  return false;
}

// performs the operations
float math(float a, float b, string op){
  if (op == "+")
    return a + b;
  else if (op == "-")
    return a - b;
  else if (op == "*")
    return a * b;
  else if (op == "/")
    return 1.0 * a / b;
  else
    return -1;
}


// returns the index value of a card within a deck.
// takes in 2 cards because if the values of the cards are equal, the second card has to
// return a different index
int indexDrawn(float card1, float card2, vector<float> drawn){
  if (card1 != card2){
    for(int i = 0; i < drawn.size(); i++){
      if (drawn[i] == card2){
        return i;
      }
    }
  }
  else if (card1 == card2){
    int a = 0;
    for(int i = 0; i < drawn.size(); i++){
      if (drawn[i] == card2){
        if (a == 1) { return i; } // only returns the index if it is the second time seeing the card
        a++;
      }
    }
  }
  return -1;
}

// draws 4 cards from a deck
vector<float> draw4(vector<float> draw){
  vector<float> drawn;
  drawn.push_back(draw[0]);
  drawn.push_back(draw[1]);
  drawn.push_back(draw[2]);
  drawn.push_back(draw[3]);
  return drawn;
}

// removes 2 cards from a deck based off their indexes
void remove(vector<float> &drawn, int index1, int index2){
  if (index1 > index2){ // removes index that's higher first
    for (int i = index1 + 1; i < drawn.size(); i++){
      drawn[i - 1] = drawn[i];
    }
    drawn.pop_back(); // then removes the lower index
    for (int i = index2 + 1; i < drawn.size(); i++){
      drawn[i - 1] = drawn[i];
    }
    drawn.pop_back();
  }
  else{ // same thing, but with the indexes switched
    for (int i = index2 + 1; i < drawn.size(); i++){
      drawn[i - 1] = drawn[i];
    }
    drawn.pop_back();
    for (int i = index1 + 1; i < drawn.size(); i++){
      drawn[i - 1] = drawn[i];
    }
    drawn.pop_back();
  }
}

// reads an input value (initially a string) into a float (a card)
float readCard(string s){
  if ((s == "quit") || (s == "QUIT") || (s == "q") || (s == "Q")){ // makes sure value is not quit before converting
    return -2;
  }
  if ((s == "skip") || (s == "SKIP") || (s == "s") || (s == "S")){ // makes sure value is not skip before converting
    return -4;
  }
  istringstream strm;
  strm.str(s);
  float i;
  strm >> i;
  return i;
}

// analyzes stats of the game
void analyze(int correct, int skips){
  cout << "# solved: " << correct << endl;
  cout << "# skipped: " << skips << endl;
  if ((correct + skips) != 0){
    cout << "\% of sets solved: " << correct * 100.00 / (correct + skips) << "\%." << endl;
  }
}

// plays the game
void playGame(){
  srand(time(0));

  vector<float> deck; // define deck
  for (int i = 1; i <= 10; i++){ // only 40 cards (took out J, Q, and K)
    deck.push_back(i);
    deck.push_back(i);
    deck.push_back(i);
    deck.push_back(i);
  }

  vector<float> drawn; // define 4 cards on screen
  vector<float> copy; // copy of the 4 drawn in case of resetting turn

  int score = 0; // define score
  int solved = 0; // keeps track of # solved
  int skip = 0; // keeps track of # skipped

  int card1, card2; // defines 2 cards
  string input1, input2; // defines input values for user
  string op; // defines operator

  bool game = true; // temp
  while (game){
    shuffle(deck); // shuffle the deck

    cout << "Your current score is " << score << "." << endl;
    drawn = draw4(deck);
    // copy = drawn;
    // ^ makes a copy of the drawn cards. NOT USED IN THIS VERSION
    // left it in because we plan to use it in future implementations of functions (such as adding a reset button)

    cout << endl;

    while (drawn.size() > 1){ // makes sure there are at least 2 cards to combine

      //
      // INPUTTING THE 2 CARDS
      //

      cout << "The four cards you have drawn are: ";
      for (int i = 0; i < drawn.size(); i ++){
        cout << drawn[i] << " ";
      }
      cout << endl;

      cout << "Please choose 2 cards to combine: " << endl;
      cin >> input1;
      card1 = readCard(input1);
      if (readCard(input1) == -2) { // error -2 is when the user typed to quit the game
        game = false;
        analyze(solved, skip); // analyzes your statistics during the game
        return;
      }
      if (readCard(input1) == -4){ // error -4 is when the user typed to skip the turn
        score--;
        skip++;
        break;
      }

      cin >> input2;
      card2 = readCard(input2);
      if (readCard(input1) == -2) { // same as above, but for input 2
        game = false;
        analyze(solved, skip); // analyzes your statistics during the game
        return;
       }
      if (readCard(input1) == -4){
        score--;
        skip++;
        break;
      }

      // v accounts for values that are invalid
      while ((indexDrawn(-1, card1, drawn) == -1) || (indexDrawn(card1, card2, drawn) == -1)){
        cout << "Your cards are invalid. Enter in the format a b (e.g: 1 2)." << endl;
        cout << "Your drawn cards are";
        for (int i = 0; i < drawn.size(); i++){
          cout << " " << drawn[i];
        }
        cout << "." << endl;
        cout << "Please choose 2 cards to combine: " << endl;
        cin >> input1;
        card1 = readCard(input1);
        if (readCard(input1) == -2) { // error -2 is when the user typed to quit the game
          game = false;
          analyze(solved, skip); // analyzes your statistics during the game
          return;
        }
        if (readCard(input1) == -4){ // error -4 is when the user typed to skip the turn
          score--;
          skip++;
          break;
        }

        cin >> input2; // same thing as above, but for second card input
        card2 = readCard(input2);
        if (readCard(input1) == -2) {
          game = false;
          analyze(solved, skip); // analyzes your statistics during the game
          return;
         }
        if (readCard(input1) == -4){
          score--;
          skip++;
          break;
        }
      }

      //
      // INPUTTING THE OPERATOR
      //

      cout << "Please choose an operator (+ - * /): ";
      cin >> op;
      if (readCard(input1) == -2) { // error -2 is when the user typed to quit the game
        game = false;
        analyze(solved, skip); // analyzes your statistics during the game
        return;
       }
      if (readCard(input1) == -4){ // error -4 is when the user typed to skip the turn
        score--;
        skip++;
        break;
      }

      // v accounts for values that are invalid
      while (!isOp(op)){
        cout << "Your operator is invalid. Please choose an operator (+ - * /): ";
        cin >> op;
        if (readCard(input1) == -2) {
          game = false;
          analyze(solved, skip); // analyzes your statistics during the game
          return;
         }
        if (readCard(input1) == -4){
          score--;
          skip++;
          break;
        }
      }

      drawn.push_back(math(card1, card2, op)); // adds in the combined value of the cards
      remove(drawn, indexDrawn(-1, card1, drawn), indexDrawn(card1, card2, drawn)); // removes the 2 cards from the drawn pile

      if (drawn.size() == 1){ // the drawn pile is down to 1 card, so we have to check if it is equal to 24 or not
        if (drawn[0] == 24){
          score++;
          solved++;
          cout << endl;
          printDivider();
          printCongrats();
          cout << endl;
        }
        else{
          cout << "You ended up with " << drawn[0] << ". Try again to get 24." << endl; // restart
          drawn = copy;
        }
      }
    } // end of one round loop

    printDivider();

  } // end of game loop

}

int main(){

  //
  // WELCOME SCREEN
  //

  printWelcome();

  cout << "Enter RULES to read the rules and instructions." << endl;
  cout << "Enter PLAY to start the game." << endl;
  cout << "Enter EXIT to exit the program." << endl << endl;

  string input;

  cin >> input;


  while ((input != "rules") && (input != "RULES") && (input != "play") &&
  (input != "PLAY") &&  (input != "exit") &&  (input != "EXIT")){ // checks that the input is valid
    cout << "Please enter a valid input." << endl;
    cout << "Enter RULES to read the rules and instructions." << endl;
    cout << "Enter PLAY to start the game." << endl;
    cout << "Enter EXIT to exit the program." << endl;
    cin >> input;
  }

  if((input == "exit") || (input == "EXIT")){
    return 0;
  }

  //
  // RULES SCREEN
  //

  if((input == "rules") || (input == "RULES")){
        printRules();
        cin >> input;

        while ((input != "play") && (input != "PLAY")){
          cout << "Please enter PLAY when you are ready to play: ";
          cin >> input;
        }
  }

  //
  // STARTING GAMEPLAY
  //

  if((input == "PLAY") || (input == "play")){
      printStart();
      playGame();
  }

}
