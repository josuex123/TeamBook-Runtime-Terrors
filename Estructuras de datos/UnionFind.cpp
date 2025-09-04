struct DSU{
  vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1); 
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }
   int find(int v){
      if(v == parent[v])
         return v;
      return parent[v] = find(parent[v]);
   }

   void unionSet(int a, int b) {
   a = find(a);
   b = find(b);
   if (a != b) {
      if (size[a] < size[b])
         swap(a, b);
      parent[b] = a;
      size[a] += size[b];
   }
}
};