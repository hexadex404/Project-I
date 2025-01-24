// Description
// Data about submission of a programming contest consists a sequence of lines, each line has the following information:
//                                                       <UserID> <ProblemID> <TimePoint> <Status> <Point>
// in which the user <UserID> submits his/her code to solve the problem <ProblemID> at time-point <TimePoint>, and gets status <Status> and point <Point>
// <UserID>: string of length from 3 to 10
// <ProblemID>: string under the format Pxy where x, y are digits 0,1,...,9 (for example P03, P10)
// <TimePoint>: string representing time-point with the format HH:MM:SS (for example, 09:45:20 means the time-point 9 hour 45 minutes 20 seconds)
// <Status>: string with two cases (ERR, OK)
// <Point>: integer from {0, 1, 2, ..., 10}

// A user can submit the code for solving each problem several time. The point that the user gets for a problem is the maximal point among the submissions for that problem.

// Perform a sequence of queries of following types:
// ?total_number_submissions: return the number of submissions of the contest
// ?number_error_submision: return the number of submissions having status ERR
// ?number_error_submision_of_user <UserID>: return the number of submission having status ERR of user <UserID>
// ?total_point_of_user <UserID>: return the total point of user <UserID>
// ?number_submission_period <from_time_point> <to_time_point>: return the number of submissions in the period from <from_time_point> to <to_time_point> (inclusive)

// Input
// The input consists of two blocks of data:
// The first block is the operational data, which is a sequence of lines (number of lines can be up to 100000), each line contains the information of a submission with above format .The first block is terminated with a line containing the character #
// The second block is the query block, which is a sequence of lines (number of lines can be up to 100000), each line is a query described above. The second block is terminated with a line containing the character #

// Output
// Write in each line, the result of the corresponding query

// Example
// Input
// U001 P01 10:30:20 ERR 0
// U001 P01 10:35:20 OK 10
// U001 P02 10:40:20 ERR 0
// U001 P02 10:55:20 OK 7
// U002 P01 10:40:20 ERR 0
// U001 P01 11:35:20 OK 8
// U002 P02 10:40:20 OK 10
// #
// ?total_number_submissions
// ?number_error_submision
// ?number_error_submision_of_user U002
// ?total_point_of_user U001
// ?number_submission_period 10:00:00 11:30:45
// #

// Output
// 7
// 3
// 1
// 17
// 6

#include <bits/stdc++.h>
using namespace std;

struct Submission
{
    string userID;
    string problemID;
    string timePoint;
    string status;
    int point;
};

vector<Submission> submissions;
unordered_map<string, unordered_map<string, int>> totalPointOfUserinProblem;
unordered_map<string, int> totalPointofUser;
unordered_map<string, int> numberErrorSubmissionOfUser;
int totalNumberSubmissions = 0;
int numberErrorSubmission = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while (getline(cin, line))
    {
        if (line == "#")
        {
            break;
        }
        stringstream ss(line);
        string userID, problemID, timePoint, status;
        int point;
        ss >> userID >> problemID >> timePoint >> status >> point;
        submissions.push_back({userID, problemID, timePoint, status, point});
        totalNumberSubmissions++;
    }

    std::sort(submissions.begin(), submissions.end(), [](const Submission &a, const Submission &b)
              { return a.timePoint < b.timePoint; });

    for (auto submission : submissions)
    {
        int grade = totalPointOfUserinProblem[submission.userID][submission.problemID];
        if (grade < submission.point)
        {
            totalPointofUser[submission.userID] += submission.point - grade;
            totalPointOfUserinProblem[submission.userID][submission.problemID] = submission.point;
        }
        if (submission.status == "ERR")
        {
            numberErrorSubmissionOfUser[submission.userID]++;
            numberErrorSubmission++;
        }
    }
    while (getline(cin, line))
    {
        if (line == "#")
        {
            break;
        }
        stringstream ss(line);
        string query;
        ss >> query;
        if (query == "?total_number_submissions")
        {
            cout << totalNumberSubmissions << "\n";
        }
        else if (query == "?number_error_submision")
        {
            cout << numberErrorSubmission << "\n";
        }
        else if (query == "?number_error_submision_of_user")
        {
            string userID;
            ss >> userID;
            cout << numberErrorSubmissionOfUser[userID] << "\n";
        }
        else if (query == "?total_point_of_user")
        {
            string userID;
            ss >> userID;
            int total = 0;
            cout << totalPointofUser[userID] << "\n";
        }
        else if (query == "?number_submission_period")
        {
            string from_time, to_time;
            ss >> from_time >> to_time;
            Submission from_submission, to_submission;
            from_submission.timePoint = from_time;
            to_submission.timePoint = to_time;

            auto compare = [](const Submission &a, const Submission &b)
            {
                return a.timePoint < b.timePoint;
            };

            auto first_submission = std::lower_bound(submissions.begin(), submissions.end(), from_submission, compare) - submissions.begin();
            auto last_submission = std::upper_bound(submissions.begin(), submissions.end(), to_submission, compare) - submissions.begin() - 1;

            cout << last_submission - first_submission + 1 << "\n";
        }
    }
}
