#include "stdc++.h"
#include "MyArray.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {

    if (expenditure.empty()) return 0;
    if (d < 1) return 0;
    if (d <= 0) return 0;

    int count = 0;

    float median = 0;
    int warnings = 0;

    myArray *a =  new myArray(expenditure.data(), expenditure.size());

    for(int n : expenditure)
    {   
        if (n < 0 || n > 200) {
             warnings = 0;
             break;
        }

        if ((median != 0) && (n >= median * 2)) 
        {
            warnings++;
            std::cout << "warning: " << n << std::endl;
        }

        count++;
        if (count >= d) {
            int start = count - (d);
            int end   = start + (d);
            std::cout << "[ " << start << "," << end - 1 << " ]" << std::endl;
            vector<int> new_arr(expenditure.begin() + start, expenditure.begin() + end);
            sort (new_arr.begin(), new_arr.end());

            for (int k: new_arr) std::cout << k << " ";
            std::cout << std::endl;

            median  = (float(new_arr[(new_arr.size() - 1) / 2]) + float(new_arr[new_arr.size() / 2])) / 2;
            if (new_arr.size() % 2 != 0) median = new_arr[new_arr.size() / 2];

            std::cout << "Median: " << median << std::endl;
        }
        
        // std::cout << n << '\n';
    }

    // sort(expenditure.begin(), expenditure.end());

    return warnings;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

