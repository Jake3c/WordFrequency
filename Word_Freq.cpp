//Word Frequency Prgram
//Programmer: Jake Carrico
//This program allows the user to analyze a text file for how many occurrences of each word are in the file.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void alphabetize(vector<string> &m); //alphabetizes the message
void removepunct(vector<string> &m); //removes all punctuation from message
void lowerall(vector<string> &m); //changes all characters to lowercase

int main(){
    ifstream infile;
    infile.open("paragraph.txt", ios::in); //opens the paragraph
    ofstream outfile;
    outfile.open("word_freq.txt", ios::out); //creates word frequency text file
    vector<string> message;
    string t; //temp string
    while(infile >> t){
        message.push_back(t); //fills the message vector with one word per slot
    }
    lowerall(message); //all words in vector become lowercase
    removepunct(message); //all punctuation is removed from vector
    alphabetize(message); //vector is alphabetized
    outfile << "Word" << '\t' << "     " << "Frequency" << '\n' << "-----------------------" << '\n' << '\n'; //formatting
    message.push_back("~"); //adds an extra string on the end to make algorithm work
    int n=0; //declares counter
    string temp = message[n]; //sets temp string equal to first word in vector
    int c=0; //will represent number of occurrence
    for(n=0; n<message.size(); n++){ //checks every word
        if(message[n] != temp){ //if current word does not equal the word before it (temp)
            if(message[n-1].size() <= 7){ //if statement that helps formatting
                outfile << temp << '\t' << '\t' << c << '\n'; //ultimately just output the word before it and its occurrence
            }
            if(message[n-1].size() >= 8){ //if statement that helps formatting
                outfile << temp << '\t' << c << '\n';
            }
            temp = message[n]; //resets temp to the current word
            c=0; //resets counter to 0
        }
        if(message[n] == temp){ //if the current word equals temp
           c++; //increment the occurrence counter
        }
    }
    return 0;
}

void alphabetize(vector<string> &m){
      bool f; //used as a flag
      do{
        f=true; //resets f to true
        for(int i=0; i<m.size()-1; i++){ //checks the whole array
            if(m[i] > m[i+1]){ //if the current word has a higher ascii value than the following word
                m[i].swap(m[i+1]); //swap the two words in the vector
                f=false; //changes f to false
            }
        }
    }while(f == false); //runs so long as there is a word to be swapped alphabetically
}

void removepunct(vector<string> &m){
    for(int i=0; i<m.size(); i++){ //checks every word
        for(int n=0; n<m[i].size(); n++){ //checks every character
            if(m[i][n] == '.' || m[i][n] == ',' || m[i][n] == ';' || //if the word ends in a punctuation mark
               m[i][n] == ':' || m[i][n] == '!' || m[i][n] == '?'){
                m[i].resize(m[i].length()-1); //cut off the punctuation mark at the end
            }
        }
    }
}

void lowerall(vector<string> &m){
    for(int i=0; i<m.size(); i++){ //checks every word
        for(int n=0; n<m[i].size(); n++){ //checks every character
            if(m[i][n] >= 65 && m[i][n] <= 90){ //if the character is capital
                m[i][n] = m[i][n]+32; //that character is replaced with its lowercase equivalent
            }
        }
    }
}
