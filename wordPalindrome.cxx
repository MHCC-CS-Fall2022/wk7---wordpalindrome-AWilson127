/*******************************************************************************
* Filename:   wordPalindrome.cxx
* Summary:    This program checks to see if the user input is a palindrome
*             word for word by checking the queue and stack and making sure
*             that they are the same word.
* Author:      Alen Wilson
* Date:        11/13/2022
*******************************************************************************/

#include <cassert>    // Provides assert
#include <cctype>     // Provides isalpha, toupper
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <iostream>   // Provides cout, cin, peek
#include <string>     // provides string
#include <queue>      // Provides the queue template class
#include <stack>      // Provides the stack template class
using namespace std;

int main( )
{
    // variables
    queue<string> q;
    stack<string> s;  
    string userInput; 
    string repeat; 
    queue<string>::size_type mismatches = 0; 
   
    // repeats so that the user can do it multiple times 
    do{      
	    cout << "Enter a line without commas and quotations:" << endl;
	    
            // takes the cin and makes it all uppercase and push into
            // queue and stack
	    while (cin.peek( ) != '\n')
	    {
	        cin >> userInput;
		for (int i = 0; i < userInput.length(); i++)
		    userInput.at(i) = toupper(userInput.at(i));
		q.push(userInput);
		s.push(userInput);
		
	    }

            // checls both queue and stack to see if they are the same until
            // they are empty
	    while ((!q.empty( )) && (!s.empty( )))
	    {
		if (q.front( ) != s.top( ))
		    ++mismatches;
		q.pop( );
		s.pop( );
	    }

            // tells the user if it is a palindrome or not
	    if (mismatches == 0)
	    {
		cout << "That is a palindrome." << endl;
		
	    }
	    else
	    {
		cout << "That is not a palindrome." << endl; 
	    } 
	    
	    // asks the user if they want to repeat
	    cout << "Do you want to run this again? (y or n)  ";
	    cin >> repeat;
	    cin.ignore(80, '\n');
	    
	    
    } while (repeat == "y" || repeat == "Y"); 
        
    return EXIT_SUCCESS;
}
