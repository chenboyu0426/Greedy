#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define maxn 760

using namespace std;

int a[maxn];
int b[maxn];
int tmp_a[maxn];

struct Item{
	int num;
	int b; //下方陣列的第幾個元素，如果和 a陣列第一個元素和被取出，要放進和第二個元素的和，以此類推 
	int a;
	bool operator< (const Item &tmp)const{
		return tmp.num < num;
	}
};

int main(){
	int n;
	
	while(scanf("%d", &n) != EOF){
		memset(a, 0, sizeof(a));
		Item item;
		priority_queue<Item> pq;
		
		for(int j = 0; j < n; j++){				
			scanf("%d", &a[j]);
			tmp_a[j] = a[j];
			
		}
		
		sort(a, a+n);
		sort(tmp_a, tmp_a+n);

		for(int i = 1; i < n; i++){
			
			for(int j = 0; j < n; j++){				
				scanf("%d", &b[j]);				
			}
			
			sort(b, b+n);
			for(int j = 0; j < n; j++){ //a的每一項 加 b的第一項放進bq 
				item.num = a[j]+b[0];
				item.b = -1;
				pq.push(item);
			}
			
			a[0] = pq.top().num;
			pq.pop();
			
			for(int j = 1; j < n; j++){	//b的每一項 加 a 的第一項放進queue 
				item.num = tmp_a[0]+b[j];
				item.b = j;
				item.a = 1;
				pq.push(item);			
			}
			
			int index = 1;
			while(index != n){
				if(pq.top().b != -1){
					item.num = tmp_a[pq.top().a] + b[pq.top().b], item.a++; //遞補和下一個 a陣列元素 的組合 
					pq.push(item);					
				}
				a[index] = pq.top().num; //最小的放進 a 陣列		
				index++;		
				pq.pop();
			}
			
			for(int j = 0; j < n; j++){
				tmp_a[j] = a[j]; //複製一份 a陣列值 
			}
			
			while(!pq.empty()){
				pq.pop();
			}
			for(int j = 0; j < n; j++){				
			printf("%d ", a[j]);
		}
		printf("\n");			
		}

		
		
	}
}
