#include <iostream>
#include <string>
#include <fstream>
#include<map>

using namespace std;
class WordRank{
    map<int, string> WordScores;

    public:
    void insertScore(int key,string word)
    {
        if (WordScores.find(key) != WordScores.end())
        {
            WordScores[key] += " " + word;
        }
        else
            WordScores[key] = word;
    }

    int findWordScore(string s){

        char scoreArray[26];
        int i = 0 , index, score = 0;
        for(i=0;i<26;i++){
            scoreArray[i] = i+1;
        }

        for(i = 0 ; i < s.length() ; i++){
            index = s[i] - 'a';
            score += scoreArray[index];
        }
        return score;
    }


    void printWordScores()
    {
        for (map<int, string>::iterator ii = WordScores.begin(); ii != WordScores.end(); ++ii)
        {
            string s=(*ii).second;
            cout << (*ii).first << "  " << s << endl;
        }
    }
};

    int main(){

    ifstream inFile;
    inFile.open("input.txt");
    string line;
    WordRank obj;
    while (!inFile.eof())
    {
        getline(inFile, line);
        int key = obj.findWordScore(line);
        obj.insertScore(key,line);
     }

   obj.printWordScores();
   return 0;
}
