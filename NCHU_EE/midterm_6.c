#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void output(unsigned int n) {
	int i, bit[8];
	for(i=0; i<8; i++) {
		bit[i] = n % 2;
		n /= 2;
	}
	
	for(i=0; i<8; i++) {
		printf("%d", bit[8-i-1]);
	}
}



int main() {
	unsigned int n, arr[4], tmp, max_value;
	int i, j, count_one[4], min, flag;
	
	scanf("%x", &n);
	
	// ���o4��bytes 
	tmp = n;
	for(i=0; i<4; i++) {
		arr[i] = tmp & ((unsigned int)pow(2, 8)-1);
		tmp >>= 8;
	}
	
	// �p��C��byte�����O���h��1 �ӧO�x�s
	min = 9; // �N��9��1
	flag = 0;
	for(i=0; i<4; i++) {
		
		tmp = arr[i];
		count_one[i] = 0; // ��l�k�s 
		
		for(j=0; j<8; j++) {
			if(tmp % 2 == 1) // or " if(tmp & 1 == 1) "
				count_one[i] += 1; // �p�G�ثe���̧C�줸��1 ���N�W�[�@��count 
			tmp >>= 1; // or " tmp /= 2 "
		}
		
		if(count_one[i] < min) {
			min = count_one[i];
			flag = 0;
		}
		else if(count_one[i] == min) {
			flag = 1;
		}
	}
	
	if(flag) { // �p�G����ӥH�W���O���̤֭�1 ���N�n�A��ƭȤj�p
		max_value = 0;
		for(i=0; i<4; i++) {
			if(count_one[i] == min && arr[i] > max_value) {
				max_value = arr[i];
			}
		}
		output(max_value);
	}
	else {
		for(i=0; i<4; i++) {
			if(count_one[i] == min)
				output(arr[i]);
		}
	}
	
	return 0;
}
