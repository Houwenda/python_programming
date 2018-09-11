using namespace std;
#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>

//解决负号问题  (-1
string negative_number(string input){
	int i;
	while(i<input.length()){
		if(input[i]=='('&&input[i+1]=='-'&&input[i+2]>='0'&&input[i+2]<='9'){
			string input_left = input.substr(0,i+1);
			string input_right = input.substr(i+1);
//			cout<<input_left<<endl;
//			cout<<input_right<<endl;	
			input = input_left + '0' +input_right;
//			cout<<input;
		}
		i++;
	}
	return input;
}

int operator_priority(char x){

	if(x=='+'||x=='-') return 1;
	else if(x=='*'||x=='/') return 2;
	else if(x=='^') return 3;
	else if(x=='(') return 0;
	return -1;
}

int compare_priority(char a, char b){
	if(operator_priority(a) <= operator_priority(b)) return 1;
	else return 0;
}

double calculate(string input){

	stack<char> ope;
	stack<double> number;
	char tmp[20];
	double tmp_num;
	int i,j;
	
	input = negative_number(input);
	
	for(i=0;i<input.length();i++){
		
		//数字
		if(input[i]>='0'&&input[i]<='9'){
			j = 0;
			while((input[i+j]>='0'&&input[i+j]<='9')||input[i+j]=='.'){
				tmp[j] = input[i+j];
				j++;
			}
			tmp[j] = 0;
			sscanf(tmp, "%lf", &tmp_num);
			number.push(tmp_num);
			i = i + j -1;
		}
		//符号
		else{
			if(input[i]=='('){
				ope.push(input[i]);
				continue;
			}
			bool flag = false;
			while(!ope.empty()&&compare_priority(input[i], ope.top())){
				char ch = ope.top();
				if(input[i]==')'){
					if(flag) break;
					if(ch=='(') flag = true;
				}
				ope.pop();
				if(ch == '*'){
					double x = number.top();
					number.pop();
					double y = number.top();
					number.pop();
					number.push(x*y);
				}
				if (ch == '/'){
            		double x = number.top();
					number.pop();
            		double y = number.top();
					number.pop();
            		number.push(y / x);
        		}
        		if (ch == '+'){
            		double x = number.top();
					number.pop();
            		double y = number.top();
					number.pop();
            		number.push(x + y);
        		}
        		if (ch == '-'){
          			double x = number.top();
					number.pop();
          			double y = number.top();
					number.pop();
          			number.push(y - x);
        		}
        		if (ch == '^'){
            		double exp = number.top();
            		number.pop();
            		double base = number.top();
          			number.pop();
            		number.push(pow(base, exp));
				}
			}
			if(input[i] != ')') ope.push(input[i]);
		}

	}

	return number.top();
}

//将double数转换为字符串 
string double_to_string(double num){	
	char str[256];
    sprintf(str, "%lf", num);
    string result = str;
    return result;
}


//sin -> s 
//cos -> c
//tan -> t
//ln -> l
//arctan -> a
//exp -> e
string shorten_function(string str){
	
	int i,j,length;
	string str_left,str_right;
	length = str.length();
	i = 0;
	while(i<length){
		//sin()
		if(str[i] == 's'){
			if(str[i+1]=='i'&&str[i+2]=='n'&&str[i+3]=='('){
				str_left = str.substr(0,i);
				str_right = str.substr(i+3);
				str = str_left + 's' +str_right;
				i = 0;
				continue;
			} 
		}
		//cos()
		else if(str[i] == 'c'){
			if(str[i+1]=='o'&&str[i+2]=='s'&&str[i+3]=='('){
				str_left = str.substr(0,i);
				str_right = str.substr(i+3);
				str = str_left + 'c' +str_right;
				i = 0;
				continue;
			}
		}
		//tan()
		else if(str[i] == 't'){
			if(str[i+1]=='a'&&str[i+2]=='n'&&str[i+3]=='('){
				str_left = str.substr(0,i);
				str_right = str.substr(i+3);
				str = str_left + 't' +str_right;
				i = 0;
				continue;
			}
		}
		//ln()
		else if(str[i] == 'l'){
			if(str[i+1]=='n'&&str[i+2]=='('){
				str_left = str.substr(0,i);
				str_right = str.substr(i+2);
				str = str_left + 'l' +str_right;
				i = 0;
				continue;
			}
		}
		//arctan()
		else if(str[i] == 'a'){
			if(str[i+1]=='r'&&str[i+2]=='c'&&str[i+3]=='t'&&str[i+4]=='a'&&str[i+5]=='n'&&str[i+6]=='('){
				str_left = str.substr(0,i);
				str_right = str.substr(i+6);
				str = str_left + 'a' +str_right;
				i = 0;
				continue;
			}
		}
		//exp()
		else if(str[i] == 'e'){
			if(str[i+1]=='x'&&str[i+2]=='p'&&str[i+3]=='('){
				str_left = str.substr(0,i);
				str_right = str.substr(i+3);
				str = str_left + 'e' +str_right;
				i = 0;
				continue;
			}
		}
		i++;
	}
	return str;
}

