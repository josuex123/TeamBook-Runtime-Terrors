const int N = 2e5 + 5;
int T[4*N];
int arr[N];
int n;

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

void update(int i, int tl, int tr, int idx, int val){
    if(tl == tr){
        arr[idx] = val;
        T[i] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if(idx <= tm){
        update(2*i+1, tl, tm, idx, val);
    }else{
        update(2*i+2,tm+1,tr,idx,val);
    }
    T[i] = min(T[2*i+1], T[2*i+2]);
}
int query(int i, int tl, int tr, int l, int r){
    if(l <= tl && tr <= r){
        return T[i];
    }
    if(r < tl || tr < l){
        return 1e9;
    }
    int tm = (tl + tr) / 2;

    int p1 = query(2*i+1, tl, tm, l, r);
    int p2 = query(2*i+2, tm+1, tr, l, r);
    
    return min(p1,p2);
}

int query(int l, int r){
    return query(0,0,n-1,l,r);
}
void update(int idx, int val){
    return update(0,0,n-1,idx,val);
}