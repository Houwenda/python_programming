using namespace std;
#include <iostream>
#include <cstring>
#define ELEMENT_TYPE int
#define MAX_X 5
#define MAX_Y 5

typedef struct {
	int x,y;
	ELEMENT_TYPE element;
}Triple; 

typedef struct {
	Triple triples[MAX_X * MAX_Y];
	int count;
}Matrix;

void AddMatrix(Matrix matrix1,Matrix matrix2,ELEMENT_TYPE result[][MAX_Y]) {
	//初始化结果矩阵
	memset(result, 0, sizeof(ELEMENT_TYPE) * MAX_X * MAX_Y);
	//遍历matrix1矩阵 
	for(int i=0;i<matrix1.count;i++) {
		int line = matrix1.triples[i].x;
		int column = matrix1.triples[i].y;
		//ELEMENT_TYPE sum = matrix1.triples[i].element + *(result + line*MAX_X + column);
		//result[line*MAX_X + column] = sum;
		//cout<<line<<" "<<column<<endl;
		result[line][column] += matrix1.triples[i].element;
	}
	//遍历matrix2矩阵
	for(int i=0;i<matrix2.count;i++) {
		int line = matrix2.triples[i].x;
		int column = matrix2.triples[i].y;
		result[line][column] += matrix2.triples[i].element;
	}
}

int main() {
	ELEMENT_TYPE result[MAX_X][MAX_Y]; 
	Matrix matrix1, matrix2;
	//初始化matrix1 
	matrix1.triples[0].element = 1;
	matrix1.triples[0].x = 0;
	matrix1.triples[0].y = 0;
	
	matrix1.triples[1].element = 2;
	matrix1.triples[1].x = 3;
	matrix1.triples[1].y = 2;
	
	matrix1.count = 2;
	//初始化matrix2 
	matrix2.triples[0].element = 3;
	matrix2.triples[0].x = 2;
	matrix2.triples[0].y = 3;
	
	matrix2.triples[1].element = 4;
	matrix2.triples[1].x = 3;
	matrix2.triples[1].y = 2;
	
	matrix2.triples[2].element = 5;
	matrix2.triples[2].x = 4;
	matrix2.triples[2].y = 4;
	
	matrix2.count = 3;
	//相加 
	AddMatrix(matrix1, matrix2, result);
	//输出结果 
	for(int i=0;i<MAX_X;i++) {
		for(int j=0;j<MAX_Y;j++)
			cout<<result[i][j]<<" ";
		cout<<endl;	
	}
		
	return 0;
} 
