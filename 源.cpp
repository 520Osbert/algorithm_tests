#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

// Ԥ�������
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

// �������1,2,...,n����m����n-1��������m
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

// �������1,2,...,n��m (1<=m<=n)��n+1��������m
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

// ��������������
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

// ��������
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

// sizeof����
struct {
	short a1;
	short a2;
	short a3;
} A;

struct {
	long a1;
	short a2;
} B;


// ָ���������
// �����õ��������ñ�������ָ��ĳЩ����ָ��ָ��Ķ���ĳЩʱ����ܲ�ָ���κζ���
// ������ʹ������֮ǰ����Ҫ������Ϸ��ԣ���ָ��Ӧ�����Ǳ����ԣ���ֹ��Ϊ��
// ��������������ָ���ڳ�ʼ��ʱ��ָ���Ķ����Ժ��ܸı䣬����ʱָ���Ķ��������ݿ��Ըı䣻ָ����Ա����¸�ֵ��ָ����һ����ͬ�Ķ���
// ������Ӧ�÷���A�治���ڲ�ָ���κζ���������B�Ƿ���Ҫ�ڲ�ͬʱ��ָ��ͬ�Ķ���

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