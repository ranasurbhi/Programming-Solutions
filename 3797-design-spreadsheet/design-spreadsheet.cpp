#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
    bool isnum(string s){
        if (s.empty()) return false; 
        for (char c : s) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
        sheet.resize(26, vector<int>(rows, 0)); // allow multiple rows
    }
    
    void setCell(string cell, int value) {
        string temp = "";
        for (int i = 1; i < cell.size(); i++) temp += cell[i];
        int row = cell[0] - 'A';
        int col = stoi(temp) - 1;
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        string temp = "";
        for (int i = 1; i < cell.size(); i++) temp += cell[i];
        int row = cell[0] - 'A';
        int col = stoi(temp) - 1;
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        string a = "";
        string b = "";
        int one = 0;
        int two = 0;
        int i;
        for (i = 1; i < formula.size(); i++) {
            if (formula[i] == '+') break;
            a += formula[i];
        }
        for (i = i + 1; i < formula.size(); i++) {
            b += formula[i];
        }

        if (isnum(a)) one = stoi(a);
        else {
            string temp = "";
            for (int j = 1; j < a.size(); j++) temp += a[j];
            int row = a[0] - 'A';
            int col = stoi(temp) - 1;
            one = sheet[row][col];
        }

        if (isnum(b)) two = stoi(b);
        else {
            string temp = "";
            for (int j = 1; j < b.size(); j++) temp += b[j];
            int row = b[0] - 'A';
            int col = stoi(temp) - 1;
            two = sheet[row][col];
        }

        return one + two;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
