#include "tappity.h"
#include <string>
#include <cmath>
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  ref_string = reference;
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
  input_string = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  int diff = abs(ref_string.length() - input_string.length());
  if (diff == 0) {return 0;}

  return diff;
}
//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{

  if (ref_string != input_string) {
    int num_of_correct = 0;

    if (ref_string.length() >= input_string.length()) {
      for (int i = 0; i < input_string.length(); i++)
      {
        /* Loop through each character within input_string and 
        count how many are correct and divide that amount by the 
        ref_string.length() to get the true accuracy */

        if (input_string[i] == ref_string[i])
        {
          num_of_correct++;
        } 
      }
      
      return double(num_of_correct / ref_string.length());

    } else if (ref_string.length() < input_string.length()) {
      for (int i = 0; i < ref_string.length(); i++)
      {
        if (input_string[i] == ref_string[i])
        {
          num_of_correct++;
        }
      }

      return double(num_of_correct / ref_string.length()); 
    }
  }

  return double(100); // If both strings are literally equal
}
