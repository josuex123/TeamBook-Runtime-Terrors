const int N = 2e5 + 5;
const int INF = 1e9;
int T[4*N];
int lazy[4*N];
int arr[N];
int n;


void push(int i, int tl, int tr){
    if(lazy[i] != 0){
        T[i] += lazy[i]; 
        
        if(tl != tr){  
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
}
void init(int i, int tl, int tr){
    if(tl == tr){
        T[i] = arr[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    init(2 * i + 1, tl, tm);
    init(2 * i + 2, tm + 1, tr);
    
    T[i] = min(T[2 * i + 1], T[2 * i + 2]);
}

void update(int i, int tl, int tr, int l, int r, int val){
    push(i, tl, tr);
    
    if(l > r) return; 

    if(tl == l && tr == r){
        lazy[i] += val; 
        push(i, tl, tr); 
        return;
    }
   int tm = (tl + tr) / 2;
   update(2*i+1, tl, tm, l, min(r,tm), val);
   update(2*i+2,tm+1,tr,max(l,tm+1),r,val);
    
    T[i] = min(T[2*i+1], T[2*i+2]);
}
int query(int i, int tl, int tr, int l, int r){
    push(i, tl, tr);
    if(l > r) return INF;

    if(tl == l && tr == r){
        return T[i];
    }
    int tm = (tl + tr) / 2;

    int p1 = query(2*i+1, tl, tm, l, min(r,tm));
    int p2 = query(2*i+2, tm+1, tr, max(l,tm+1), r);
    
    return min(p1,p2);
}

int query(int l, int r){
    return query(0,0,n-1,l,r);
}
void update(int l,int r, int val){
    return update(0,0,n-1,l,r,val);
}