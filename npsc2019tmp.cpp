#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

uint64_t MeowHash(char *s) {
 uint64_t meow = 7122ul;
 while (*s != 0)
 meow = (meow << 13) ^ (meow >> 11) ^ (meow << 9)
 ^ (meow >> 7) ^ (meow << 5) ^ (meow >> 3)
 ^ (meow << 1) ^ ((uint64_t)(*s++) * 0xdeadbeeful);
 return meow;
 }
 char str[1000005]; 
signed main(){
	cin>>str; 
	cout<<MeowHash(str)<<endl;
}
