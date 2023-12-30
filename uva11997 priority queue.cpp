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
	int b; //�U��}�C���ĴX�Ӥ����A�p�G�M a�}�C�Ĥ@�Ӥ����M�Q���X�A�n��i�M�ĤG�Ӥ������M�A�H������ 
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
			for(int j = 0; j < n; j++){ //a���C�@�� �[ b���Ĥ@����ibq 
				item.num = a[j]+b[0];
				item.b = -1;
				pq.push(item);
			}
			
			a[0] = pq.top().num;
			pq.pop();
			
			for(int j = 1; j < n; j++){	//b���C�@�� �[ a ���Ĥ@����iqueue 
				item.num = tmp_a[0]+b[j];
				item.b = j;
				item.a = 1;
				pq.push(item);			
			}
			
			int index = 1;
			while(index != n){
				if(pq.top().b != -1){
					item.num = tmp_a[pq.top().a] + b[pq.top().b], item.a++; //���ɩM�U�@�� a�}�C���� ���զX 
					pq.push(item);					
				}
				a[index] = pq.top().num; //�̤p����i a �}�C		
				index++;		
				pq.pop();
			}
			
			for(int j = 0; j < n; j++){
				tmp_a[j] = a[j]; //�ƻs�@�� a�}�C�� 
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
