#include <bits/stdc++.h>
using namespace std;


unordered_map<string, int>ds_variable;
unordered_map<string, string>ds_command;

int calculate(vector<string>&temp){
	int c_i;
	
	// temp.size() = 1, assigning
	if (temp.size() == 1){
		string assigned_to = temp[0];
		char c = assigned_to[0]; // the first letter of variable to be assigned
		if(isalpha(c)){
			c_i = ds_variable[assigned_to];
		}
		else{
			c_i = stoi(assigned_to); // convert string to int
		}
	}
		
	// temp.size() > 1 
	else{
		string a_str, sign, b_str;
		a_str = temp[0];
		sign = temp[1];
		b_str = temp[2];
		int a_i, b_i, c_i;
		if(isalpha(a_str[0])){
			int a_i = ds_variable[a_str];
		}
		else{
			int a_i = stoi(a_str);
		}
		
		if(isalpha(b_str[0])){
			int b_i = ds_variable[b_str];
		}
		else{
			int b_i = stoi(b_str);
		}
		
		
		if (sign == "+"){
			c_i = a_i + b_i; 
		}
		
		else if (sign == "-"){
			c_i = a_i - b_i;
		}
		
		else if (sign == "*"){
			c_i = a_i * b_i;
		}
		
		else if (sign == "/"){
			c_i = a_i / b_i;
		}
	}
	
	return c_i;
}

void run_command(string command){
	istringstream iss(command);
	
	string token;
	string type;
	string id; 
	iss >> id;
	iss >> type;
	
	ds_command[id] = command;
	// 	if lets x
	if (type == "LET"){
		string x, dump;
		iss >> x; iss >> dump; //load variable and "=" sign
		vector<string>temp;
		
		// insert all remaining strings to temp;
		while(iss>>dump){
			temp.push_back(dump);
		}
		
		int c_i = calculate(temp);
		ds_variable[x] = c_i;
	}
	
	// if Goto to
	else if (type == "IF"){
		string x, dump;
		iss >> x; 
		iss >> dump;
		vector<string>temp;
		while(iss>>dump){
			temp.push_back(dump);
		}
		// remove go to xxx from the vector temp
		for(int i = 0; i < 3; i++){
			temp.pop_back();	
		}

		string goto_id = temp[temp.size()-1];
		int c_i = calculate(temp);
		if(ds_variable[x] == c_i){
			run_command(goto_id);
		}
		
	}
	// if print varibale
	else{
		string text;
		getline(iss, text);
		if (text[0] == '"'){
			string sub_text = text.substr(0,text.size()-1);
			cout << sub_text;
		}
		else{
			int to_print = ds_variable[text];
			cout << to_print;
		}
		
		if (type == "PRINTLN"){
			cout << endl;
		}
		
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	string command;
	while(getline(cin, command) && command!=""){
		run_command(command);
	}
	return 0;
}

