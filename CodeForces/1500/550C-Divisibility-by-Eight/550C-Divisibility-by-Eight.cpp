

#include "500C-Divisibility-by-Eight.h"

void divisibility(std::istream &is, std::ostream &os) {

    string input;
    is >> input;
    vector<string> substrings{input};
    int idx = 0;

    while (idx < substrings.size()) {
        string tempString = substrings[idx];
        int tempStringSize = tempString.size();
        if (tempStringSize >= 3) {
            string last3Digits = tempString.substr(tempStringSize - 3);
            int last3AsInt = stoi(last3Digits);

            if (last3AsInt % 8 == 0) {
                cout << "YES\n" << tempString;
                return;
            }

            string newString1 = tempString;
            newString1.erase(tempStringSize-1, 1);

            string newString2 = tempString;
            newString2.erase(tempStringSize-2, 1);

            string newString3 = tempString;
            newString3.erase(tempStringSize-3, 1);
            bool found1 = false;
            bool found2 = false;
            bool found3 = false;
            for (unsigned i = substrings.size() - 1; i >= 0; i--) {
                string compareString = substrings[i];
                if(compareString.size() > newString1.size()){
                    break;
                }
                if (compareString == newString1){
                    found1 = true;
                }
                if (compareString == newString2){
                    found2 = true;
                }
                if (compareString == newString3){
                    found3 = true;
                }
            }
            if(!found1){
                substrings.emplace_back(newString1);
            }
            if(!found2){
                substrings.emplace_back(newString2);
            }
            if(!found3){
                substrings.emplace_back(newString3);
            }
        } else if(tempStringSize == 2){
            string last2Digits = tempString.substr(tempStringSize - 2);
            int last2AsInt = stoi(last2Digits);

            if (last2AsInt % 8 == 0) {
                cout << "YES\n" << tempString;
                return;
            }

            string newString1 = tempString;
            newString1.erase(tempStringSize-1, 1);

            string newString2 = tempString;
            newString2.erase(tempStringSize-2, 1);

            bool found1 = false;
            bool found2 = false;

            for (unsigned i = substrings.size() - 1; i >= 0; i--) {
                string compareString = substrings[i];
                if(compareString.size() > newString1.size()){
                    break;
                }
                if (compareString == newString1){
                    found1 = true;
                }
                if (compareString == newString2){
                    found2 = true;
                }

            }
            if(!found1){
                substrings.emplace_back(newString1);
            }
            if(!found2){
                substrings.emplace_back(newString2);
            }
        } else if(tempStringSize == 1){
            string last1Digit = tempString.substr(tempStringSize - 1);
            int last1AsInt = stoi(last1Digit);

            if (last1AsInt % 8 == 0) {
                cout << "YES\n" << tempString;
                return;
            }

            string newString1 = tempString;
            newString1.erase(tempStringSize-1, 1);

            bool found1 = false;

            for (unsigned i = substrings.size() - 1; i >= 0; i--) {
                string compareString = substrings[i];
                if(compareString.size() > newString1.size()){
                    break;
                }
                if (compareString == newString1){
                    found1 = true;
                }
            }
            if(!found1){
                substrings.emplace_back(newString1);
            }
        }

        idx++;
    }

    cout << "NO";


}