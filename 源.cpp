#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

// 预处理测试
#define SUB(x,y) (x-y)
#define ACCESS_BEFORE(element,offset,value) *SUB(&element,offset) =value

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;
};



class KMP_alg {
private:
	void computeLPSArray(char* pat, int M, int* lps) {

		int len = 0;

		lps[0] = 0;

		int i = 1;
		while (i < M) {
			if (pat[i] == pat[len]) {
				len++;
				lps[i] = len;
				i++;
			}
			else {
				if (len != 0) {
					len = lps[len - 1];
				}
				else {
					lps[i] = 0;
					i++;
				}
			}
		}
	}

public:
	void KMPSearch(char* pat, char* txt) {
		int M = strlen(pat);
		int N = strlen(txt);

		int* lps = new int[M];
		computeLPSArray(pat, M, lps);

		int i = 0;
		int j = 0;
		while (i < N) {
			if (pat[j] == txt[i]) {
				j++;
				i++;
			}

			if (j == M) {
				cout << "Found pattern at index " << i - j << endl;
				j = lps[j - 1];
			}

			else if (i < N && pat[j] != txt[i]) {
				if (j != 0)
					j = lps[j - 1];
				else
					i++;
			}
		}

		delete[] lps;
	}

	
};

// 数组包含1,2,...,n除了m以外n-1个数，求m
int getLostNum(int arr[], int n) {
	int a, b;
	a = arr[0];
	b = 1;

	for (int i = 1; i < n - 1; i++) {
		a ^= arr[i];
	}

	for (int j = 2; j <= n; j++) {
		b ^= j;
	}
	
	return a ^ b;
}

// 数组包含1,2,...,n和m (1<=m<=n)共n+1个数，求m
int getExtraNum(int arr[], int n) {
	int a, b;
	a = arr[0];
	b = 1;

	for (int i = 1; i < n + 1; i++) {
		a ^= arr[i];
	}

	for (int j = 2; j <= n; j++) {
		b ^= j;
	}

	return a ^ b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

// 求数组连续最大和
int maxSubSum(int arr[], int len) {
	int all = arr[0];
	int end = arr[0];
	int i;

	for (i = 1; i < len; i++) {
		end = max(end + arr[i], arr[i]);
		all = max(end, all);
	}

	return all;
}

void partition(int arr[], int low, int high, int* pos) {
	int key = arr[low];
	while (low < high) {
		while (low < high && arr[high] > key) {
			high--;
		}
		arr[low] = arr[high];
		while (low < high && arr[low] < key) {
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = key;
	*pos = low;
}

// 数组逆序
void reverse(int arr[], int n) {
	int low = 0;
	int high = n - 1;
	while (low < high) {
		int temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
		low++;
		high--;
	}
}

void printArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

void swap(char* c1, char* c2) {
	char temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}

void permutation(char* str, char* pos) {
	char* p;
	
	if ('\0' == *pos) {
		printf("%s ", str);
	}
	else {
		for (p = pos; *p != '\0'; p++) {
			swap(p, pos);
			permutation(str, pos+1);
			swap(p, pos);
		}
	}
}
void Reverse_str(char* s) {
	char* p = s;
	char* c ;
	int len = 0;
	for (c = s; *c != '\0'; c++)
		len++;

	char* q = p + len - 1;

	for (; q > p; q--, p++) {
		*p = *p^*q;
		*q = *p^*q;
		*p = *p^*q;
	}
}

// sizeof例题
struct {
	short a1;
	short a2;
	short a3;
} A;

struct {
	long a1;
	short a2;
} B;


// 指针基本问题
// 和引用的区别：引用必须总是指向某些对象；指针指向的对象某些时候可能不指向任何对象
// （续）使用引用之前不需要测试其合法性；但指针应该总是被测试，防止其为空
// （续）引用总是指向在初始化时被指定的对象，以后不能改变，到那时指定的对象其内容可以改变；指针可以被重新赋值以指向另一个不同的对象
// （续）应用方向：A存不存在不指向任何对象的情况，B是否需要在不同时刻指向不同的对象

class Ac {
public:
	int _a;
	Ac() {
		_a = 1;
	}
	void print() {
		printf("%d\n", _a);
	}
};

class Bc : public Ac {
public:
	int _a;
	Bc() {
		_a = 2;
	}
};

int main() {
	int a;
	int b;
	
	return 0;
}