//============================================================================
// Name        : DS_Week3_HW1.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : Your copyright notice
// Description : Phone Book Assignment in C++, Ansi-style
/*
Task. In this task your goal is to implement a simple phone book manager. It should be able to process
the following types of user’s queries:
    • add number name. It means that the user adds a person with name name and phone number
      number to the phone book. If there exists a user with such number already, then your manager
      has to overwrite the corresponding name.
    • del number. It means that the manager should erase a person with number number from the
      phone book. If there is no such person, then it should just ignore the query.
    • find number. It means that the user looks for a person with phone number number. The manager
      should reply with the appropriate name, or with string “not found” (without quotes) if there is
      no such person in the book.
Input Format. There is a single integer N in the first line — the number of queries. It’s followed by N
lines, each of them contains one query in the format described above.
Constraints. 1 ≤ N ≤ 105
. All phone numbers consist of decimal digits, they don’t have leading zeros,
and each of them has no more than 7 digits. All names are non-empty strings of latin letters, and each
of them has length at most 15. It’s guaranteed that there is no person with name “not found”.

Output Format. Print the result of each find query — the name corresponding to the phone number or
“not found” (without quotes) if there is no person in the phone book with such phone number. Output
one result per line in the same order as the find queries are given in the input.
*/
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <list>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::list;

list <string> output;

void read_queries() {
    vector<string> name_hash(1e7);
    int n; int number; string name; string type;
    cin>>n;
    for(int i=0; i<n;i++){
        cin >> type;
        if(type == "add"){
            cin >> number >> name;
            name_hash[number]=name;
            //cout<<"adding elements"<<"\n";
        }
        if(type=="find"){
            cin >> number;
            if(name_hash[number]!=""){
                output.push_back(name_hash[number]);
                //cout<<"finding elements"<<"\n";
            }
            else{
                output.push_back("not found");
                //cout<<"not found to list"<<"\n";
            }
        }
        if(type=="del"){
            cin >> number;
            name_hash[number]="";
        }
    }
    //return queries;
}


//void write_responses(const vector<string>& result) {
void write_responses(){
    //cout<<"output size="<<output.size()<<"\n";
    //for (size_t i = 0; i < output.size(); ++i){
     while(!output.empty()){
        std::cout << output.front() << "\n";
        output.pop_front();
        //cout<<i<<"\n";
    }
}

int main() {
    //write_responses(process_queries(read_queries()));
    read_queries();
    write_responses();
    return 0;
}


