/******************************* 

完成对形如 x^2+2^(x+1)-x^-1+3 的解析
sin cos tan cot log arctan等函数 

*******************************/

using namespace std;
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath> 
#include <algorithm>
#include <stack>
#define ms(a,b) memset(a,b,sizeof(a))



double sum=0; 
/*
void arithmetic(char * str,double x){
	int barrier=0,i;
	string tmp_str;
//	cout<<str<<endl;


}

//匹配括号中的内容进行递归  未完成 
void brackets(char * str,double x){
	

	for(barrier=0;barrier<strlen(str);barrier++){
		if(str[barrier]=='('){
			for(i=1;i<strlen(str)-barrier;i++){
				if(str[barrier+i]!=')') tmp_str +=  str[barrier+i];
				else break;
			}
		}
	}	 
}
*/

//将表达式中x替换为指定数字n 
char* replace_x(char * str, char * formula, double n){
	char num[20];
	int i,count,m,j;
	double k;
	//将double数转换为字符串 
	i = 0;
	m = int(n);  //小数点前的部分 
	while(m/10!=0){
		m /= 10;
		i++;
	} 
	count = i + 1;
	m = int(n);
	while(i>=0){
		num[i] = m%10 + '0';
		m /= 10;
		i--;
	}
	num[count] = '.';
	i = 0;
	k = n - int(n);  //小数点后的部分 
	k = floor(k * 10000.00000f + 0.5) / 10000.00000f;  //保留小数点后四位 
	while(k-int(k)!=0){
		k *= 10;
		i++;
	}
	num[count+i+1] = '\0';
	m = int(k);
	while(i>0){
		num[count+i] = m%10 + '0';
		m /= 10;
		i--;
	}
//  cout<<num; 
	count = 0;
	i= 0;
	while(i<strlen(str)){
		if(str[i]!='X'){
			formula[count] = str[i];
//			cout<<formula[count]<<endl;
			count++;
			i++;
		}
		//遇到x
		else{
			//x前为数字则补上*
			if(i!=0&&str[i-1]>='0'&&str[i-1]<='9'){
				formula[count] = '*';
//				cout<<formula[count]<<endl;
				count++;
				j = 0;
				while(j<strlen(num)){
					formula[count] = num[j];
//					cout<<formula[count]<<endl;
					count++;
					j++;
				}
				i++;
			}
			//直接替换x放入formula 
			else{
				j = 0;
				while(j<strlen(num)){
					formula[count] = num[j];
//					cout<<formula[count]<<endl;
					count++;
					j++;
				}
				i++;
			}
			count--;//直接替换多出一空位 
		}	
	} 
	formula[count] = '\0';
/*
	for(i=0;i<strlen(str);i++){
		if(str[i]!='X'){
			formula[i] = str[i];
		}
		//遇到x 
		else{
			//x前为数字则补上* 
			if(str[i-1]>='0'&&str[i-1]<='9'){
				str[i] = '*';
				i++;
				for(j=0;j<strlen(num);j++){
					formula[i] = num[j];
					i++;
				}
				i--; 
			}
			//直接替换x放入formula 
			else{
				for(j=0;j<strlen(num);j++){
					formula[i] = num[j];
					i++;
				}
				i--;
			} 
		}
			
	}
*/	 
	return formula; 
} 




//检查输入合法性 Y=X^2+2X+1
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

//检查输入合法性 a=sin(3X^2)
bool check_tri(char * str){
	//传入的str是三角函数括号中的内容，如sin(3X^2+(X^X))中的 3X^2+(X^X)
	return check(str);	
}

void throw_error1(){
	cout<<"invalid character"<<endl;
}
void throw_error2(){
	cout<<"invalid expression"<<endl;
}

int main(){
    char str[50],a;
    char formula[70];
    cin.getline(str,50);
//  cout<<str<<endl;
//	cout<<strlen(str)<<endl;
	
	//检查输入字符种类 
	for(int i=0;i<strlen(str);i++){
		a = str[i];
		if(a=='X'||a=='+'||a=='-'||a=='*'||a=='/'||a=='^'||a=='('||a==')'||(a>='0'&&a<='9')||a=='.'){}
		else{
			throw_error1();
			return 0;
		}
	}
	if(!check(str)){
		throw_error2();
		return 0;
	}
//	cout<<"check succeeded"<<endl; 
	cout<<replace_x(str, formula, 10);
//	calc(str,10);
    return 0;
}


















