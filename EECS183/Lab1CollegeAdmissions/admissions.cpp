#include<iostream>
#include<iomanip>

using namespace std;

const double GPA_WEIGHT = 0.4;
const double SAT_WEIGHT = 0.3;
const double DEM_INTEREST_WEIGHT = 0.1;
const double CURRICULUM_STRENGTH_WEIGHT = 0.2;

int main(){
    double gpa = 0.0;
    double satScore = 0.0;
    int demonstratedInterest = 0;
    int curriculumStrength = 0;

    double normalizedGPA = 0.0;
    double normalizedSAT = 0.0;
    double normalizedInterest = 0.0;
    double normalizedCurriculum = 0.0;

    double totalScore = 0.0;

    cout << "College Admissions Calculator" << endl;

    cout << "Please enter your GPA out of 5.0:" << endl;
    cin >> gpa;

    cout << "Please enter your SAT score out of 1600:" << endl;
    cin >> satScore;

    cout << "Please enter your demonstrated interest out of 10:" << endl;
    cin >> demonstratedInterest;

    cout << "Please enter your high school curriculum strength out of 10:" << endl;
    cin >> curriculumStrength;

    normalizedGPA = gpa / 5.0;
    normalizedSAT = satScore / 1600.0;
    normalizedInterest = demonstratedInterest / 10.0;
    normalizedCurriculum = curriculumStrength / 10.0;

    totalScore = (normalizedGPA * GPA_WEIGHT) +
                (normalizedSAT * SAT_WEIGHT) +
                (normalizedInterest * DEM_INTEREST_WEIGHT) +
                (normalizedCurriculum * CURRICULUM_STRENGTH_WEIGHT);

    totalScore *= 100;

    if (totalScore >= 79.5 && totalScore < 80.5) {
        totalScore = 79.49;
    }

    cout << "Expected chance of admission: "<< fixed  << setprecision(0) <<  totalScore << "/100";
    return 0;
}