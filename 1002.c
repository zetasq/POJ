#include "stdio.h"
int _n, _nodup = 0, _idx[10000000];
int _mapint[25] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};
int main(){
	register int _i, _j, _x;
	register int _k;
	register char _c;
	scanf("%d\n",&_n);
	for(_i = 0; _i < _n; ++_i){
		_x = 0; _j = 0;
		while(_j < 7){
			_c = getchar();
			if(_c >= '0' && _c <= '9'){
				_x = _x * 10 + _c - '0';
				++_j;
			}else if(_c >= 'A' && _c <= 'Y' && _c != 'Q'){
				_x = _x * 10 + _mapint[_c - 'A'];
				++_j;
			}
		}
		_idx[_x]++;
		while(getchar() != '\n');
	}
	for(_i = 0; _i < 10000000; ++_i){
		_k = _idx[_i];
		if(_k > 1){
			printf("%03d-%04d %d\n", (_i/10000), (_i%10000), _k);
			_nodup = 1;
		}
	}
	if(_nodup == 0) printf("No duplicates.\n");
	return 0;
}
