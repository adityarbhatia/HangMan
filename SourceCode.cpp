
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


int main() {
    
    string guess;
    int incorrect_entry = 0;
    string word;
    string unsolvedBlank;

    cout << "Enter the word for the other player to guess\n";
    
    
    getline(cin, word);
    
    string copy = word;
    
    for(int index = 0; index!=word.length(); index++)
    {
        
        if(word.at(index)==' ')
        {
            unsolvedBlank += " ";
        }
        else
        {
            unsolvedBlank +="_";
        }
    }
    
    for(int index = 0; index<25; index++)
    {
        cout << endl;
    }
    
    
    
    while(1)
    {
        if(incorrect_entry==6)
        {
            cout << "You lose! The word was: "<< word << endl;
            break;
        }    
        
        cout << "\t\t\t\t" << unsolvedBlank <<endl;
        cout << "There are "<<word.length()<<" letters with spaces"<< endl;
        cout << "You have " << 6-incorrect_entry << " more tries left" << endl;
        
        
        if(unsolvedBlank==word)
        {
            cout << "You win!" << endl;
            break;
        }
        
        cout << "Guess a letter or a word" << endl;
        getline(cin, guess);
        
        
        if(guess.length()>1)
        {
            if(guess == word)
            {
                cout << "That's right, you win!" << endl;
                break;
            }
            else
            {
            cout <<"incorrect_entry word" <<endl;
            incorrect_entry++;
            }
        }

        else if(copy.find(guess) != -1)
        {
            while(copy.find(guess)!= -1)
            {
                unsolvedBlank.replace(copy.find(guess), 1, guess);
                copy.replace(copy.find(guess), 1, "_");
            }
        }
        else
        {
        cout << "That's wrong!" << endl;
        incorrect_entry++;
        }
        
        
        cout << endl; 
}
        
    return 0;
}

