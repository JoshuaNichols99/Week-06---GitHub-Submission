// Week 06 - Programming Assignment.cpp from Joshua Nichols.
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int NUMBER_OF_BOWLERS = 10; // Column.
const int NUMBER_OF_SCORES = 5; // Row.
// Declaring Void Functions.
void GetBowlingData(string bowlerName[NUMBER_OF_BOWLERS], int bowlerScore[NUMBER_OF_BOWLERS][NUMBER_OF_SCORES]);
void GetAverageScore(int bowlerScore[NUMBER_OF_BOWLERS][NUMBER_OF_SCORES], double bowlerAverage[NUMBER_OF_BOWLERS]);
void PrettyPrintResults(string bowlerName[NUMBER_OF_BOWLERS] ,int bowlerScore[NUMBER_OF_BOWLERS][NUMBER_OF_SCORES], double bowlerAverage[NUMBER_OF_BOWLERS]);
int main(){
    cout << setw(25) << setfill('*') << "" << endl;
    cout << setw(4) << setfill('*') << "" << " Bowler's Scores " << setw(4) << setfill('*') << "" << endl;
    cout << setw(25) << setfill('*') << "" << endl;
    // Declared Arrays.
    string bowlerName[NUMBER_OF_BOWLERS];
    int bowlerScore[NUMBER_OF_BOWLERS][NUMBER_OF_SCORES];
    double bowlerAverage[NUMBER_OF_BOWLERS];
    // Calling Void Functions.
    GetBowlingData(bowlerName, bowlerScore);
    GetAverageScore(bowlerScore, bowlerAverage);
    PrettyPrintResults(bowlerName,bowlerScore, bowlerAverage);
}
void GetBowlingData(string bowlerName[NUMBER_OF_BOWLERS], int bowlerScore[NUMBER_OF_BOWLERS][NUMBER_OF_SCORES]) {
    ifstream inFile("BowlingScores.txt");
    // Extracts variables from txt file and puts them into a one-dimensional array and a two-dimensional array.
    for (int i = 0; i < NUMBER_OF_BOWLERS; i++) {
        inFile >> bowlerName[i]; 
        for (int j = 0; j < NUMBER_OF_SCORES; j++) {
            inFile >> bowlerScore[i][j];
        }
    }
    inFile.close();
}
void GetAverageScore(int bowlerScore[NUMBER_OF_BOWLERS][NUMBER_OF_SCORES], double bowlerAverage[NUMBER_OF_BOWLERS]) {
    // Averages bowler's score by summing up total and dividing it by number of scores.
    for(int i = 0; i < NUMBER_OF_BOWLERS; i++) {
        double total = 0.0;
        for(int j = 0; j < NUMBER_OF_SCORES; j++) {
            total = total + bowlerScore[i][j];
        }
        double average = total / NUMBER_OF_SCORES;
        bowlerAverage[i] = average;
    } 
}
void PrettyPrintResults(string bowlerName[NUMBER_OF_BOWLERS], int bowlerScore[NUMBER_OF_BOWLERS][NUMBER_OF_SCORES], double bowlerAverage[NUMBER_OF_BOWLERS]){
    // Displays bowler's final results. 
    for (int i = 0; i < NUMBER_OF_BOWLERS; i++) {
        cout << setw(25) << setfill('*') << "" << endl;
        cout << "Bowler's Name: " << bowlerName[i] << endl;
        cout << "Score: ";
        for (int j = 0; j < NUMBER_OF_SCORES; j++) {
            cout << bowlerScore[i][j] << " ";
        }
        cout << endl;
        cout << "Average Score: " << bowlerAverage[i] << endl;
        cout << setw(25) << setfill('*') << "" << endl;
    }
    cout << setw(7) << setfill('*') << "" << " COMPLETED " << setw(7) << setfill('*') << "" << endl;
}
// No visuals were present in instructions of programming assginment.
// Don't know if you wanted a float or intger of  average score per bowler.