//s(1+s(x+(1+1)))
//s(s())
//sin() cos() tan() arctan() ln() exp()
string function_convert(string input){
	
	double tmp_result;
	string tmp_str;
//	input = shorten_function(input);
	int i = input.length() - 4;
	string tmp;
	char tmp1[20];
	while(i >= 0){
		//sin()
		if(input[i]=='s'){
			int j = 2;
			int count=1;
//			tmp.append(a,1);
			tmp1[0] = '(';

			while(count!=0){
				if(input[i+j]=='(') count++;
				else if(input[i+j]==')') count--;
				
//				tmp.append(input,i+j,1);
				tmp1[j-1] = input[i+j];
				j++;
			}
			tmp1[j-1] = '\0';
//			cout<<tmp1<<endl;
			
			tmp = tmp1;
			
			tmp_result = calculate(tmp);
			tmp_result = sin(tmp_result);	
			tmp_str = double_to_string(tmp_result);
			
			string input_left = input.substr(0,i);
			string input_right = input.substr(i+j);
			
//			cout<<input_left<<endl;
//			cout<<input_right<<endl;
//			cout<<tmp_str<<endl;
			
			input = input_left + '(' + tmp_str + ')' + input_right;
			i = input.length()-4;
			continue;
		}
		//cos()
		else if(input[i]=='c'){
			int j = 2;
			int count=1;
//			tmp.append(a,1);
			tmp1[0] = '(';

			while(count!=0){
				if(input[i+j]=='(') count++;
				else if(input[i+j]==')') count--;
				
//				tmp.append(input,i+j,1);
				tmp1[j-1] = input[i+j];
				j++;
			}
			tmp1[j-1] = '\0';
//			cout<<tmp1<<endl;
			
			tmp = tmp1;
			
			tmp_result = calculate(tmp);
			tmp_result = cos(tmp_result);	
			tmp_str = double_to_string(tmp_result);
			
			string input_left = input.substr(0,i);
			string input_right = input.substr(i+j);
			
//			cout<<input_left<<endl;
//			cout<<input_right<<endl;
//			cout<<tmp_str<<endl;
			
			input = input_left + '(' + tmp_str + ')' + input_right;
			i = input.length()-4;
			continue;
		} 
		//tan()
		else if(input[i]=='t'){
			int j = 2;
			int count=1;
//			tmp.append(a,1);
			tmp1[0] = '(';

			while(count!=0){
				if(input[i+j]=='(') count++;
				else if(input[i+j]==')') count--;
				
//				tmp.append(input,i+j,1);
				tmp1[j-1] = input[i+j];
				j++;
			}
			tmp1[j-1] = '\0';
//			cout<<tmp1<<endl;
			
			tmp = tmp1;
			
			tmp_result = calculate(tmp);
			tmp_result = tan(tmp_result);	
			tmp_str = double_to_string(tmp_result);
			
			string input_left = input.substr(0,i);
			string input_right = input.substr(i+j);
			
//			cout<<input_left<<endl;
//			cout<<input_right<<endl;
//			cout<<tmp_str<<endl;
			
			input = input_left + '(' + tmp_str + ')' + input_right;
			i = input.length()-4;
			continue;
		}
		//arctan()
		if(input[i]=='a'){
			int j = 2;
			int count=1;
//			tmp.append(a,1);
			tmp1[0] = '(';

			while(count!=0){
				if(input[i+j]=='(') count++;
				else if(input[i+j]==')') count--;
				
//				tmp.append(input,i+j,1);
				tmp1[j-1] = input[i+j];
				j++;
			}
			tmp1[j-1] = '\0';
//			cout<<tmp1<<endl;
			
			tmp = tmp1;
			
			tmp_result = calculate(tmp);
			tmp_result = atan(tmp_result);	
			tmp_str = double_to_string(tmp_result);
			
			string input_left = input.substr(0,i);
			string input_right = input.substr(i+j);
			
//			cout<<input_left<<endl;
//			cout<<input_right<<endl;
//			cout<<tmp_str<<endl;
			
			input = input_left + '(' + tmp_str + ')' + input_right;
			i = input.length()-4;
			continue;
		}
		//exp()
		else if(input[i]=='e'){
			int j = 2;
			int count=1;
//			tmp.append(a,1);
			tmp1[0] = '(';

			while(count!=0){
				if(input[i+j]=='(') count++;
				else if(input[i+j]==')') count--;
				
//				tmp.append(input,i+j,1);
				tmp1[j-1] = input[i+j];
				j++;
			}
			tmp1[j-1] = '\0';
//			cout<<tmp1<<endl;
			
			tmp = tmp1;
			
			tmp_result = calculate(tmp);
			tmp_result = exp(tmp_result);	
			tmp_str = double_to_string(tmp_result);
			
			string input_left = input.substr(0,i);
			string input_right = input.substr(i+j);
			
//			cout<<input_left<<endl;
//			cout<<input_right<<endl;
//			cout<<tmp_str<<endl;
			
			input = input_left + '(' + tmp_str + ')' + input_right;
			i = input.length()-4;
			continue;
		}
		//ln()
		else if(input[i]=='l'){
			int j = 2;
			int count=1;
			const char a='(';
//			tmp.append(a,1);
			tmp1[0] = '(';

			while(count!=0){
				if(input[i+j]=='(') count++;
				else if(input[i+j]==')') count--;
				
//				tmp.append(input,i+j,1);
				tmp1[j-1] = input[i+j];
				j++;
			}
			tmp1[j-1] = '\0';
//			cout<<tmp1<<endl;
			
			tmp = tmp1;
			
			tmp_result = calculate(tmp);
			tmp_result = log(tmp_result);	
			tmp_str = double_to_string(tmp_result);
			
			string input_left = input.substr(0,i);
			string input_right = input.substr(i+j);
			
//			cout<<input_left<<endl;
//			cout<<input_right<<endl;
//			cout<<tmp_str<<endl;
			
			input = input_left + '(' + tmp_str + ')' + input_right;
			i = input.length()-4;
			continue;
		}
		else{
			i--;
		}

	}
	return input;
} 
 
