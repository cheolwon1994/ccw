#include <iostream>
using namespace std;
int heap[100001];
int heapSize = 0;

void push(int key) {
	int i = ++heapSize;
	while (i > 1 && key > heap[i / 2]) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = key;
}

int pop() {
	if (heapSize == 0) return 0;
	int result = heap[1];				//반환 값
	heap[1] = heap[heapSize--];		//마지막 원소
	int parent = 1;
	int child = 2;
	while (child <= heapSize) {
		if (child < heapSize && heap[child] < heap[child + 1])
			child++;
		if (heap[child] < heap[parent]) break;
		int temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;
		parent = child;
		child *= 2;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) cout << pop() << '\n';
		else push(a);
	}
	return 0;
}