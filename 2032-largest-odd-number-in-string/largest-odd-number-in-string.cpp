class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        string temp="";
        while(i>=0){
            temp+=num[i];
            int t=stoi(temp);
            if(t%2==0){
                num.pop_back();
                temp="";
            }
            else{
                break;
            }
            i--;
        }
        return num;
    }
};