//检查输入合法性 
bool check(char * str){
	int count,i;
	//第一个字符只能是x或数字或(	
	if(str[0]=='X'||str[0]=='('||(str[0]>='0'&&str[0]<='9')){} 
	else return false;
	
	//中间字符 
	for(i=1;i<strlen(str)-1;i++){
		if(str[i]=='X'){
			//每个x前只能是数字或+-或^或( 
			if(str[i-1]=='+'||str[i-1]=='-'||str[i-1]=='('||str[i-1]=='^'||(str[i-1]>='0'&&str[i-1]<='9')){}
			else{
				cout<<"before x"<<endl;
				return false;
			} 
			//每个x后只能是^或+-*/或)
			if(str[i+1]=='^'||str[i+1]=='+'||str[i+1]=='-'||str[i+1]==')'||str[i+1]=='*'||str[i+1]=='/'){} 
			else{
				cout<<"after x"<<endl; 
				return false;
			} 
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			//运算符号前只能是数字或x或) 
			if(str[i-1]=='X'||str[i-1]==')'||(str[i-1]>='0'&&str[i-1]<='9')){}
			else if(str[i]=='-'&&str[i-1]=='^'){}  //特殊 x^-2 
			else{
				cout<<"before sign"<<endl;
				return false;
			} 
			//运算符号后只能是数字或x或(
			if(str[i+1]=='X'||str[i+1]=='('||(str[i+1]>='0'&&str[i+1]<='9')){}
			else{
				cout<<"after sign"<<endl;
				return false;
			} 
		}
		else if(str[i]=='('){
			//每个(前只能是^或+-*/
			if(str[i-1]=='^'||str[i-1]=='+'||str[i-1]=='-'||str[i-1]=='*'||str[i-1]=='/'){}
			else{
				cout<<"before ("<<endl;
				return false;
			} 
			//每个(后只能是数字或x 
			if(str[i+1]=='X'||(str[i+1]>='0'&&str[i+1]<='9')){}
			else{
				cout<<"after ("<<endl;
				return false;
			}
		} 
		else if(str[i]==')'){
			//每个)前只能是数字或x
			if(str[i-1]=='X'||(str[i-1]>='0'&&str[i-1]<='9')){}
			else{
				cout<<"before )"<<endl;
				return false;
			}
			//每个)后只能是^或+-*/ 
			if(str[i+1]=='^'||str[i+1]=='+'||str[i+1]=='-'||str[i+1]=='*'||str[i+1]=='/'){}
			else{
				cout<<"after )"<<endl;
				return false;
			}
		}
		else if(str[i]=='^'){
			//每个^前只能是)或数字或x
			if(str[i-1]==')'||str[i-1]=='X'||(str[i-1]>='0'&&str[i-1]<='9')){}
			else{
				cout<<"before ^"<<endl;
				return false;
			}
			//每个^后只能是(或数字或x或-
			if(str[i+1]=='('||str[i+1]=='X'||str[i+1]=='-'||(str[i+1]>='0'&&str[i+1]<='9')){}
			else{
				cout<<"after ^"<<endl;
				return false;
			}
		}
		else if(str[i]=='.'){
			//每个.前后只能是数字 
			if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9'){}
			else{
				cout<<"near ."<<endl;
				return false;
			}
		}
	}
	
	//结尾字符只能是)或数字或x
	if(str[strlen(str)-1]==')'||str[strlen(str)-1]=='X'||(str[strlen(str)-1]>='0'&&str[strlen(str)-1]<='9')){}
	else return false;
	 
	//括号闭合问题
	i = 0;
	count = 0; 
	while(i<strlen(str)){
		if(str[i]=='(') count++;
		else if(str[i]==')') count--;
		
		if(count<0) return false;
		i++;
	} 
	if(count!=0){
		cout<<"buckets error"<<endl;
		return false;
	}
	
	return true; 
}

string replace_x(string str, double n){
	string num;
	int i;
	double k;
	//将double数转换为字符串 
	num = double_to_string(n);
	//cout<<num; 
	i = 0;
	while(i<str.length()){
		
		if(str[i]=='X'){
			string str_left = str.substr(0,i);
			string str_right = str.substr(i+1);
			str = str_left + '(' + num + ')' + str_right;
			i = 0;
		}
		else i++;
	}
	return str;
} 



int main(){

	string input;
/*
	string in;
	cin>>input;
	in = '(' + input + ")\0";
	cout<<in<<endl;
	cout<<calculate(in);
*/
/*
	double x;
	cin>>x;
	cout<<double_to_string(x);
*/

/*
	cin>>input;
	negative_number(input);
*/

	cin>>input;
	string out1 = replace_x(input,2);
	cout<<out1<<endl;
	string out2 = function_convert(shorten_function(out1));
	string input2 = '(' + out2 + ")\0";
	cout<<input2<<endl;
	cout<<calculate(input2)<<endl;

	return 0;
}
