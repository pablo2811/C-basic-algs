import time



def hanoi(N,n,start,aux,dest,h):
	if not n:
		return
	hanoi(N,n-1,start,dest,aux,h)
	h[dest][N-n] = h[start][N-n]
	h[start][N-n] = 0
	hanoi(N,n-1,aux,start,dest,h)



N = int(input())
with open("PY_hanoi_times","w") as f:
	times = [0 for _ in range(N)]
	for x in range(1,N+1):
		h = [[i for i in range(x,0,-1)],[0 for _ in range(x)],[0 for __ in range(x)]]
		t = time.time()
		hanoi(x,x,0,1,2,h)
		times[x-1] = time.time() - t
		print("%.5f"%times[x-1],file=f)





